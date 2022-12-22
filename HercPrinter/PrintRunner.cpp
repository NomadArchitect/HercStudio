#include "PrintRunner.h"
#include "PrinterItem.h"

#include <QHostAddress>
#include <QElapsedTimer>
#include <QtGlobal>
#include <algorithm>

PrinterBufferReader::PrinterBufferReader() 
{
    mSocket = new QTcpSocket();
    mBuffPos = mBuff;
    mRunning = true;
}

QByteArray PrinterBufferReader::returnLine(const char *end)
{
    end++;
    QByteArray line(mBuff, end-mBuff);

    memmove(mBuff, end, mBuffPos-end);

    mBuffPos -= (end - mBuff);
    return line;
}

char *PrinterBufferReader::nextPos()
{
    char * maybeEndF = std::find(mBuff, mBuffPos, '\f');
    char * maybeEndN = std::find(mBuff, mBuffPos, '\n');
    char * maybeEndR = std::find(mBuff, mBuffPos, '\r');

    char * ret = std::min(std::min(maybeEndF, maybeEndN), maybeEndR);
    if (ret < mBuffPos) return ret;

    return NULL;
}

QByteArray PrinterBufferReader::readLine()
{
    char *pos = nextPos();
    if (pos != NULL)
    {
        return returnLine(pos);
    }

    while (mRunning) {
        qint64 len = mSocket->read(mBuffPos, 255);
        if (len == 0) {
            mSocket->waitForReadyRead(500);
            continue;
        }
        if (len < 0) { // error
            return "";
        }
        mBuffPos += len;
        pos = nextPos();
        if (pos != NULL)
            return returnLine(pos);
    }
    return "";
}

qint64 PrinterBufferReader::bytesAvailable() const
{
    return mSocket->bytesAvailable() + (mBuffPos - mBuff);
}

PrintRunner::PrintRunner(SynchronizedQueue& queue, PrinterItemConstPtr& printerItem, int maxQueueSize) :
    Runner(queue), mQueue(queue), mPrinterItem(printerItem), mMaxQueueSize(maxQueueSize)
{
}

void PrintRunner::readBuffer()
{
    while((mBufferReader->socket()->state() == QAbstractSocket::ConnectedState && mRunning))
    {
        bool ff = false;
        QByteArray line = mBufferReader->readLine();
        int len = line.length();
        if (len == 0) {  // no data
            continue; 
        }
        if ((line[len-1] == '\f') && (len > 1)) // in practice this is not likely to happen as all \f are preceded by \r or \n
        {
            line.data()[len-1] = '\n';
            ff = true;
        }

        if ( (len>0) &&  ((line[len-1] == '\n') || (line[len-1] == '\r')) )
            line.data()[len-1] = '\0';

        if (line.length() != 0)
        {
            hOutDebug(5,":" << line.data());
            if (ff) mQueue.push_back("\f"); // generate eject
#ifdef Q_OS_DARWIN
            else mQueue.push_back((line));
#else
            else mQueue.push_back(std::move(line));
#endif
            emit newData();
            while (mQueue.size() > mMaxQueueSize) // do not flood the queue
                QThread::msleep(100);
        }
    }
}

void PrintRunner::waitForConnected()
{
    while(mBufferReader->socket()->state() != QAbstractSocket::ConnectedState && mRunning)
    {
        hOutDebug(3,"not connected:" << mBufferReader->socket()->state());
        if (mBufferReader->socket()->state() == QAbstractSocket::UnconnectedState)
        {
            mBufferReader->socket()->connectToHost(QHostAddress(mPrinterItem->mIp), mPrinterItem->mPort);
            mBufferReader->socket()->waitForConnected(1000);
            if(mRunning && mBufferReader->socket()->state() != QAbstractSocket::ConnectedState)
                QThread::msleep(200);
            hOutDebug(3, "error:" << mBufferReader->socket()->errorString().toStdString());
        }
        else
        {
            QThread::sleep(1);
        }
    }
}

void PrintRunner::run()
{
    mBufferReader = QSharedPointer<PrinterBufferReader>(new PrinterBufferReader());
    mRunning = true;

    qRegisterMetaType<QAbstractSocket::SocketState>("QAbstractSocket::SocketState");
    connect(mBufferReader->socket(), SIGNAL(stateChanged(QAbstractSocket::SocketState)),this, SLOT(socketStateChanged(QAbstractSocket::SocketState)));

    while(mRunning)
    {
        QElapsedTimer timer;
        timer.start();
        emit waiting();
        waitForConnected();

        if (!mRunning) break;

        emit connected();
        hOutDebug(3,"appl connected");

        readBuffer();
        hOutDebug(3, "state:" << mBufferReader->socket()->state() << " running: " << (mRunning? "y" : "n") );
        emit disconnected();
        if (timer.elapsed() < 1000)
        {
            QThread::msleep(1000);
        }
    }

    emit stoppedWaiting();
    mBufferReader->socket()->close();
}

void PrintRunner::socketStateChanged(QAbstractSocket::SocketState state)
{
    static QAbstractSocket::SocketState prevState = QAbstractSocket::UnconnectedState;
    if (state != prevState)
    {
        if (state == QAbstractSocket::ConnectedState && prevState != QAbstractSocket::ConnectedState)
        {
            hOutDebug(3,"Connected");
            emit connected();
        }
        if (state != QAbstractSocket::ConnectedState && prevState == QAbstractSocket::ConnectedState)
        {
            hOutDebug(3,"Disconnected");
            emit disconnected();
        }
        prevState = state;
    }
    hOutDebug(3, "Socket state: " << state);
}

void PrintRunner::stop()
{
    mRunning = false;
    mBufferReader->close();
}

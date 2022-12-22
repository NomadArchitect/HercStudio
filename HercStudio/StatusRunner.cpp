/*
 *  File:       StatusRunner.cpp
 *
 *  Author:     Jacob Dekel
 *  Created on: Aug 7, 2009
 *
 *  Copyright (c) 2009-2013 Jacob Dekel
 *  $Id$
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "StatusRunner.h"
#include "HerculesStudio.h"
#include "NamedPipe.h"

#include <fcntl.h>

StatusRunner::StatusRunner(SynchronizedQueue& statusQueue, HerculesExecutor * herculesExecutor)
: Runner(statusQueue), mHerculesExecutor(herculesExecutor)
{

}

StatusRunner::~StatusRunner()
{
}

void StatusRunner::run()
{
#ifdef hFramework
	mProcess = mHerculesExecutor->getQProcess();
	connect(mHerculesExecutor->getQProcess(),
			SIGNAL(readyReadStandardError()),
			this,
			SLOT(readStandardError()));
	return;
#else
	QFile& statusFile = NamedPipe::getInstance().getHerculesStatus();
	mRunning = true;
    bool lineRead = false;
    int startupCounter = 0;

	while(mRunning)
	{
		QByteArray line = statusFile.readLine(512);
		if (line.length() == 0)
		{
            // we wait up to 2 seconds for data to appear in the log
            if (!lineRead)
            {
                if (startupCounter++ < 200)
                {
                    QThread::msleep(10);
                    continue; // retry reading by returning to main loop
                }
            }
			emit newData();
			break;
		}
        lineRead = true;
		line.truncate(line.indexOf('\n'));
		mQueue.push_back(line);
		emit newData();
	}
#endif
}


void StatusRunner::readStandardError()
{
	mProcess->setReadChannel(QProcess::StandardError);
	while (true)
	{
		QByteArray output = mProcess->readLine();
		if (output.length() == 0) break;
		output[output.length()-1]='\0';
		mQueue.push_back(output.data());
		emit newData();
	}
}


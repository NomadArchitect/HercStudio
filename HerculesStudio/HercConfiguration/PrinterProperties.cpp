/*
 *  File: PrinterProperties.cpp
 *
 *  Author:     Jacob Dekel
 *  Created on: Aug 7, 2009
 *
 *  Copyright (c) 2009 Jacob Dekel
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

#include "PrinterProperties.h"

#include <QMessageBox>
#include <QFileDialog>

#include <algorithm>
#include <sstream>

PrinterProperties::PrinterProperties(ConfigLine& line, QWidget *parent)
    : GenericDeviceProperties(line, parent)
{
  ui.setupUi(this);

  ui.filename->setValidator(new PrinterFileNameValidator(this));

  if (!line.isNew())
    {
        ui.deviceNumber->setText(mLine.getToken(0).c_str());
        ui.printerCombo->setCurrentIndex( (mLine.getToken(1) == "3211") ? 1 : 0);
        if (mLine.size() > 2)
        {
            ui.filename->setText(mLine.getToken(2).c_str());
            if (mLine.size() > 3)
            {
                std::string crlf = mLine.getToken(3);
                std::transform(crlf.begin(), crlf.end(), crlf.begin(), ::tolower);
                ui.crlfCheckBox->setChecked(crlf == "crlf");
            }
        }
        else
            ui.crlfCheckBox->setEnabled(false);
    }

    connect(ui.OKButton, SIGNAL(clicked()), this, SLOT(ok()));
    connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(ui.filenameBrowseButton, SIGNAL(clicked()), this, SLOT(fileNameBrowse()));

}

PrinterProperties::~PrinterProperties()
{

}

void PrinterProperties::ok()
{
    if (!deviceNumberValidator(ui.deviceNumber))
            return;

    if (ui.filename->text().isEmpty())
    {
        QMessageBox::warning(this, "File name is empty", "Please provide file name", QMessageBox::Ok);
        return;
    }


    std::stringstream newLineBuff;
    bool crlf = (ui.filename->text().isEmpty() == false) && (ui.crlfCheckBox->isChecked());

    newLineBuff << ui.deviceNumber->text().toStdString() << " "
            << ui.printerCombo->currentText().toStdString() << " "
            << ui.filename->text().toStdString() << " "
            << (crlf ? "crlf" : " ")
            << "\n";
    outDebug(5, std::cout << "new line:" << newLineBuff.str() << std::endl);
    mLine.replaceLine(newLineBuff.str());
    emit updateLine(true);
    this->deleteLater();
}

void PrinterProperties::cancel()
{
    emit updateLine(false);
    this->deleteLater();
}

void PrinterProperties::setCrlfEnabled(bool checked)
{
     ui.crlfCheckBox->setEnabled(checked);
}

void PrinterProperties::fileNameBrowse()
{
    std::string s = QFileDialog::getOpenFileName(this,
                "Set Printer File",
                "~/",
                tr("All files(*)")).toUtf8().data();
    ui.filename->setText(s.c_str());
}

PrinterFileNameValidator::PrinterFileNameValidator(QObject * parent)
: QValidator(parent), mParent(dynamic_cast<PrinterProperties *>(parent))
{

}

QValidator::State PrinterFileNameValidator::validate(QString & v, int & ) const
{
    mParent->setCrlfEnabled(v.length()>0);
    return QValidator::Acceptable;
}

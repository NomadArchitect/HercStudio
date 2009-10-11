/*
 *  File: CtcProperties.cpp
 *
 *  Author:     Jacob Dekel
 *  Created on:
 *
 *  Copyright (c) 2009 Jacob Dekel
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

#include "CtcProperties.h"
#include "ConfigurationEditor.h"
#include "Preferences.h"

#include <QMessageBox>
#include <QFileDialog>

#include <sstream>

CtcProperties::CtcProperties(ConfigLine& configLine, QWidget *parent)
   : GenericDeviceProperties(configLine, parent)
{
	ui.setupUi(this);
	initialize(configLine);

	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(ok()));
	connect(ui.cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
	connect(ui.typeCombo, SIGNAL(currentIndexChanged(const QString &)), this, SLOT(typeChanged(const QString &)));
	connect(ui.oatBrowseButton, SIGNAL(clicked()), this, SLOT(oatBrowse()));
}

CtcProperties::~CtcProperties()
{

}


void CtcProperties::ok()
{
    if (!deviceNumberValidator(ui.deviceNumber))
        return;
    std::stringstream newLineBuff;

    newLineBuff << ui.deviceNumber->text().toStdString();
    newLineBuff << " " << ui.typeCombo->currentText().toStdString();

    if (ui.typeCombo->currentIndex() == 0)  // lcs
    {
        if (!ui.tun->text().isEmpty())
        {
            newLineBuff << " -n " << ui.tun->text().toStdString();
        }
        if (!ui.oat->text().isEmpty())
        {
            newLineBuff << " -o " <<  ui.oat->text().toStdString();
        }
        if (!(ui.mac->text() == ":::::"))
        {
            if (macValidator(ui.mac->text().toStdString()))
            {
                newLineBuff << " -m " <<  ui.mac->text().toStdString() ;
            }
            else
                return;
        }
        if ( !ui.guestIP->text().isEmpty() && (ui.guestIP->text() != "..." ) )
        {
            if (ipValidator(ui.guestIP, false))
            {
                newLineBuff << " " << ui.guestIP->text().toStdString() ;
            }
            else
                return;
        }
    }
    else  if (ui.typeCombo->currentIndex() == 2)  // ctct
    {
    	if (!ipValidator(ui.hostIP,false))
    	   return;
        newLineBuff << " " << ui.lportSpinbox->text().toStdString() ;
        newLineBuff << " " << ui.hostIP->text().toStdString();
        newLineBuff << " " << ui.hostPortSpinbox->text().toStdString();
        newLineBuff << " " << ui.buffsizeSpinBox->text().toStdString();
    }
    else  // ctci
    {
    	if (!ipValidator(ui.guestIP,false))
    		return;
    	if (!ipValidator(ui.hostIP,false))
    		return;
        if (!ui.tun->text().isEmpty())
        {
            newLineBuff << " -n " << ui.tun->text().toStdString();
        }
        if (!(ui.mac->text() == ":::::"))
        {
            if (macValidator(ui.mac->text().toStdString()))
            {
                newLineBuff << " -m " <<  ui.mac->text().toStdString() ;
            }
            else
                return;
        }
        if (!(ui.mask->text() == "..."))
        {
            if (ipValidator(ui.mask, false))
            {
                newLineBuff << " -s " <<  ui.mask->text().toStdString() ;
            }
            else
                return;
        }
        if (!(ui.guestIP->text() == "..."))
        {
            if (ipValidator(ui.guestIP, false))
            {
                newLineBuff << " " <<  ui.guestIP->text().toStdString() ;
            }
            else
                return;
        }
        if (!(ui.hostIP->text() == "..."))
        {
            if (ipValidator(ui.hostIP, false))
            {
                newLineBuff << " " <<  ui.hostIP->text().toStdString() ;
            }
            else
                return;
        }
    }


    newLineBuff << "\n";
    mLine.replaceLine(newLineBuff.str());
    emit updateLine(true);
    this->deleteLater();
}

void CtcProperties::cancel()
{
    emit updateLine(false);
    this->deleteLater();
}

bool CtcProperties::macValidator(const std::string& mac)
{
    bool ret = true;
    if (mac.length() != 17)
        ret = false;
    QString qmac = mac.c_str();
    for (int i=0; i<6 && ret; i++)
    {
        int pos = i*3;
        if (i>0 && qmac.toStdString().substr(i*3-1,1) != ":")
            ret=false;
        std::string c1 = qmac.toLower().toStdString().substr(pos,1).c_str();
        std::string c2 = qmac.toLower().toStdString().substr(pos+1,1).c_str();
        if (c1[0] < '0' || c1[0] > 'f' || c2[0] < '0' || c2[0] > 'f')
        {
            ret=false;
        }
    }
    if (!ret)
    {
        QMessageBox::warning(this, "Illegal MAC address", "Please provide device name\nhh:hh:hh:hh:hh:hh", QMessageBox::Ok);
        return false;
    }
    return true;
}


void CtcProperties::typeChanged(const QString &newValue)
{
    if (newValue.toLower() == "lcs") arangeLcs(true);
    else if (newValue.toLower() == "ctct") arangeCtct(true);
    else arangeCtc(true);
}

void CtcProperties::arangeLcs(bool set)
{
    outDebug(5, std::cout << "lcs " << (set ? "true" : "false") << std::endl);
    if (set)
    {
        arangeCtc(!set);
        arangeCtct(!set);
        ui.hostIP->setInputMask("000.000.000.000;");
    }
    ui.guestIPLabel->setVisible(set);
    ui.guestIP->setVisible(set);
    ui.tunLabel->setVisible(set);
    ui.tun->setVisible(set);
    ui.macLabel->setVisible(set);
    ui.mac->setVisible(set);
    ui.macLabel2->setVisible(set);
    ui.oatFilenameLabel->setVisible(set);
    ui.oat->setVisible(set);
    ui.oatBrowseButton->setVisible(set);
    //ui.oatEditButton->setVisible(set);

    ui.hostIPLabel->setGeometry(20,70,53,16);
    ui.hostIP->setGeometry(110,60,113,26);
    ui.tunLabel->setGeometry(20,70,81,16);
    ui.tun->setGeometry(110,60,301,26);
    ui.macLabel->setGeometry(20,110,53,16);
    ui.mac->setGeometry(110,100,171,26);
    ui.macLabel2->setGeometry(300,100,53,16);
    ui.oatFilenameLabel->setGeometry(20,150,91,16);
    ui.oat->setGeometry(110,140,211,26);
    ui.oatBrowseButton->setGeometry(330,140,21,26);
    //ui.oatEditButton->setGeometry(360,140,52,26);
}

void CtcProperties::arangeCtc(bool set)
{
    outDebug(5, std::cout << "ctc " << (set ? "true" : "false") << std::endl);
    if (set)
    {
        arangeLcs(!set);
        arangeCtct(!set);
        ui.hostIP->setInputMask("000.000.000.000;");
    }
    ui.guestIPLabel->setVisible(set);
    ui.guestIP->setVisible(set);
    ui.maskLabel->setVisible(set);
    ui.mask->setVisible(set);
    ui.hostIPLabel->setVisible(set);
    ui.hostIP->setVisible(set);
    ui.tunLabel->setVisible(set);
    ui.tun->setVisible(set);
    ui.macLabel->setVisible(set);
    ui.mac->setVisible(set);
    ui.macLabel2->setVisible(set);

    ui.hostIPLabel->setGeometry(20,70,53,16);
    ui.hostIP->setGeometry(110,60,113,26);
    ui.tunLabel->setGeometry(20,110,81,16);
    ui.tun->setGeometry(110,100,301,26);
    ui.macLabel->setGeometry(20,150,53,16);
    ui.mac->setGeometry(110,140,171,26);
    ui.macLabel2->setGeometry(300,140,53,16);
}

void CtcProperties::arangeCtct(bool set)
{
    outDebug(3, std::cout << "ctct " << (set ? "true" : "false") << std::endl);
    if (set)
    {
        arangeCtc(!set);
        arangeLcs(!set);
        ui.hostIP->setInputMask("000.000.000.000;");
    }
    ui.hostIPLabel->setVisible(set);
    ui.hostIP->setVisible(set);
    ui.hostPortLabel->setVisible(set);
    ui.hostPortSpinbox->setVisible(set);
    ui.lportLabel->setVisible(set);
    ui.lportSpinbox->setVisible(set);
    ui.buffsizeLabel->setVisible(set);
    ui.buffsizeSpinBox->setVisible(set);

    ui.hostIPLabel->setGeometry(20,30,53,16);
    ui.hostIP->setGeometry(110,20,113,26);
    ui.hostPortLabel->setGeometry(240,30,61,16);
    ui.hostPortSpinbox->setGeometry(320,20,61,26);
    ui.lportLabel->setGeometry(20,70,61,16);
    ui.lportSpinbox->setGeometry(110,60,61,26);
    ui.buffsizeLabel->setGeometry(20,110,71,16);
    ui.buffsizeSpinBox->setGeometry(110,100,71,26);
}

void CtcProperties::arangeByType()
{
    if (ui.typeCombo->currentText().toLower() == "lcs")
    {
        arangeLcs(true);
    }
    else if (ui.typeCombo->currentText().toLower() == "ctct")
    {
        arangeCtct(true);
    }
    else
    {
        arangeCtc(true);
    }
}

void CtcProperties::oatBrowse()
{
    std::string s = QFileDialog::getOpenFileName(this,
                    "Locate OAT File Name",
                    Preferences::getInstance().configDir().c_str(),
                    tr("All files(*)")).toUtf8().data();
    ui.oat->setText(s.c_str());
}

void CtcProperties::initialize(ConfigLine & configLine)
{
    if (configLine.size() > 0)
            ui.deviceNumber->setText(configLine.getToken(0).c_str());

    QString type = configLine.getToken(1).c_str();
    if (type.toLower() == "lcs")
    {
        ui.typeCombo->setCurrentIndex(0);

        for (int i=2; i<configLine.size(); i++)
        {
            if (configLine.getToken(i) == "-n" ||
                configLine.getToken(i) == "--dev")
            {
                ui.tun->setText(configLine.getToken(++i).c_str());
            }
            else if (configLine.getToken(i) == "-o" ||
                configLine.getToken(i) == "--oat")
            {
                ui.oat->setText(configLine.getToken(++i).c_str());
            }
            else if (configLine.getToken(i) == "-m" ||
                configLine.getToken(i) == "--mac")
            {
                ui.mac->setText(configLine.getToken(++i).c_str());
            }
            else if (i+1 == configLine.size())
            {
                ui.guestIP->setText(configLine.getToken(i).c_str());
            }
        }
    }
    else if (type.toLower() == "ctct")
    {
        ui.typeCombo->setCurrentIndex(2);

        int port = atoi(configLine.getToken(2).c_str());
        ui.lportSpinbox->setValue(port);
        ui.hostIP->setInputMask("");
        ui.hostIP->setText(configLine.getToken(3).c_str());
        port = atoi(configLine.getToken(4).c_str());
        ui.hostPortSpinbox->setValue(port);
        if (configLine.size() > 5)
        {
            int size = atoi(configLine.getToken(5).c_str());
            ui.buffsizeSpinBox->setValue(size);
        }
    }
    else
    {
        ui.typeCombo->setCurrentIndex(1);

        for (int i=2; i<configLine.size(); i++)
        {
            if (configLine.getToken(i) == "-n" ||
                configLine.getToken(i) == "--dev")
            {
                ui.tun->setText(configLine.getToken(++i).c_str());
            }
            else if (configLine.getToken(i) == "-m" ||
                configLine.getToken(i) == "--mac")
            {
                ui.mac->setText(configLine.getToken(++i).c_str());
            }
            else if (configLine.getToken(i) == "-s")
            {
                ui.mask->setText(configLine.getToken(++i).c_str());
            }
            else if (i+1 == configLine.size())
            {
                ui.hostIP->setText(configLine.getToken(i).c_str());
            }
            else if (i+2 == configLine.size())
            {
                ui.guestIP->setText(configLine.getToken(i).c_str());
            }
        }
    }
/*
    ui.hostIPLabel->setGeometry(20,70,53,16);
    ui.hostIP->setGeometry(110,60,113,26);
    ui.hostPortLabel->setGeometry(240,70,61,16);
    ui.hostPortSpinbox->setGeometry(320,60,61,26);
    ui.tunLabel->setGeometry(20,110,81,16);
    ui.tun->setGeometry(110,100,301,26);
    ui.macLabel->setGeometry(20,150,53,16);
    ui.mac->setGeometry(110,140,171,26);
    ui.macLabel2->setGeometry(300,140,53,16);
    ui.oatFilenameLabel->setGeometry(20,190,91,16);
    ui.oat->setGeometry(110,180,211,26);
    ui.oatBrowseButton->setGeometry(330,180,21,26);
    ui.oatEditButton->setGeometry(360,180,52,26);
    ui.lportLabel->setGeometry(20,250,61,16);
    ui.lportSpinbox->setGeometry(110,240,61,26);
    ui.buffsizeLabel->setGeometry(20,290,71,16);
    ui.buffsize->setGeometry(110,280,151,26);
*/

    arangeByType();


}
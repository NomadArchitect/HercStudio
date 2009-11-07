/*
 *  File: DevicesPane.h
 *
 *  Author:     Jacob Dekel
 *  Created on: Nov 1, 2009
 *
 *  Copyright (c) 2009 Jacob Dekel
 *  $Id: DevicesRename.h 34 2009-11-07 06:15:58Z jacob $
 *
 *	This object handles the re-initialization of devices during hercules run time
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

#ifndef DEVICESRENAME_H
#define DEVICESRENAME_H

#include "Configuration.h"

#include <QtGui/QDialog>
#include "ui_DevicesRename.h"

class DevicesRename : public QDialog
{
    Q_OBJECT

public:
    DevicesRename(QWidget *parent = 0, int value=0);
    ~DevicesRename();

public slots:
    void ok();
    void notok();

signals:
    void accepted(QString oldValue, QString newValue);
    void rejected();

private:
    Ui::DevicesRenameClass ui;
    int mInitialDevNum;

    Configuration::HexSpinBox* mSpinBox;
};

#endif // DEVICESRENAME_H
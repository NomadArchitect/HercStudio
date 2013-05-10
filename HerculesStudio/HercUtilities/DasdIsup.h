/*
 *  File:       DasdIsup.h
 *
 *  Author:     Jacob Dekel
 *  Created on: Aug 7, 2009
 *
 *  Copyright (c) 2009-2013 Jacob Dekel
 *  $Id$
 *
 *  Dasdisup utility object
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

#ifndef DASDISUP_H
#define DASDISUP_H

#include "GenericUtility.h"

#include <QtWidgets/QDialog>
#include "ui_DasdIsup.h"

class UtilityExecutor;
class DasdIsup : public GenericUtility
{
    Q_OBJECT

public:
    DasdIsup(QWidget *parent = 0);
    ~DasdIsup();

private:
    Ui::DasdIsupClass ui;

	virtual void finishedSlot();

private slots:
    void exitClicked();
    void runClicked();
    void browseFileClicked();
    void browseSfClicked();
    void runnerMaximumChanged(int maximum);
    void runnerValueChanged(int value);
};

#endif // DASDISUP_H

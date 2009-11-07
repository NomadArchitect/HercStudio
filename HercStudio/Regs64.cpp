/*
 *  File:       Regs64.cpp
 *
 *  Author:     Jacob Dekel
 *  Created on: Aug 7, 2009
 *
 *  Copyright (c) 2009 Jacob Dekel
 *  $Id: Regs64.cpp 34 2009-11-07 06:15:58Z jacob $
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

#include "Regs64.h"

std::string Regs64::gCommand = "]GREGS64=";
std::string Regs64::cCommand = "]CREGS64=";
std::string Regs64::fCommand = "]FREGS64=";

Regs64::Regs64(QWidget * parent, std::string command) :
	Regs32(parent, command),
	mLine5(this),
	mLine6(this),
	mLine7(this),
	mLine8(this)
{
    QFont font("monospace", 9);
    font.setStyleHint(QFont::Courier);
    mLine5.setFont(font);
    mLine6.setFont(font);
    mLine7.setFont(font);
    mLine8.setFont(font);
    mLine5.setGeometry(340,10,330,12);
    mLine6.setGeometry(340,26,330,12);
    mLine7.setGeometry(340,42,330,12);
    mLine8.setGeometry(340,58,330,12);

}

Regs64::~Regs64()
{
}

void Regs64::setActive(bool active)
{
	Regs32::setActive(active);
    mLine5.setVisible(active);
    mLine6.setVisible(active);
    mLine7.setVisible(active);
    mLine8.setVisible(active);
    std::string command = mCommand + (active ? '1' : '0');
}

void Regs64::notify(const std::string& statusLine)
{
	if (statusLine[5] == '0')
		Regs32::mLine1.setText(statusLine.c_str());
	if (statusLine[5] == '2')
		Regs32::mLine2.setText(statusLine.c_str());
	if (statusLine[5] == '4')
		Regs32::mLine3.setText(statusLine.c_str());
	if (statusLine[5] == '6')
		Regs32::mLine4.setText(statusLine.c_str());
	if (statusLine[5] == '8')
		Regs64::mLine5.setText(statusLine.c_str());
	if (statusLine[5] == 'A')
		Regs64::mLine6.setText(statusLine.c_str());
	if (statusLine[5] == 'C')
		Regs64::mLine7.setText(statusLine.c_str());
	if (statusLine[5] == 'E')
		Regs64::mLine8.setText(statusLine.c_str());
}
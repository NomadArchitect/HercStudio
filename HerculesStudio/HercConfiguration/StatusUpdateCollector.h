/*
 *  File: StatusUpdateCollector
 *
 *  Author:     Jacob Dekel
 *  Created on:
 *
 *  Copyright (c) 2009 Jacob Dekel
 *
 *	This is the base class for all objects receiving status updates
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

#ifndef STATUSUPDATECOLLECTOR_H_
#define STATUSUPDATECOLLECTOR_H_

#include <string>

class StatusUpdateCollector {
public:
  StatusUpdateCollector();
  virtual ~StatusUpdateCollector();

  virtual void notify(const std::string& ) = 0;
};

#endif /* STATUSUPDATECOLLECTOR_H_ */
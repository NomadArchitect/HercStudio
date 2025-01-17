/*
 *  File: ConfigFile.h
 *
 *  Author:     Jacob Dekel
 *  Created on: Aug 7, 2009
 *
 *  Copyright (c) 2009-2013 Jacob Dekel
 *  $Id$
 *
 *	This object manages the configuration file
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

#ifndef CONFIG_FILE
#define CONFIG_FILE

#include "SystemConfigLine.h"
#include "DeviceConfigLine.h"

#include <QPlainTextEdit>
#include <QTextBlock>
#include <string>
#include <vector>

typedef std::vector<ConfigLine> FileArray;
#define MAX_CONFIG_LINE 512

struct SynonymTableEntry
{
	std::string keyword1;
	std::string keyword2;
};

class ConfigFile
{
public:
	ConfigFile(const std::string& fileName);
	virtual ~ConfigFile();

	void 				initialize();
	void                updateEditor(QPlainTextEdit& document);
	const std::string& 	getFileName() const;
	SystemConfigLine 	* operator[] (int index) const;
	DeviceConfigLine 	* getDevice(int index) const;
	DeviceConfigLine 	* getDevice(const std::string& devno) const;
	DeviceConfigLine 	* findFirstDeviceByType(const char * type) const;
	int                 numberOfDevices();
	bool 				write(const std::string& fileName);
	bool 				write();
	int 				size() const;
	void 				addNonDev(SystemConfigLine * configLine);
	void 				addDev(DeviceConfigLine * configLine);
	void 				appendNewLines();
    const 				ConfigLine * locateLine(const std::string& keyword, bool create=false, bool synonyms=true);
	void 				deleteLine(int index);
	inline int 			getLastSys() { return mLastSys; };
	bool 				changed();
	inline bool 		isNew() const {return mNewConfig;};
	void 				setNew(bool newVal);

private:
	enum BuildType
	{
		File=1,
		TextEdit
	};

  std::string 	     				mFileName;
  FileArray 						mFileArray;
  std::vector<SystemConfigLine> 	mNewLines;
  std::vector<DeviceConfigLine> 	mNewDeviceLines;
  static struct SynonymTableEntry 	mSynonyms[];
  FILE *							mFile;
  QPlainTextEdit *                  mEditor;
  QTextBlock                        mEditorIterator;

  int 	mLastSys;              // last line before device statements
  bool 	mChanged;              // updates were done to file which were not saved yet
  bool 	mNewConfig;		       // never saved
  static const char *configTemplate[];  // template for new config file
  int  	templateCounter;	   // line number to read from template

  void openTemplate();
  char * getNextLine(char * buff, int len, BuildType type);

  void buildConfig(BuildType);
};

#endif

/*
 *  File:       NamedPipe.h
 *
 *  Author:     Jacob Dekel
 *  Created on: Aug 7, 2009
 *
 *  Copyright (c) 2009 Jacob Dekel
 *  $Id: NamedPipe.h 34 2009-11-07 06:15:58Z jacob $
 *
 *	This object manages the pipe between hercules and hercules studio
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

#ifndef NAMEDPIPE_H_
#define NAMEDPIPE_H_

#include <QMutex>

#include <string>
#include <cstdio>

class NamedPipe
{
public:
    static NamedPipe& getInstance();
    virtual ~NamedPipe();
    int recover();
    void generatePid(int studioPid, int herculesPid);
    int getHerculesPid();
    std::string getHerculesCommandline();

    FILE * getHerculesStdin();
    FILE * getHerculesCommandsFile();
    FILE * getHerculesStdout();
    FILE * getHerculesLogfile();
    FILE * getHerculesStderr();
    FILE * getHerculesStatus();

private:
    static NamedPipe sInstance;
    std::string mSetPath;
    std::string mFifo0;
    std::string mFifo1;
    std::string mFifo2;
    bool mRecovery;
    int mHerculesPid;

    int delDir(std::string& path);
    bool processIsRunning(int pid);

    QMutex      mMutex;
    FILE * mStdinOutput;
    FILE * mStdout;
    FILE * mStdoutInput;
    FILE * mStderr;
    FILE * mStderrInput;


protected:
    NamedPipe();
};

#endif /* NAMEDPIPE_H_ */

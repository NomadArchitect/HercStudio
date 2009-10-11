/*
 *  File:       HerculesExecutor.cpp
 *
 *  Author:     Jacob Dekel
 *  Created on: Aug 7, 2009
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

#include "HerculesExecutor.h"
#include "Arguments.h"
#include "NamedPipe.h"

#include <unistd.h>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <cerrno>
#include <iostream>

int pipeLog[2];
int pipeStatus[2];
int pipeCommand[2];

HerculesExecutor::HerculesExecutor(QMainWindow & mainWindow)
: mMainWindow(mainWindow)
{

}

HerculesExecutor::~HerculesExecutor()
{

}

int HerculesExecutor::run(std::string & configName, std::string& herculesPath)
{
    int pid;
    int rc =0;

    pid = fork();
    if (pid < 0)
    	return -1;
    if (pid == 0)
    {
        std::string hercules = herculesPath;
        if (herculesPath.length() != 0 )
            hercules += "/";
        hercules += "hercules";
        outDebug(2, std::cout << "hercules:" << hercules << std::endl);

        FILE * fileOut = NamedPipe::getInstance().getHerculesStdout();
        rc = dup2(fileno(fileOut),fileno(stdout));

        FILE * fileErr = NamedPipe::getInstance().getHerculesStderr();
        rc = dup2(fileno(fileErr),fileno(stderr));

        FILE * fileIn = NamedPipe::getInstance().getHerculesStdin();
        if (fileIn == NULL) perror("fifo0");
        fflush(stdout);
        rc = dup2(fileno(fileIn),fileno(stdin));
        if (rc != 0) perror("stdin");

        if (Arguments::getInstance().resourceFileName().length() > 0)
        {
        	std::string resourceFile = "HERCULES_RC=" + Arguments::getInstance().resourceFileName();
        	int stat = putenv(const_cast<char *>(resourceFile.c_str()));
            if (stat)
            {
             std::cout<<"failed to define environment variable "<< stat << std::endl;
            }
        }
        rc = execlp(hercules.c_str(),hercules.c_str(),"-d","-f",configName.c_str(),"EXTERNALGUI",NULL);
        std::cout << "***************************************************************" << std::endl
				<< "hercules could not be started (" <<  rc << ")" << std::endl
				<< "check that hercules is properly installed and is on the default path " << std::endl
				<< "or that the path specified in Edit/Preferences is correct." << std::endl
				<< "**************************************************************" << std::endl;
        _exit(1);
    }

    printf("pid=:%d\n",pid);
    return pid;

}
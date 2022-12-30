/*
 *  File: ReaderFileListView.cpp
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

#include "HerculesStudio.h"
#include "ReaderFileListView.h"
#include "CardReaderProperties.h"

#include <QStandardItem>
#include <QDropEvent>


ReaderFileListView::ReaderFileListView(QWidget * parent )
 : QListView(parent)
{

}

ReaderFileListView::~ReaderFileListView()
{
}

void ReaderFileListView::setReaderParent(QWidget * parent)
{
    mReaderParent = parent;
}

void ReaderFileListView::dropEvent ( QDropEvent * event )
{
    QListView::dropEvent(event);

    if (event->isAccepted())
    {
        CardReaderProperties * parent = NULL;
        try
        {
            parent = static_cast<CardReaderProperties *>(mReaderParent);
        }
        catch (...){}
        if (parent != NULL)
        {
            parent->shouldBeDeleted();
        }
    }
}
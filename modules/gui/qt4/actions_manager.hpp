/*****************************************************************************
 * Controller.hpp : Controller for the main interface
 ****************************************************************************
 * Copyright (C) 2006-2008 the VideoLAN team
 * $Id$
 *
 * Authors: Jean-Baptiste Kempf <jb@videolan.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef _ACTIONS_MANAGER_H_
#define _ACTIONS_MANAGER_H_

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "qt4.hpp"

#include <QObject>
typedef enum actionType_e
{
    PLAY_ACTION,
    STOP_ACTION,
    OPEN_ACTION,
    PREVIOUS_ACTION,
    NEXT_ACTION,
    SLOWER_ACTION,
    FASTER_ACTION,
    FULLSCREEN_ACTION,
    EXTENDED_ACTION,
    PLAYLIST_ACTION,
    SNAPSHOT_ACTION,
    RECORD_ACTION,
    FRAME_ACTION,
    ATOB_ACTION,
    REVERSE_ACTION,
    SKIP_BACK_ACTION,
    SKIP_FW_ACTION,
} actionType_e;

class ActionsManager : public QObject
{

    Q_OBJECT
public:
    static ActionsManager *getInstance( intf_thread_t *_p_intf )
    {
        if( !instance )
            instance = new ActionsManager( _p_intf );
        return instance;
    }
    static void killInstance()
    {
        if( instance ) delete instance;
    }
    virtual ~ActionsManager();

private:
    static ActionsManager *instance;
    ActionsManager( intf_thread_t  *_p_i, QObject *_parent = 0 );
    intf_thread_t       *p_intf;

protected slots:
    virtual void doAction( int );

protected slots:
    void play();
    void stop();
    void prev();
    void next();
    void fullscreen();
    void extSettings();
    void faster();
    void slower();
    void reverse();
    void playlist();
    void snapshot();
    void record();
    void frame();

};

#endif


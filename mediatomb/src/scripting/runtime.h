/*  scripting.h - this file is part of MediaTomb.
                                                                                
    Copyright (C) 2005 Gena Batyan <bgeradz@deadlock.dhs.org>,
                       Sergey Bostandzhyan <jin@deadlock.dhs.org>
                                                                                
    MediaTomb is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.
                                                                                
    MediaTomb is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
                                                                                
    You should have received a copy of the GNU General Public License
    along with MediaTomb; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __SCRIPTING_RUNTIME_H__
#define __SCRIPTING_RUNTIME_H__

#define XP_UNIX 1
#include <jsapi.h>
#include <pthread.h>
#include "common.h"
#include "sync.h"

class Runtime : public zmm::Object
{
protected:
    JSRuntime *rt;
public:
	Runtime();
	virtual ~Runtime();
    JSRuntime *getRT();
    static zmm::Ref<Runtime> getInstance();
    inline void lock() { mutex->lock(); }
    inline void unlock() { mutex->unlock(); }
protected:
    zmm::Ref<Mutex> mutex;
};

#endif // __SCRIPTING_RUNTIME_H__

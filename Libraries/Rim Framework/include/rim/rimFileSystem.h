/*
 *  rimFileSystem.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 3/18/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_FILE_SYSTEM_H
#define INCLUDE_RIM_FILE_SYSTEM_H


#include "fs/rimFileSystemConfig.h"


//********************************************************************************
//********************************************************************************
//********************************************************************************
//	File System Classes


#include "fs/rimPath.h"
#include "fs/rimURL.h"


#include "fs/rimFileSystemNode.h"
#include "fs/rimFile.h"
#include "fs/rimDirectory.h"


#ifdef RIM_FILE_SYSTEM_NAMESPACE_START
	#undef RIM_FILE_SYSTEM_NAMESPACE_START
#endif




#ifdef RIM_FILE_SYSTEM_NAMESPACE_END
	#undef RIM_FILE_SYSTEM_NAMESPACE_END
#endif


#endif // INCLUDE_RIM_FILE_SYSTEM_H

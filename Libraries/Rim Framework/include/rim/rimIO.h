/*
 *  rimIO.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 3/18/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IO_H
#define INCLUDE_RIM_IO_H


#include "io/rimIOConfig.h"


//********************************************************************************
//********************************************************************************
//********************************************************************************
//	Stream Interfaces


#include "io/rimStringInputStream.h"
#include "io/rimStringOutputStream.h"

#include "io/rimDataInputStream.h"
#include "io/rimDataOutputStream.h"


//********************************************************************************
//********************************************************************************
//********************************************************************************
//	Stream Classes


#include "io/rimPrintStream.h"


#include "io/rimFileReader.h"
#include "io/rimFileWriter.h"


//********************************************************************************
//********************************************************************************
//********************************************************************************
//	Log Classes



#include "io/rimLog.h"



//##########################################################################################
//******************************  Start Rim IO Namespace  **********************************
RIM_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//******************************  End Rim IO Namespace  ************************************
RIM_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_IO_H
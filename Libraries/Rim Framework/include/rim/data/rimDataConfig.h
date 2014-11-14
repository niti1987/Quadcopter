/*
 *  rimDataConfig.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DATA_CONFIG_H
#define INCLUDE_RIM_DATA_CONFIG_H


#include "../rimConfig.h"


#include <cstdlib>
#include <new>


#include "../util/rimAllocator.h"
#include "../math/rimScalarMath.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the data library namespace.
#ifndef RIM_DATA_NAMESPACE
	#define RIM_DATA_NAMESPACE data
#endif




#ifndef RIM_DATA_NAMESPACE_START
	#define RIM_DATA_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_DATA_NAMESPACE {
#endif




#ifndef RIM_DATA_NAMESPACE_END
	#define RIM_DATA_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing basic data manipulation classes: strings, buffers, and hashing.
namespace RIM_DATA_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################



#endif // INCLUDE_RIM_DATA_CONFIG_H

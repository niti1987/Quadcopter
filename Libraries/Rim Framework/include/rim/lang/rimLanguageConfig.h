/*
 *  rimLanguageConfig.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_LANGUAGE_CONFIG_H
#define INCLUDE_RIM_LANGUAGE_CONFIG_H


#include "../rimConfig.h"


#include "../util/rimAllocator.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




/// Define the name of the language library namespace.
#ifndef RIM_LANGUAGE_NAMESPACE
	#define RIM_LANGUAGE_NAMESPACE lang
#endif




#ifndef RIM_LANGUAGE_NAMESPACE_START
	#define RIM_LANGUAGE_NAMESPACE_START		RIM_NAMESPACE_START namespace RIM_LANGUAGE_NAMESPACE {
#endif




#ifndef RIM_LANGUAGE_NAMESPACE_END
	#define RIM_LANGUAGE_NAMESPACE_END		}; RIM_NAMESPACE_END
#endif




RIM_NAMESPACE_START
/// A namespace containing classes which extend the basic functionality of C++.
namespace RIM_LANGUAGE_NAMESPACE {
};
RIM_NAMESPACE_END




//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################




//##########################################################################################
//##########################################################################################
//############		
//############		Library Internal Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_LANGUAGE_INTERNAL_NAMESPACE_START
	#define RIM_LANGUAGE_INTERNAL_NAMESPACE_START		RIM_LANGUAGE_NAMESPACE_START namespace internal {
#endif




#ifndef RIM_LANGUAGE_INTERNAL_NAMESPACE_END
	#define RIM_LANGUAGE_INTERNAL_NAMESPACE_END		}; RIM_LANGUAGE_NAMESPACE_END
#endif




//##########################################################################################
//***********************  Start Rim Language Internal Namespace  **************************
RIM_LANGUAGE_INTERNAL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//***********************  End Rim Language Internal Namespace  ****************************
RIM_LANGUAGE_INTERNAL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################



#endif // INCLUDE_RIM_LANGUAGE_CONFIG_H

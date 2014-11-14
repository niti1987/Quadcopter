/*
 *  rimImageIOConfig.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 12/29/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef _INCLUDE_RIM_IMAGE_IO_CONFIG_H_
#define _INCLUDE_RIM_IMAGE_IO_CONFIG_H_


#include "../rimImagesConfig.h"


#include "../rimImage.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Library Namespace Configuration
//############		
//##########################################################################################
//##########################################################################################




#ifndef RIM_IMAGE_IO_NAMESPACE_START
	#define RIM_IMAGE_IO_NAMESPACE_START		RIM_IMAGES_NAMESPACE_START namespace io {
#endif




#ifndef RIM_IMAGE_IO_NAMESPACE_END
	#define RIM_IMAGE_IO_NAMESPACE_END		}; RIM_IMAGES_NAMESPACE_END
#endif




//##########################################################################################
//***************************  Start Rim Image IO Namespace  *******************************
RIM_IMAGE_IO_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//***************************  End Rim Image IO Namespace  *********************************
RIM_IMAGE_IO_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // _INCLUDE_RIM_IMAGE_IO_CONFIG_H_

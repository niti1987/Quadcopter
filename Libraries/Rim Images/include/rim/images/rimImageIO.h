/*
 *  rimImageIO.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 12/29/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGE_IO_H
#define INCLUDE_RIM_IMAGE_IO_H


#include "io/rimImageIOConfig.h"


#include "io/rimImageFormat.h"


#include "io/rimImageTranscoder.h"
#include "io/rimImagesBMPTranscoder.h"
#include "io/rimImagesJPEGTranscoder.h"
#include "io/rimImagesPNGTranscoder.h"
#include "io/rimImagesTGATranscoder.h"


#include "io/rimImageConverter.h"



#ifdef RIM_IMAGE_IO_NAMESPACE_START
	#undef RIM_IMAGE_IO_NAMESPACE_START
#endif



#ifdef RIM_IMAGE_IO_NAMESPACE_END
	#undef RIM_IMAGE_IO_NAMESPACE_END
#endif



#endif // INCLUDE_RIM_IMAGE_IO_H

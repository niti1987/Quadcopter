/*
 *  rimImages.h
 *  Rim Images
 *
 *  Created by Carl Schissler on 2/2/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_IMAGES_H
#define INCLUDE_RIM_IMAGES_H


#include "images/rimImagesConfig.h"


#include "images/rimColor3D.h"
#include "images/rimColor4D.h"


#include "images/rimPixelFormat.h"
#include "images/rimImage.h"


#include "images/rimImageIO.h"


//##########################################################################################
//****************************  Start Rim Images Namespace  ********************************
RIM_IMAGES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



using rim::images::io::ImageFormat;
using rim::images::io::ImageConverter;
using rim::images::io::BMPTranscoder;
using rim::images::io::TGATranscoder;
using rim::images::io::PNGTranscoder;
using rim::images::io::JPEGTranscoder;
using rim::images::io::ImageEncodingParameters;



//##########################################################################################
//****************************  End Rim Images Namespace  **********************************
RIM_IMAGES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################



#endif // INCLUDE_RIM_IMAGES_H

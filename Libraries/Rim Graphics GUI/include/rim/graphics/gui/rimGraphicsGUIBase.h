/*
 *  rimGraphicsGUIBase.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/11/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_BASE_H
#define INCLUDE_RIM_GRAPHICS_GUI_BASE_H


#include "rimGraphicsGUIConfig.h"


// Include basic utility classes which most GUI elements need.
#include "rimGraphicsGUIUtilities.h"


// Include font classes which most GUI elements need.
#include "rimGraphicsGUIFonts.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



using fonts::Font;
using fonts::FontStyle;


using util::Origin;
using util::Orientation;
using util::Direction;
using util::Rectangle;
using util::Margin;
using util::BorderType;
using util::Border;
using util::GUIImage;
using util::TextureImage;
using util::ValueCurve;



//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_BASE_H

/*
 *  rimGUIView.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 5/24/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_VIEW_H
#define INCLUDE_RIM_GUI_VIEW_H


#include "rimGUIConfig.h"


#include "rimGUIWindowElement.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular content region that is part of a window.
class View : public WindowElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Displaying Methods
			
			
			
			
			/// Tell the view to redraw its contents (if applicable).
			/**
			  * This method should be called whenever the user wishes to force the view
			  * to redraw itself. This forces a call to the view's drawing function.
			  */
			//virtual void display() = 0;
			
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_VIEW_H

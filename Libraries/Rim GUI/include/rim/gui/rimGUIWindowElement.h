/*
 *  rimGUIWindowElement.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 9/23/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_WINDOW_ELEMENT_H
#define INCLUDE_RIM_GUI_WINDOW_ELEMENT_H


#include "rimGUIConfig.h"


#include "rimGUIElement.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Window;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rectangular region that is part of a window.
class WindowElement : public GUIElement
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the horizontal size in pixels of this window element.
			RIM_INLINE Size getWidth() const
			{
				return this->getSize().x;
			}
			
			
			
			
			/// Return the vertical size in pixels of this window element.
			RIM_INLINE Size getHeight() const
			{
				return this->getSize().y;
			}
			
			
			
			
			/// Return a 2D vector indicating the size on the screen of this window element in pixels.
			virtual Size2D getSize() const = 0;
			
			
			
			
			/// Set the size on the screen of this window element in pixels.
			/**
			  * The method returns whether or not the size change operation was
			  * successful.
			  */
			RIM_INLINE Bool setSize( Size newWidth, Size newHeight )
			{
				return this->setSize( Size2D( newWidth, newHeight ) );
			}
			
			
			
			
			/// Set the size on the screen of this window element in pixels.
			/**
			  * The method returns whether or not the size change operation was
			  * successful.
			  */
			virtual Bool setSize( const Size2D& size ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the 2D position of this view in pixels, relative to the bottom left corner of the view.
			/**
			  * The coordinate position is defined relative to its enclosing coordinate frame
			  * where the origin will be the bottom left corner of the enclosing view or window.
			  */
			virtual Vector2i getPosition() const = 0;
			
			
			
			
			/// Set the 2D position of this view in pixels, relative to the bottom left corner of the view.
			/**
			  * The coordinate position is defined relative to its enclosing coordinate frame
			  * where the origin will be the bottom left corner of the enclosing view or window.
			  *
			  * If the position change operation is successful, TRUE is returned and the view is
			  * moved. Otherwise, FALSE is returned and the view is not moved.
			  */
			virtual Bool setPosition( const Vector2i& position ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parent Window Accessor Methods
			
			
			
			
			/// Return the window which is a parent of this window element.
			/**
			  * If NULL is returned, it indicates that the window element is not part of a window.
			  */
			virtual Window* getParentWindow() const = 0;
			
			
			
			
			/// Return whether or not this window element belongs to a window.
			RIM_INLINE Bool hasParentWindow() const
			{
				return this->getParentWindow() != NULL;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Declarations
			
			
			
			
			/// Declare the Window class as a friend so that it can make itself a parent of a window element privately.
			friend class Window;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Parent Accessor Methods
			
			
			
			
			/// Set the window which is going to be a parent of this window.
			/**
			  * Setting this value to NULL should indicate that the window element is no longer
			  * part of a window.
			  */
			virtual void setParentWindow( Window* parentWindow ) = 0;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_WINDOW_ELEMENT_H

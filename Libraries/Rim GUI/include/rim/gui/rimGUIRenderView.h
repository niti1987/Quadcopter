/*
 *  rimGUIRenderView.h
 *  Rim GUI
 *
 *  Created by Carl Schissler on 3/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GUI_RENDER_VIEW_H
#define INCLUDE_RIM_GUI_RENDER_VIEW_H


#include "rimGUIConfig.h"


#include "rimGUIView.h"
#include "rimGUISystem.h"
#include "rimGUIRenderViewDelegate.h"


//##########################################################################################
//***************************     Start Rim GUI Namespace     ******************************
RIM_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which allows the user to render to a rectangular region.
class RenderView : public View
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new render view with the specified size.
			RenderView( const Size2D& size );
			
			
			
			
			/// Create a new render view with the specified position and size relative to its parent view.
			RenderView( const Size2D& size, const Vector2i& position );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an render view, releasing all resources associated with it.
			~RenderView();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return a 2D vector indicating the size on the screen of this render view in pixels.
			/**
			  * The actual size of the rendering framebuffer may be different than this value,
			  * due to differences in the pixel density of displays. Call getFramebufferSize()
			  * to get the actual size in rendered pixels of this view.
			  */
			virtual Size2D getSize() const;
			
			
			
			
			/// Set the size on the screen of this render view in pixels.
			/**
			  * The method returns whether or not the size change operation was
			  * successful.
			  */
			virtual Bool setSize( const Size2D& size );
			
			
			
			
			/// Return a 2D vector indicating the size on the screen of this render view in framebuffer pixels.
			/**
			  * The nominal size of the render view may be different than this value,
			  * due to differences in the pixel density of displays.
			  */
			Size2D getFramebufferSize() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the 2D position of this render view in pixels, relative to the bottom left corner of the view.
			/**
			  * The coordinate position is defined relative to its enclosing coordinate frame
			  * where the origin will be the bottom left corner of the enclosing view or window.
			  */
			virtual Vector2i getPosition() const;
			
			
			
			
			/// Set the 2D position of this render view in pixels, relative to the bottom left corner of the view.
			/**
			  * The coordinate position is defined relative to its enclosing coordinate frame
			  * where the origin will be the bottom left corner of the enclosing view or window.
			  *
			  * If the position change operation is successful, TRUE is returned and the view is
			  * moved. Otherwise, FALSE is returned and the view is not moved.
			  */
			virtual Bool setPosition( const Vector2i& position );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pixel Density Accessor Methods
			
			
			
			
			/// Return the number of actual rendered pixels (in one dimension) per point.
			/**
			  * The default value is 1, indicating one rendered pixel for each framebuffer point.
			  * Higher values (i.e. 2) can be used to indicate high-resolution (i.e. retina) displays
			  * that need greater actual pixel density per logical pixel.
			  */
			Float getPixelDensity() const;
			
			
			
			
			/// Set the maximum pixel density that this render view can use.
			/**
			  * If possible, the render view will use the specified pixel density
			  * to determine the actual resolution of the render view. The
			  * render view uses a valid pixel density that is as close to this
			  * value as possible. The default is 1.
			  *
			  * This method should be called before this render view is bound to a rendering
			  * context.
			  */
			Bool setMaxPixelDensity( Float newMaxDensity );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Fullscreen Status Accessor Methods
			
			
			
			
			/// Return whether or not this render view is in fullscreen mode.
			Bool getIsFullscreen() const;
			
			
			
			
			/// Set whether or not this render view is in fullscreen mode.
			/**
			  * The method returns whether or not the fullscreen mode change was successful.
			  * Setting an render view to fullscreen can fail if the view is already part
			  * of a window or is a child of another view.
			  *
			  * This method uses the current resolution of the main display for the view
			  * and uses the main display as the fullscreen display.
			  *
			  * Calling this method may potentially resize the render view if the display has
			  * a different size than the view.
			  */
			Bool setIsFullscreen( Bool newIsFullscreen );
			
			
			
			
			/// Set whether or not this render view is in fullscreen mode.
			/**
			  * The method returns whether or not the fullscreen mode change was successful.
			  * Setting an render view to fullscreen can fail if the view is already part
			  * of a window or is a child of another view.
			  *
			  * This method uses the current resolution of the specified display for the view
			  * and uses that display as the fullscreen display.
			  *
			  * Calling this method may potentially resize the render view if the display has
			  * a different size than the view.
			  */
			Bool setIsFullscreen( Bool newIsFullscreen, const system::Display& display );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a const reference to the object which responds to events for this RenderView.
			const RenderViewDelegate& getDelegate() const;
			
			
			
			
			/// Set the object to which RenderView events should be delegated.
			void setDelegate( const RenderViewDelegate& newDelegate );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parent Window Accessor Methods
			
			
			
			
			/// Return the window which is a parent of this render view.
			/**
			  * If NULL is returned, it indicates that the view is not part of a window.
			  */
			virtual Window* getParentWindow() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Platform-Specific Pointer Accessor Method
			
			
			
			
			/// Return a pointer to platform-specific data for this render view.
			/**
			  * On Mac OS X, this method returns a pointer to a subclass of NSView
			  * which represents the render view.
			  *
			  * On Windows, this method returns an HWND indicating the 'window' which
			  * represents the render view.
			  */
			virtual void* getInternalPointer() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Shared Construction Methods
			
			
			
			
			/// Create a shared-pointer render view object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<RenderView> construct( const Size2D& newSize )
			{
				return Pointer<RenderView>( util::construct<RenderView>( newSize ) );
			}
			
			
			
			
			/// Create a shared-pointer render view object, calling the constructor with the same arguments.
			RIM_INLINE static Pointer<RenderView> construct( const Size2D& newSize, const Vector2i& newPosition )
			{
				return Pointer<RenderView>( util::construct<RenderView>( newSize, newPosition ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which wraps platform-specific state for an render view.
			class Wrapper;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Parent Accessor Methods
			
			
			
			
			/// Set the window which is going to be a parent of this render view.
			/**
			  * Setting this value to NULL should indicate that the view is no longer
			  * part of a window.
			  */
			virtual void setParentWindow( Window* parentWindow );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to an object which wraps platform-specific state for an render view.
			Wrapper* wrapper;
			
			
			
};




//##########################################################################################
//***************************     End Rim GUI Namespace     ********************************
RIM_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif	// INCLUDE_RIM_GUI_RENDER_VIEW_H

/*
 *  rimSimpleDemo.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 12/16/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENGINE_SIMPLE_DEMO_H
#define INCLUDE_RIM_ENGINE_SIMPLE_DEMO_H


#include "rimEngineConfig.h"


//##########################################################################################
//***************************  Start Rim Engine Namespace  *********************************
RIM_ENGINE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A simple demo application with a single window, basic key/mouse input, and drawing. 
/**
  * This class provides basic functionality needed for simple demo applications
  * where quick prototyping is important.
  */
class SimpleDemo
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Class Declaration
			
			
			
			
			/// A class which represents a set of delegate methods for demo event handling.
			class Delegate
			{
				public:
					
					/// A delegate method that is called when the demo should be initialized.
					Function<Bool ( const Pointer<GraphicsContext>& )> initialize;
					
					/// A delegate method that is called when the demo should be cleaned up.
					Function<void ()> deinitialize;
					
					/// A delegate method that is called when the demo view should be drawn.
					Function<void ( const Pointer<GraphicsContext>& )> draw;
					
					/// A delegate method that is called when the demo view should be resized.
					Function<void ( const Size2D& )> resize;
					
					/// A delegate method that is called when a keyboard event is received.
					Function<void ( const KeyboardEvent& )> keyEvent;
					
					/// A delegate method that is called when a mouse button event is received.
					Function<void ( const MouseButtonEvent& )> mouseButtonEvent;
					
					/// A delegate method that is called when a mouse wheel event is received.
					Function<void ( const MouseWheelEvent& )> mouseWheelEvent;
					
					/// A delegate method that is called when a mouse motion event is received.
					Function<void ( const MouseMotionEvent& )> mouseMotionEvent;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new simple demo with the name "Simple Demo" and window size 1024x768.
			SimpleDemo();
			
			
			
			
			/// Create a new simple demo with the specified name and window size.
			SimpleDemo( const UTF8String& newName, const Size2D& newWindowSize );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			virtual ~SimpleDemo();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Run Methods
			
			
			
			
			/// Run this demo.
			virtual void run();
			
			
			
			
			/// Stop running this demo.
			void stop();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Demo State Accessor Methods
			
			
			
			
			/// Return whether or not the demo is currently running.
			RIM_INLINE Bool getIsRunning() const
			{
				return isRunning;
			}
			
			
			
			
			/// Set whether or not the demo should be running.
			RIM_INLINE void setIsRunning( Bool newIsRunning )
			{
				isRunning = newIsRunning;
			}
			
			
			
			
			/// Return whether or not the demo is currently paused.
			RIM_INLINE Bool getIsPaused() const
			{
				return isPaused;
			}
			
			
			
			
			/// Set whether or not the demo should be paused.
			RIM_INLINE void setIsPaused( Bool newIsPaused )
			{
				isPaused = newIsPaused;
			}
			
			
			
			
			/// Return whether or not the demo is currently fullscreen.
			RIM_INLINE Bool getIsFullscreen() const
			{
				return isFullscreen;
			}
			
			
			
			
			/// Set whether or not the demo should be fullscreen.
			RIM_INLINE void setIsFullscreen( Bool newIsFullscreen )
			{
				isFullscreen = newIsFullscreen;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics context which this simple demo is using.
			/**
			  * If the demo has not yet been started or the context was not able to be
			  * created, this method returns NULL.
			  */
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return graphicsContext;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Graphics Converter Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics converter which this simple demo is using.
			/**
			  * If the demo has not yet been started or the context was not able to be
			  * created, this method returns NULL.
			  */
			RIM_INLINE const Pointer<GraphicsConverter>& getGraphicsConverter() const
			{
				return graphicsConverter;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Manager Accessor Methods
			
			
			
			
			/// Return a pointer to the resource manager which this simple demo is using.
			/**
			  * If the demo has not yet been started this method returns NULL.
			  */
			RIM_INLINE const Pointer<ResourceManager>& getResourceManager() const
			{
				return resourceManager;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Keyboard Accessor Methods
			
			
			
			
			/// Return a pointer to the keyboard state for this demo.
			RIM_INLINE const Pointer<Keyboard>& getKeyboard() const
			{
				return keyboard;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return the total number of delegate objects that are responding to events for this demo.
			RIM_INLINE Size getDelegateCount() const
			{
				return delegates.getSize();
			}
			
			
			
			
			/// Return a pointer to the delegate at the specified index.
			/**
			  * The method returns NULL if the specified delegate index is invalid.
			  */
			RIM_INLINE const Delegate* getDelegate( Index delegateIndex ) const
			{
				if ( delegateIndex < delegates.getSize() )
					return &delegates[delegateIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Return a pointer to the delegate at the specified index.
			/**
			  * The method returns NULL if the specified delegate index is invalid.
			  */
			RIM_INLINE Delegate* getDelegate( Index delegateIndex )
			{
				if ( delegateIndex < delegates.getSize() )
					return &delegates[delegateIndex];
				else
					return NULL;
			}
			
			
			
			
			/// Add a new delegate to this demo.
			/**
			  * The method returns the index of the new delegate.
			  */
			RIM_INLINE Index addDelegate( const Delegate& newDelegate )
			{
				Index delegateIndex = delegates.getSize();
				
				delegates.add( newDelegate );
				
				return delegateIndex;
			}
			
			
			
			
			/// Remove all delegates from this simple demo.
			RIM_INLINE void clearDelegates()
			{
				delegates.clear();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Engine Accessor Methods
			
			
			
			
			/// Return a reference to the entity engine for this demo.
			RIM_INLINE EntityEngine& getEngine()
			{
				return engine;
			}
			
			
			
			
			/// Return a reference to the entity engine for this demo.
			RIM_INLINE const EntityEngine& getEngine() const
			{
				return engine;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Frame Time Accessor Methods
			
			
			
			
			/// Return the total time that it took to update the last frame.
			RIM_INLINE const Time& getLastUpdateTime() const
			{
				return lastUpdateTime;
			}
			
			
			
			
			/// Return the total time that it took to draw the last frame.
			RIM_INLINE const Time& getLastDrawTime() const
			{
				return lastDrawTime;
			}
			
			
			
			
			/// Return the total time that it took to complete the last frame.
			RIM_INLINE const Time& getLastFrameTime() const
			{
				return lastFrameTime;
			}
			
			
			
			
			/// Return current average frames per second for the demo.
			RIM_INLINE Double getCurrentFPS() const
			{
				return currentFPS;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Delegate Methods
			
			
			
			
			virtual Bool initialize( const Pointer<GraphicsContext>& context );
			
			
			
			
			virtual void deinitialize();
			
			
			
			
			virtual void update( const Time& dt );
			
			
			
			
			virtual void draw( const Pointer<GraphicsContext>& context );
			
			
			
			
			virtual void resize( const Size2D& newSize );
			
			
			
			
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Demo Methods
			
			
			
			
			Bool initializeGUI();
			
			
			
			
			void deinitializeGUI();
			
			
			
			
			Bool initializeGraphics();
			
			
			
			
			void deinitializeGraphics();
			
			
			
			
			/// Update the render view so that it has the current fullscreen status.
			void updateFullscreen( Display& display );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Input Handling Methods
			
			
			
			
			Bool windowResize( Window& window, const Size2D& newSize );
			
			
			
			
			Bool windowClose( Window& window );
			
			
			
			
			Bool viewResize( RenderView& view, const Size2D& newSize );
			
			
			
			
			void viewKeyEvent( RenderView& view, const KeyboardEvent& event );
			
			
			
			
			void viewMouseButtonEvent( RenderView& view, const MouseButtonEvent& event );
			
			
			
			
			void viewMouseWheelEvent( RenderView& view, const MouseWheelEvent& event );
			
			
			
			
			void viewMouseMotionEvent( RenderView& view, const MouseMotionEvent& event );
			
			
			
			
			void fullscreenItemSelect( MenuItem& item );
			
			
			
			
			void pauseItemSelect( MenuItem& item );
			
			
			
			
			void quitItemSelect( MenuItem& item );
			
			
			
			
			/// Broadcast the input events synchronously to the delegates.
			void sendInputEvents();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private GUI Data Members
			
			
			
			
			Pointer<Window> window;
			
			
			
			
			Pointer<RenderView> renderView;
			
			
			
			
			Pointer<MenuBar> menuBar;
			
			
			
			
			Pointer<Menu> mainMenu;
			
			
			
			
			/// An object which keeps track of the current keyboard state for this demo.
			Pointer<Keyboard> keyboard;
			
			
			
			
			/// A list of keyboard events queued to be synchronously sent to the demo delegates.
			ArrayList<KeyboardEvent> keyEvents;
			
			
			
			
			/// A list of mouse button events queued to be synchronously sent to the demo delegates.
			ArrayList<MouseButtonEvent> mouseButtonEvents;
			
			
			
			
			/// A list of mouse motion events queued to be synchronously sent to the demo delegates.
			ArrayList<MouseMotionEvent> mouseMotionEvents;
			
			
			
			
			/// A list of mouse wheel events queued to be synchronously sent to the demo delegates.
			ArrayList<MouseWheelEvent> mouseWheelEvents;
			
			
			
			
			Mutex inputMutex;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Graphics Data Members
			
			
			
			
			Pointer<GraphicsDevice> graphicsDevice;
			
			
			
			
			Pointer<GraphicsContext> graphicsContext;
			
			
			
			
			/// A pointer to a resource manager for this demo.
			Pointer<ResourceManager> resourceManager;
			
			
			
			
			/// A pointer to a graphics converter for this demo.
			Pointer<GraphicsConverter> graphicsConverter;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The entity engine for this demo.
			EntityEngine engine;
			
			
			
			
			/// A string representing the name for this demo. This is used as the window title.
			UTF8String demoName;
			
			
			
			
			/// The size in pixels of the content area of the window for this demo.
			Size2D windowSize;
			
			
			
			
			/// A list of delegates that receive events for this demo.
			ArrayList<Delegate> delegates;
			
			
			
			
			/// A timer which keeps track of the time that it takes to update the demo.
			Timer updateTimer;
			
			
			
			
			/// A timer which keeps track of the time that it takes to draw for the demo.
			Timer drawTimer;
			
			
			
			
			/// A timer which keeps track of the total time that it takes to complete a frame.
			Timer frameTimer;
			
			
			
			
			/// The time that it took to update the demo on the last frame.
			Time lastUpdateTime;
			
			
			
			
			/// The time that it took to draw the demo on the last frame.
			Time lastDrawTime;
			
			
			
			
			/// The total that it took to do the last frame.
			Time lastFrameTime;
			
			
			
			
			/// The current number of frames per second that this demo is running at.
			Double currentFPS;
			
			
			
			
			/// The size of the main display before it was changed.
			Size2D oldDisplaySize;
			
			
			
			
			/// A boolean value indicating whether or not this demo is currently running.
			Bool isRunning;
			
			
			
			
			/// A boolean value indicating whether or not this demo is currently paused.
			Bool isPaused;
			
			
			
			
			/// A boolean value indicating whether or not the demo is in fullscreen mode.
			Bool isFullscreen;
			
			
			
			
			/// A boolean value indicating whether or not the demo should change the display resolution when going fullscreen.
			Bool changeDisplayResolution;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Engine Namespace  ***********************************
RIM_ENGINE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENGINE_SIMPLE_DEMO_H

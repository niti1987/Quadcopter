/*
 *  QuadcopterDemo.h
 *  Quadcopter
 *
 *  Created by Carl Schissler on 9/10/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef INCLUDE_QUADCOPTER_DEMO_H
#define INCLUDE_QUADCOPTER_DEMO_H


#include "rim/rimEngine.h"
#include "rim/rimGraphicsGUI.h"


using namespace rim;
using namespace rim::graphics;
using namespace rim::graphics::gui;
using namespace rim::engine;




class QuadcopterDemo : public SimpleDemo
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			QuadcopterDemo();
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Methods
			
			
			
			
			virtual Bool initialize( const Pointer<GraphicsContext>& context );
			
			
			
			
			virtual void deinitialize();
			
			
			
			
			virtual void update( const Time& dt );
			
			
			
			
			void handleInput( const Time& dt );
			
			
			
			
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			virtual void draw( const Pointer<GraphicsContext>& context );
			
			
			
			
			virtual void resize( const Size2D& newSize );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Rendering Data Members
			
			
			
			Pointer<ForwardRenderer> sceneRenderer;
			Pointer<ImmediateRenderer> immediateRenderer;
			
			
			Pointer<fonts::GraphicsFontDrawer> fontDrawer;
			fonts::FontStyle fontStyle;
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Scene Data Members
			
			
			
			Pointer<GraphicsScene> scene;
			
			
			
			Pointer<PerspectiveCamera> camera;
			Vector3f cameraVelocity;
			Float cameraSpeed;
			Float cameraFriction;
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Other Data Members
			
			
			
			/// The time in seconds that the last simulation frame took to process.
			Time simulationTime;
			
			
			Path rootPath;
			
			
			Float timeStep;
			
			
};




#endif // INCLUDE_BALLISTIC_DEMO_H

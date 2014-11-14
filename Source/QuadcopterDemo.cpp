/*
 *  QuadcopterDemo.cpp
 *  Quadcopter
 *
 *  Created by Carl Schissler on 9/10/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#include "QuadcopterDemo.h"


//##########################################################################################
//##########################################################################################
//############		
//############		Constructor
//############		
//##########################################################################################
//##########################################################################################




QuadcopterDemo:: QuadcopterDemo()
	:	SimpleDemo( "Quadcopter Demo", Size2D( 1024, 768 ) ),
		cameraSpeed( 100 ),
		cameraFriction( 0.15 ),
		timeStep( 1/60.0f )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Initialize Method
//############		
//##########################################################################################
//##########################################################################################




Bool QuadcopterDemo:: initialize( const Pointer<GraphicsContext>& context )
{
	rootPath = Directory::getExecutable();
	
	//********************************************************************************
	// Initialize the renderers.
	
	sceneRenderer = Pointer<ForwardRenderer>::construct( context );
	immediateRenderer = Pointer<ImmediateRenderer>::construct( context );
	
	fontDrawer = Pointer<fonts::GraphicsFontDrawer>::construct( context );
	fontStyle.setFont( fonts::Font::getDefault() );
	fontStyle.setColor( Color4f( 1.0, 1.0, 1.0, 1.0 ) );
	fontStyle.setFontSize( 20 );
	
	//********************************************************************************
	// Initialize the scene.
	
	scene = Pointer<GraphicsScene>::construct();
	camera = Pointer<PerspectiveCamera>::construct();
	camera->setPosition( Vector3f( 5, 2, 5 ) );
	camera->setNearPlaneDistance( 0.5f );
	camera->setFarPlaneDistance( 2000.0f );
	camera->setHorizontalFieldOfView( 75.0f );
	scene->addCamera( camera );
	
	// Add a light.
	{
		Pointer<DirectionalLight> light = Pointer<DirectionalLight>::construct();
		light->setColor( Color3f( 1.0f, 1.0f, 1.0f ) );
		light->setIntensity( 1.0 );
		light->setAmbientContribution( 0.1 );
		light->setDirection( Vector3f( -0.5, -1, -0.5 ).normalize() );
		light->setFlag( LightFlags::SHADOWS_ENABLED, true );
		scene->addLight( light );
	}
	
	// Add a sky light.
	{
		Pointer<PointLight> light = Pointer<PointLight>::construct();
		light->setPosition( Vector3f( 0, 500, 0 ) );
		light->setColor( Color3f( 1.0f, 1.0f, 1.0f ) );
		light->setIntensity( 50000.0 );
		light->setAttenuation( LightAttenuation( 1, 0, 1 ) );
		light->setAmbientContribution( 0.0 );
		light->setFlag( LightFlags::SHADOWS_ENABLED, false );
		scene->addLight( light );
	}
	
	// Load a mesh for the scene.
	{
		Resource<GraphicsShape> mesh = getResourceManager()->getResource<GraphicsShape>( 
											ResourceID( rootPath + "Data/Port City/Port City.obj" ) );
		Pointer<MeshShape> shape = getGraphicsConverter()->convertGenericMesh( mesh.getData().dynamicCast<GenericMeshShape>() );
		Pointer<GraphicsObject> object = Pointer<GraphicsObject>::construct( shape );
		object->setPosition( Vector3f( 0, 0, 0 ) );
		scene->addObject( object );
	}
	
	// Load a mesh for the sky.
	{
		Resource<GraphicsShape> mesh = getResourceManager()->getResource<GraphicsShape>( 
											ResourceID( rootPath + "Data/Skydome/Skydome.obj" ) );
		Pointer<MeshShape> shape = getGraphicsConverter()->convertGenericMesh( mesh.getData().dynamicCast<GenericMeshShape>() );
		Pointer<GraphicsObject> object = Pointer<GraphicsObject>::construct( shape );
		object->setPosition( Vector3f( 0, 0, 0 ) );
		object->setScale( Vector3f( 0.5 ) );
		object->setFlag( GraphicsObjectFlags::SHADOWS_ENABLED, false );
		scene->addObject( object );
	}
	
	// Load a mesh for the quadcopter.
	{
		Resource<GraphicsShape> mesh = getResourceManager()->getResource<GraphicsShape>( 
											ResourceID( rootPath + "Data/Quadcopter/Quadcopter.obj" ) );
		Pointer<MeshShape> shape = getGraphicsConverter()->convertGenericMesh( mesh.getData().dynamicCast<GenericMeshShape>() );
		Pointer<GraphicsObject> object = Pointer<GraphicsObject>::construct( shape );
		object->setPosition( Vector3f( 0, 0, 0 ) );
		object->setScale( Vector3f( 1 ) );
		object->setFlag( GraphicsObjectFlags::SHADOWS_ENABLED, true );
		scene->addObject( object );
	}
	
	//********************************************************************************
	// Initialize the viewport.
	
	Pointer<ViewportLayout> viewportLayout = Pointer<ViewportLayout>::construct();
	ViewportLayout::CameraView cameraView( camera, scene, Viewport() );
	cameraView.clearColor = Color4D<Double>(0.2,0.2,0.2,1);
	viewportLayout->addCameraView( cameraView );
	sceneRenderer->setViewportLayout( viewportLayout );
	
	return true;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Deinitialize Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: deinitialize()
{
	sceneRenderer.release();
	immediateRenderer.release();
}




//##########################################################################################
//##########################################################################################
//############		
//############		Update Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: update( const Time& dt )
{
	handleInput( dt );
	
	// Update the simulation.
	Timer timer;
	
	
	
	
	simulationTime = timer.getElapsedTime();
	
	// Update the graphics.
	scene->update( dt );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Input Handle Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: handleInput( const Time& dt )
{
	const Pointer<Keyboard>& keyboard = getKeyboard();
	
	//********************************************************************************
	// Move the camera.
	
	Vector3f cameraAcceleration = Vector3f::ZERO;
	
	if ( keyboard->keyIsPressed( Key::W ) )
		cameraAcceleration += camera->getViewDirection()*cameraSpeed;
	
	if ( keyboard->keyIsPressed( Key::S ) )
		cameraAcceleration -= camera->getViewDirection()*cameraSpeed;
	
	if ( keyboard->keyIsPressed( Key::A ) )
		cameraAcceleration += camera->getLeftDirection()*cameraSpeed;
	
	if ( keyboard->keyIsPressed( Key::D ) )
		cameraAcceleration -= camera->getLeftDirection()*cameraSpeed;
	
	// Integrate the camera's velocity.
	cameraVelocity += cameraAcceleration*dt;
	
	// Apply camera friction.
	cameraVelocity *= (Float(1) - cameraFriction);
	
	// Integrate the camera's position.
	camera->setPosition( camera->getPosition() + cameraVelocity*dt );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Key Event Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: keyEvent( const KeyboardEvent& event )
{
	if ( event.isAPress() )
	{
		if ( event.getKey() == Key::ESCAPE )
			this->stop();
		
	}
}




//##########################################################################################
//##########################################################################################
//############		
//############		Mouse Button Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: mouseButtonEvent( const MouseButtonEvent& event )
{
}




//##########################################################################################
//##########################################################################################
//############		
//############		Mouse Motion Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: mouseMotionEvent( const MouseMotionEvent& event )
{
	//****************************************************************************
	// Turn the camera based on the mouse motion.
	
	Float fov = camera->getHorizontalFieldOfView();
	Float dx = event.getRelativeMotion().x*(90/fov)/10.0f;
	Float dy = event.getRelativeMotion().y*(90/fov)/10.0f;
	
	Matrix3f rotation = Matrix3f::rotationXDegrees(-dy)*Matrix3f::rotationYDegrees(dx);
	
	camera->setOrientation( (camera->getOrientation()*rotation).orthonormalize() );
	
}




//##########################################################################################
//##########################################################################################
//############		
//############		Input Handle Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: draw( const Pointer<GraphicsContext>& context )
{
	sceneRenderer->render();
	
	immediateRenderer->synchronizeContext();
	immediateRenderer->setTransform( camera->getInverseTransformMatrix() );
	immediateRenderer->setProjection( camera->getProjectionMatrix() );
	
	//****************************************************************************
	// Draw debug information in the scene.
	
	
	
	
	//****************************************************************************
	// Draw the UI
	
	Vector2f textPosition( 20, context->getFramebufferSize().y - fontStyle.getFontSize() - 20 );
	
	fontDrawer->drawString( UTF8String("Time Step: ") + UTF8String(timeStep*1000,2) + " ms\n" +
							UTF8String("Simulation Time: ") + UTF8String(simulationTime*1000,3) + " ms\n"
							, fontStyle, textPosition );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Window Resize Handle Method
//############		
//##########################################################################################
//##########################################################################################




void QuadcopterDemo:: resize( const Size2D& newSize )
{
	camera->setAspectRatio( Float(newSize.x)/Float(newSize.y) );
}






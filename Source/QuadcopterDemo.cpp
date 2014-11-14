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
		cameraSpeed( 300 ),
		cameraFriction( 0.15 ),
		cameraPitch( 40.0f ),
		cameraYaw( 0 ),
		cameraDistance( 50.0f ),
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
	
	sceneRenderer->setFlag( SceneRendererFlags::SHADOWS_ENABLED, false );
	sceneRenderer->setFlag( SceneRendererFlags::DEBUG_CAMERAS, false );
	sceneRenderer->setFlag( SceneRendererFlags::DEBUG_BOUNDING_BOXES, true );
	sceneRenderer->setFlag( SceneRendererFlags::DEBUG_OBJECTS, false );
	
	// Initialize the viewport.
	Pointer<ViewportLayout> viewportLayout = Pointer<ViewportLayout>::construct();
	sceneRenderer->setViewportLayout( viewportLayout );
	
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
	
	ViewportLayout::CameraView cameraView( camera, scene, Viewport() );
	cameraView.clearColor = Color4D<Double>(0.2,0.2,0.2,1);
	viewportLayout->addCameraView( cameraView );
	
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
		quadcopterMesh = getGraphicsConverter()->convertGenericMesh( mesh.getData().dynamicCast<GenericMeshShape>() );
		quadcopterMesh->setScale( 2.0f );
	}
	
	//********************************************************************************
	
	
	// Create a quadcopter.
	addQuadcopterToScene( newQuadcopter( Vector3f( 0, 10, 0 ) ) );
	
	
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
	
	//********************************************************************************
	// Update the simulation.
	Timer timer;
	
	
	
	
	simulationTime = timer.getElapsedTime();
	
	//********************************************************************************
	// Update the graphics.
	
	// Update all of the quadcopter graphical representations with their new positions.
	for ( Index i = 0; i < quadcopters.getSize(); i++ )
		quadcopters[i]->updateGraphics();
	
	// Update the camera's orientation and position.
	camera->setOrientation( Matrix3f::rotationYDegrees( cameraYaw )*Matrix3f::rotationXDegrees( cameraPitch ) );
	camera->setPosition( cameraTarget - camera->getViewDirection()*cameraDistance );
	
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
	// Turn the camera.
	
	const Float yawSpeed = 120.0f*dt;
	const Float pitchSpeed = 60.0f*dt;
	
	if ( keyboard->keyIsPressed( Key::LEFT_ARROW ) )
		cameraYaw -= yawSpeed;
	
	if ( keyboard->keyIsPressed( Key::RIGHT_ARROW ) )
		cameraYaw += yawSpeed;
	
	if ( keyboard->keyIsPressed( Key::UP_ARROW ) )
		cameraPitch = math::clamp( cameraPitch - pitchSpeed, -90.0f, 90.0f );
	
	if ( keyboard->keyIsPressed( Key::DOWN_ARROW ) )
		cameraPitch = math::clamp( cameraPitch + pitchSpeed, -90.0f, 90.0f );
	
	camera->setOrientation( Matrix3f::rotationYDegrees( cameraYaw )*Matrix3f::rotationXDegrees( cameraPitch ) );
	
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
	cameraTarget += cameraVelocity*dt;
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
	if ( !event.isAPress() )
		return;
	
	// Compute the ray direction where the mouse is clicking in 3D space.
	const Pointer<rim::gui::RenderView>& renderView = getContext()->getTargetView();
	Vector2f viewportPosition = 2.0f*(event.getPosition() / renderView->getSize() - 0.5f);
	
	// Compute the basis vectors that parameterize the camera's near plane from [-1,1].
	Vector3f nearPlaneCenter = camera->getPosition() + camera->getViewDirection()*camera->getNearPlaneDistance();
	Float horizontalSlope = math::tan( 0.5f*math::degreesToRadians( camera->getHorizontalFieldOfView() ) );
	Float halfNearWidth = camera->getNearPlaneDistance()*horizontalSlope;
	Float halfNearHeight = halfNearWidth / camera->getAspectRatio();
	Vector3f nearX = camera->getRightDirection()*halfNearWidth;
	Vector3f nearY = camera->getUpDirection()*halfNearHeight;
	
	// Compute the position on the near plane.
	Vector3f nearPosition = nearPlaneCenter + viewportPosition.x*nearX + viewportPosition.y*nearY;
	
	// The final ray direction is the vector from the camera's position.
	Vector3f mouseDirection = (nearPosition - camera->getPosition()).normalize();
	
	// Set the camera target to be the intersection of the mouse ray with the XZ plane.
	const Float targetY = 15.0f;
	Float t = (targetY - camera->getPosition().y) / mouseDirection.y;
	
	goal = (camera->getPosition() + mouseDirection*t);
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
	/*
	Float fov = camera->getHorizontalFieldOfView();
	Float dx = event.getRelativeMotion().x*(90/fov)/10.0f;
	Float dy = event.getRelativeMotion().y*(90/fov)/10.0f;
	
	cameraPitch = math::clamp( cameraPitch - dy, -90.0f, 90.0f );
	cameraYaw += dx;
	*/
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
	
	immediateRenderer->setPointSize( 10 );
	immediateRenderer->begin( IndexedPrimitiveType::POINTS );
	immediateRenderer->color( 0.0f, 1.0f, 0.0f );
	immediateRenderer->vertex( goal );
	
	
	immediateRenderer->color( 1.0f, 0.0f, 0.0f );
	
	for ( Index i = 0; i < quadcopters.getSize(); i++ )
		immediateRenderer->vertex( quadcopters[i]->graphics->getPosition() );
	
	
	immediateRenderer->render();
	
	
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




//##########################################################################################
//##########################################################################################
//############		
//############		Quadcopter Management Methods
//############		
//##########################################################################################
//##########################################################################################




Pointer<Quadcopter> QuadcopterDemo:: newQuadcopter( const Vector3f& position ) const
{
	// Create a new quadcopter at the given position.
	Pointer<Quadcopter> quadcopter = Pointer<Quadcopter>::construct();
	quadcopter->position = position;
	
	// Create a graphics object for the quadcopter.
	Pointer<GraphicsObject> graphics = Pointer<GraphicsObject>::construct( quadcopterMesh );
	graphics->setPosition( Vector3f( 0, 0, 0 ) );
	graphics->setScale( Vector3f( 1 ) );
	graphics->setFlag( GraphicsObjectFlags::SHADOWS_ENABLED, true );
	quadcopter->graphics = graphics;
	
	// Configure the cameras.
	quadcopter->frontCamera->setHorizontalFieldOfView( 90 );
	quadcopter->frontCamera->setNearPlaneDistance( 1.0f );
	quadcopter->frontCamera->setFarPlaneDistance( 1000 );
	quadcopter->downCamera->setHorizontalFieldOfView( 90 );
	quadcopter->downCamera->setNearPlaneDistance( 1.0f );
	quadcopter->downCamera->setFarPlaneDistance( 1000 );
	
	return quadcopter;
}




Bool QuadcopterDemo:: addQuadcopterToScene( const Pointer<Quadcopter>& newQuadcopter )
{
	if ( newQuadcopter.isNull() )
		return false;
	
	// Add the graphical representation to the scene.
	if ( newQuadcopter->graphics.isSet() )
		scene->addObject( newQuadcopter->graphics );
	
	// The size (as a fraction of screen size) of the quadcopter's viewport.
	const Float viewWidth = 0.25f;
	const Float viewHeight = 0.25f;
	
	// Add the cameras to the scene.
	if ( newQuadcopter->frontCamera.isSet() )
	{
		// Determine where to place the camera.
		AABB2f viewport( 1.0f - viewWidth*2, 1.0f - viewWidth,
						1.0f - (quadcopters.getSize() + 1)*viewHeight, 1.0f - quadcopters.getSize()*viewHeight );
		
		Pointer<ViewportLayout> viewportLayout = sceneRenderer->getViewportLayout();
		ViewportLayout::CameraView cameraView( newQuadcopter->frontCamera, scene, viewport );
		cameraView.clearColor = Color4D<Double>(0.2,0.2,0.2,1);
		
		viewportLayout->addCameraView( cameraView );
		scene->addCamera( newQuadcopter->frontCamera );
	}
	
	if ( newQuadcopter->downCamera.isSet() )
	{
		// Determine where to place the camera.
		AABB2f viewport( 1.0f - viewWidth, 1.0f,
						1.0f - (quadcopters.getSize() + 1)*viewHeight, 1.0f - quadcopters.getSize()*viewHeight );
		
		Pointer<ViewportLayout> viewportLayout = sceneRenderer->getViewportLayout();
		ViewportLayout::CameraView cameraView( newQuadcopter->downCamera, scene, viewport );
		cameraView.clearColor = Color4D<Double>(0.2,0.2,0.2,1);
		
		viewportLayout->addCameraView( cameraView );
		scene->addCamera( newQuadcopter->downCamera );
	}
	
	quadcopters.add( newQuadcopter );
	
	return true;
}




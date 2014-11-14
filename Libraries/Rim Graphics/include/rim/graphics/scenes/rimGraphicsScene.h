/*
 *  rimGraphicsScene.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/5/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SCENE_H
#define INCLUDE_RIM_GRAPHICS_SCENE_H


#include "rimGraphicsScenesConfig.h"


//##########################################################################################
//************************  Start Rim Graphics Scenes Namespace  ***************************
RIM_GRAPHICS_SCENES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that contains all of the information necessary to draw a complete graphics scene.
class GraphicsScene
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new empty graphics scene with the default initial state.
			GraphicsScene();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this scene, releasing all resources.
			virtual ~GraphicsScene();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the scene from its previous state using the specified time step.
			/**
			  * This allows the scene to update bounding volumes, animations, etc. with their
			  * current states.
			  */
			virtual void update( const Time& dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the number of objects that there are in this graphics scene.
			RIM_INLINE Size getObjectCount() const
			{
				return objects.getSize();
			}
			
			
			
			
			/// Return a pointer to the object at the specified index in this scene.
			RIM_INLINE const Pointer<GraphicsObject>& getObject( Index objectIndex ) const
			{
				return objects[objectIndex];
			}
			
			
			
			
			/// Add a new object to this scene.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the specified object pointer is NULL.
			  */
			Bool addObject( const Pointer<GraphicsObject>& object );
			
			
			
			
			/// Remove the object at the specified index from this scene.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the specified index is out of bounds.
			  */
			Bool removeObject( Index objectIndex );
			
			
			
			
			/// Remove the specified object from this scene.
			/**
			  * The method returns whether or not the object was found and successfully removed.
			  */
			Bool removeObject( const Pointer<GraphicsObject>& object );
			
			
			
			
			/// Remove all objects from this scene.
			void clearObjects();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Accessor Methods
			
			
			
			
			/// Return the number of lights that are part of this scene.
			RIM_INLINE Size getLightCount() const
			{
				return lights.getSize();
			}
			
			
			
			
			/// Return a pointer to the light at the specified index in this scene.
			RIM_INLINE const Pointer<Light>& getLight( Index lightIndex ) const
			{
				return lights[lightIndex];
			}
			
			
			
			
			/// Add a new light to this scene.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the specified light pointer is NULL.
			  */
			Bool addLight( const Pointer<Light>& light );
			
			
			
			
			/// Remove the light at the specified index from this scene.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the specified index is out of bounds.
			  */
			Bool removeLight( Index lightIndex );
			
			
			
			
			/// Remove the specified light from this scene.
			/**
			  * The method returns whether or not the light was found and successfully removed.
			  */
			Bool removeLight( const Pointer<Light>& light );
			
			
			
			
			/// Remove all lights from this scene.
			void clearLights();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Camera Accessor Methods
			
			
			
			
			/// Return the number of cameras that are part of this scene.
			RIM_INLINE Size getCameraCount() const
			{
				return cameras.getSize();
			}
			
			
			
			
			/// Return a pointer to the camera in this scene at the specified index.
			RIM_INLINE const Pointer<Camera>& getCamera( Index cameraIndex ) const
			{
				return cameras[cameraIndex];
			}
			
			
			
			
			/// Add a new camera to this scene.
			/**
			  * The method returns whether or not the camera was successfully added.
			  * The method can fail if the specified camera pointer is NULL.
			  */
			Bool addCamera( const Pointer<Camera>& camera );
			
			
			
			
			/// Remove the specified camera from this scene.
			/**
			  * The method returns whether or not the camera was found and
			  * successfully removed.
			  */
			Bool removeCamera( Index cameraIndex );
			
			
			
			
			/// Remove the specified camera from this scene.
			/**
			  * The method returns whether or not the camera was found and
			  * successfully removed.
			  */
			Bool removeCamera( const Pointer<Camera>& camera );
			
			
			
			
			/// Remove all cameras from this scene.
			void clearCameras();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Controller Accessor Methods
			
			
			
			
			/// Return the number of animation controllers that are part of this scene.
			RIM_INLINE Size getControllerCount() const
			{
				return controllers.getSize();
			}
			
			
			
			
			/// Return a pointer to the animation controller in this scene at the specified index.
			RIM_INLINE const Pointer<AnimationController>& getController( Index controllerIndex ) const
			{
				return controllers[controllerIndex];
			}
			
			
			
			
			/// Add a new animation controller to this scene.
			/**
			  * The method returns whether or not the animation controller was successfully added.
			  * The method can fail if the specified animation controller pointer is NULL.
			  */
			Bool addController( const Pointer<AnimationController>& controller );
			
			
			
			
			/// Remove the specified animation controller from this scene.
			/**
			  * The method returns whether or not the animation controller was found and
			  * successfully removed.
			  */
			Bool removeController( Index controllerIndex );
			
			
			
			
			/// Remove the specified animation controller from this scene.
			/**
			  * The method returns whether or not the animation controller was found and
			  * successfully removed.
			  */
			Bool removeController( const Pointer<AnimationController>& controller );
			
			
			
			
			/// Remove all animation controllers from this scene.
			void clearControllers();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Culler Accessor Methods
			
			
			
			
			/// Return a pointer to the object culler that this scene uses to cull hidden objects.
			RIM_INLINE const Pointer<ObjectCuller>& getObjectCuller() const
			{
				return objectCuller;
			}
			
			
			
			
			/// Set a pointer to the object culler that this scene uses to cull hidden objects.
			/**
			  * The method returns whether or not the object culler was changed. The method
			  * can fail if the specified object culler pointer is NULL.
			  */
			Bool setObjectCuller( const Pointer<ObjectCuller>& newObjectCuller );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Light Culler Accessor Methods
			
			
			
			
			/// Return a pointer to the hidden culler that this scene uses to cull hidden objects.
			RIM_INLINE const Pointer<LightCuller>& getLightCuller() const
			{
				return lightCuller;
			}
			
			
			
			
			/// Set a pointer to the light culler that this scene uses to cull hidden lights.
			/**
			  * The method returns whether or not the light culler was changed. The method
			  * can fail if the specified light culler pointer is NULL.
			  */
			Bool setLightCuller( const Pointer<LightCuller>& newLightCuller );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of the generic graphics scene.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of the generic graphics scene.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the objects that are part of this scene.
			ArrayList< Pointer<GraphicsObject> > objects;
			
			
			
			
			/// A list of the lights that are part of this scene.
			ArrayList< Pointer<Light> > lights;
			
			
			
			
			/// A list of the cameras that are part of this scene.
			ArrayList< Pointer<Camera> > cameras;
			
			
			
			
			/// A list of the animation controllers that are part of this scene.
			ArrayList< Pointer<AnimationController> > controllers;
			
			
			
			
			/// A pointer to an object which handles hidden object culling for this scene.
			Pointer<ObjectCuller> objectCuller;
			
			
			
			
			/// A pointer to an object which handles hidden light culling for this scene.
			Pointer<LightCuller> lightCuller;
			
			
			
			
			/// A string representing the name of this generic scene.
			String name;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Scenes Namespace  *****************************
RIM_GRAPHICS_SCENES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SCENE_H

/*
 *  rimGraphicsObjectCuller.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/5/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OBJECT_CULLER_H
#define INCLUDE_RIM_GRAPHICS_OBJECT_CULLER_H


#include "rimGraphicsObjectsConfig.h"


#include "rimGraphicsObject.h"


//##########################################################################################
//************************  Start Rim Graphics Objects Namespace  **************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class interface which determines which objects in a scene are visible to cameras and lights.
/**
  * This class keeps an internal set of objects that it queries for visibility.
  *
  * Typically, a class implementing this interface will have data structures
  * that speed up the O(n) problem of determining which objects intersect any given
  * bounding sphere, bounding cone, or view volume.
  */
class ObjectCuller
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this object culler.
			virtual ~ObjectCuller()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibile Object Query Methods
			
			
			
			
			/// Add a pointer to each object that intersects the specified bounding sphere to the output list.
			virtual void getIntersectingObjects( const BoundingSphere& sphere, ArrayList< Pointer<GraphicsObject> >& outputList ) const = 0;
			
			
			
			
			/// Add a pointer to each object that intersects the specified bounding cone to the output list.
			virtual void getIntersectingObjects( const BoundingCone& cone, ArrayList< Pointer<GraphicsObject> >& outputList ) const = 0;
			
			
			
			
			/// Add a pointer to each object that intersects the specified view volume to the output list.
			virtual void getIntersectingObjects( const ViewVolume& viewVolume, ArrayList< Pointer<GraphicsObject> >& outputList ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibile Mesh Chunk Query Methods
			
			
			
			
			/// Add each object's mesh chunks that intersect the specified camera's view volume to the output list.
			virtual void getIntersectingChunks( const Camera& camera, const ViewVolume* viewVolume, const Vector2D<Size>& viewportSize,
												const GraphicsObjectFlags& requiredFlags, ArrayList<MeshChunk>& outputList ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the bounding volumes of all objects that are part of this object culler and any spatial data structures.
			virtual void update() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the number of objects that are in this object culler.
			virtual Size getObjectCount() const = 0;
			
			
			
			
			/// Return whether or not this object culler contains the specified object.
			virtual Bool containsObject( const Pointer<GraphicsObject>& object ) const = 0;
			
			
			
			
			/// Add the specified object to this object culler.
			virtual Bool addObject( const Pointer<GraphicsObject>& object ) = 0;
			
			
			
			
			/// Remove the specified object from this object culler and return whether or not it was removed.
			virtual Bool removeObject( const Pointer<GraphicsObject>& object ) = 0;
			
			
			
			
			/// Remove all objects from this object culler.
			virtual void clearObjects() = 0;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Objects Namespace  ****************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OBJECT_CULLER_H

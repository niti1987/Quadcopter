/*
 *  rimGraphicsVisibilityCullerSimple.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 12/5/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OBJECT_CULLER_SIMPLE_H
#define INCLUDE_RIM_GRAPHICS_OBJECT_CULLER_SIMPLE_H


#include "rimGraphicsObjectsConfig.h"


#include "rimGraphicsObjectCuller.h"


//##########################################################################################
//************************  Start Rim Graphics Objects Namespace  **************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A simple implementation of the ObjectCuller interface that provides O(n) performance.
class ObjectCullerSimple : public ObjectCuller
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new empty simple object culler.
			ObjectCullerSimple();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibile Object Query Methods
			
			
			
			
			/// Add a pointer to each object that intersects the specified bounding sphere to the output list.
			virtual void getIntersectingObjects( const BoundingSphere& sphere, ArrayList< Pointer<GraphicsObject> >& outputList ) const;
			
			
			
			
			/// Add a pointer to each object that intersects the specified bounding cone to the output list.
			virtual void getIntersectingObjects( const BoundingCone& cone, ArrayList< Pointer<GraphicsObject> >& outputList ) const;
			
			
			
			
			/// Add a pointer to each object that intersects the specified view volume to the output list.
			virtual void getIntersectingObjects( const ViewVolume& viewVolume, ArrayList< Pointer<GraphicsObject> >& outputList ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibile Mesh Chunk Query Methods
			
			
			
			
			/// Add each object's mesh chunks that intersect the specified camera's view volume to the output list.
			virtual void getIntersectingChunks( const Camera& camera, const ViewVolume* viewVolume, const Vector2D<Size>& viewportSize,
												const GraphicsObjectFlags& requiredFlags, ArrayList<MeshChunk>& outputList ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the bounding volumes of all objects that are part of this object culler and any spatial data structures.
			virtual void update();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the number of objects that are in this object culler.
			virtual Size getObjectCount() const;
			
			
			
			
			/// Return whether or not this object culler contains the specified object.
			virtual Bool containsObject( const Pointer<GraphicsObject>& object ) const;
			
			
			
			
			/// Add the specified object to this object culler.
			virtual Bool addObject( const Pointer<GraphicsObject>& object );
			
			
			
			
			/// Remove the specified object from this object culler and return whether or not it was removed.
			virtual Bool removeObject( const Pointer<GraphicsObject>& object );
			
			
			
			
			/// Remove all objects from this object culler.
			virtual void clearObjects();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			
			static void flattenHierarchy( const GraphicsObject& object, const GraphicsObjectFlags& requiredFlags,
											const Transform3& worldTransform, const Camera& camera,
											const ViewVolume* viewVolume, const Vector2D<Size>& viewportSize,
											ArrayList<MeshChunk>& chunks );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of all of the objects in this simple object culler.
			ArrayList< Pointer<GraphicsObject> > objects;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Objects Namespace  ****************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OBJECT_CULLER_SIMPLE_H

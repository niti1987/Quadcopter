/*
 *  rimObjectInterface.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 10/28/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BVH_OBJECT_INTERFACE_H
#define INCLUDE_RIM_BVH_OBJECT_INTERFACE_H


#include "rimBVHConfig.h"


#include "rimBoundingSphere.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An interface to an opaque collection of generic geometric objects.
/**
  * This class allows a scene BVH to have access to the objects in the scene
  * on demand each time the scene BVH is rebuilt.
  */
class ObjectInterface
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this object interface.
			virtual ~ObjectInterface()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Return the number of objects contained in this object interface.
			virtual Size getSize() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Return an axis-aligned bounding box for the object with the specified index.
			virtual AABB3f getAABB( Index objectIndex ) const = 0;
			
			
			
			
			/// Return a bounding sphere for the object with the specified index.
			virtual BoundingSphere<Float> getBoundingSphere( Index objectIndex ) const = 0;
			
			
			
			
			/// Return a pointer to the object BVH at the specified index.
			virtual Pointer<BVH> getBVH( Index objectIndex ) const = 0;
			
			
			
			
			/// Return the object transformation at the specified index.
			virtual Transform3f getTransform( Index objectIndex ) const = 0;
			
			
			
};





//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BVH_OBJECT_INTERFACE_H

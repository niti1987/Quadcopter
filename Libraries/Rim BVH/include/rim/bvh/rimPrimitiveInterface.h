/*
 *  rimPrimitiveInterface.h
 *  Rim BVH
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BVH_PRIMITIVE_INTERFACE_H
#define INCLUDE_RIM_BVH_PRIMITIVE_INTERFACE_H


#include "rimBVHConfig.h"


#include "rimBoundingSphere.h"
#include "rimPrimitiveInterfaceType.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An interface to an opaque collection of generic geometric primitives.
/**
  * This class allows a BVH to not have to know the concrete type of the
  * geometric primitives that it contains, only generic attributes and operations.
  */
class PrimitiveInterface
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this primitive interface.
			virtual ~PrimitiveInterface()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Attribute Accessor Methods
			
			
			
			
			/// Return the number of primitives contained in this primitive interface.
			virtual Size getSize() const = 0;
			
			
			
			
			/// Return an object indicating the type of primitives that this inteface uses.
			/**
			  * The default implementation returns an UNDEFINED primitive interface type,
			  * meaning that the slower generic methods will be used instead of the BVH
			  * caching the primitive data in a faster format.
			  */
			virtual PrimitiveInterfaceType getType() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Return an axis-aligned bounding box for the primitive with the specified index.
			virtual AABB3f getAABB( Index primitiveIndex ) const = 0;
			
			
			
			
			/// Return a bounding sphere for the primitive with the specified index.
			virtual BoundingSphere<Float> getBoundingSphere( Index primitiveIndex ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Intersections Methods
			
			
			
			
			/// Return whether or not the primitive with the specified index is intersected by the specified ray.
			/**
			  * If there is an intersection, TRUE is returned and the distance along the ray is
			  * placed in the output parameter. Otherwise, FALSE is returned.
			  */
			virtual Bool intersectRay( Index primitiveIndex, const Ray3f& ray, Float& distance ) const = 0;
			
			
			
			
			/// Return whether or not the primitives with the specified indices are intersected by the specified ray.
			/**
			  * If there is an intersection, TRUE is returned and the distance to the
			  * closest intersection along the ray is placed in the output parameter.
			  * Otherwise, FALSE is returned.
			  */
			virtual Bool intersectRay( const Index* primitiveIndices, Size numPrimitives,
										const Ray3f& ray, Float& distance, Index& closestPrimitive ) const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Concrete-Type Primitive Accessor Methods
			
			
			
			
			/// Get the vertices of the triangle at the specified index in this primitive set.
			/**
			  * The method returns whether or not the triangle was able to be accessed
			  * and if so, places the vertices of the triangle in the output parameters.
			  * The method should only succeed when the type of this primitive interface
			  * is PrimitiveInterfaceType::TRIANGLES.
			  */
			virtual Bool getTriangle( Index index, Vector3f& v0, Vector3f& v1, Vector3f& v2 ) const;
			
			
			
			
			/// Get the center and radius of the sphere at the specified index in this primitive set.
			/**
			  * The method returns whether or not the sphere was able to be accessed
			  * and if so, places the vertices of the sphere in the output parameters.
			  * The method should only succeed when the type of this primitive interface
			  * is PrimitiveInterfaceType::SPHERES.
			  */
			virtual Bool getSphere( Index index, Vector3f& center, Float& radius ) const;
			
			
			
};





//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BVH_PRIMITIVE_INTERFACE_H

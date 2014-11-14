/*
 *  rimBVH.h
 *  Rim BVH
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_BVH_BVH_H
#define INCLUDE_RIM_BVH_BVH_H


#include "rimBVHConfig.h"


#include "rimPrimitiveInterface.h"
#include "rimTraversalStack.h"


//##########################################################################################
//*****************************  Start Rim BVH Namespace  **********************************
RIM_BVH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A generic interface for a Bounding Volume Hierarchy.
class BVH
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this BVH.
			virtual ~BVH()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Primitive Accessor Methods
			
			
			
			
			/// Set the primitive set that this BVH should use.
			/**
			  * Calling this method invalidates the current BVH, requiring it
			  * to be rebuilt before it can be used.
			  */
			virtual void setPrimitives( const Pointer<const PrimitiveInterface>& newPrimitives ) = 0;
			
			
			
			
			/// Return a pointer to the primitive set used by this BVH.
			virtual const Pointer<const PrimitiveInterface>& getPrimitives() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Building Methods
			
			
			
			
			/// Rebuild the BVH using the current set of primitives.
			virtual void rebuild() = 0;
			
			
			
			
			/// Do a quick update of the BVH by refitting the bounding volumes without changing the hierarchy.
			virtual void refit() = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	BVH Attribute Accessor Methods
			
			
			
			
			/// Return the maximum depth of this BVH's hierarchy.
			/**
			  * This value can be used to pre-allocate traversal stacks to prevent overflow.
			  */
			virtual Size getMaxDepth() const = 0;
			
			
			
			
			/// Return whether or not this BVH is built, valid, and ready for use.
			virtual Bool isValid() const = 0;
			
			
			
			
			/// Return the approximate total amount of memory in bytes allocated for this BVH.
			virtual Size getSizeInBytes() const = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Ray Tracing Methods
			
			
			
			
			/// Trace the specified ray through this BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found. If so, the distance
			  * along the ray and the intersected primitive index are placed in the output parameters.
			  */
			RIM_FORCE_INLINE Bool traceRay( const Ray3f& ray, Float maxDistance, TraversalStack& stack,
											Float& closestIntersection, Index& closestPrimitiveIndex ) const
			{
				return this->traceRay( ray, maxDistance, stack.getRoot(), closestIntersection, closestPrimitiveIndex );
			}
			
			
			
			
			/// Trace the specified ray through this BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found. If so, the distance
			  * along the ray and the intersected primitive index are placed in the output parameters.
			  */
			virtual Bool traceRay( const Ray3f& ray, Float maxDistance, const void** stack,
									Float& closestIntersection, Index& closestPrimitiveIndex ) const = 0;
			
			
			
			
			/// Trace the specified ray through this BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found.
			  */
			RIM_FORCE_INLINE Bool traceRay( const Ray3f& ray, Float maxDistance, TraversalStack& stack ) const
			{
				return this->traceRay( ray, maxDistance, stack.getRoot() );
			}
			
			
			
			
			/// Trace the specified ray through this BVH up to a maximum distance.
			/**
			  * The method returns whether or not an intersection was found.
			  */
			virtual Bool traceRay( const Ray3f& ray, Float maxDistance, const void** stack ) const = 0;
			
			
			
			
};





//##########################################################################################
//*****************************  End Rim BVH Namespace  ************************************
RIM_BVH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_BVH_BVH_H

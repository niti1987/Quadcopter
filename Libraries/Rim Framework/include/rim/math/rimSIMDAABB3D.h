/*
 *  rimSIMDAABB3D.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 7/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SIMD_AABB_3D_H
#define INCLUDE_RIM_SIMD_AABB_3D_H


#include "rimMathConfig.h"


#include "rimAABB3D.h"
#include "rimSIMDVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template < typename T, Size width >
class SIMDAABB3D;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a set of 3D vectors stored in a SIMD-compatible format.
/**
  * This class is used to store and operate on a set of axis-aligned bounding boxes
  * in a SIMD fashion. The bounding boxes are stored in a structure-of-arrays format
  * that accelerates SIMD operations. Each bounding box is specified by a minimum
  * and maximum vertex coordinate.
  */
template < typename T >
class RIM_ALIGN(16) SIMDAABB3D<T,4>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a SIMD axis-aligned bounding box that has all components initialized to zero.
			RIM_FORCE_INLINE SIMDAABB3D()
			{
			}
			
			
			
			
			
			/// Create a SIMD axis-aligned bounding box from a single bounding box.
			RIM_FORCE_INLINE SIMDAABB3D( const AABB3D<T>& aabb )
				:	min( aabb.min ),
					max( aabb.max )
			{
			}
			
			
			
			
			/// Create a SIMD axis-aligned bounding box from the four specified bounding boxes.
			RIM_FORCE_INLINE SIMDAABB3D( const AABB3D<T>& aabb1, const AABB3D<T>& aabb2,
										const AABB3D<T>& aabb3, const AABB3D<T>& aabb4 )
				:	min( aabb1.min, aabb2.min, aabb3.min, aabb4.min ),
					max( aabb1.max, aabb2.max, aabb3.max, aabb4.max )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Get either the minimal or maximal vertex of this AABB.
			/**
			  * If the index parameter is 0, the minimal vertex is returned, if the
			  * index parameter is 1, the maximal vertex is returned. Otherwise the
			  * result is undefined.
			  */
			RIM_FORCE_INLINE const SIMDVector3D<T,4>& getMinMax( Index i ) const
			{
				return (&min)[i];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Required Alignment Accessor Methods
			
			
			
			
			/// Return the alignment required for objects of this type.
			/**
			  * For most SIMD types this value will be 16 bytes. If there is
			  * no alignment required, 0 is returned.
			  */
			RIM_FORCE_INLINE static Size getRequiredAlignment()
			{
				return 16;
			}
			
			
			
			
			/// Get the width of this vector (number of 3D vectors it has).
			RIM_FORCE_INLINE static Size getWidth()
			{
				return 4;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The minimum coordinate vectors for this SIMD axis-aligned bounding box.
			SIMDVector3D<T,4> min;
			
			
			
			
			/// The maximum coordinate vectors for this SIMD axis-aligned bounding box.
			SIMDVector3D<T,4> max;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SIMD_AABB_3D_H

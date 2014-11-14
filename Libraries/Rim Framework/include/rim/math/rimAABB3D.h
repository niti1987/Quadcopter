/*
 *  rimAABB3D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 4/29/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_AABB_3D_H
#define INCLUDE_RIM_AABB_3D_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "rimAABB1D.h"
#include "rimAABB2D.h"
#include "rimVector3D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a range of values in 3D space.
/**
  * This class contains two data members: min and max. These indicate the minimum
  * and maximum coordinates that this axis-aligned bounding box represents. The class
  * invariant is that min is less than max (on at least one dimension), though this
  * is not enforced. The class supports union, containment, and intersection operations.
  */
template < typename T >
class AABB3D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a 3D axis-aligned bounding box with no extent centered about the origin.
			RIM_FORCE_INLINE AABB3D()
				:	min(),
					max()
			{
			}
			
			
			
			
			/// Create a 3D axis-aligned bounding box with the specified minimum and maximum coodinates.
			RIM_FORCE_INLINE AABB3D( T newXMin, T newXMax, 
									T newYMin, T newYMax, 
									T newZMin, T newZMax )
				:	min( newXMin, newYMin, newZMin ),
					max( newXMax, newYMax, newZMax )
			{
			}
			
			
			
			
			/// Create a 3D axis-aligned bounding box with the minimum and maximum coordinates equal to the specified vector.
			RIM_FORCE_INLINE AABB3D( const Vector3D<T>& center )
				:	min( center ),
					max( center )
			{
			}
			
			
			
			
			/// Create a 3D axis-aligned bounding box with the specified minimum and maximum coodinates.
			RIM_FORCE_INLINE AABB3D( const Vector3D<T>& newMin, const Vector3D<T>& newMax )
				:	min( newMin ),
					max( newMax )
			{
			}
			
			
			
			
			/// Create a 3D axis-aligned bounding box from the specified 2D bounding box, setting the Z bounds to [0,0].
			RIM_FORCE_INLINE explicit AABB3D( const AABB2D<T>& bounds2D )
				:	min( bounds2D.min, T() ),
					max( bounds2D.max, T() )
			{
			}
			
			
			
			
			/// Create a 3D axis-aligned bounding box from the specified 2D bounding box and Z coordinate bounding box.
			RIM_FORCE_INLINE explicit AABB3D( const AABB2D<T>& bounds2D, const AABB1D<T>& boundsZ )
				:	min( bounds2D.min, boundsZ.min ),
					max( bounds2D.max, boundsZ.max )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	AABB Cast Operator
			
			
			
			
			/// Cast this bounding box to a bounding box with a different underlying primitive type.
			template < typename U >
			RIM_FORCE_INLINE operator AABB3D<U> () const
			{
				return AABB3D<U>( (U)min.x, (U)max.x, (U)min.y, (U)max.y, (U)min.z, (U)max.z );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	AABB Comparison Methods
			
			
			
			
			/// Return whether or not this bounding box completely contains another.
			RIM_FORCE_INLINE Bool contains( const AABB3D& bounds ) const
			{
				return	min.x <= bounds.min.x && max.x >= bounds.max.x && 
						min.y <= bounds.min.y && max.y >= bounds.max.y && 
						min.z <= bounds.min.z && max.z >= bounds.max.z;
			}
			
			
			
			
			/// Return whether or not this bounding box contains the specified coordinate.
			RIM_FORCE_INLINE Bool contains( const Vector3D<T>& coordinate ) const
			{
				return coordinate.x >= min.x && coordinate.x <= max.x &&
						coordinate.y >= min.y && coordinate.y <= max.y &&
						coordinate.z >= min.z && coordinate.z <= max.z;
			}
			
			
			
			
			/// Return whether or not this bounding box intersects another.
			RIM_FORCE_INLINE Bool intersects( const AABB3D& bounds ) const
			{
				return	(min.x < bounds.max.x) && (max.x > bounds.min.x) && 
						(min.y < bounds.max.y) && (max.y > bounds.min.y) && 
						(min.z < bounds.max.z) && (max.z > bounds.min.z);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Set the minimum and maximum coordinates of the axis-aligned bounding box.
			RIM_FORCE_INLINE void set( T newXMin, T newXMax, T newYMin, T newYMax, T newZMin, T newZMax )
			{
				min.set( newXMin, newYMin, newZMin );
				max.set( newXMax, newYMax, newZMax );
			}
			
			
			
			
			/// Get the different between the maximum and minimum X coordinates.
			RIM_FORCE_INLINE T getWidth() const
			{
				return max.x - min.x;
			}
			
			
			
			
			/// Get the different between the maximum and minimum Y coordinates.
			RIM_FORCE_INLINE T getHeight() const
			{
				return max.y - min.y;
			}
			
			
			
			
			/// Get the different between the maximum and minimum Z coordinates.
			RIM_FORCE_INLINE T getDepth() const
			{
				return max.z - min.z;
			}
			
			
			
			
			/// Return a vector indicating the axial distances between the minimum and maximum coordinate.
			RIM_FORCE_INLINE Vector3D<T> getSize() const
			{
				return max - min;
			}
			
			
			
			
			/// Get the vector from the minimum coordinate to the maximum.
			RIM_FORCE_INLINE Vector3D<T> getDiagonal() const
			{
				return max - min;
			}
			
			
			
			
			/// Get the center of the bounding box.
			RIM_FORCE_INLINE Vector3D<T> getCenter() const
			{
				return math::midpoint( min, max );
			}
			
			
			
			
			/// Get the volume in cubic units enclosed by this 3D range.
			RIM_FORCE_INLINE T getVolume() const
			{
				return this->getWidth()*this->getHeight()*this->getDepth();
			}
			
			
			
			
			/// Return either the minimal or maximal vertex of this AABB.
			/**
			  * If the index parameter is 0, the minimal vertex is returned, if the
			  * index parameter is 1, the maximal vertex is returned. Otherwise the
			  * result is undefined.
			  */
			RIM_FORCE_INLINE const Vector3D<T>& getMinMax( Index i ) const
			{
				return (&min)[i];
			}
			
			
			
			
			/// Return a 1D AABB for the X coordinate range of this AABB.
			RIM_FORCE_INLINE AABB1D<T> getX() const
			{
				return AABB1D<T>( min.x, max.x );
			}
			
			
			
			
			/// Return a 1D AABB for the Y coordinate range of this AABB.
			RIM_FORCE_INLINE AABB1D<T> getY() const
			{
				return AABB1D<T>( min.y, max.y );
			}
			
			
			
			
			/// Return a 1D AABB for the Z coordinate range of this AABB.
			RIM_FORCE_INLINE AABB1D<T> getZ() const
			{
				return AABB1D<T>( min.z, max.z );
			}
			
			
			
			
			/// Return a 2D AABB for the X and Y coordinate ranges of this AABB.
			RIM_FORCE_INLINE AABB2D<T> getXY() const
			{
				return AABB2D<T>( min.getXY(), max.getXY() );
			}
			
			
			
			
			/// Return a 2D AABB for the X and Y coordinate ranges of this AABB.
			RIM_FORCE_INLINE AABB2D<T> getYZ() const
			{
				return AABB2D<T>( min.getYZ(), max.getYZ() );
			}
			
			
			
			
			/// Return a 2D AABB for the X and Z coordinate ranges of this AABB.
			RIM_FORCE_INLINE AABB2D<T> getXZ() const
			{
				return AABB2D<T>( min.getXZ(), max.getXZ() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enlargement Methods
			
			
			
			
			/// Modify the current bounding box such that it encloses the specified point.
			RIM_FORCE_INLINE void enlargeFor( const Vector3D<T>& point )
			{
				min = math::min( min, point );
				max = math::max( max, point );
			}
			
			
			
			
			/// Modify the current bounding box such that it encloses the specified box.
			RIM_FORCE_INLINE void enlargeFor( const AABB3D& bounds )
			{
				min = math::min( min, bounds.min );
				max = math::max( max, bounds.max );
			}
			
			
			
			
			/// Modify the current bounding box such that it encloses the specified point.
			RIM_FORCE_INLINE AABB3D<T>& operator |= ( const Vector3D<T>& point )
			{
				min = math::min( min, point );
				max = math::max( max, point );
				
				return *this;
			}
			
			
			
			
			/// Return the bounding box necessary to enclose a point and the current bounding box.
			RIM_FORCE_INLINE AABB3D<T> operator | ( const Vector3D<T>& point ) const
			{
				return AABB3D<T>( math::min( min, point ), math::max( max, point ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Union Methods
			
			
			
			
			/// Return the union of this bounding box and another.
			RIM_FORCE_INLINE AABB3D<T> getUnion( const AABB3D<T>& bounds ) const
			{
				return AABB3D<T>( math::min( min, bounds.min ), math::max( max, bounds.max ) );
			}
			
			
			
			
			/// Modify this bounding box such that it contains the specified bounding box.
			RIM_FORCE_INLINE AABB3D<T>& operator |= ( const AABB3D<T>& bounds )
			{
				min = math::min( min, bounds.min );
				max = math::max( max, bounds.max );
				
				return *this;
			}
			
			
			
			
			/// Return the union of this bounding box and another.
			RIM_FORCE_INLINE AABB3D<T> operator | ( const AABB3D<T>& bounds ) const
			{
				return this->getUnion( bounds );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Intersection Methods
			
			
			
			
			/// Return the intersection of this bounding box and another.
			RIM_FORCE_INLINE AABB3D<T> getIntersection( const AABB3D<T>& bounds ) const
			{
				return AABB3D<T>( math::max( min, bounds.min ), math::min( max, bounds.max ) );
			}
			
			
			
			
			/// Return the intersection of this bounding box and another.
			RIM_FORCE_INLINE AABB3D<T>& operator &= ( const AABB3D<T>& bounds )
			{
				min = math::max( min, bounds.min );
				max = math::min( max, bounds.max );
				
				return *this;
			}
			
			
			
			
			/// Return the intersection of this bounding box and another.
			RIM_FORCE_INLINE AABB3D<T> operator & ( const AABB3D<T>& bounds ) const
			{
				return this->getIntersection( bounds );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this bounding box is exactly the same as another.
			RIM_INLINE Bool operator == ( const AABB3D<T>& other ) const
			{
				return min == other.min && max == other.max;
			}
			
			
			
			
			/// Return whether or not this bounding box is different than another.
			RIM_INLINE Bool operator != ( const AABB3D<T>& other ) const
			{
				return min != other.min || max != other.max;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this 2D range into a human-readable string representation.
			RIM_NO_INLINE data::String toString() const
			{
				data::StringBuffer buffer;
				
				buffer << "[ " << min.x << " < " << max.x;
				buffer << ", " << min.y << " < " << max.y;
				buffer << ", " << min.z << " < " << max.z << " ]";
				
				return buffer.toString();
			}
			
			
			
			
			/// Convert this 2D range into a human-readable string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Members
			
			
			
			
			/// The minumum coordinate of the bounding box.
			Vector3D<T> min;
			
			
			
			
			/// The maximum coordinate of the bounding box.
			Vector3D<T> max;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_AABB_3D_H

/*
 *  rimAABB2D.h
 *  Rim Math
 *
 *  Created by Carl Schissler on 11/10/07.
 *  Copyright 2007 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_AABB_2D_H
#define INCLUDE_RIM_AABB_2D_H


#include "rimMathConfig.h"


#include "../data/rimBasicString.h"
#include "../data/rimBasicStringBuffer.h"
#include "rimAABB1D.h"
#include "rimVector2D.h"


//##########################################################################################
//*****************************  Start Rim Math Namespace  *********************************
RIM_MATH_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a range of values in 2D space.
/**
  * This class contains two data members: min and max. These indicate the minimum
  * and maximum coordinates that this axis-aligned bounding box represents. The class
  * invariant is that min is less than max (on at least one dimension), though this
  * is not enforced. The class supports union, containment, and intersection operations.
  */
template < typename T >
class AABB2D
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a 2D axis-aligned bounding box with no extent centered about the origin.
			RIM_FORCE_INLINE AABB2D()
				:	min(),
					max()
			{
			}
			
			
			
			
			/// Create a 2D axis-aligned bounding box with the specified minimum and maximum coodinates.
			RIM_FORCE_INLINE AABB2D( T newXMin, T newXMax, T newYMin, T newYMax )
				:	min( newXMin, newYMin ),
					max( newXMax, newYMax )
			{
			}
			
			
			
			
			/// Create a 2D axis-aligned bounding box with the minimum and maximum coordinates equal to the specified vector.
			RIM_FORCE_INLINE AABB2D( const Vector2D<T>& center )
				:	min( center ),
					max( center )
			{
			}
			
			
			
			
			/// Create a 2D axis-aligned bounding box with the specified minimum and maximum coodinates.
			RIM_FORCE_INLINE AABB2D( const Vector2D<T>& newMin, const Vector2D<T>& newMax )
				:	min( newMin ),
					max( newMax )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	AABB Cast Operator
			
			
			
			
			/// Cast this bounding box to a bounding box with a different underlying primitive type.
			template < typename U >
			RIM_FORCE_INLINE operator AABB2D<U> () const
			{
				return AABB2D<U>( (U)min.x, (U)max.x, (U)min.y, (U)max.y );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	AABB Comparison Methods
			
			
			
			
			/// Return whether or not this bounding box completely contains another.
			RIM_FORCE_INLINE Bool contains( const AABB2D& bounds ) const
			{
				return	min.x <= bounds.min.x && max.x >= bounds.max.x && 
						min.y <= bounds.min.y && max.y >= bounds.max.y;
			}
			
			
			
			
			/// Return whether or not this bounding box contains the specified coordinate.
			RIM_FORCE_INLINE Bool contains( const Vector2D<T>& coordinate ) const
			{
				return coordinate.x >= min.x && coordinate.x <= max.x &&
						coordinate.y >= min.y && coordinate.y <= max.y;
			}
			
			
			
			
			/// Return whether or not this bounding box intersects another.
			RIM_FORCE_INLINE Bool intersects( const AABB2D& bounds ) const
			{
				return	(min.x < bounds.max.x) && (max.x > bounds.min.x) && 
						(min.y < bounds.max.y) && (max.y > bounds.min.y);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Accessor Methods
			
			
			
			
			/// Set the minimum and maximum coordinates of the axis-aligned bounding box.
			RIM_FORCE_INLINE void set( T newXMin, T newXMax, T newYMin, T newYMax )
			{
				min.set( newXMin, newYMin );
				max.set( newXMax, newYMax );
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
			
			
			
			
			/// Return a vector indicating the axial distances between the minimum and maximum coordinate.
			RIM_FORCE_INLINE Vector2D<T> getSize() const
			{
				return max - min;
			}
			
			
			
			
			/// Get the vector from the minimum coordinate to the maximum.
			RIM_FORCE_INLINE Vector2D<T> getDiagonal() const
			{
				return max - min;
			}
			
			
			
			
			/// Get the center of the bounding box.
			RIM_FORCE_INLINE Vector2D<T> getCenter() const
			{
				return math::midpoint( min, max );
			}
			
			
			
			
			/// Get the area in square units enclosed by this 3D range.
			RIM_FORCE_INLINE T getArea() const
			{
				return this->getWidth()*this->getHeight();
			}
			
			
			
			
			/// Return either the minimal or maximal vertex of this AABB.
			/**
			  * If the index parameter is 0, the minimal vertex is returned, if the
			  * index parameter is 1, the maximal vertex is returned. Otherwise the
			  * result is undefined.
			  */
			RIM_FORCE_INLINE const Vector2D<T>& getMinMax( Index i ) const
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
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enlargement Methods
			
			
			
			
			/// Modify the current bounding box such that it encloses the specified point.
			RIM_FORCE_INLINE void enlargeFor( const Vector2D<T>& point )
			{
				min = math::min( min, point );
				max = math::max( max, point );
			}
			
			
			
			
			/// Modify the current bounding box such that it encloses the specified box.
			RIM_FORCE_INLINE void enlargeFor( const AABB2D& bounds )
			{
				min = math::min( min, bounds.min );
				max = math::max( max, bounds.max );
			}
			
			
			
			
			/// Modify the current bounding box such that it encloses the specified point.
			RIM_FORCE_INLINE AABB2D<T>& operator |= ( const Vector2D<T>& point )
			{
				min = math::min( min, point );
				max = math::max( max, point );
				
				return *this;
			}
			
			
			
			
			/// Return the bounding box necessary to enclose a point and the current bounding box.
			RIM_FORCE_INLINE AABB2D<T> operator | ( const Vector2D<T>& point ) const
			{
				return AABB2D<T>( math::min( min, point ), math::max( max, point ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Union Methods
			
			
			
			
			/// Return the union of this bounding box and another.
			RIM_FORCE_INLINE AABB2D<T> getUnion( const AABB2D<T>& bounds ) const
			{
				return AABB2D<T>( math::min( min, bounds.min ), math::max( max, bounds.max ) );
			}
			
			
			
			
			/// Modify this bounding box such that it contains the specified bounding box.
			RIM_FORCE_INLINE AABB2D<T>& operator |= ( const AABB2D<T>& bounds )
			{
				min = math::min( min, bounds.min );
				max = math::max( max, bounds.max );
				
				return *this;
			}
			
			
			
			
			/// Return the union of this bounding box and another.
			RIM_FORCE_INLINE AABB2D<T> operator | ( const AABB2D<T>& bounds ) const
			{
				return this->getUnion( bounds );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Intersection Methods
			
			
			
			
			/// Return the intersection of this bounding box and another.
			RIM_FORCE_INLINE AABB2D<T> getIntersection( const AABB2D<T>& bounds ) const
			{
				return AABB2D<T>( math::max( min, bounds.min ), math::min( max, bounds.max ) );
			}
			
			
			
			
			/// Return the intersection of this bounding box and another.
			RIM_FORCE_INLINE AABB2D<T>& operator &= ( const AABB2D<T>& bounds )
			{
				min = math::max( min, bounds.min );
				max = math::min( max, bounds.max );
				
				return *this;
			}
			
			
			
			
			/// Return the intersection of this bounding box and another.
			RIM_FORCE_INLINE AABB2D<T> operator & ( const AABB2D<T>& bounds ) const
			{
				return this->getIntersection( bounds );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this bounding box is exactly the same as another.
			RIM_INLINE Bool operator == ( const AABB2D<T>& other ) const
			{
				return min == other.min && max == other.max;
			}
			
			
			
			
			/// Return whether or not this bounding box is different than another.
			RIM_INLINE Bool operator != ( const AABB2D<T>& other ) const
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
				buffer << ", " << min.y << " < " << max.y << " ]";
				
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
		//******	Public Data Members
			
			
			
			
			/// The minumum coordinate of the bounding box.
			Vector2D<T> min;
			
			
			
			
			/// The maximum coordinate of the bounding box.
			Vector2D<T> max;
			
			
			
			
};




//##########################################################################################
//*****************************  End Rim Math Namespace  ***********************************
RIM_MATH_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_AABB_2D_H

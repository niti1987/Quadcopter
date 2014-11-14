/*
 *  rimGraphicsGUIMargin.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/29/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_MARGIN_H
#define INCLUDE_RIM_GRAPHICS_GUI_MARGIN_H


#include "rimGraphicsGUIUtilitiesConfig.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a 4-sided margin for a rectangular GUI object.
/**
  * Each side of the rectangle can have a different margin width.
  */
class Margin
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default margin object which has a width on all sides of 0.
			RIM_INLINE Margin()
				:	left( 0 ),
					right( 0 ),
					bottom( 0 ),
					top( 0 )
			{
			}
			
			
			
			
			/// Create a new margin object using the specified margin size for all sides.
			RIM_INLINE Margin( Float newMargin )
				:	left( newMargin ),
					right( newMargin ),
					bottom( newMargin ),
					top( newMargin )
			{
			}
			
			
			
			
			/// Create a new margin object using the specified sizes for each rectangular side.
			RIM_INLINE Margin( Float newLeft, Float newRight, Float newBottom, Float newTop )
				:	left( newLeft ),
					right( newRight ),
					bottom( newBottom ),
					top( newTop )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Margin Size Accessor Method
			
			
			
			
			/// Set all of the sides for this margin to have the specified size.
			RIM_INLINE void setSize( Float newSize )
			{
				left = right = bottom = top = newSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounds Accessor Method
			
			
			
			
			/// Return the bounding box for the specified area if this margin is applied inwardly.
			/**
			  * This method shrinks the specified bounding box by the margin and returns
			  * the resulting bounding box.
			  */
			RIM_INLINE AABB2f getInnerBounds( const AABB2f& bounds ) const
			{
				return AABB2f( bounds.min.x + left, bounds.max.x - right,
								bounds.min.y + bottom, bounds.max.y - top );
			}
			
			
			
			
			/// Return the bounding box for the specified area if this margin is applied externally.
			/**
			  * This method grows the specified bounding box by the margin and returns
			  * the resulting bounding box.
			  */
			RIM_INLINE AABB2f getOuterBounds( const AABB2f& bounds ) const
			{
				return AABB2f( bounds.min.x - left, bounds.max.x + right,
								bounds.min.y - bottom, bounds.max.y + top );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Margin Arithmetic Operators
			
			
			
			
			/// Scale this margin on all sides by the specified value and return the result.
			RIM_INLINE Margin operator * ( Float scale ) const
			{
				return Margin( left*scale, right*scale, bottom*scale, top*scale );
			}
			
			
			
			
			/// Scale this margin on all sides by the specified vector scaling and return the result.
			RIM_INLINE Margin operator * ( const Vector2f& scale ) const
			{
				return Margin( left*scale.x, right*scale.x, bottom*scale.y, top*scale.y );
			}
			
			
			
			
			/// Scale this margin on all sides by the specified value and store the result.
			RIM_INLINE Margin& operator *= ( Float scale )
			{
				left *= scale;
				right *= scale;
				bottom *= scale;
				top *= scale;
				
				return *this;
			}
			
			
			
			
			/// Scale this margin on all sides by the specified vector scaling and store the result.
			RIM_INLINE Margin& operator *= ( const Vector2f& scale )
			{
				left *= scale.x;
				right *= scale.x;
				bottom *= scale.y;
				top *= scale.y;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The size of the left-side margin, in vertical screen coordinates.
			Float left;
			
			
			
			
			/// The size of the right-side margin, in vertical screen coordinates.
			Float right;
			
			
			
			
			/// The size of the bottom-side margin, in vertical screen coordinates.
			Float bottom;
			
			
			
			
			/// The size of the top-side margin, in vertical screen coordinates.
			Float top;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Commutative Margin Arithmetic Operators
//############		
//##########################################################################################
//##########################################################################################





/// Scale a margin on all sides by the specified value and return the result.
RIM_INLINE Margin operator * ( Float scale, const Margin& margin )
{
	return Margin( margin.left*scale, margin.right*scale, margin.bottom*scale, margin.top*scale );
}





/// Scale a margin on all sides by the specified vector scaling and return the result.
RIM_INLINE Margin operator * ( const Vector2f& scale, const Margin& margin )
{
	return Margin( margin.left*scale.x, margin.right*scale.x, margin.bottom*scale.y, margin.top*scale.y );
}




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_MARGIN_H

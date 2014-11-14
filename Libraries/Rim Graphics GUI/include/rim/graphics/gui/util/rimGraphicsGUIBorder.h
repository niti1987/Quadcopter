/*
 *  rimGraphicsGUIBorder.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/10/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_BORDER_H
#define INCLUDE_RIM_GRAPHICS_GUI_BORDER_H


#include "rimGraphicsGUIUtilitiesConfig.h"


#include "rimGraphicsGUIMargin.h"
#include "rimGraphicsGUIBorderType.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes information about the border for a rectangular region.
class Border
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new border with the specified type and width.
			/**
			  * The border's frame is set to be the border's width on all sides and the
			  * border's radius is set to be 0.
			  */
			RIM_INLINE Border( const BorderType& newType, Float newWidth )
				:	type( newType ),
					frame( newWidth ),
					width( newWidth ),
					radius( 0 )
			{
			}
			
			
			
			
			/// Create a new border with the specified type, width, and radius.
			/**
			  * The border's frame is set to be the border's width on all sides.
			  */
			RIM_INLINE Border( const BorderType& newType, Float newWidth, Float newRadius )
				:	type( newType ),
					frame( newWidth ),
					width( newWidth ),
					radius( newRadius )
			{
			}
			
			
			
			
			/// Create a new border with the specified type, width, radius, and frame.
			RIM_INLINE Border( const BorderType& newType, Float newWidth, Float newRadius, const Margin& newFrame )
				:	type( newType ),
					frame( newFrame ),
					width( newWidth ),
					radius( newRadius )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Type Accessor Methods
			
			
			
			
			/// Return an object representing the type of this border.
			RIM_INLINE const BorderType& getType() const
			{
				return type;
			}
			
			
			
			
			/// Set the type of this border.
			RIM_INLINE void setType( const BorderType& newType )
			{
				type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Frame Accessor Methods
			
			
			
			
			/// Return an object representing the frame of the border on all four sides.
			/**
			  * This object indirectly describes the (potentially non-circular) radii of
			  * curvature for each of the border's 4 corners by describing the frame inset
			  * at each side of the border.
			  */
			RIM_INLINE const Margin& getFrame() const
			{
				return frame;
			}
			
			
			
			
			/// Set an object representing the frame of the border on all four sides.
			/**
			  * This object indirectly describes the (potentially non-circular) radii of
			  * curvature for each of the border's 4 corners by describing the frame inset
			  * at each side of the border.
			  */
			RIM_INLINE void setFrame( const Margin& newFrame )
			{
				frame = newFrame;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Width Accessor Methods
			
			
			
			
			/// Return the thickness of this border.
			RIM_INLINE Float getWidth() const
			{
				return width;
			}
			
			
			
			
			/// Set the thickness of this border.
			RIM_INLINE void setWidth( Float newWidth )
			{
				width = newWidth;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius Accessor Methods
			
			
			
			
			/// Return the radius of this border's rounded corners.
			/**
			  * A radius of 0 will result in right-angled corners.
			  */
			RIM_INLINE Float getRadius() const
			{
				return radius;
			}
			
			
			
			
			/// Return the radius of this border's rounded corners.
			/**
			  * A radius of 0 will result in right-angled corners.
			  */
			RIM_INLINE void setRadius( Float newRadius )
			{
				radius = newRadius;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the bounding box for the inner content area of the border's given rectangular region.
			/**
			  * This rectangle is calculated based on the width of this border's frame and 
			  * its border type. It is guaranteed to be the largest rectangle that can be
			  * placed within this border if it has the specified outside dimensions.
			  */
			RIM_INLINE AABB2f getContentBounds( const AABB2f& borderBounds ) const
			{
				return this->getContentFrame().getInnerBounds( borderBounds );
			}
			
			
			
			
			/// Return the frame for the inner content area of the border's given rectangular region.
			/**
			  * This is the margin around the edge of the bordered area which indicates
			  * the inset for a content area. This basically returns the maximum width
			  * of the border for all 4 sides.
			  */
			RIM_INLINE Margin getContentFrame() const
			{
				// Compute the axially-aligned offset for the border based on the radius and border width.
				Float borderOffset = math::min( width, radius );
				
				return Margin( math::max( borderOffset, frame.left ),
								math::max( borderOffset, frame.right ),
								math::max( borderOffset, frame.bottom ),
								math::max( borderOffset, frame.top ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Scaling Methods
			
			
			
			
			/// Scale this border by the specified 2D scaling amount and return the resulting scaled border.
			Border scale( const Vector2f& scale ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The type of this border, indicating its visual appearance.
			BorderType type;
			
			
			
			
			/// An object representing the width of the border on all four sides.
			Margin frame;
			
			
			
			
			/// The thickness of this border.
			Float width;
			
			
			
			
			/// The radius of this border's rounded corners.
			Float radius;
			
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_BORDER_H

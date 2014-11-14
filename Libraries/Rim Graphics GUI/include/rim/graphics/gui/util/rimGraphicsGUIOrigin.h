/*
 *  rimGraphicsGUIOrigin.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/22/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_ORIGIN_H
#define INCLUDE_RIM_GRAPHICS_GUI_ORIGIN_H


#include "rimGraphicsGUIUtilitiesConfig.h"


//##########################################################################################
//*******************  Start Rim Graphics GUI Utilities Namespace  *************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the location of the origin of a GUI rectangle coordinate system.
class Origin
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum which specifies the different types of horizontal coordinate origins.
			typedef enum XOrigin
			{
				/// An origin that is at the minimum X coordinate of a rectangular region.
				X_MIN = 1,
				
				/// An origin that is at the center X coordinate of a rectangular region.
				X_CENTER = 2,
				
				/// An origin that is at the maximum X coordinate of a rectangular region.
				X_MAX = 4,
				
				/// A coordinate origin that lies to the left of a rectangular region.
				LEFT = X_MIN,
				
				/// A coordinate origin that is horizontally centered within a rectangular region.
				HORIZONTAL_CENTER = X_CENTER,
				
				/// A coordinate origin that lies to the right of a rectangular region.
				RIGHT = X_MAX
			};
			
			
			
			
			/// An enum which specifies the different types of vertical coordinate origins.
			typedef enum YOrigin
			{
				/// An origin that is at the minimum Y coordinate of a rectangular region.
				Y_MIN = 1,
				
				/// An origin that is at the center Y coordinate of a rectangular region.
				Y_CENTER = 2,
				
				/// An origin that is at the maximum Y coordinate of a rectangular region.
				Y_MAX = 4,
				
				/// A coordinate origin that lies to the bottom of a rectangular region.
				BOTTOM = Y_MIN,
				
				/// A coordinate origin that is vertically centered within a rectangular region.
				VERTICAL_CENTER = Y_CENTER,
				
				/// A coordinate origin that lies to the top of a rectangular region.
				TOP = Y_MAX
			};
			
			
			
			
			/// An enum which specifies the different types of depth coordinate origins.
			typedef enum ZOrigin
			{
				/// An origin that is at the minimum Z coordinate of a rectangular region.
				Z_MIN = 1,
				
				/// An origin that is at the center Z coordinate of a rectangular region.
				Z_CENTER = 2,
				
				/// An origin that is at the maximum Z coordinate of a rectangular region.
				Z_MAX = 4,
				
				/// A coordinate origin that lies to the back of a 3D rectangular region.
				BACK = Z_MIN,
				
				/// A coordinate origin that is depth centered within a rectangular region.
				DEPTH_CENTER = Z_CENTER,
				
				/// A coordinate origin that lies to the front of a 3D rectangular region.
				FRONT = Z_MAX
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default coordinate origin, the bottom-left corner.
			RIM_INLINE Origin()
				:	xOrigin( X_MIN ),
					yOrigin( Y_MIN ),
					zOrigin( Z_CENTER )
			{
			}
			
			
			
			
			/// Create a new coordinate origin using the specified horizontal and vertical origin alignments.
			RIM_INLINE Origin( XOrigin newXOrigin, YOrigin newYOrigin )
				:	xOrigin( newXOrigin ),
					yOrigin( newYOrigin ),
					zOrigin( Z_CENTER )
			{
			}
			
			
			
			
			/// Create a new coordinate origin using the specified horizontal and vertical origin alignments.
			RIM_INLINE Origin( XOrigin newXOrigin, YOrigin newYOrigin, ZOrigin newZOrigin )
				:	xOrigin( newXOrigin ),
					yOrigin( newYOrigin ),
					zOrigin( newZOrigin )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Horizontal Origin Accessor Methods
			
			
			
			
			/// Return an enum value indicating the alignment of the horizontal axis of the coordinate system.
			RIM_INLINE XOrigin getX() const
			{
				return static_cast<XOrigin>( xOrigin );
			}
			
			
			
			
			/// Set an enum value indicating the alignment of the horizontal axis of the coordinate system.
			RIM_INLINE void setX( XOrigin newXOrigin )
			{
				xOrigin = static_cast<UByte>( newXOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertical Origin Accessor Methods
			
			
			
			
			/// Return an enum value indicating the alignment of the vertical axis of the coordinate system.
			RIM_INLINE YOrigin getY() const
			{
				return static_cast<YOrigin>( yOrigin );
			}
			
			
			
			
			/// Set an enum value indicating the alignment of the vertical axis of the coordinate system.
			RIM_INLINE void setY( YOrigin newYOrigin )
			{
				yOrigin = static_cast<UByte>( newYOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Origin Accessor Methods
			
			
			
			
			/// Return an enum value indicating the alignment of the depth axis of the coordinate system.
			RIM_INLINE ZOrigin getZ() const
			{
				return static_cast<ZOrigin>( zOrigin );
			}
			
			
			
			
			/// Set an enum value indicating the alignment of the depth axis of the coordinate system.
			RIM_INLINE void setZ( ZOrigin newZOrigin )
			{
				zOrigin = static_cast<UByte>( newZOrigin );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this coordinate origin object is the same as another.
			RIM_INLINE Bool operator == ( const Origin& other ) const
			{
				return xOrigin == other.xOrigin && yOrigin == other.yOrigin && zOrigin == other.zOrigin;
			}
			
			
			
			
			/// Return whether or not this coordinate origin object is different than another.
			RIM_INLINE Bool operator != ( const Origin& other ) const
			{
				return xOrigin != other.xOrigin || yOrigin != other.yOrigin || zOrigin != other.zOrigin;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Origin Offset Accessor Method
			
			
			
			
			/// Return a vector indicating the origin offset from the bottom left (minimum) coordinate of a parent bounding box.
			/**
			  * The 2D vector indicates, relative to the minimum corner of the parent bounding box
			  * with the specified 2D size, the direction and distance to this origin's position.
			  */
			Vector2f getOffset( const Vector2f& parentSize, const Vector2f& childSize ) const;
			
			
			
			
			/// Return a vector indicating the origin offset from the bottom left (minimum) coordinate of a parent bounding box.
			/**
			  * The 3D vector indicates, relative to the minimum corner of the parent bounding box
			  * with the specified 3D size, the direction and distance to this origin's position.
			  */
			Vector3f getOffset( const Vector3f& parentSize, const Vector3f& childSize ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the origin type.
			String toString() const;
			
			
			
			
			/// Convert this origin type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the alignment of the horizontal axis of the coordinate system.
			UByte xOrigin;
			
			
			
			
			/// An enum value indicating the alignment of the vertical axis of the coordinate system.
			UByte yOrigin;
			
			
			
			
			/// An enum value indicating the alignment of the depth axis of the coordinate system.
			UByte zOrigin;
			
			
			
};




//##########################################################################################
//*******************  End Rim Graphics GUI Utilities Namespace  ***************************
RIM_GRAPHICS_GUI_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_ORIGIN_H

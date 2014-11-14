/*
 *  rimGraphicsRasterMode.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/16/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_RASTER_MODE_H
#define INCLUDE_RIM_GRAPHICS_RASTER_MODE_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the way that geometry is rasterized.
class RasterMode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Test Enum Definition
			
			
			
			
			/// An enum type which represents the type of rasterization to perform.
			typedef enum Enum
			{
				/// A rasterization mode where only vertices are drawn.
				POINTS,
				
				/// A rasterization mode where lines are used to draw the outlines of rendering primitives.
				LINES,
				
				/// A rasterization mode where all of the area of rendering primitives is filled.
				TRIANGLES
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new raster mode with the specified raster mode enum value.
			RIM_INLINE RasterMode( Enum newMode )
				:	mode( newMode )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this raster mode type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)mode;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the raster mode.
			String toString() const;
			
			
			
			
			/// Convert this raster mode into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of raster mode.
			UByte mode;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_RASTER_MODE_H

/*
 *  rimColorSpace.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 3/28/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_COLOR_SPACE_H
#define INCLUDE_RIM_COLOR_SPACE_H


#include "rimImagesConfig.h"


//##########################################################################################
//****************************  Start Rim Images Namespace  ********************************
RIM_IMAGES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class representing the color space of a color.
class ColorSpace
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Space Enum Declaration
			
			
			
			
			typedef enum Type
			{
				/// An undefined color space.
				UNDEFINED,
				
				
				//******************************************************************
				// RGB Color Spaces.
				
				
				/// The RGB color space with unspecified gamma.
				/**
				  * The user should usually interpret this as sRGB, since most images
				  * are created to look good in that color space. However, the image
				  * data for some applications may be specified in linear RGB space.
				  */
				RGB,
				
				/// The standard sRGB color space.
				sRGB,
				
				/// The RGB color space with values on a linear scale.
				/**
				  * This is a color space where intensity values are spaced linearly
				  * from dark to light. Unless your images are known to be in a linear
				  * color space, it is best to use sRGB.
				  */
				LINEAR_RGB,
				
				/// The Adobe RGB color space.
				ADOBE_RGB,
				
				/// The CIE RGB color space.
				CIE_RGB,
				
				/// The scRGB color space.
				scRGB,
				
				//******************************************************************
				// Other Color Spaces.
				
				/// The Cyan-Magenta-Yellow-Black color space for subtractive color mixing.
				CMYK,
				
				/// The Hue-Saturation-Value color space.
				HSV,
				
				/// The Hue-Saturation-Lightness color space.
				HSL,
				
				/// The YUV color space.
				YUV,
				
				/// THe YIQ color space.
				YIQ,
				
				/// The YPbPr color space
				YPbPr,
				
				/// The xvYCC color space.
				xvYCC,
				
				/// The CIE XYZ color space.
				CIE_XYZ,
				
				/// The CIE LAB color space.
				CIE_LAB,
				
				/// The CIE LUV color space.
				CIE_LUV,
				
				/// The CIE UVW color space.
				CIE_UVW
				
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a color space object with an UNDEFINED color space.
			RIM_INLINE ColorSpace()
				:	type( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a color space object from the specified color space Enum.
			RIM_INLINE ColorSpace( ColorSpace::Type newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this light type to an enum value.
			RIM_INLINE operator Type () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Space String Conversion Methods
			
			
			
			
			/// Return a string representation of the color space.
			String toString() const;
			
			
			
			
			/// Convert this color space into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value specifying the color space.
			Type type;
			
			
			
};




//##########################################################################################
//****************************  End Rim Images Namespace  **********************************
RIM_IMAGES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_COLOR_SPACE_H

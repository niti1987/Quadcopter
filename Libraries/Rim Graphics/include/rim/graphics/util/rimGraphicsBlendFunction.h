/*
 *  rimGraphicsBlendFunction.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BLEND_FUNCTION_H
#define INCLUDE_RIM_GRAPHICS_BLEND_FUNCTION_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies an operation performed between the source and destination blend factors when blending.
/**
  * This operation is performed on a per-component basis and the result of the
  * function is the final color for the framebuffer for a given fragment.
  */
class BlendFunction
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Blend Function Enum Definition
			
			
			
			
			/// An enum type which represents the type of blend function.
			typedef enum Enum
			{
				/// An undefined blend function.
				UNDEFINED = 0,
				
				/// A blend function where the final color is the sum of the source and destination blend factors.
				/**
				  * This blend function is useful for common things like antialiasing and transparency.
				  */
				ADD = 1,
				
				/// A blend function where the final color is the source blend factor minus the destination blend factor.
				SUBTRACT = 2,
				
				/// A blend function where the final color is the destination blend factor minus the source blend factor.
				REVERSE_SUBTRACT = 3,
				
				/// A blend function where the final color is the minimum of the source and destination blend factors.
				MIN = 4,
				
				/// A blend function where the final color is the maximum of the source and destination blend factors.
				MAX = 5
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new default blend function with the UNDEFINED enum value.
			RIM_INLINE BlendFunction()
				:	function( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new blend function with the specified blend function enum value.
			RIM_INLINE BlendFunction( Enum newFunction )
				:	function( newFunction )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this blend function type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)function;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this blend function that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a blend function which corresponds to the given enum string.
			static BlendFunction fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the blend function.
			String toString() const;
			
			
			
			
			/// Convert this blend function into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the blend function.
			UByte function;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BLEND_FUNCTION_H

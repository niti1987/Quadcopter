/*
 *  rimGraphicsBlendFactor.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BLEND_FACTOR_H
#define INCLUDE_RIM_GRAPHICS_BLEND_FACTOR_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the scale factor applied to a source or destination color when blending.
/**
  * A blend factor determines the value of a source or destination operand for
  * any given BlendFunction. The factor is component-wise multiplied with the
  * color of a given source or destination fragment and used as an operand for
  * the blend function.
  */
class BlendFactor
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Blend Factor Enum Definition
			
			
			
			
			/// An enum type which represents the type of blend factor.
			typedef enum Enum
			{
				/// An undefined blend factor.
				UNDEFINED = 0,
				
				/// A blend factor where the color operand is multiplied by 0.
				ZERO,
				
				
				/// A blend factor where the color operand is multiplied by 1.
				ONE,
				
				
				/// A blend factor where the color operand is multiplied by the source color's alpha.
				SOURCE_ALPHA,
				
				
				/// A blend factor where the color operand is multiplied by the inverse source color alpha.
				/**
				  * The inverse alpha is equal to one minus the source alpha.
				  */
				INVERSE_SOURCE_ALPHA,
				
				
				/// A blend factor where the color operand is component-wise multiplied by the source color.
				SOURCE_COLOR,
				
				
				/// A blend factor where the color operand is component-wise multiplied by the inverse source color.
				/**
				  * The inverse source color is equal to one minus the source color for each
				  * color component.
				  */
				INVERSE_SOURCE_COLOR,
				
				
				/// A blend factor where the color operand is multiplied by the destination color's alpha.
				DESTINATION_ALPHA,
				
				
				/// A blend factor where the color operand is multiplied by the inverse destination color alpha.
				/**
				  * The inverse alpha is equal to one minus the destination alpha.
				  */
				INVERSE_DESTINATION_ALPHA,
				
				
				/// A blend factor where the color operand is component-wise multiplied by the destination color.
				DESTINATION_COLOR,
				
				
				/// A blend factor where the color operand is component-wise multiplied by the inverse destination color.
				/**
				  * The inverse destination color is equal to one minus the destination color for each
				  * color component.
				  */
				INVERSE_DESTINATION_COLOR,
				
				
				/// A blend factor where the color operand is multiplied by the constant color's alpha.
				CONSTANT_ALPHA,
				
				
				/// A blend factor where the color operand is multiplied by the inverse constant color alpha.
				/**
				  * The inverse alpha is equal to one minus the constant alpha.
				  */
				INVERSE_CONSTANT_ALPHA,
				
				
				/// A blend factor where the color operand is component-wise multiplied by the constant color.
				CONSTANT_COLOR,
				
				
				/// A blend factor where the color operand is component-wise multiplied by the inverse constant color.
				/**
				  * The inverse constant color is equal to one minus the constant color for each
				  * color component.
				  */
				INVERSE_CONSTANT_COLOR
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new blend factor with the specified blend factor enum value.
			RIM_INLINE BlendFactor( Enum newFactor )
				:	factor( newFactor )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this blend factor type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)factor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this blend factor that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a blend factor which corresponds to the given enum string.
			static BlendFactor fromEnumString( const String& enumString );
			
			
			
			
			/// Return a string representation of the blend factor.
			String toString() const;
			
			
			
			
			/// Convert this blend factor into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the blend factor.
			UByte factor;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BLEND_FACTOR_H

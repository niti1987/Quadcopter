/*
 *  rimGraphicsStencilAction.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_STENCIL_ACTION_H
#define INCLUDE_RIM_GRAPHICS_STENCIL_ACTION_H


#include "rimGraphicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the operation performed when updating a stencil buffer.
class StencilAction
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Action Enum Definition
			
			
			
			
			/// An enum type which represents the type of stencil action.
			typedef enum Enum
			{
				/// An action where the current stencil value is kept in the stencil buffer.
				KEEP = 0,
				
				/// An action where the stencil buffer value is set to 0.
				ZERO = 1,
				
				/// An action where the stencil buffer value is set to a constant stencil value.
				REPLACE = 2,
				
				/// An action where one is added to the stencil buffer value.
				/**
				  * With this action, if the increment operation overflows the stencil buffer
				  * precision, the new stencil value is clamped at the maximum stencil value.
				  */
				INCREMENT = 3,
				
				/// An action where one is added to the stencil buffer value, wrapping at the max stencil value.
				/**
				  * With this action, if the increment operation overflows the stencil
				  * buffer's precision, the new stencil value is set to 0.
				  */
				INCREMENT_WRAP = 4,
				
				/// An action where one is subtracted from the stencil buffer value.
				/**
				  * With this action, if the decrement operation makes the value negative,
				  * the new stencil value is clamped at 0.
				  */
				DECREMENT = 5,
				
				/// An action where one is subtracted from the stencil buffer value, wrapping at 0.
				/**
				  * With this action, if the decrement operation makes the value negative,
				  * the new stencil value is set to the maximum stencil value.
				  */
				DECREMENT_WRAP = 6,
				
				/// An action where the stencil buffer value is set to its bitwise inverse.
				INVERT = 7
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new stencil action with the specified stencil action enum value.
			RIM_INLINE StencilAction( Enum newAction )
				:	action( newAction )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this stencil action type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return (Enum)action;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a stencil action enum which corresponds to the given enum string.
			static StencilAction fromEnumString( const String& enumString );
			
			
			
			
			/// Return a unique string for this stencil action that matches its enum value name.
			String toEnumString() const;
			
			
			
			
			/// Return a string representation of the stencil action.
			String toString() const;
			
			
			
			
			/// Convert this stencil action into a string representation.
			RIM_FORCE_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of stencil action.
			UByte action;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_STENCIL_ACTION_H

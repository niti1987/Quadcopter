/*
 *  rimSoundFilterParameterType.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_PARAMETER_TYPE_H
#define INCLUDE_RIM_SOUND_FILTER_PARAMETER_TYPE_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the actual type of a SoundFilter parameter.
class FilterParameterType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Type Enum Declaration
			
			
			
			
			/// An enum which specifies the allowed SoundFilter parameter types.
			typedef enum Enum
			{
				/// A undefined filter parameter type.
				UNDEFINED = 0,
				
				/// A filter parameter type which indicates a boolean parameter value.
				BOOLEAN = 1,
				
				/// A filter parameter type which indicates an integral parameter value.
				INTEGER = 2,
				
				/// A filter parameter type which is an enumeration of possible integer values.
				ENUMERATION = 3,
				
				/// A filter parameter type which indicates a single-precision parameter value.
				FLOAT = 4,
				
				/// A filter parameter type which indicates a double-precision parameter value.
				DOUBLE = 5,
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new filter parameter type object with an UNDEFINED parameter type.
			RIM_INLINE FilterParameterType()
				:	type( (UByte)UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new filter parameter type object with the specified type enum value.
			RIM_INLINE FilterParameterType( Enum newType )
				:	type( (UByte)newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this filter parameter type to an enum value.
			/**
			  * This operator is provided so that the FilterParameterType object can be used
			  * directly in a switch statement without the need to explicitly access
			  * the underlying enum value.
			  * 
			  * @return the enum representation of this parameter type.
			  */
			RIM_INLINE operator Enum () const
			{
				return (Enum)type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the parameter type.
			UTF8String toString() const;
			
			
			
			
			/// Convert this parameter type into a string representation.
			RIM_INLINE operator UTF8String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value indicating the concrete type of a SoundFilter parameter.
			UByte type;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_PARAMETER_TYPE_H

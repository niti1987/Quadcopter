/*
 *  rimSoundFilterParameter.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/21/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_PARAMETER_H
#define INCLUDE_RIM_SOUND_FILTER_PARAMETER_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilterParameterValue.h"
#include "rimSoundFilterParameterType.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which holds the type and value of a SoundFilter parameter.
/**
  * The class provides ways to access the value of the generic parameter in a 
  * type-safe manner.
  */
class FilterParameter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a filter parameter with an undefined type and value.
			RIM_INLINE FilterParameter()
				:	 type( FilterParameterType::UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new filter parameter with the specified boolean value.
			RIM_INLINE FilterParameter( Bool newBoolean )
				:	value( newBoolean ),
					type( FilterParameterType::BOOLEAN )
			{
			}
			
			
			
			
			/// Create a new filter parameter with the specified integer or enumeration value.
			RIM_INLINE FilterParameter( Int64 newInteger )
				:	value( newInteger ),
					type( FilterParameterType::INTEGER )
			{
			}
			
			
			
			
			/// Create a new filter parameter with the specified float value.
			RIM_INLINE FilterParameter( Float32 newFloat )
				:	value( newFloat ),
					type( FilterParameterType::FLOAT )
			{
			}
			
			
			
			
			/// Create a new filter parameter with the specified double value.
			RIM_INLINE FilterParameter( Float64 newDouble )
				:	value( newDouble ),
					type( FilterParameterType::DOUBLE )
			{
			}
			
			
			
			
			/// Create a new filter parameter with the specified type and generic value union.
			RIM_INLINE FilterParameter( FilterParameterType newType, const FilterParameterValue& newValue )
				:	value( newValue ),
					type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Type Accessor Methods
			
			
			
			
			/// Return the actual type of this filter parameter.
			RIM_INLINE FilterParameterType getType() const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Read Methods
			
			
			
			
			/// Read this filter parameter as a boolean value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no output is converted.
			  */
			RIM_INLINE Bool getValue( Bool& output ) const
			{
				return value.getValueAsType( type, output );
			}
			
			
			
			
			/// Read this filter parameter as an integer value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no output is converted.
			  */
			RIM_INLINE Bool getValue( Int64& output ) const
			{
				return value.getValueAsType( type, output );
			}
			
			
			
			
			/// Read this filter parameter as a float value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no output is converted.
			  */
			RIM_INLINE Bool getValue( Float32& output ) const
			{
				return value.getValueAsType( type, output );
			}
			
			
			
			
			/// Read this filter parameter as a double value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no output is converted.
			  */
			RIM_INLINE Bool getValue( Float64& output ) const
			{
				return value.getValueAsType( type, output );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Write Methods
			
			
			
			
			/// Write this filter parameter as a boolean value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no value is set.
			  */
			RIM_INLINE Bool setValue( Bool output )
			{
				return value.setValueAsType( type, output );
			}
			
			
			
			
			/// Write this filter parameter as an integer or enumeration value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no value is set.
			  */
			RIM_INLINE Bool setValue( Int64 output )
			{
				return value.setValueAsType( type, output );
			}
			
			
			
			
			/// Write this filter parameter as a float value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no value is set.
			  */
			RIM_INLINE Bool setValue( Float32 output )
			{
				return value.setValueAsType( type, output );
			}
			
			
			
			
			/// Write this filter parameter as a double value.
			/**
			  * If the conversion succeeds, TRUE is returned. Otherwise, if the conversion fails,
			  * FALSE is returned and no value is set.
			  */
			RIM_INLINE Bool setValue( Float64 output )
			{
				return value.setValueAsType( type, output );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of this parameter's value.
			UTF8String toString() const;
			
			
			
			
			/// Return a string representation of this parameter's value.
			RIM_INLINE operator UTF8String () const
			{
				return this->toString();
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which stores the data representation of this parameter.
			FilterParameterValue value;
			
			
			
			
			/// The actual type of this filter parameter.
			FilterParameterType type;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_PARAMETER_H

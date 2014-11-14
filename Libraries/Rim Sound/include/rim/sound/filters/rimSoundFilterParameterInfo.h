/*
 *  rimSoundFilterParameterInfo.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/16/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_PARAMETER_INFO_H
#define INCLUDE_RIM_SOUND_FILTER_PARAMETER_INFO_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilterParameterType.h"
#include "rimSoundFilterParameterValue.h"
#include "rimSoundFilterParameterUnits.h"
#include "rimSoundFilterParameterCurve.h"
#include "rimSoundFilterParameterFlags.h"
#include "rimSoundFilterParameter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents information about a particular SoundFilter parameter.
class FilterParameterInfo
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an uninitialized filter parameter information class.
			/**
			  * The information stored in this class does not represent any valid
			  * parameter information.
			  */
			RIM_INLINE FilterParameterInfo()
				:	index( 0 )
			{
			}
			
			
			
			
			/// Create a new parameter information object with the specified attributes.
			RIM_INLINE FilterParameterInfo( UInt32 newIndex, const UTF8String& newName, FilterParameterType newType,
								FilterParameterUnits newUnits, FilterParameterCurve newCurve,
								FilterParameterValue newMinimum, FilterParameterValue newMaximum,
								FilterParameterValue newDefault, FilterParameterFlags newFlags )
				:	index( newIndex ),
					name( newName ),
					minimum( newMinimum ),
					maximum( newMaximum ),
					defaultValue( newDefault ),
					type( newType ),
					units( newUnits ),
					curve( newCurve ),
					flags( newFlags )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Index Accessor Methods
			
			
			
			
			/// Return the index of this parameter within its host SoundFilter.
			RIM_INLINE UInt32 getIndex() const
			{
				return index;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Name Accessor Methods
			
			
			
			
			/// Return a reference to a human-readable name string for this parameter.
			RIM_INLINE const UTF8String& getName() const
			{
				return name;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Type Accessor Methods
			
			
			
			
			/// Return an object indicating the actual type of this filter parameter.
			RIM_INLINE FilterParameterType getType() const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Units Type Accessor Methods
			
			
			
			
			/// Return an object indicating the units of this filter parameter.
			RIM_INLINE FilterParameterUnits getUnits() const
			{
				return units;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Curve Type Accessor Methods
			
			
			
			
			/// Return an object indicating the display curve of this filter parameter.
			RIM_INLINE FilterParameterCurve getCurve() const
			{
				return curve;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Flags Accessor Methods
			
			
			
			
			/// Return an object indicating boolean attributes of this filter parameter.
			RIM_INLINE FilterParameterFlags getFlags() const
			{
				return flags;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Minimum Value Accessor Methods
			
			
			
			
			/// Query a boolean minimum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of BOOLEAN, the method returns
			  * TRUE and the minimum boolean value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no minimum
			  * value is set.
			  */
			RIM_INLINE Bool getMinimum( Bool& booleanValue ) const
			{
				return minimum.getValueAsType( type, booleanValue );
			}
			
			
			
			
			/// Query an integer or enumeration minimum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of INTEGER or ENUMERATION,
			  * the method returns TRUE and the minimum integer value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no minimum
			  * value is set.
			  */
			RIM_INLINE Bool getMinimum( Int64& integerValue ) const
			{
				return minimum.getValueAsType( type, integerValue );
			}
			
			
			
			
			/// Query a float minimum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of FLOAT, the method returns
			  * TRUE and the minimum float value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no minimum
			  * value is set.
			  */
			RIM_INLINE Bool getMinimum( Float32& floatValue ) const
			{
				return minimum.getValueAsType( type, floatValue );
			}
			
			
			
			
			/// Query a double minimum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of DOUBLE, the method returns
			  * TRUE and the minimum double value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no minimum
			  * value is set.
			  */
			RIM_INLINE Bool getMinimum( Float64& doubleValue ) const
			{
				return minimum.getValueAsType( type, doubleValue );
			}
			
			
			
			
			/// Return a generic-typed minimum value for this parameter.
			RIM_INLINE FilterParameter getMinimum() const
			{
				return FilterParameter( type, minimum );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Maximum Value Accessor Methods
			
			
			
			
			/// Query a boolean maximum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of BOOLEAN, the method returns
			  * TRUE and the maximum boolean value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no maximum
			  * value is set.
			  */
			RIM_INLINE Bool getMaximum( Bool& booleanValue ) const
			{
				return maximum.getValueAsType( type, booleanValue );
			}
			
			
			
			
			/// Query an integer or enumeration maximum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of INTEGER or ENUMERATION, the method returns
			  * TRUE and the maximum integer value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no maximum
			  * value is set.
			  */
			RIM_INLINE Bool getMaximum( Int64& integerValue ) const
			{
				return maximum.getValueAsType( type, integerValue );
			}
			
			
			
			
			/// Query a float maximum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of FLOAT, the method returns
			  * TRUE and the maximum float value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no maximum
			  * value is set.
			  */
			RIM_INLINE Bool getMaximum( Float32& floatValue ) const
			{
				return maximum.getValueAsType( type, floatValue );
			}
			
			
			
			
			/// Query a double maximum value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of DOUBLE, the method returns
			  * TRUE and the maximum double value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no maximum
			  * value is set.
			  */
			RIM_INLINE Bool getMaximum( Float64& doubleValue ) const
			{
				return maximum.getValueAsType( type, doubleValue );
			}
			
			
			
			
			/// Return a generic-typed maximum value for this parameter.
			RIM_INLINE FilterParameter getMaximum() const
			{
				return FilterParameter( type, maximum );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Parameter Default Value Accessor Methods
			
			
			
			
			/// Query a boolean default value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of BOOLEAN, the method returns
			  * TRUE and the default boolean value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no default
			  * value is set.
			  */
			RIM_INLINE Bool getDefault( Bool& booleanValue ) const
			{
				return defaultValue.getValueAsType( type, booleanValue );
			}
			
			
			
			
			/// Query an integer or enumeration default value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of INTEGER or ENUMERATION, the method returns
			  * TRUE and the default integer value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no default
			  * value is set.
			  */
			RIM_INLINE Bool getDefault( Int64& integerValue ) const
			{
				return defaultValue.getValueAsType( type, integerValue );
			}
			
			
			
			
			/// Query a float default value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of FLOAT, the method returns
			  * TRUE and the default float value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no default
			  * value is set.
			  */
			RIM_INLINE Bool getDefault( Float32& floatValue ) const
			{
				return defaultValue.getValueAsType( type, floatValue );
			}
			
			
			
			
			/// Query a double default value of this filter parameter.
			/**
			  * If this parameter can be converted to a type of DOUBLE, the method returns
			  * TRUE and the default double value for this parameter is placed in
			  * the output parameter. Otherwise, FALSE is returned and no default
			  * value is set.
			  */
			RIM_INLINE Bool getDefault( Float64& doubleValue ) const
			{
				return defaultValue.getValueAsType( type, doubleValue );
			}
			
			
			
			
			/// Return a generic-typed default value for this parameter.
			RIM_INLINE FilterParameter getDefault() const
			{
				return FilterParameter( type, defaultValue );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The index of this parameter within its host SoundFilter.
			UInt32 index;
			
			
			
			
			/// A human-readable name for this filter parameter.
			UTF8String name;
			
			
			
			
			/// The minimum allowed value of this filter parameter.
			FilterParameterValue minimum;
			
			
			
			
			/// The maximum allowed value of this filter parameter.
			FilterParameterValue maximum;
			
			
			
			
			/// The default value of this filter parameter.
			FilterParameterValue defaultValue;
			
			
			
			
			/// An object representing the type of this filter parameter.
			FilterParameterType type;
			
			
			
			
			/// An object which declares the unit type of this filter parameter.
			FilterParameterUnits units;
			
			
			
			
			/// An object which declares the curve type of this filter parameter.
			FilterParameterCurve curve;
			
			
			
			
			/// An object which encapsulates boolean flags for this filter parameter.
			FilterParameterFlags flags;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_PARAMETER_INFO_H

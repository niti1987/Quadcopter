/*
 *  rimEntityComponent.h
 *  Rim Entity
 *
 *  Created by Carl Schissler on 11/19/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENTITY_COMPONENT_H
#define INCLUDE_RIM_ENTITY_COMPONENT_H


#include "rimEntitiesConfig.h"


//##########################################################################################
//**************************  Start Rim Entities Namespace  ********************************
RIM_ENTITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




/// A class which encapsulates a named object.
template < typename ComponentType >
class Component
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new unnnamed component with the specified value.
			RIM_INLINE Component( const Pointer<ComponentType>& newValue )
				:	name(),
					value( newValue )
			{
			}
			
			
			
			
			/// Create a new component with the specified value and name.
			RIM_INLINE Component( const Pointer<ComponentType>& newValue, const String& newName )
				:	name( newName ),
					value( newValue )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Component Name Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the name of this component.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Return a reference to a string representing the name of this component.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Value Accessor Methods
			
			
			
			
			/// Return a reference to the value object stored by this component.
			RIM_INLINE Pointer<ComponentType>& getValue()
			{
				return value;
			}
			
			
			
			
			/// Return a const reference to the value object stored by this component.
			RIM_INLINE const Pointer<ComponentType>& getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set the value object stored by this component.
			RIM_INLINE void setValue( const Pointer<ComponentType>& newValue )
			{
				value = newValue;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the name of this component.
			String name;
			
			
			
			
			/// The value of this component, the object that it stores.
			Pointer<ComponentType> value;
			
			
			
};




//##########################################################################################
//**************************  End Rim Entities Namespace  **********************************
RIM_ENTITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENTITY_COMPONENT_H

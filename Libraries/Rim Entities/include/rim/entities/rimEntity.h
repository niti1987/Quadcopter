/*
 *  rimEntity.h
 *  Rim Entities
 *
 *  Created by Carl Schissler on 5/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENTITY_H
#define INCLUDE_RIM_ENTITY_H


#include "rimEntitiesConfig.h"


#include "rimEntityEvent.h"
#include "rimEntityComponent.h"


//##########################################################################################
//**************************  Start Rim Entities Namespace  ********************************
RIM_ENTITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores sets of arbitrarily-typed component objects, named and organized by type.
/**
  * This class can be used as the basis for complex component-based objects in
  * a variety of applications, particularly game development.
  */
class Entity
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty entity that has no stored components.
			Entity();
			
			
			
			
			/// Create a copy of another entity, copying all of its stored components.
			Entity( const Entity& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an entity, deallocating all stored components.
			virtual ~Entity();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one entity to another, copying all stored components.
			Entity& operator = ( const Entity& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Methods
			
			
			
			
			/// Should this even be here?
			virtual void update()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Component Accessor Methods
			
			
			
			
			/// Return a pointer to the first component that the entity has for the specified type.
			/**
			  * If the entity does not have any components for the specified template type,
			  * NULL is returned.
			  */
			template < typename ComponentType >
			ComponentType* getComponent();
			
			
			
			
			/// Return a const pointer to the first component that the entity has for the specified type.
			/**
			  * If the entity does not have any components for the specified template type,
			  * NULL is returned.
			  */
			template < typename ComponentType >
			const ComponentType* getComponent() const;
			
			
			
			
			/// Return a pointer to the component that the entity has for the specified type and with the given name.
			/**
			  * If the entity does not have any components for the specified template type and
			  * a matching name string, NULL is returned.
			  */
			template < typename ComponentType >
			ComponentType* getComponent( const String& name );
			
			
			
			
			/// Return a const pointer to the component that the entity has for the specified type and with the given name.
			/**
			  * If the entity does not have any components for the specified template type and
			  * a matching name string, NULL is returned.
			  */
			template < typename ComponentType >
			const ComponentType* getComponent( const String& name ) const;
			
			
			
			
			/// Return a pointer to a list of components of the specified template type.
			/**
			  * If the entity does not have any components for the specified template type,
			  * NULL is returned.
			  */
			template < typename ComponentType >
			const ArrayList< Component<ComponentType> >* getComponents() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Component Adding Methods
			
			
			
			
			/// Add the specified unnamed component to this entity.
			/**
			  * The method returns whether or not adding the component was successful.
			  */
			template < typename ComponentType >
			Bool addComponent( const ComponentType& component );
			
			
			
			
			/// Add the specified component to this entity, giving it the specified name string.
			/**
			  * This name string can be used to identify between component instances of the
			  * same type. The method returns whether or not adding the component was successful.
			  */
			template < typename ComponentType >
			Bool addComponent( const ComponentType& component, const String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Component Removing Methods
			
			
			
			
			/// Remove the specified component from this entity if it exists.
			/**
			  * If the entity contains a component which is equal in type and
			  * value to the specified component, the component is removed and
			  * TRUE is returned. Otherwise, FALSE is returned and the entity
			  * is unchanged.
			  */
			template < typename ComponentType >
			Bool removeComponent( const ComponentType* component );
			
			
			
			
			/// Remove the component with the specified name from this entity if it exists.
			/**
			  * If the entity contains a component which is equal in type and
			  * has the specified name, the component is removed and
			  * TRUE is returned. Otherwise, FALSE is returned and the entity
			  * is unchanged.
			  */
			template < typename ComponentType >
			Bool removeComponent( const String& name );
			
			
			
			
			/// Remove all components with the specified component type from this entity.
			/**
			  * If the entity contains any components that have the specified type,
			  * the components are removed and TRUE is returned. Otherwise, FALSE is
			  * returned and the entity is unchanged.
			  */
			template < typename ComponentType >
			Bool removeComponents();
			
			
			
			
			/// Remove all components from this entity.
			void clearComponents();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// The base class for a templated array of components.
			class ComponentArrayBase;
			
			
			
			
			/// A class which holds an array of components of a given type.
			template < typename ComponentType >
			class ComponentArray;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Get a reference to a statically-instantiated Type object.
			/**
			  * The Type object is instantiated on the first call to the
			  * method using the method's template type. This allows the
			  * caller to efficiently retrieve a Type object for a compile-time
			  * template type multiple times without having to create a new Type
			  * object each time.
			  */
			template < typename T >
			RIM_INLINE static const Type& getType()
			{
				static const Type type = Type::of<T>();
				
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from Type object to component type arrays of all of the components in the entity.
			HashMap<Type,ComponentArrayBase*> components;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		ComponentArrayBase Class Defintion
//############		
//##########################################################################################
//##########################################################################################




class Entity:: ComponentArrayBase
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this base component array.
			virtual ~ComponentArrayBase()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Virtual Copy Method
			
			
			
			
			/// Return a copy of this component array's concrete type.
			virtual ComponentArrayBase* copy() const = 0;
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Component Accessor Methods
			
			
			
			
			/// Return a pointer to the array of components which this array holds.
			/**
			  * The method attempts to convert the internal component array to the given
			  * type. If the conversion fails, NULL is returned.
			  */
			template < typename ComponentType >
			RIM_INLINE ArrayList<Component<ComponentType> >* getComponents();
			
			
			
			
			/// Return a const pointer to the array of components which this array holds.
			/**
			  * The method attempts to convert the internal component array to the given
			  * type. If the conversion fails, NULL is returned.
			  */
			template < typename ComponentType >
			RIM_INLINE const ArrayList<Component<ComponentType> >* getComponents() const;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		ComponentArray Class Defintion
//############		
//##########################################################################################
//##########################################################################################




template < typename ComponentType >
class Entity:: ComponentArray : public ComponentArrayBase
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			RIM_INLINE ComponentArray( const ComponentType& component )
				:	components( 1 )
			{
				components.add( component );
			}
			
			
			
			
			RIM_INLINE ComponentArray( const ComponentType& component, const String& name )
				:	components( 1 )
			{
				components.add( Component<ComponentType>( Pointer<ComponentType>::construct( component ), name ) );
			}
			
			
			
			
			RIM_INLINE ComponentArray( const Component<ComponentType>& component )
				:	components( 1 )
			{
				components.add( component );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Virtual Copy Method
			
			
			
			
			/// Create and return a copy of this concrete type.
			virtual ComponentArray<ComponentType>* copy() const
			{
				return util::construct<ComponentArray<ComponentType> >( *this );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Component Accessor Methods
			
			
			
			
			/// Return a pointer to the internal list of components that this component array stores.
			RIM_INLINE ArrayList<Component<ComponentType> >* getComponents()
			{
				return &components;
			}
			
			
			
			
			/// Return a const pointer to the internal list of components that this component array stores.
			RIM_INLINE const ArrayList<Component<ComponentType> >* getComponents() const
			{
				return &components;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the components stored by this concrete component array.
			ArrayList< Component<ComponentType> > components;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Component Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename ComponentType >
ComponentType* Entity:: getComponent()
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	if ( components.find( type.getHashCode(), type, base ) )
	{
		ArrayList<Component<ComponentType> >* array = (*base)->getComponents<ComponentType>();
		
		if ( array != NULL && array->getSize() > 0 )
			return array->getFirst().getValue();
	}
	
	return NULL;
}




template < typename ComponentType >
const ComponentType* Entity:: getComponent() const
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	if ( components.find( type.getHashCode(), type, base ) )
	{
		const ArrayList<Component<ComponentType> >* array = (*base)->getComponents<ComponentType>();
		
		if ( array != NULL && array->getSize() > 0 )
			return array->getFirst().getValue();
	}
	
	return NULL;
}




template < typename ComponentType >
ComponentType* Entity:: getComponent( const String& name )
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	if ( components.find( type.getHashCode(), type, base ) )
	{
		ArrayList<Component<ComponentType> >* array = (*base)->getComponents<ComponentType>();
		
		if ( array != NULL )
		{
			const Size arraySize = array->getSize();
			
			for ( Index i = 0; i < arraySize; i++ )
			{
				if ( (*array)[i].getName() == name )
					return (*array)[i].getValue();
			}
		}
	}
	
	return NULL;
}




template < typename ComponentType >
const ComponentType* Entity:: getComponent( const String& name ) const
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	if ( components.find( type.getHashCode(), type, base ) )
	{
		const ArrayList<Component<ComponentType> >* array = (*base)->getComponents<ComponentType>();
		
		if ( array != NULL )
		{
			const Size arraySize = array->getSize();
			
			for ( Index i = 0; i < arraySize; i++ )
			{
				if ( array[i].getName() == name )
					return array[i].getValue();
			}
		}
	}
	
	return NULL;
}




template < typename ComponentType >
const ArrayList<Component<ComponentType> >* Entity:: getComponents() const
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	if ( components.find( type.getHashCode(), type, base ) )
		return (*base)->getComponents<ComponentType>();
	
	return NULL;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Component List Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename ComponentType >
ArrayList<Component<ComponentType> >* Entity::ComponentArrayBase:: getComponents()
{
	ComponentArray<ComponentType>* array = dynamic_cast<ComponentArray<ComponentType>*>( this );
	
	if ( array != NULL )
		return array->getComponents();
	else
		return NULL;
}




template < typename ComponentType >
const ArrayList<Component<ComponentType> >* Entity::ComponentArrayBase:: getComponents() const
{
	const ComponentArray<ComponentType>* array = dynamic_cast<const ComponentArray<ComponentType>*>( this );
	
	if ( array != NULL )
		return array->getComponents();
	else
		return NULL;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Component Add Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename ComponentType >
Bool Entity:: addComponent( const ComponentType& component )
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase** base;
	
	if ( components.find( type.getHashCode(), type, base ) )
	{
		// Found an array of components of this type.
		ArrayList<Component<ComponentType> >* array = (*base)->getComponents<ComponentType>();
		
		// Check to see if the component type conversion is correct. If so, add the new component.
		if ( array != NULL )
			array->add( Component<ComponentType>( component ) );
		else
			return false;
	}
	else
	{
		// This type of component does not yet exist in this entity.
		// Create a new one and add it to the map of components.
		ComponentArray<ComponentType>* newComponentArray = util::construct<ComponentArray<ComponentType> >( component );
		components.add( type.getHashCode(), type, newComponentArray );
	}
	
	return true;
}




template < typename ComponentType >
Bool Entity:: addComponent( const ComponentType& component, const String& name )
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase** base;
	
	if ( components.find( type.getHashCode(), type, base ) )
	{
		// Found an array of components of this type.
		ArrayList<Component<ComponentType> >* array = (*base)->getComponents<ComponentType>();
		
		// Check to see if the component type conversion is correct. If so, add the new component.
		if ( array != NULL )
			array->add( Component<ComponentType>( Pointer<ComponentType>::construct( component ), name ) );
		else
			return false;
	}
	else
	{
		// This type of component does not yet exist in this entity.
		// Create a new one and add it to the map of components.
		ComponentArray<ComponentType>* newComponentArray = util::construct<ComponentArray<ComponentType> >( component, name );
		components.add( type.getHashCode(), type, newComponentArray );
	}
	
	return true;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Component Remove Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename ComponentType >
Bool Entity:: removeComponent( const ComponentType* component )
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	if ( !components.find( type.getHashCode(), type, base ) )
		return false;
	
	ArrayList<ComponentType>* array = (*base)->getComponents<ComponentType>();
	
	if ( array == NULL )
		return false;
	
	const Size numComponents = array->getSize();
	
	for ( Index i = 0; i < numComponents; i++ )
	{
		if ( (*array)->getValue() == component )
		{
			array->removeAtIndexUnordered( i );
			return true;
		}
	}
	
	return false;
}




template < typename ComponentType >
Bool Entity:: removeComponent( const String& componentName )
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	if ( !components.find( type.getHashCode(), type, base ) )
		return false;
	
	ArrayList<ComponentType>* array = (*base)->getComponents<ComponentType>();
	
	if ( array == NULL )
		return false;
	
	const Size numComponents = array->getSize();
	
	for ( Index i = 0; i < numComponents; i++ )
	{
		if ( (*array)->getName() == componentName )
		{
			array->removeAtIndexUnordered( i );
			return true;
		}
	}
	
	return false;
}




template < typename ComponentType >
Bool Entity:: removeComponents()
{
	const Type& type = Entity::getType<ComponentType>();
	ComponentArrayBase* const * base;
	
	return components.remove( type.getHashCode(), type );
}




//##########################################################################################
//**************************  End Rim Entities Namespace  **********************************
RIM_ENTITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENTITY_H

/*
 *  rimEntitySystem.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/17/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENTITY_SYSTEM_H
#define INCLUDE_RIM_ENTITY_SYSTEM_H


#include "rimEntitiesConfig.h"


#include "rimEntityEvent.h"
#include "rimEntity.h"


//##########################################################################################
//**************************  Start Rim Entities Namespace  ********************************
RIM_ENTITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class EntityEngine;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An interface for classes that operate on entities and their components.
class EntitySystem
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty entity system.
			EntitySystem();
			
			
			
			
			/// Create a copy of the specified entity system.
			EntitySystem( const EntitySystem& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this entity system, releasing all internal resources.
			virtual ~EntitySystem();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another entity system to this one.
			virtual EntitySystem& operator = ( const EntitySystem& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	System Update Methods
			
			
			
			
			/// Update the state of all entities in this system for the specified time interval.
			virtual void update( const Time& dt, EntityEngine* engine = NULL ) = 0;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Entity Accessor Methods
			
			
			
			
			/// Return the number of entities that are part of this entity system.
			virtual Size getEntityCount() const;
			
			
			
			
			/// Return whether or not this system contains the specified entity.
			virtual Bool containsEntity( const Pointer<Entity>& entity ) const;
			
			
			
			
			/// Return whether or not this system contains the entity with the specified name.
			virtual Bool containsEntity( const String& entityName ) const;
			
			
			
			
			/// Add an entity to this entity system.
			/**
			  * The method returns whether or not the entity was successfully added.
			  */
			virtual Bool addEntity( const Pointer<Entity>& newEntity );
			
			
			
			
			/// Add an entity to this entity system with the given name.
			/**
			  * The method returns whether or not the entity was successfully added.
			  */
			virtual Bool addEntity( const Pointer<Entity>& newEntity, const String& newName );
			
			
			
			
			/// Remove the specified entity from this system.
			/**
			  * The method returns whether or not the entity was successfully removed.
			  */
			virtual Bool removeEntity( const Pointer<Entity>& entity );
			
			
			
			
			/// Remove the entity with the specified name from this system.
			/**
			  * The method returns whether or not the entity was successfully removed.
			  */
			virtual Bool removeEntity( const String& entityName );
			
			
			
			
			/// Remove all entities from this system.
			virtual void clearEntities();
			
			
			
			
			/// Return whether or not this entity system is able to use the specified entity.
			/**
			  * The method returns TRUE if the entity has any of the system's supported
			  * component types.
			  */
			Bool supportsEntity( const Entity& entity ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Component Type Accessor Methods
			
			
			
			
			/// Return the number of component types that this entity system operates on.
			RIM_INLINE Size getComponentTypeCount() const
			{
				return componentTypes.getSize();
			}
			
			
			
			
			/// Return whether or not this entity system supports the templated component type.
			template < typename ComponentType >
			RIM_INLINE Bool supportsComponentType() const
			{
				ComponentTypeInfo<ComponentType> typeInfo;
				
				for ( Index i = 0; i < componentTypes.getSize(); i++ )
				{
					if ( componentTypes[i]->equals( typeInfo ) )
					{
						util::destruct( componentTypes[i] );
						componentTypes.removeAtIndexUnordered( i );
						return true;
					}
				}
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Type Accessor Methods
			
			
			
			
			/// Return the number of event types that this system responds to.
			RIM_INLINE Size getEventTypeCount() const
			{
				return eventTypes.getSize();
			}
			
			
			
			
			/// Return a reference to the event type for this sytem at the specified index.
			RIM_INLINE const EventType& getEventType( Index typeIndex ) const
			{
				return eventTypes[typeIndex];
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Class Declarations
			
			
			
			
			/// An object which encapsulates a component and entity pair.
			template < typename ComponentType >
			class EntityComponent
			{
				public:
					
					/// Create a new entity-component pair for the specified entity and component.
					RIM_INLINE EntityComponent( const Pointer<Entity>& newEntity, const Pointer<ComponentType>& newComponent )
						:	entity( newEntity ),
							component( newComponent )
					{
					}
					
					
					/// A pointer to the entity for this entity-component pair.
					Pointer<Entity> entity;
					
					
					/// A pointer to the component data for this entity-component pair.
					Pointer<ComponentType> component;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Component Type Accessor Methods
			
			
			
			
			/// Add the templated type to the list of supported component types for this entity system.
			/**
			  * The method returns whether or not the type was successfully added.
			  */
			template < typename ComponentType >
			RIM_INLINE Bool addComponentType()
			{
				// Make sure the type does not already exist.
				ComponentTypeInfo<ComponentType> typeInfo;
				
				for ( Index i = 0; i < componentTypes.getSize(); i++ )
				{
					if ( componentTypes[i]->equals( typeInfo ) )
						return false;
				}
				
				componentTypes.add( util::construct< ComponentTypeInfoList<ComponentType> >() );
				
				return true;
			}
			
			
			
			
			/// Remove the templated type from the list of supported component types for this entity system.
			/**
			  * The method returns whether or not the type was successfully removed.
			  */
			template < typename ComponentType >
			RIM_INLINE Bool removeComponentType()
			{
				ComponentTypeInfo<ComponentType> typeInfo;
				
				for ( Index i = 0; i < componentTypes.getSize(); i++ )
				{
					if ( componentTypes[i]->equals( typeInfo ) )
					{
						util::destruct( componentTypes[i] );
						componentTypes.removeAtIndexUnordered( i );
						return true;
					}
				}
				
				return false;
			}
			
			
			
			
			/// Remove all supported component types from this entity system.
			void clearComponentTypes();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Component Accessor Methods
			
			
			
			
			/// Return a pointer to the list of components for each entity in this system.
			template < typename ComponentType >
			RIM_INLINE const ArrayList< EntityComponent<ComponentType> >* getComponentList() const
			{
				// Find the component list with this type.
				ComponentTypeInfo<ComponentType> typeInfo;
				
				for ( Index i = 0; i < componentTypes.getSize(); i++ )
				{
					if ( componentTypes[i]->equals( typeInfo ) )
						return &((ComponentTypeInfoList<ComponentType>*)componentTypes[i])->components;
				}
				
				return NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Event Type Accessor Methods
			
			
			
			
			/// Add a new event type to the list of event types that this system can handle.
			RIM_INLINE void addEventType( const EventType& newType )
			{
				eventTypes.add( newType );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// The base class for objects that store the component types that an entity system supports.
			class ComponentTypeInfoBase
			{
				public:
					
					virtual ~ComponentTypeInfoBase()
					{
					}
					
					/// Construct and return a pointer to a copy of this type info object.
					virtual ComponentTypeInfoBase* copy() const = 0;
					
					/// Return whether or not this type info is equal to another.
					virtual Bool equals( const ComponentTypeInfoBase& other ) = 0;
					
					/// Return whether or not an entity has a component of this type.
					virtual Bool supportsEntity( const Entity& entity ) const = 0;
					
					/// Add the components of this entity with this component type to the list of components.
					virtual Bool addEntity( const Pointer<Entity>& entity )
					{
						return false;
					}
					
					/// Remove the entity at the specified index, setting its component pointers to NULL in-place.
					virtual Bool removeEntity( const Pointer<Entity>& entity )
					{
						return false;
					}
					
					/// Remove all entities from this component type.
					virtual void clearEntities()
					{
					}
					
			};
			
			
			
			
			/// A template class that stores the runtime type of a supported system component type.
			template < typename ComponentType >
			class ComponentTypeInfo : public ComponentTypeInfoBase
			{
				public:
					
					/// Construct and return a pointer to a copy of this type info object.
					virtual ComponentTypeInfoBase* copy() const
					{
						return util::construct< ComponentTypeInfo<ComponentType> >( *this );
					}
					
					/// Return whether or not this type info is equal to another.
					virtual Bool equals( const ComponentTypeInfoBase& other )
					{
						return dynamic_cast<const ComponentTypeInfo<ComponentType>*>( &other ) != NULL;
					}
					
					/// Return whether or not an entity has a component of this type.
					virtual Bool supportsEntity( const Entity& entity ) const
					{
						return entity.getComponent<ComponentType>() != NULL;
					}
					
			};
			
			
			
			
			/// A template class that stores the runtime type of a supported system component type.
			template < typename ComponentType >
			class ComponentTypeInfoList : public ComponentTypeInfo<ComponentType>
			{
				public:
					
					/// Construct and return a pointer to a copy of this type info object.
					virtual ComponentTypeInfoBase* copy() const
					{
						return util::construct< ComponentTypeInfoList<ComponentType> >( *this );
					}
					
					/// Add the components of this entity with this component type to the list of components.
					virtual Bool addEntity( const Pointer<Entity>& entity )
					{
						// Get the entity components for this type.
						const ArrayList< Component<ComponentType> >* entityComponents = entity->getComponents<ComponentType>();
						
						// If the entity does not have any components of this type, return failure.
						if ( entityComponents == NULL )
							return false;
						
						/// Add all of the entities components of this type to the list of components for that entity.
						for ( Index i = 0; i < entityComponents->getSize(); i++ )
							components.add( EntityComponent<ComponentType>( entity, (*entityComponents)[i].getValue() ) );
						
						return true;
					}
					
					/// Remove the entity at the specified index, setting its component pointers to NULL in-place.
					virtual Bool removeEntity( const Pointer<Entity>& entity )
					{
						const Size numComponents = components.getSize();
						
						for ( Index i = 0; i < numComponents; )
						{
							if ( components[i].entity == entity )
							{
								components.removeAtIndexUnordered(i);
								continue;
							}
							
							i++;
						}
						
						return true;
					}
					
					/// Remove all entities from this component type.
					virtual void clearEntities()
					{
						components.clear();
					}
					
					/// A map from entity pointers to components of this type.
					ArrayList< EntityComponent<ComponentType> > components;
					
			};
			
			
			
			
			/// A class that encapsulates information about an entity that is part of this system.
			class EntityInfo;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Create and return a pointer to a new entity info object for the specified entity.
			const Pointer<EntityInfo>& newEntityInfo( const Pointer<Entity>& entity );
			
			
			
			
			/// Create and return a pointer to a new entity info object for the specified named entity.
			const Pointer<EntityInfo>& newEntityInfo( const Pointer<Entity>& entity, const String& entityName );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the component types supported by this system.
			ArrayList<ComponentTypeInfoBase*> componentTypes;
			
			
			
			
			/// A list of information for all of the entities in this system.
			ArrayList< Pointer<EntityInfo> > entities;
			
			
			
			
			/// A list of entity indices that were previously used but no longer.
			ArrayList<Index> unusedEntityIndices;
			
			
			
			
			/// A map from entity names to information about the entities.
			HashMap< String, Pointer<EntityInfo> > entityNameMap;
			
			
			
			
			/// A map from entities to information about the entities.
			HashMap< Pointer<Entity>, Pointer<EntityInfo> > entityMap;
			
			
			
			
			/// A list of the event types that this system reponds to.
			ArrayList<EventType> eventTypes;
			
			
};




//##########################################################################################
//**************************  End Rim Entities Namespace  **********************************
RIM_ENTITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENTITY_SYSTEM_H

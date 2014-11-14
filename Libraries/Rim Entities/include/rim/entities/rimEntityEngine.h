/*
 *  rimEntityEngine.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/17/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENTITY_ENGINE_H
#define INCLUDE_RIM_ENTITY_ENGINE_H


#include "rimEntitiesConfig.h"


#include "rimEntityEvent.h"
#include "rimEntity.h"
#include "rimEntitySystem.h"


//##########################################################################################
//**************************  Start Rim Entities Namespace  ********************************
RIM_ENTITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A collection of EntitySystem objects that operate on a set of entities and their components.
class EntityEngine
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty entity engine with no entity systems or entities.
			EntityEngine();
			
			
			
			
			/// Create a copy of another entity engine.
			EntityEngine( const EntityEngine& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this entity engine, releasing all internal resources.
			virtual ~EntityEngine();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the entire state of one entity engine to this one.
			virtual EntityEngine& operator = ( const EntityEngine& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Engine Update Method
			
			
			
			
			/// Update the state of all systems in this engine for the specified time interval.
			virtual void update( const Time& dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Entity Accessor Methods
			
			
			
			
			/// Return the total number of entities that are a part of this entity engine.
			virtual Size getEntityCount() const;
			
			
			
			
			/// Return whether or not this engine is using the specified entity.
			virtual Bool containsEntity( const Pointer<Entity>& entity ) const;
			
			
			
			
			/// Return whether or not this engine is using the entity with the specified name.
			virtual Bool containsEntity( const String& entityName ) const;
			
			
			
			
			/// Add an entity with no name to this engine.
			/**
			  * The method returns whether or not the entity was successfully added.
			  */
			virtual Bool addEntity( const Pointer<Entity>& entity );
			
			
			
			
			/// Add an entity with the specified name to this engine.
			/**
			  * The method returns whether or not the entity was successfully added.
			  */
			virtual Bool addEntity( const Pointer<Entity>& entity, const String& entityName );
			
			
			
			
			/// Remove the specified entity from this engine.
			/**
			  * The method returns whether or not the entity was successfully removed.
			  */
			virtual Bool removeEntity( const Pointer<Entity>& entity );
			
			
			
			
			/// Remove the entity with the specified name from this engine.
			/**
			  * The method returns whether or not the entity was successfully removed.
			  */
			virtual Bool removeEntity( const String& entityName );
			
			
			
			
			/// Remove all entities from this engine and all associated systems.
			virtual void clearEntities();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	System Accessor Methods
			
			
			
			
			/// Return the number of entity systems there are in this engine.
			virtual Size getSystemCount() const;
			
			
			
			
			/// Return a pointer to the system with the specified name in this engine.
			virtual Pointer<EntitySystem> getSystem( const String& systemName ) const;
			
			
			
			
			/// Return whether or not this engine contains an entity system with the specified name.
			virtual Bool containsSystem( const String& systemName ) const;
			
			
			
			
			/// Return whether or not this engine contains the specified system.
			virtual Bool containsSystem( const Pointer<EntitySystem>& system ) const;
			
			
			
			
			/// Add a system to this entity engine with no name.
			/**
			  * The method returns whether or not the given system was able to be added to the engine.
			  * The method can fail if the system pointer is NULL.
			  *
			  * The system is associated with entities containing any component type,
			  * i.e. all entities are given to the system.
			  */
			virtual Bool addSystem( const Pointer<EntitySystem>& system );
			
			
			
			
			/// Add a system to this entity engine with the specified name.
			/**
			  * The method returns whether or not the given system was able to be added to the engine.
			  * The method can fail if the system pointer is NULL. If there is already a system
			  * with the given name, the new system replaces the old one and the old system is removed.
			  *
			  * The system is associated with entities containing any component type,
			  * i.e. all entities are given to the system.
			  */
			virtual Bool addSystem( const Pointer<EntitySystem>& system, const String& systemName );
			
			
			
			
			/// Remove the system in this engine with the given name.
			/**
			  * The method returns whether or not a system with that name
			  * was able to be removed.
			  */
			virtual Bool removeSystem( const String& systemName );
			
			
			
			
			/// Remove the system in this engine with the given pointer.
			/**
			  * The method returns whether or not a system with that name
			  * was able to be removed.
			  */
			virtual Bool removeSystem( const Pointer<EntitySystem>& system );
			
			
			
			
			/// Remove all entity systems from this engine.
			/**
			  * The entities in the engine are unaffected.
			  */
			virtual void clearSystems();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Accessor Methods
			
			
			
			
			/// Return a pointer to the list of events for the specified event type in the engine.
			virtual const ArrayList<const Event*>* getEvents( const EventType& eventType ) const;
			
			
			
			
			/// Post the specified entity event to this engine, propagating it to all systems that want it.
			virtual Bool postEvent( const Event& newEvent );
			
			
			
			
			/// Remove all previously posted events from this engine.
			virtual void clearEvents();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class that stores information about a single entity system in an engine.
			class SystemInfo;
			
			
			
			
			/// A class that encapsulates information about an entity in this engine.
			class EntityInfo;
			
			
			
			
			/// A class that stores information about a singe type of event in this engine.
			class EventTypeInfo;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Functions
			
			
			
			
			/// Create and return a pointer to a new entity info object for the specified entity.
			const Pointer<EntityInfo>& newEntityInfo( const Pointer<Entity>& entity );
			
			
			
			
			/// Create and return a pointer to a new entity info object for the specified named entity.
			const Pointer<EntityInfo>& newEntityInfo( const Pointer<Entity>& entity, const String& entityName );
			
			
			
			
			/// Add the specified system to the list of systems for the given event type
			Bool addSystemEventType( const EventType& eventType, const Pointer<SystemInfo>& system );
			
			
			
			
			/// Remove the specified system to the list of systems for the given event type
			Bool removeSystemEventType( const EventType& eventType, const Pointer<SystemInfo>& system );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from system names to pointers to info objects for those systems.
			HashMap<String,Pointer<SystemInfo> > systemNameMap;
			
			
			
			
			/// A map from system pointers to pointers to info objects for those systems.
			HashMap< Pointer<EntitySystem>, Pointer<SystemInfo> > systemMap;
			
			
			
			
			/// A map from entity names to information about the entities.
			HashMap< String, Pointer<EntityInfo> > entityNameMap;
			
			
			
			
			/// A map from entities to information about the entities.
			HashMap< Pointer<Entity>, Pointer<EntityInfo> > entityMap;
			
			
			
			
			/// A list of information for all of the entities in this engine.
			ArrayList< Pointer<EntityInfo> > entities;
			
			
			
			
			/// A list of entity indices that were previously used but no longer.
			ArrayList<Index> unusedEntityIndices;
			
			
			
			
			/// A map from event types to the info objects associated with those types.
			HashMap< EventType, Pointer<EventTypeInfo> > eventTypeMap;
			
			
			
			
			/// A list of the events that are currently being processed by the engine on the current frame.
			ArrayList<Event> events;
			
			
			
};




//##########################################################################################
//**************************  End Rim Entities Namespace  **********************************
RIM_ENTITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENTITY_ENGINE_H

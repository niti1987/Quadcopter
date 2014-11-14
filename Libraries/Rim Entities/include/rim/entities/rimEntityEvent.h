/*
 *  rimEntityEvent.h
 *  Rim Entities
 *
 *  Created by Carl Schissler on 5/13/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENTITY_EVENT_H
#define INCLUDE_RIM_ENTITY_EVENT_H


#include "rimEntitiesConfig.h"


//##########################################################################################
//**************************  Start Rim Entities Namespace  ********************************
RIM_ENTITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



class Entity;
class EntitySystem;



/// The type to use for event types.
typedef String EventType;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that encapsulates an entity event.
/**
  * An event consists of a string-based event type, a time when the event
  * occurred, a time-out period for the event, and a value of arbitrary type
  * that the user an use to pass any kind of data with an event.
  */
class Event
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an event with the specified type and timeout period.
			/**
			  * If not specified, the timeout period has a default value of 60 seconds.
			  */
			Event( const EventType& newType, const Entity* entitySender = NULL, const EntitySystem* systemSender = NULL,
					const Time newTimeoutPeriod = 60.0 );
			
			
			
			
			/// Create an event with the specified type, value, and timeout period.
			/**
			  * If not specified, the timeout period has a default value of 60 seconds.
			  */
			template < typename ValueType >
			Event( const EventType& newType, ValueType newValue, const Entity* entitySender = NULL,
					const EntitySystem* systemSender = NULL, Time newTimeoutPeriod = 60.0 );
			
			
			
			
			/// Create a copy of the specified event.
			Event( const Event& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this event and all of its state.
			virtual ~Event();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of another event to this event.
			Event& operator = ( const Event& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Type Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the type of this event.
			RIM_INLINE const EventType& getType() const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Time Accessor Methods
			
			
			
			
			/// Return a reference to a Time object which represents the moment that this event was created.
			RIM_INLINE const Time& getTime() const
			{
				return time;
			}
			
			
			
			
			/// Return a reference to a Time object which represents the time that this event is valid.
			RIM_INLINE const Time& getTimeoutPeriod() const
			{
				return timeoutPeriod;
			}
			
			
			
			
			/// Return whether or not this event has timed out yet.
			/**
			  * If the current time is later than the event's creation time plus
			  * its timeout period, the event is no longer considered valid.
			  */
			RIM_INLINE Bool isValid() const
			{
				return Time::getCurrent() >= time + timeoutPeriod;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Value Accessor Methods
			
			
			
			
			/// Return whether or not this event has a value associated with it.
			RIM_INLINE Bool hasValue() const
			{
				return value != NULL;
			}
			
			
			
			
			/// Return a pointer to this event's value.
			/**
			  * If the event does not have a value or if the requested templated
			  * type is incompatible with the event's value, NULL is returned.
			  */
			template < typename ValueType >
			RIM_INLINE const ValueType* getValue() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Event Sender Accessor Methods
			
			
			
			
			/// Return a pointer to entity that produced this event, or NULL if there is no entity sender.
			RIM_INLINE const Entity* getEntity() const
			{
				return entitySender;
			}
			
			
			
			
			/// Return a pointer to entity system that produced this event, or NULL if there is no system sender.
			RIM_INLINE const EntitySystem* getSystem() const
			{
				return systemSender;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// The base class for classes that hold event values of arbitrary type.
			class EventValueBase;
			
			
			
			
			/// A class which holds an event value of the specified value type.
			template < typename ValueType >
			class EventValue;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A string representing the type of this event.
			EventType type;
			
			
			
			
			/// The time at which this event was created.
			Time time;
			
			
			
			
			/// The amount of time that can pass before this event becomes invalid.
			Time timeoutPeriod;
			
			
			
			
			/// The value for this event. This value is used to carry arbitrary information about the event.
			EventValueBase* value;
			
			
			
			
			/// A pointer to the entity which produced this event.
			const Entity* entitySender;
			
			
			
			
			/// A pointer to the entity system which produced this event.
			const EntitySystem* systemSender;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Base Event Value Class Defintion
//############		
//##########################################################################################
//##########################################################################################




class Event:: EventValueBase
{
	public:
		
		
		virtual ~EventValueBase()
		{
		}
		
		
		/// Return a pointer to the value stored in this event value.
		/**
		  * If there is no value or the type is incompatible, the method
		  * returns NULL.
		  */
		template < typename ValueType >
		RIM_INLINE ValueType* getValue();
		
		
		/// Return a const pointer to the value stored in this event value.
		/**
		  * If there is no value or the type is incompatible, the method
		  * returns NULL.
		  */
		template < typename ValueType >
		RIM_INLINE const ValueType* getValue() const;
		
		
		/// Construct and return a copy of this event value.
		virtual EventValueBase* copy() const = 0;
		
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		Event Value Class Defintion
//############		
//##########################################################################################
//##########################################################################################




template < typename ValueType >
class Event:: EventValue : public EventValueBase
{
	public:
		
		/// Create a new event value object which stores a copy of the specified value.
		RIM_INLINE EventValue( const ValueType& newValue )
			:	value( newValue )
		{
		}
		
		
		/// Return a pointer to the value stored in this event value.
		/**
		  * If there is no value or the type is incompatible, the method
		  * returns NULL.
		  */
		RIM_INLINE ValueType* getValue()
		{
			return &value;
		}
		
		
		/// Return a const pointer to the value stored in this event value.
		/**
		  * If there is no value or the type is incompatible, the method
		  * returns NULL.
		  */
		RIM_INLINE const ValueType* getValue() const
		{
			return &value;
		}
		
		
		
		/// Construct and return a copy of this event value.
		virtual EventValueBase* copy() const
		{
			return util::construct<EventValue<ValueType> >( *this );
		}
		
		
	private:
		
		
		/// The user-defined value object associated with this event value.
		ValueType value;
		
		
};




//##########################################################################################
//##########################################################################################
//############		
//############		Event Constructors
//############		
//##########################################################################################
//##########################################################################################




template < typename ValueType >
Event:: Event( const EventType& newType, ValueType newValue, const Entity* newEntitySender,
				const EntitySystem* newSystemSender, Time newTimeoutPeriod )
	:	type( newType ),
		time( Time::getCurrent() ),
		timeoutPeriod( newTimeoutPeriod )
{
	value = util::construct<EventValue<ValueType> >( newValue );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Event Value Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename ValueType >
ValueType* Event::EventValueBase:: getValue()
{
	EventValue<ValueType>* array = dynamic_cast<EventValue<ValueType>*>( this );
	
	if ( array != NULL )
		return array->getComponents();
	else
		return NULL;
}




template < typename ValueType >
const ValueType* Event::EventValueBase:: getValue() const
{
	const EventValue<ValueType>* value = dynamic_cast<const EventValue<ValueType>*>( this );
	
	if ( value != NULL )
		return value->getValue();
	else
		return NULL;
}




template < typename ValueType >
const ValueType* Event:: getValue() const
{
	if ( value != NULL )
		return value->getValue<ValueType>();
	else
		return NULL;
}




//##########################################################################################
//**************************  End Rim Entities Namespace  **********************************
RIM_ENTITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENTITY_EVENT_H

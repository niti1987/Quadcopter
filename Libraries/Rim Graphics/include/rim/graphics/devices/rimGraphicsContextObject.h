/*
 *  rimGraphicsContextObject.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CONTEXT_OBJECT_H
#define INCLUDE_RIM_GRAPHICS_CONTEXT_OBJECT_H


#include "rimGraphicsDevicesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class GraphicsContext;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the base class for a hardware-based context-specific object.
/**
  * Examples of types that should inherit from ContextObject: textures, hardware-based
  * buffer objects, shader objects, framebuffers, etc.
  *
  * The main reason for this class is to provide a common interface for
  * all hardware-based objects to access the context that is associated with them.
  *
  * A context object cannot be directly copied (it has a private copy constructor
  * and assignment operator).
  */
class ContextObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a context object, releasing all internal state.
			virtual ~ContextObject()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Method
			
			
			
			
			/// Return a pointer to the graphics context associated with this ContextObject.
			/**
			  * This is the context that created this object. The object cannot
			  * be used with any other context. This pointer is mainly used by contexts
			  * to make sure that the context object is associated with the same context
			  * which is trying to use it.
			  */
			RIM_INLINE const GraphicsContext* getContext() const
			{
				return context;
			}
			
			
			
			
	protected:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Protected Constructor
			
			
			
			
			/// Create a new context object which is associated with the specified graphics context.
			RIM_INLINE ContextObject( const GraphicsContext* newContext )
				:	context( newContext )
			{
				RIM_DEBUG_ASSERT_MESSAGE( context != NULL, "Cannot create a new ContextObject with a NULL context" );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Copy Operations
			
			
			
			
			/// Declared private to prevent user copying of context objects.
			RIM_INLINE ContextObject( const ContextObject& other )
				:	context( other.context )
			{
			}
			
			
			
			
			/// Declared private to prevent user copying of context objects.
			RIM_INLINE ContextObject& operator = ( const ContextObject& other )
			{
				context = other.context;
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics context associated with this context object.
			/**
			  * This is the context that created this object. The object cannot
			  * be used with any other context.
			  */
			const GraphicsContext* context;
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CONTEXT_OBJECT_H

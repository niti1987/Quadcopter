/*
 *  rimGraphicsSystem.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/21/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENGINE_GRAPHICS_SYSTEM_H
#define INCLUDE_RIM_ENGINE_GRAPHICS_SYSTEM_H


#include "rimEngineConfig.h"


//##########################################################################################
//***************************  Start Rim Engine Namespace  *********************************
RIM_ENGINE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




class GraphicsSystem : public EntitySystem
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty graphics system with no entities and no rendering pipeline.
			GraphicsSystem();
			
			
			
			
			/// Create a new empty graphics system that uses the specified graphics pipeline for rendering.
			GraphicsSystem( const Pointer<GraphicsPipeline>& newPipeline );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the state of all entities in this system for the specified time interval.
			virtual void update( const Time& dt, EntityEngine* engine = NULL );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pipeline Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics pipeline that this system is using.
			RIM_INLINE const Pointer<GraphicsPipeline>& getPipeline() const
			{
				return pipeline;
			}
			
			
			
			
			/// Set the graphics pipeline that this system is using.
			RIM_INLINE void setPipeline( const Pointer<GraphicsPipeline>& newPipeline )
			{
				pipeline = newPipeline;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the graphics pipeline that this system is using.
			Pointer<GraphicsPipeline> pipeline;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Engine Namespace  ***********************************
RIM_ENGINE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENGINE_GRAPHICS_SYSTEM_H

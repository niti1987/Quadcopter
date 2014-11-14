/*
 *  rimGraphicsDeviceType.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/2/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_DEVICE_TYPE_H
#define INCLUDE_RIM_GRAPHICS_DEVICE_TYPE_H


#include "rimGraphicsDevicesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Devices Namespace  ***************************
RIM_GRAPHICS_DEVICES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which enumerates the different possible types of GraphicsDevice that may exist.
/**
  * A GraphicsDevice represents a particular interface to the system's graphics
  * hardware, such as OpenGL or Direct3D. This class indicates the type of interface
  * that a device uses. This allows the user to determine which device to use when
  * rendering graphics on a given system platform.
  */
class GraphicsDeviceType
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Enum Declaration
			
			
			
			
			/// An enum type which represents the different graphics device types.
			typedef enum Enum
			{
				/// A graphics device type that uses the OpenGL API to draw graphics.
				OPENGL,
				
				/// A graphics device type that uses the Direct3D 9 API to draw graphics.
				DIRECT3D_9,
				
				/// A graphics device type that uses the Direct3D 10 API to draw graphics.
				DIRECT3D_10,
				
				/// A graphics device type that uses the Direct3D 11 API to draw graphics.
				DIRECT3D_11,
				
				/// An undefined or unknown graphics device type.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graphics device type with the specified device type enum value.
			RIM_INLINE GraphicsDeviceType( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this graphics device type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the graphics device type.
			String toString() const;
			
			
			
			
			/// Convert this graphics device type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum representing the graphics device type.
			Enum type;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Devices Namespace  *****************************
RIM_GRAPHICS_DEVICES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_DEVICE_TYPE_H

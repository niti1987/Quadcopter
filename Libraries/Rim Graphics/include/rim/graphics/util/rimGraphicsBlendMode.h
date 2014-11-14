/*
 *  rimGraphicsBlendMode.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/13/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BLEND_MODE_H
#define INCLUDE_RIM_GRAPHICS_BLEND_MODE_H


#include "rimGraphicsUtilitiesConfig.h"


#include "rimGraphicsBlendFactor.h"
#include "rimGraphicsBlendFunction.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies how blending should be performed between a source and destination fragment.
class BlendMode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new blend mode with the default blending parameters.
			/**
			  * The default blend mode is SOURCE_ALPHA for the source factor,
			  * INVERSE_SOURCE_ALPHA for the destination factor, and a blend
			  * function of ADD.
			  */
			RIM_INLINE BlendMode()
				:	sourceFactor( BlendFactor::SOURCE_ALPHA ),
					destinationFactor( BlendFactor::INVERSE_SOURCE_ALPHA ),
					function( BlendFunction::ADD ),
					constantColor()
			{
			}
			
			
			
			
			/// Create a new blend mode with the given source and destination blend factors and blend function.
			RIM_INLINE BlendMode( BlendFactor newSourceFactor, BlendFactor newDestinationFactor,
								BlendFunction newFunction )
				:	sourceFactor( newSourceFactor ),
					destinationFactor( newDestinationFactor ),
					function( newFunction ),
					constantColor()
			{
			}
			
			
			
			
			/// Create a new blend mode with the given source and destination blend factors, blend function, and color.
			RIM_INLINE BlendMode( BlendFactor newSourceFactor, BlendFactor newDestinationFactor,
								BlendFunction newFunction, const Color4f& newConstantColor )
				:	sourceFactor( newSourceFactor ),
					destinationFactor( newDestinationFactor ),
					function( newFunction ),
					constantColor( newConstantColor )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Source Factor Accessor Methods
			
			
			
			
			/// Return an object which describes the source color blend factor for this blend mode.
			RIM_INLINE const BlendFactor& getSource() const
			{
				return sourceFactor;
			}
			
			
			
			
			/// Set the source color blend factor for this blend mode.
			RIM_INLINE void setSource( const BlendFactor& newSource )
			{
				sourceFactor = newSource;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destination Factor Accessor Methods
			
			
			
			
			/// Return an object which describes the destination color blend factor for this blend mode.
			RIM_INLINE const BlendFactor& getDestination() const
			{
				return destinationFactor;
			}
			
			
			
			
			/// Set the destination color blend factor for this blend mode.
			RIM_INLINE void setDestination( const BlendFactor& newDestination )
			{
				destinationFactor = newDestination;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Blend Function Accessor Methods
			
			
			
			
			/// Return an object which describes the blending function used by this blend mode.
			RIM_INLINE const BlendFunction& getFunction() const
			{
				return function;
			}
			
			
			
			
			/// Set the blending function used by this blend mode.
			RIM_INLINE void setFunction( const BlendFunction& newFunction )
			{
				function = newFunction;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constant Color Accessor Methods
			
			
			
			
			/// Return a constant color value which may be used as a blending factor in some operations.
			RIM_INLINE const Color4f& getConstantColor() const
			{
				return constantColor;
			}
			
			
			
			
			/// Set a constant color value which may be used as a blending factor in some operations.
			RIM_INLINE void setConstantColor( const Color4f& newConstantColor )
			{
				constantColor = newConstantColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this blend mode is equal to another blend mode.
			RIM_INLINE Bool operator == ( const BlendMode& other ) const
			{
				return sourceFactor == other.sourceFactor && destinationFactor == other.destinationFactor &&
						function == other.function && constantColor == other.constantColor;
			}
			
			
			
			
			/// Return whether or not this blend mode is not equal to another blend mode.
			RIM_INLINE Bool operator != ( const BlendMode& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which describes the blend factor for the source pixel color.
			BlendFactor sourceFactor;
			
			
			
			
			/// An object which describes the blend factor for the destination pixel color.
			BlendFactor destinationFactor;
			
			
			
			
			/// An object which describes the operation applied between the source and destionation blend factors.
			BlendFunction function;
			
			
			
			
			/// A constant color value which may be used as a blending factor in some operations.
			Color4f constantColor;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BLEND_MODE_H

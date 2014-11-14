/*
 *  rimGraphicsRenderMode.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 3/14/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_RENDER_MODE_H
#define INCLUDE_RIM_GRAPHICS_RENDER_MODE_H


#include "rimGraphicsUtilitiesConfig.h"


#include "rimGraphicsRenderFlags.h"
#include "rimGraphicsRasterMode.h"
#include "rimGraphicsBlendMode.h"
#include "rimGraphicsDepthMode.h"
#include "rimGraphicsStencilMode.h"
#include "rimGraphicsAlphaTest.h"


//##########################################################################################
//**********************  Start Rim Graphics Utilities Namespace  **************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies the configuration of the fixed-function rendering pipeline.
class RenderMode
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new render mode with the default rendering parameters.
			/**
			  * By default, color writing, depth writing, and the depth test are
			  * enabled by the render flags.
			  */
			RIM_INLINE RenderMode()
				:	flags( DEFAULT_RENDER_FLAGS ),
					rasterMode( RasterMode::TRIANGLES ),
					blendMode(),
					depthMode(),
					stencilMode(),
					alphaTest( AlphaTest::ALWAYS ),
					lineWidth( 1.0f ),
					pointSize( 1.0f )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Render Flags Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains boolean parameters of the render mode.
			RIM_INLINE RenderFlags& getFlags()
			{
				return flags;
			}
			
			
			
			
			/// Return an object which contains boolean parameters of the render mode.
			RIM_INLINE const RenderFlags& getFlags() const
			{
				return flags;
			}
			
			
			
			
			/// Set an object which contains boolean parameters of the render mode.
			RIM_INLINE void setFlags( const RenderFlags& newFlags )
			{
				flags = newFlags;
			}
			
			
			
			
			/// Return whether or not the specified boolan render flag is set for this render mode.
			RIM_INLINE Bool flagIsSet( RenderFlags::Flag flag ) const
			{
				return flags.isSet( flag );
			}
			
			
			
			
			/// Set whether or not the specified boolan render flag is set for this render mode.
			RIM_INLINE void setFlag( RenderFlags::Flag flag, Bool newIsSet = true )
			{
				flags.set( flag, newIsSet );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Raster Mode Accessor Methods
			
			
			
			
			/// Return a reference to an object representing the raster mode for this render mode.
			RIM_INLINE RasterMode& getRasterMode()
			{
				return rasterMode;
			}
			
			
			
			
			/// Return a reference to an object representing the raster mode for this render mode.
			RIM_INLINE const RasterMode& getRasterMode() const
			{
				return rasterMode;
			}
			
			
			
			
			/// Set an object representing the raster mode for this render mode.
			RIM_INLINE void setRasterMode( const RasterMode& newRasterMode )
			{
				rasterMode = newRasterMode;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Blend Mode Accessor Methods
			
			
			
			
			/// Return a reference to an object representing the blend mode for this render mode.
			RIM_INLINE BlendMode& getBlendMode()
			{
				return blendMode;
			}
			
			
			
			
			/// Return a reference to an object representing the blend mode for this render mode.
			RIM_INLINE const BlendMode& getBlendMode() const
			{
				return blendMode;
			}
			
			
			
			
			/// Set an object representing the blend mode for this render mode.
			RIM_INLINE void setBlendMode( const BlendMode& newBlendMode )
			{
				blendMode = newBlendMode;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Mode Accessor Methods
			
			
			
			
			/// Return a reference to an object representing the depth mode for this render mode.
			RIM_INLINE DepthMode& getDepthMode()
			{
				return depthMode;
			}
			
			
			
			
			/// Return a reference to an object representing the depth mode for this render mode.
			RIM_INLINE const DepthMode& getDepthMode() const
			{
				return depthMode;
			}
			
			
			
			
			/// Set an object representing the depth mode for this render mode.
			RIM_INLINE void setDepthMode( const DepthMode& newDepthMode )
			{
				depthMode = newDepthMode;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Stencil Mode Accessor Methods
			
			
			
			
			/// Return a reference to an object representing the stencil mode for this render mode.
			RIM_INLINE StencilMode& getStencilMode()
			{
				return stencilMode;
			}
			
			
			
			
			/// Return a reference to an object representing the stencil mode for this render mode.
			RIM_INLINE const StencilMode& getStencilMode() const
			{
				return stencilMode;
			}
			
			
			
			
			/// Set an object representing the stencil mode for this render mode.
			RIM_INLINE void setStencilMode( const StencilMode& newStencilMode )
			{
				stencilMode = newStencilMode;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Alpha Test Accessor Methods
			
			
			
			
			/// Return a reference to an object representing the alpha test for this render mode.
			RIM_INLINE AlphaTest& getAlphaTest()
			{
				return alphaTest;
			}
			
			
			
			
			/// Return a reference to an object representing the alpha test for this render mode.
			RIM_INLINE const AlphaTest& getAlphaTest() const
			{
				return alphaTest;
			}
			
			
			
			
			/// Set an object representing the alpha test for this render mode.
			RIM_INLINE void setAlphaTest( const AlphaTest& newAlphaTest )
			{
				alphaTest = newAlphaTest;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Line Width Accessor Methods
			
			
			
			
			/// Return the width in pixels to use when rendering lines.
			RIM_INLINE Float getLineWidth() const
			{
				return lineWidth;
			}
			
			
			
			
			/// Set the width in pixels to use when rendering lines.
			RIM_INLINE void setLineWidth( Float newLineWidth )
			{
				lineWidth = newLineWidth;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Point Size Accessor Methods
			
			
			
			
			/// Return the size in pixels to use when rendering points.
			RIM_INLINE Float getPointSize() const
			{
				return pointSize;
			}
			
			
			
			
			/// Set the size in pixels to use when rendering points.
			RIM_INLINE void setPointSize( Float newPointSize )
			{
				pointSize = newPointSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Comparison Operators
			
			
			
			
			/// Return whether or not this render mode is equal to another render mode.
			RIM_INLINE Bool operator == ( const RenderMode& other ) const
			{
				return flags == other.flags &&
						blendMode == other.blendMode &&
						depthMode == other.depthMode &&
						stencilMode == other.stencilMode &&
						lineWidth == other.lineWidth &&
						pointSize == other.pointSize;
			}
			
			
			
			
			/// Return whether or not this render mode is not equal to another render mode.
			RIM_INLINE Bool operator != ( const RenderMode& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default set flags to use for a render mode.
			static const UInt DEFAULT_RENDER_FLAGS = RenderFlags::COLOR_WRITE | RenderFlags::DEPTH_WRITE |
													RenderFlags::DEPTH_TEST | RenderFlags::GAMMA_CORRECTION;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A value which contains boolean parameters for the render mode.
			RenderFlags flags;
			
			
			
			
			/// An object which determines how primitive geometry is rasterized.
			RasterMode rasterMode;
			
			
			
			
			/// An object which contains the configuration of the blending pipeline.
			BlendMode blendMode;
			
			
			
			
			/// An object which contains the configuration of the depth test pipeline.
			DepthMode depthMode;
			
			
			
			
			/// An object which contains the configuration of the stencil test pipeline.
			StencilMode stencilMode;
			
			
			
			
			/// An object which contains the configuration of the alpha test pipeline.
			AlphaTest alphaTest;
			
			
			
			
			/// The width in pixels to use when rendering lines.
			Float lineWidth;
			
			
			
			
			/// The size in pixels of the points that are rendered.
			Float pointSize;
			
			
			
};




//##########################################################################################
//**********************  End Rim Graphics Utilities Namespace  ****************************
RIM_GRAPHICS_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_RENDER_MODE_H

/*
 *  rimResourceFormat.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/24/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_RESOURCE_FORMAT_H
#define INCLUDE_RIM_RESOURCE_FORMAT_H


#include "rimResourcesConfig.h"


#include "rimResourceType.h"


//##########################################################################################
//**************************  Start Rim Resources Namespace  *******************************
RIM_RESOURCES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// An enum class which specifies a format (format) for a resource.
class ResourceFormat
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Type Enum Definition
			
			
			
			
			/// An enum type which represents the type of resource format.
			typedef enum Enum
			{
				/// An undefined resource format.
				UNDEFINED = 0,
				
				//********************************************************************************
				// Scene formats
				
				/// Open-standard .dae scene format for digital access exchange.
				COLLADA,
				
				/// FBX Autodesk scene format.
				FBX,
				
				/// The Virtual Reality Modeling Language scene format.
				VRML,
				
				/// The DirectX .x scene format.
				X,
				
				/// The old 3DS Max .3ds scene format.
				THREE_DS,
				
				/// The Cinema 4D scene format.
				CINEMA_4D,
				
				/// The SketchUp .skp scene format.
				SKETCH_UP,
				
				/// The Asset scene format.
				ASSET_SCENE,
				
				//********************************************************************************
				// Graphics Shape formats
				
				/// The wavefront .obj shape format.
				OBJ,
				
				/// PLY polygon shape format (Stanford triangle format).
				PLY,
				
				/// The .tri alias triangle shape format.
				TRI,
				
				//********************************************************************************
				// Graphics Material formats
				
				/// The wavefront .mtl material file format, used with the OBJ shape format.
				MTL,
				
				//********************************************************************************
				// Image formats
				
				/// The uncompressed .bmp image file format.
				BMP,
				
				/// The lossily-compressed .jpg image file format.
				JPEG,
				
				/// The losslessly-compressed .png image file format.
				PNG,
				
				/// The .tga image file format.
				TGA,
				
				/// The .tiff image file format.
				TIFF,
				
				/// The .gif image file format.
				GIF,
				
				/// The JPEG 2000 image file format.
				JPEG_2000,
				
				/// The DDS image/texture file format.
				DDS,
				
				//********************************************************************************
				// Sound formats
				
				/// The WAVE sound format.
				WAVE,
				
				/// The Audio Interchange File Format (AIFF) sound format.
				AIFF,
				
				/// The compressed OGG sound format.
				OGG,
				
				/// The compressed MPEG-3 sound format.
				MP3,
				
				/// The MPEG-4 audio-only sound format.
				M4A,
				
				/// The Free Lossless Audio Codec (FLAC) sound format.
				FLAC,
				
				/// The Core Audio Format (CAF) sound format.
				CAF,
				
				//********************************************************************************
				// MIDI formats
				
				/// The Musical Instrument Digital Interface (MIDI) format.
				MIDI
				
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new resource format with the UNDEFINED resource format.
			RIM_INLINE ResourceFormat()
				:	format( UNDEFINED )
			{
			}
			
			
			
			
			/// Create a new resource format with the specified resource format enum value.
			RIM_INLINE ResourceFormat( Enum newFormat )
				:	format( newFormat )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this resource format type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return format;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Resource Type Accessor Method
			
			
			
			
			/// Return an object describing the type of resource that this format cannonically corresponds to.
			ResourceType getResourceType() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Format Extension Accessor Method
			
			
			
			
			/// Return the standard file extension used for this format.
			data::UTF8String getExtension() const;
			
			
			
			
			/// Return a format which corresponds to the type with the given extension string.
			static ResourceFormat fromExtension( const data::UTF8String& extension );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a unique string for this resource format that matches its enum value name.
			data::String toEnumString() const;
			
			
			
			
			/// Return a format which corresponds to the given enum string.
			static ResourceFormat fromEnumString( const data::String& enumString );
			
			
			
			
			/// Return a string representation of the resource format.
			data::String toString() const;
			
			
			
			
			/// Convert this resource format into a string representation.
			RIM_FORCE_INLINE operator data::String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum value which indicates the type of resource format.
			Enum format;
			
			
			
};




//##########################################################################################
//**************************  End Rim Resources Namespace  *********************************
RIM_RESOURCES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_RESOURCE_FORMAT_H

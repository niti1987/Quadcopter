/*
 *  rimGraphicsShaderPassSourceAssetTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/22/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PASS_SOURCE_ASSET_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PASS_SOURCE_ASSET_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


#include "rimGraphicsShaderProgramAssetTranscoder.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encodes and decodes graphics shader passes to the asset format.
class GraphicsShaderPassSourceAssetTranscoder : public AssetTypeTranscoder<ShaderPassSource>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Encoding/Decoding Methods
			
			
			
			
			/// Decode an object from the specified string stream, returning a pointer to the final object.
			virtual Pointer<ShaderPassSource> decodeText( const AssetType& assetType, const AssetObject& assetObject,
														ResourceManager* resourceManager = NULL );
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const ShaderPassSource& shaderPassSource );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An object indicating the asset type for a graphics shader pass source.
			static const AssetType SHADER_PASS_SOURCE_ASSET_TYPE;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// An enum describing the fields that a graphics shader pass can have.
			typedef enum Field
			{
				/// An undefined field.
				UNDEFINED = 0,
				
				/// "program" The shader program that this shader pass source is using.
				PROGRAM,
				
				/// "renderMode" The rendering mode that this shader pass source is using.
				RENDER_MODE,
				
				/// "constantBindings" The constant bindings that this shader pass source has.
				CONSTANT_BINDINGS,
				
				/// "textureBindings" The texture bindings that this shader pass source has.
				TEXTURE_BINDINGS,
				
				/// "vertexBindings" The vertex bindings that this shader pass source has.
				VERTEX_BINDINGS
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return an enum value indicating the field indicated by the given field name.
			static Field getFieldType( const AssetObject::String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object that handles encoding/decoding shader programs.
			GraphicsShaderProgramAssetTranscoder programTranscoder;
			
			
			
			
			/// A temporary asset object used when parsing shader pass source child objects.
			AssetObject tempObject;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Assets Namespace  ******************************
RIM_GRAPHICS_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template <>
RIM_INLINE const AssetType& AssetType::of<rim::graphics::shaders::ShaderPassSource>()
{
	return rim::graphics::assets::GraphicsShaderPassSourceAssetTranscoder::SHADER_PASS_SOURCE_ASSET_TYPE;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PASS_SOURCE_ASSET_TRANSCODER_H

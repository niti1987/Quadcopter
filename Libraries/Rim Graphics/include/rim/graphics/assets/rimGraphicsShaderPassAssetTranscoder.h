/*
 *  rimGraphicsShaderPassAssetTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/14/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_PASS_ASSET_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_SHADER_PASS_ASSET_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


#include "rimGraphicsShaderPassSourceAssetTranscoder.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encodes and decodes graphics shader passes to the asset format.
class GraphicsShaderPassAssetTranscoder : public AssetTypeTranscoder<GenericShaderPass>
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
			virtual Pointer<GenericShaderPass> decodeText( const AssetType& assetType, const AssetObject& assetObject,
														ResourceManager* resourceManager = NULL );
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const GenericShaderPass& shaderPass );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An object indicating the asset type for a graphics shader pass.
			static const AssetType SHADER_PASS_ASSET_TYPE;
			
			
			
			
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
				
				/// "name" The name of this shader pass.
				NAME,
				
				/// "usage" The semantic usage for the shader pass.
				USAGE,
				
				/// "sources" A list of the sources for this shader pass.
				SOURCES
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
			
			
			
			
			/// A temporary asset object used when parsing shader pass child objects.
			AssetObject tempObject;
			
			
			
			
			/// An object that encodes and decodes ShaderPassSource objects for this transcoder.
			GraphicsShaderPassSourceAssetTranscoder sourceTranscoder;
			
			
			
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
RIM_INLINE const AssetType& AssetType::of<rim::graphics::shaders::GenericShaderPass>()
{
	return rim::graphics::assets::GraphicsShaderPassAssetTranscoder::SHADER_PASS_ASSET_TYPE;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_PASS_ASSET_TRANSCODER_H

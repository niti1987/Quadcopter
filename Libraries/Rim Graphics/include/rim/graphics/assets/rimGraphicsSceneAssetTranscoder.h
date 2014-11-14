/*
 *  rimGraphicsSceneAssetTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/14/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SCENE_ASSET_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_SCENE_ASSET_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


#include "rimGraphicsObjectAssetTranscoder.h"
#include "rimGraphicsCameraAssetTranscoder.h"
#include "rimGraphicsLightAssetTranscoder.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encodes and decodes graphics scenes to the asset format.
class GraphicsSceneAssetTranscoder : public AssetTypeTranscoder<GraphicsScene>
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
			virtual Pointer<GraphicsScene> decodeText( const AssetType& assetType, const AssetObject& assetObject,
													ResourceManager* resourceManager = NULL );
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const GraphicsScene& scene );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An object indicating the asset type for a graphics scene.
			static const AssetType SCENE_ASSET_TYPE;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// An enum describing the fields that a graphics scene can have.
			typedef enum Field
			{
				/// An undefined field.
				UNDEFINED = 0,
				
				/// "name" The name of this graphics scene.
				NAME,
				
				/// "objects" A list of the graphics objects in this scene.
				OBJECTS,
				
				/// "cameras" A list of the graphics cameras in this scene.
				CAMERAS,
				
				/// "lights" A list of the graphics lights in this scene.
				LIGHTS
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
			
			
			
			
			/// An object that helps transcode graphics objects that are part of a scene.
			GraphicsObjectAssetTranscoder objectTranscoder;
			
			
			
			
			/// An object that helps transcode graphics cameras that are part of a scene.
			GraphicsCameraAssetTranscoder cameraTranscoder;
			
			
			
			
			/// An object that helps transcode graphics lights that are part of a scene.
			GraphicsLightAssetTranscoder lightTranscoder;
			
			
			
			
			/// A temporary asset object used when parsing scene child objects.
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
RIM_INLINE const AssetType& AssetType::of<rim::graphics::scenes::GraphicsScene>()
{
	return rim::graphics::assets::GraphicsSceneAssetTranscoder::SCENE_ASSET_TYPE;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SCENE_ASSET_TRANSCODER_H

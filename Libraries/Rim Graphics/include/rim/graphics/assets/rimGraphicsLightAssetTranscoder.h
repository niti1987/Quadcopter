/*
 *  rimGraphicsLightAssetTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/14/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LIGHT_ASSET_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_LIGHT_ASSET_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encodes and decodes graphics lights to the asset format.
class GraphicsLightAssetTranscoder : public AssetTypeTranscoder<Light>
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
			virtual Pointer<Light> decodeText( const AssetType& assetType, const AssetObject& assetObject,
												ResourceManager* resourceManager = NULL );
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const Light& data );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An object indicating the asset type for a spot light.
			static const AssetType SPOT_LIGHT_ASSET_TYPE;
			
			
			/// An object indicating the asset type for a point light.
			static const AssetType POINT_LIGHT_ASSET_TYPE;
			
			
			/// An object indicating the asset type for a directional light.
			static const AssetType DIRECTIONAL_LIGHT_ASSET_TYPE;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// An enum describing the fields that a graphics light can have.
			typedef enum Field
			{
				/// An undefined field.
				UNDEFINED = 0,
				
				//********************************************************************
				// Common Light Fields
				
				/// "name" The name of this graphics light.
				NAME,
				
				/// "flags" Boolean configuration flags for this light source.
				FLAGS,
				
				/// "intensity" A float value indicating the light's intensity.
				INTENSITY,
				
				/// "color" The main color of the light.
				COLOR,
				
				//********************************************************************
				// Directional Light Fields
				
				/// "direction" The 3D direction of the light, the direction the light travels.
				DIRECTION,
				
				//********************************************************************
				// Point Light Fields
				
				/// "position" The 3D position of this light source in world space.
				POSITION,
				
				/// "attenuation" An object describing the distance attenuation of this point light.
				ATTENUATION,
				
				//********************************************************************
				// Spot Light Fields
				
				/// "cutoff" The half angle width in degrees of the spot light's light cone.
				CUTOFF,
				
				/// "falloff" The fraction of the spot light's angular width where the intensity falls off.
				FALLOFF,
				
				/// "exponent" How focused the spot light is towards the center.
				EXPONENT
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Decode the given asset object as if it was a spot light.
			Pointer<SpotLight> decodeTextSpot( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the given asset object as if it was a point light.
			Pointer<PointLight> decodeTextPoint( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the given asset object as if it was a directional light.
			Pointer<DirectionalLight> decodeTextDirectional( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the common light field, returning if the field is a common field.
			Bool decodeCommonField( Field field, const AssetObject::String& fieldValue, Light& light );
			
			
			
			
			/// Return an enum value indicating the field indicated by the given field name.
			static Field getFieldType( const AssetObject::String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A temporary asset object used when parsing light child objects.
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
RIM_INLINE const AssetType& AssetType::of<rim::graphics::lights::SpotLight>()
{
	return rim::graphics::assets::GraphicsLightAssetTranscoder::SPOT_LIGHT_ASSET_TYPE;
}




template <>
RIM_INLINE const AssetType& AssetType::of<rim::graphics::lights::PointLight>()
{
	return rim::graphics::assets::GraphicsLightAssetTranscoder::POINT_LIGHT_ASSET_TYPE;
}




template <>
RIM_INLINE const AssetType& AssetType::of<rim::graphics::lights::DirectionalLight>()
{
	return rim::graphics::assets::GraphicsLightAssetTranscoder::DIRECTIONAL_LIGHT_ASSET_TYPE;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LIGHT_ASSET_TRANSCODER_H

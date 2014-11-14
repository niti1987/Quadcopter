/*
 *  rimGraphicsCameraAssetTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/14/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CAMERA_ASSET_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_CAMERA_ASSET_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encodes and decodes graphics cameras to the asset format.
class GraphicsCameraAssetTranscoder : public AssetTypeTranscoder<Camera>
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
			virtual Pointer<Camera> decodeText( const AssetType& assetType, const AssetObject& assetObject,
												ResourceManager* resourceManager = NULL );
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const Camera& data );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An object indicating the asset type for an orthographic camera.
			static const AssetType ORTHOGRAPHIC_CAMERA_ASSET_TYPE;
			
			
			/// An object indicating the asset type for an perspective camera.
			static const AssetType PERSPECTIVE_CAMERA_ASSET_TYPE;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// An enum describing the fields that a graphics camera can have.
			typedef enum Field
			{
				/// An undefined field.
				UNDEFINED = 0,
				
				//********************************************************************
				// Common Camera Fields
				
				/// "name" The name of this graphics camera.
				NAME,
				
				/// "position" The 3D position of the camera in world space.
				POSITION,
				
				/// "orientation" The 3D orientation of the camera in world space.
				ORIENTATION,
				
				/// "scale" The scale of the camera in world space.
				SCALE,
				
				/// "near" The near plane distance for the camera.
				NEAR,
				
				/// "far" The far plane distance for the camera.
				FAR,
				
				/// "viewport" The rectangle on the screen where the camera's view is.
				VIEWPORT,
				
				//********************************************************************
				// Orthographic Camera Fields
				
				/// "viewBounds" The 2D camera-space bounding box of the camera's viewport.
				VIEW_BOUNDS,
				
				//********************************************************************
				// Perspective Camera Fields
				
				/// "aspectRatio" The aspect ratio of the camera's perspective projection.
				ASPECT_RATIO,
				
				/// "hFOV" The horizontal field of view in degrees of the camera's perspective projection.
				H_FOV
				
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Decode the given asset object as if it was an orthographic camera.
			Pointer<OrthographicCamera> decodeTextOrthographic( const AssetObject& assetObject,
																ResourceManager* resourceManager );
			
			
			
			
			/// Decode the given asset object as if it was a perspective camera.
			Pointer<PerspectiveCamera> decodeTextPerspective( const AssetObject& assetObject,
															ResourceManager* resourceManager );
			
			
			
			
			/// Decode the common camera field, returning if the field is a common field.
			Bool decodeCommonField( Field field, const AssetObject::String& fieldValue, Camera& camera );
			
			
			
			
			/// Return an enum value indicating the field indicated by the given field name.
			static Field getFieldType( const AssetObject::String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A temporary asset object used when parsing camera child objects.
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
RIM_INLINE const AssetType& AssetType::of<rim::graphics::OrthographicCamera>()
{
	return rim::graphics::assets::GraphicsCameraAssetTranscoder::ORTHOGRAPHIC_CAMERA_ASSET_TYPE;
}




template <>
RIM_INLINE const AssetType& AssetType::of<graphics::PerspectiveCamera>()
{
	return rim::graphics::assets::GraphicsCameraAssetTranscoder::PERSPECTIVE_CAMERA_ASSET_TYPE;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CAMERA_ASSET_TRANSCODER_H

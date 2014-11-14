/*
 *  rimGraphicsMeshGroupTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/28/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_MESH_GROUP_ASSET_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_MESH_GROUP_ASSET_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


#include "rimGraphicsMaterialAssetTranscoder.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encodes and decodes graphics groups to the asset format.
class GraphicsMeshGroupAssetTranscoder : public AssetTypeTranscoder<GenericMeshGroup>
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
			virtual Pointer<GenericMeshGroup> decodeText( const AssetType& assetType, const AssetObject& assetObject,
														ResourceManager* resourceManager = NULL );
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const GenericMeshGroup& group );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An object indicating the asset type for a mesh group.
			static const AssetType MESH_GROUP_ASSET_TYPE;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// An enum describing the fields that a mesh group can have.
			typedef enum Field
			{
				/// An undefined field.
				UNDEFINED = 0,
				
				/// "name" The name of this mesh group.
				NAME,
				
				/// "material" The material of this mesh grouop.
				MATERIAL,
				
				/// "primitiveType" An enum indicating the primitive type of this mesh group.
				PRIMITIVE_TYPE,
				
				/// "indexBuffer" A buffer of vertex indices for the mesh group.
				INDEX_BUFFER,
				
				/// "vertexBuffers" A vertex buffer list for the mesh group.
				VERTEX_BUFFERS
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
			
			
			
			
			/// An object that handles encoding/decoding materials.
			GraphicsMaterialAssetTranscoder materialTranscoder;
			
			
			
			
			/// A temporary asset object used when parsing group child objects.
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
RIM_INLINE const AssetType& AssetType::of<graphics::assets::GenericMeshGroup>()
{
	return rim::graphics::assets::GraphicsMeshGroupAssetTranscoder::MESH_GROUP_ASSET_TYPE;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_MESH_GROUP_ASSET_TRANSCODER_H

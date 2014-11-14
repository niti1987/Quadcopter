/*
 *  rimGraphicsShapeAssetTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/14/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHAPE_ASSET_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_SHAPE_ASSET_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


#include "rimGraphicsMaterialAssetTranscoder.h"
#include "rimGraphicsMeshGroupAssetTranscoder.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encodes and decodes graphics shapes to the asset format.
class GraphicsShapeAssetTranscoder : public AssetTypeTranscoder<GraphicsShape>
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
			virtual Pointer<GraphicsShape> decodeText( const AssetType& assetType, const AssetObject& assetObject,
												ResourceManager* resourceManager = NULL );
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const GraphicsShape& data );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// An object indicating the asset type for a GenericSphereShape shape.
			static const AssetType SPHERE_SHAPE_ASSET_TYPE;
			
			
			/// An object indicating the asset type for a GenericCylinderShape shape.
			static const AssetType CYLINDER_SHAPE_ASSET_TYPE;
			
			
			/// An object indicating the asset type for a GenericCapsuleShape shape.
			static const AssetType CAPSULE_SHAPE_ASSET_TYPE;
			
			
			/// An object indicating the asset type for a GenericBoxShape shape.
			static const AssetType BOX_SHAPE_ASSET_TYPE;
			
			
			/// An object indicating the asset type for a GenericMeshShape shape.
			static const AssetType MESH_SHAPE_ASSET_TYPE;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Declarations
			
			
			
			
			/// An enum describing the fields that a graphics shape can have.
			typedef enum Field
			{
				/// An undefined field.
				UNDEFINED = 0,
				
				//********************************************************************
				// Common Shape Fields
				
				/// "name" The name of this graphics shape.
				NAME,
				
				/// "position" The 3D position of the shape in its parent coordinate space.
				POSITION,
				
				/// "orientation" The 3D orientation of the shape in its parent coordinate space.
				ORIENTATION,
				
				/// "scale" The scale of the shape in its parent coordinate space.
				SCALE,
				
				//********************************************************************
				// Sphere Shape Fields
				
				/// "radius" The radius of the sphere in its local coordinate frame.
				RADIUS,
				
				//********************************************************************
				// Cylinder and Capsule Shape Fields
				
				/// "endpoint1" The position of the center of the first end cap of a cylinder or capsule.
				ENDPOINT_1,
				
				/// "endpoint2" The position of the center of the second end cap of a cylinder or capsule.
				ENDPOINT_2,
				
				/// "radius1" The radius of the first end cap of a cylinder or capsule.
				RADIUS_1,
				
				/// "radius2" The radius of the first end cap of a cylinder or capsule.
				RADIUS_2,
				
				//********************************************************************
				// Box Shape Fields
				
				/// "size" The XYZ dimensions of this box.
				SIZE,
				
				//********************************************************************
				// Mesh Shape Fields
				
				/// "groups" The material mesh groups for the mesh.
				GROUPS
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Decode the given asset object as if it was a generic sphere shape.
			Pointer<GenericSphereShape> decodeTextSphere( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the given asset object as if it was a generic cylinder shape.
			Pointer<GenericCylinderShape> decodeTextCylinder( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the given asset object as if it was a generic capsule shape.
			Pointer<GenericCapsuleShape> decodeTextCapsule( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the given asset object as if it was an generic box shape.
			Pointer<GenericBoxShape> decodeTextBox( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the given asset object as if it was an generic mesh shape.
			Pointer<GenericMeshShape> decodeTextMesh( const AssetObject& assetObject, ResourceManager* resourceManager );
			
			
			
			
			/// Decode the common shape field, returning if the field is a common field.
			Bool decodeCommonField( Field field, const AssetObject::String& fieldValue, GraphicsShape& shape );
			
			
			
			
			/// Return an enum value indicating the field indicated by the given field name.
			static Field getFieldType( const AssetObject::String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object that handles encoding/decoding mesh groups.
			GraphicsMeshGroupAssetTranscoder meshGroupTranscoder;
			
			
			
			
			/// An object that handles encoding/decoding materials.
			GraphicsMaterialAssetTranscoder materialTranscoder;
			
			
			
			
			/// A temporary asset object used when parsing shape child objects.
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
RIM_INLINE const AssetType& AssetType::of<rim::graphics::shapes::GenericSphereShape>()
{
	return rim::graphics::assets::GraphicsShapeAssetTranscoder::SPHERE_SHAPE_ASSET_TYPE;
}




template <>
RIM_INLINE const AssetType& AssetType::of<rim::graphics::shapes::GenericCylinderShape>()
{
	return rim::graphics::assets::GraphicsShapeAssetTranscoder::CYLINDER_SHAPE_ASSET_TYPE;
}




template <>
RIM_INLINE const AssetType& AssetType::of<rim::graphics::shapes::GenericCapsuleShape>()
{
	return rim::graphics::assets::GraphicsShapeAssetTranscoder::CAPSULE_SHAPE_ASSET_TYPE;
}




template <>
RIM_INLINE const AssetType& AssetType::of<rim::graphics::shapes::GenericBoxShape>()
{
	return rim::graphics::assets::GraphicsShapeAssetTranscoder::BOX_SHAPE_ASSET_TYPE;
}




template <>
RIM_INLINE const AssetType& AssetType::of<rim::graphics::shapes::GenericMeshShape>()
{
	return rim::graphics::assets::GraphicsShapeAssetTranscoder::MESH_SHAPE_ASSET_TYPE;
}




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHAPE_ASSET_TRANSCODER_H

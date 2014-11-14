/*
 *  rimAssetTypeTranscoder.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/11/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ASSET_TYPE_TRANSCODER_H
#define INCLUDE_RIM_ASSET_TYPE_TRANSCODER_H


#include "rimAssetsConfig.h"


#include "rimAssetObject.h"


//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which specifies functions that determine how an asset type should be encoded/decoded.
template < typename DataType >
class AssetTypeTranscoder
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			virtual ~AssetTypeTranscoder()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Text Encoding/Decoding Methods
			
			
			
			
			/// Decode an object from the specified string stream, returning a pointer to the final object.
			virtual Pointer<DataType> decodeText( const AssetType& assetType, const AssetObject& assetObject,
													ResourceManager* resourceManager = NULL ) = 0;
			
			
			
			
			/// Encode an object of this asset type into a text-based format.
			virtual Bool encodeText( UTF8StringBuffer& buffer, ResourceManager* resourceManager,
									const DataType& data ) = 0;
			
			
			
};





//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ASSET_TYPE_TRANSCODER_H

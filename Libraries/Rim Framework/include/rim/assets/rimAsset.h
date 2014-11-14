/*
 *  rimAsset.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/11/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ASSET_H
#define INCLUDE_RIM_ASSET_H


#include "rimAssetsConfig.h"


//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates a named asset.
template < typename DataType >
class Asset
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new unnnamed asset with the specified value.
			RIM_INLINE Asset( const Pointer<DataType>& newData )
				:	name(),
					data( newData )
			{
			}
			
			
			
			
			/// Create a new asset with the specified value and name.
			RIM_INLINE Asset( const Pointer<DataType>& newData, const UTF8String& newName )
				:	name( newName ),
					data( newData )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Name Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the name of this asset.
			RIM_INLINE const UTF8String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Return a reference to a string representing the name of this asset.
			RIM_INLINE void setName( const UTF8String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Data Accessor Methods
			
			
			
			
			/// Return a const reference to the value object stored by this asset.
			RIM_INLINE const Pointer<DataType>& getData() const
			{
				return data;
			}
			
			
			
			
			/// Set the value object stored by this asset.
			RIM_INLINE void setData( const Pointer<DataType>& newData )
			{
				data = newData;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The data of this asset, the object that it stores.
			Pointer<DataType> data;
			
			
			
			
			/// A string representing the name of this asset.
			UTF8String name;
			
			
			
};




//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ASSET_H

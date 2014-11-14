/*
 *  rimAssetScene.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 6/11/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ASSET_SCENE_H
#define INCLUDE_RIM_ASSET_SCENE_H


#include "rimAssetsConfig.h"


#include "rimAsset.h"
#include "rimAssetType.h"


//##########################################################################################
//****************************  Start Rim Assets Namespace  ********************************
RIM_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a multi-media scene and all of its data.
class AssetScene
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new empty asset scene that has no stored assets.
			AssetScene();
			
			
			
			
			/// Create a copy of another asset scene, copying all of its stored assets.
			AssetScene( const AssetScene& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an asset scene, deallocating all stored assets.
			virtual ~AssetScene();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of one asset scene to another, copying all stored assets.
			AssetScene& operator = ( const AssetScene& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Accessor Methods
			
			
			
			
			/// Return a pointer to the first asset that the asset scene has for the specified type.
			/**
			  * If the asset scene does not have any assets for the specified template type,
			  * NULL is returned.
			  */
			template < typename DataType >
			Asset<DataType>* getAsset();
			
			
			
			
			/// Return a const pointer to the first asset that the asset scene has for the specified type.
			/**
			  * If the asset scene does not have any assets for the specified template type,
			  * NULL is returned.
			  */
			template < typename DataType >
			const Asset<DataType>* getAsset() const;
			
			
			
			
			/// Return a pointer to the asset that the asset scene has for the specified type and with the given name.
			/**
			  * If the asset scene does not have any assets for the specified template type and
			  * a matching name string, NULL is returned.
			  */
			template < typename DataType >
			Asset<DataType>* getAsset( const UTF8String& name );
			
			
			
			
			/// Return a const pointer to the asset that the asset scene has for the specified type and with the given name.
			/**
			  * If the asset scene does not have any assets for the specified template type and
			  * a matching name string, NULL is returned.
			  */
			template < typename DataType >
			const Asset<DataType>* getAsset( const UTF8String& name ) const;
			
			
			
			
			/// Return a pointer to a list of assets of the specified template type.
			/**
			  * If the asset scene does not have any assets for the specified template type,
			  * NULL is returned.
			  */
			template < typename DataType >
			const ArrayList<Asset<DataType> >* getAssets() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Adding Methods
			
			
			
			
			/// Add the specified unnamed asset to this asset scene.
			/**
			  * The method returns whether or not adding the asset was successful.
			  */
			template < typename DataType >
			Bool addAsset( const Pointer<DataType>& asset );
			
			
			
			
			/// Add the specified asset to this asset scene, giving it the specified name string.
			/**
			  * This name string can be used to identify between asset instances of the
			  * same type. The method returns whether or not adding the asset was successful.
			  */
			template < typename DataType >
			Bool addAsset( const Pointer<DataType>& asset, const UTF8String& name );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Removing Methods
			
			
			
			
			/// Remove the specified asset from this asset scene if it exists.
			/**
			  * If the asset scene contains a asset which is equal in type and
			  * value to the specified asset, the asset is removed and
			  * TRUE is returned. Otherwise, FALSE is returned and the asset scene
			  * is unchanged.
			  */
			template < typename DataType >
			Bool removeAsset( const Pointer<DataType>& asset );
			
			
			
			
			/// Remove the asset with the specified name from this asset scene if it exists.
			/**
			  * If the asset scene contains a asset which is equal in type and
			  * has the specified name, the asset is removed and
			  * TRUE is returned. Otherwise, FALSE is returned and the asset scene
			  * is unchanged.
			  */
			template < typename DataType >
			Bool removeAsset();
			
			
			
			
			/// Remove all assets with the specified asset type from this asset scene.
			/**
			  * If the asset scene contains any assets that have the specified type,
			  * the assets are removed and TRUE is returned. Otherwise, FALSE is
			  * returned and the asset scene is unchanged.
			  */
			template < typename DataType >
			Bool removeAssets();
			
			
			
			
			/// Remove all assets from this asset scene.
			void clearAssets();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the name of this asset scene.
			RIM_INLINE const UTF8String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Return a reference to a string representing the name of this asset scene.
			RIM_INLINE void setName( const UTF8String& newName )
			{
				name = newName;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Description Accessor Methods
			
			
			
			
			/// Return a reference to a string representing the name of this asset scene.
			RIM_INLINE const UTF8String& getDescription() const
			{
				return description;
			}
			
			
			
			
			/// Return a reference to a string representing the name of this asset scene.
			RIM_INLINE void setDescription( const UTF8String& newDescription )
			{
				description = newDescription;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// The base class for a templated array of assets.
			class AssetArrayBase;
			
			
			
			
			/// A class which holds an array of assets of a given type.
			template < typename DataType >
			class AssetArray;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from Type object to asset type arrays of all of the assets in the asset scene.
			HashMap<AssetType,AssetArrayBase*> assets;
			
			
			
			
			/// The name for this asset scene.
			UTF8String name;
			
			
			
			
			/// A text description of this asset scene.
			UTF8String description;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		AssetArrayBase Class Defintion
//############		
//##########################################################################################
//##########################################################################################




class AssetScene:: AssetArrayBase
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this base asset array.
			virtual ~AssetArrayBase()
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Virtual Copy Method
			
			
			
			
			/// Return a copy of this asset array's concrete type.
			virtual AssetArrayBase* copy() const = 0;
			
			
			
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Accessor Methods
			
			
			
			
			/// Return a pointer to the array of assets which this array holds.
			/**
			  * The method attempts to convert the internal asset array to the given
			  * type. If the conversion fails, NULL is returned.
			  */
			template < typename DataType >
			RIM_INLINE ArrayList<Asset<DataType> >* getAssets();
			
			
			
			
			/// Return a const pointer to the array of assets which this array holds.
			/**
			  * The method attempts to convert the internal asset array to the given
			  * type. If the conversion fails, NULL is returned.
			  */
			template < typename DataType >
			RIM_INLINE const ArrayList<Asset<DataType> >* getAssets() const;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		AssetArray Class Defintion
//############		
//##########################################################################################
//##########################################################################################




template < typename DataType >
class AssetScene:: AssetArray : public AssetArrayBase
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			RIM_INLINE AssetArray( const Pointer<DataType>& asset )
				:	assets( 1 )
			{
				assets.add( asset );
			}
			
			
			
			
			RIM_INLINE AssetArray( const Pointer<DataType>& asset, const UTF8String& name )
				:	assets( 1 )
			{
				assets.add( Asset<DataType>( asset, name ) );
			}
			
			
			
			
			RIM_INLINE AssetArray( const Asset<DataType>& asset )
				:	assets( 1 )
			{
				assets.add( asset );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Virtual Copy Method
			
			
			
			
			/// Create and return a copy of this concrete type.
			virtual AssetArray<DataType>* copy() const
			{
				return util::construct<AssetArray<DataType> >( *this );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Asset Accessor Methods
			
			
			
			
			/// Return a pointer to the internal list of assets that this asset array stores.
			RIM_INLINE ArrayList<Asset<DataType> >* getAssets()
			{
				return &assets;
			}
			
			
			
			
			/// Return a const pointer to the internal list of assets that this asset array stores.
			RIM_INLINE const ArrayList<Asset<DataType> >* getAssets() const
			{
				return &assets;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the assets stored by this concrete asset array.
			ArrayList< Asset<DataType> > assets;
			
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Asset Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename DataType >
Asset<DataType>* AssetScene:: getAsset()
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase* const * base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
	{
		ArrayList<Asset<DataType> >* array = (*base)->getAssets<DataType>();
		
		if ( array != NULL && array->getSize() > 0 )
			return &array->getFirst();
	}
	
	return NULL;
}




template < typename DataType >
const Asset<DataType>* AssetScene:: getAsset() const
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase* const * base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
	{
		const ArrayList<Asset<DataType> >* array = (*base)->getAssets<DataType>();
		
		if ( array != NULL && array->getSize() > 0 )
			return &array->getFirst();
	}
	
	return NULL;
}




template < typename DataType >
Asset<DataType>* AssetScene:: getAsset( const UTF8String& name )
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase* const * base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
	{
		ArrayList<Asset<DataType> >* array = (*base)->getAssets<DataType>();
		
		if ( array != NULL )
		{
			const Size arraySize = array->getSize();
			
			for ( Index i = 0; i < arraySize; i++ )
			{
				if ( (*array)[i].getName() == name )
					return &(*array)[i];
			}
		}
	}
	
	return NULL;
}




template < typename DataType >
const Asset<DataType>* AssetScene:: getAsset( const UTF8String& name ) const
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase* const * base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
	{
		const ArrayList<Asset<DataType> >* array = (*base)->getAssets<DataType>();
		
		if ( array != NULL )
		{
			const Size arraySize = array->getSize();
			
			for ( Index i = 0; i < arraySize; i++ )
			{
				if ( array[i].getName() == name )
					return &array[i];
			}
		}
	}
	
	return NULL;
}




template < typename DataType >
const ArrayList<Asset<DataType> >* AssetScene:: getAssets() const
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase* const * base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
		return (*base)->getAssets<Asset<DataType> >();
	
	return NULL;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Asset List Accessor Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename DataType >
ArrayList<Asset<DataType> >* AssetScene::AssetArrayBase:: getAssets()
{
	AssetArray<DataType>* array = dynamic_cast<AssetArray<DataType>*>( this );
	
	if ( array != NULL )
		return array->getAssets();
	else
		return NULL;
}




template < typename DataType >
const ArrayList<Asset<DataType> >* AssetScene::AssetArrayBase:: getAssets() const
{
	const AssetArray<DataType>* array = dynamic_cast<const AssetArray<DataType>*>( this );
	
	if ( array != NULL )
		return array->getAssets();
	else
		return NULL;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Asset Add Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename DataType >
Bool AssetScene:: addAsset( const Pointer<DataType>& asset )
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase** base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
	{
		// Found an array of assets of this type.
		ArrayList<Asset<DataType> >* array = (*base)->getAssets<DataType>();
		
		// Check to see if the asset type conversion is correct. If so, add the new asset.
		if ( array != NULL )
			array->add( Asset<DataType>( asset ) );
		else
			return false;
	}
	else
	{
		// This type of asset does not yet exist in this asset scene.
		// Create a new one and add it to the map of assets.
		AssetArray<DataType>* newAssetArray = util::construct<AssetArray<DataType> >( asset );
		assets.add( type.getHashCode(), type, newAssetArray );
	}
	
	return true;
}




template < typename DataType >
Bool AssetScene:: addAsset( const Pointer<DataType>& asset, const UTF8String& name )
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase** base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
	{
		// Found an array of assets of this type.
		ArrayList<Asset<DataType> >* array = (*base)->getAssets<DataType>();
		
		// Check to see if the asset type conversion is correct. If so, add the new asset.
		if ( array != NULL )
			array->add( Asset<DataType>( asset, name ) );
		else
			return false;
	}
	else
	{
		// This type of asset does not yet exist in this asset scene.
		// Create a new one and add it to the map of assets.
		AssetArray<DataType>* newAssetArray = util::construct<AssetArray<DataType> >( asset, name );
		assets.add( type.getHashCode(), type, newAssetArray );
	}
	
	return true;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Asset Remove Methods
//############		
//##########################################################################################
//##########################################################################################




template < typename DataType >
Bool AssetScene:: removeAsset( const Pointer<DataType>& asset )
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase* const * base;
	
	if ( assets.find( type.getHashCode(), type, base ) )
	{
		ArrayList<Asset<DataType> >* array = (*base)->getAssets<DataType>();
		
		if ( array != NULL )
			return array->remove( asset );
		else
			return false;
	}
	else
		return false;
}




template < typename DataType >
Bool AssetScene:: removeAssets()
{
	const AssetType& type = AssetType::of<DataType>();
	AssetArrayBase* const * base;
	
	return assets.remove( type.getHashCode(), type );
}





//##########################################################################################
//****************************  End Rim Assets Namespace  **********************************
RIM_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ASSET_SCENE_H

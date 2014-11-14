/*
 *  rimGraphicsBone.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BONE_H
#define INCLUDE_RIM_GRAPHICS_BONE_H


#include "rimGraphicsShapesConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that stores information about a bone that makes up a skeleton.
class Bone : public Transformable
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new root bone with the specified name and bind transform.
			Bone( const String& newName, const Transform3& newBindTransform );
			
			
			
			
			/// Create a new bone with the specified name, bind transform, and parent bone index.
			Bone( const String& newName, const Transform3& newBindTransform, Index parentIndex );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bind Transform Accessor Methods
			
			
			
			
			/// Return a reference to the parent-relative bind transformation of this bone.
			RIM_INLINE const Transform3& getBindTransform() const
			{
				return bindTransform;
			}
			
			
			
			
			/// Set the parent-relative bind transformation of this bone.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			RIM_INLINE Bool setBindTransform( const Transform3& newBindTransform )
			{
				bindTransform = newBindTransform;
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bone Name Accessor Methods
			
			
			
			
			/// Return a reference to the name of this bone.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of this bone.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			RIM_INLINE Bool setName(const String& newName )
			{
				name = newName;
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bone Parent Accessor Methods
			
			
			
			
			/// Return the index of the parent of the bone at the specified index.
			/**
			  * The method returns INVALID_BONE_INDEX if there is no parent for that bone.
			  */
			RIM_INLINE Index getParentIndex() const
			{
				return parentIndex;
			}
			
			
			
			
			/// Set the index of the parent of the bone at the specified index in this skeleton.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			RIM_INLINE Bool setParentIndex( Index newParentIndex )
			{
				parentIndex = newParentIndex;
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The index used to indicate an invalid bone.
			static const Index INVALID_BONE_INDEX = Index(-1);
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The index of this parent of this bone in the skeleton.
			Index parentIndex;
			
			
			/// A string that stores the human-readable name of this bone.
			String name;
			
			
			/// The bind-pose transformation of this bone.
			Transform3 bindTransform;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BONE_H

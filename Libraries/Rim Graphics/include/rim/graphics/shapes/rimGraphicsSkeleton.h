/*
 *  rimGraphicsSkeleton.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 7/3/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SKELETON_H
#define INCLUDE_RIM_GRAPHICS_SKELETON_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsBone.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which encapsulates geometry and a material with which it should be rendered.
/**
  * A MeshGroup specifies its geometry relative to the origin of its parent
  * shape and does not have its own transformation.
  */
class Skeleton
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty skeleton with no bones.
			Skeleton();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bone Accessor Methods
			
			
			
			
			/// Return the number of bones there are in this skeleton.
			RIM_INLINE Size getBoneCount() const
			{
				return bones.getSize();
			}
			
			
			
			
			/// Return a pointer to the bone in this skeleton at the specified index.
			RIM_INLINE Pointer<Bone> getBone( Index boneIndex ) const
			{
				return bones[boneIndex];
			}
			
			
			
			
			/// Determine the index of the first bone in this skeleton with the specified name.
			/**
			  * The method places the bone index in the output parameter and returns TRUE
			  * if there is a bone with that name in the skeleton. If not, FALSE is returned
			  * indicating there was no bone with that name.
			  */
			Bool getBoneIndex( const String& boneName, Index& boneIndex ) const;
			
			
			
			
			/// Add a new bone to this skeleton with the specified name, bind transform (relative to parent), and parent index.
			/**
			  * The method returns the index of the new bone in this skeleton.
			  * There are no restrictions on the parent index range, since the parent index
			  * may reference bones that are not added to the skeleton yet.
			  * During skeleton updating, an out-of-range parent index is interpreted
			  * as INVALID_BONE_INDEX.
			  */
			Index addBone( const String& boneName, const Transform3& bindTransform,
							Index parentIndex = Bone::INVALID_BONE_INDEX );
			
			
			
			
			/// Remove the bone with the specified name from this skeleton.
			/**
			  * The method returns whether or not the bone was successfully removed.
			  * This method automatically adjusts all bone parent indices that are
			  * greater than the removed bone index so that the reflect the new bone
			  * indices.
			  */
			Bool removeBone( const String& boneName );
			
			
			
			
			/// Remove the bone at the specified index from this skeleton.
			/**
			  * The method returns whether or not the bone was successfully removed.
			  * This method automatically adjusts all bone parent indices that are
			  * greater than the removed bone index so that the reflect the new bone
			  * indices.
			  */
			Bool removeBone( Index boneIndex );
			
			
			
			
			/// Remove all bones from this skeleton.
			void clearBones();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bone Transform Accessor Methods
			
			
			
			
			/// Return a reference to the parent-relative transformation of the bone at the specified index.
			RIM_INLINE const Transform3& getBoneTransform( Index boneIndex ) const
			{
				return bones[boneIndex]->getTransform();
			}
			
			
			
			
			/// Set the parent-relative transformation of the bone at the specified index in this skeleton.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			RIM_INLINE Bool setBoneTransform( Index boneIndex, const Transform3& newTransform )
			{
				if ( boneIndex >= bones.getSize() )
					return false;
				
				bones[boneIndex]->setTransform( newTransform );
				
				return true;
			}
			
			
			
			
			/// Return a reference to the parent-relative bind transformation of the bone at the specified index.
			RIM_INLINE const Transform3& getBoneBindTransform( Index boneIndex ) const
			{
				return bones[boneIndex]->getBindTransform();
			}
			
			
			
			
			/// Set the parent-relative bind transformation of the bone at the specified index in this skeleton.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			RIM_INLINE Bool setBoneBindTransform( Index boneIndex, const Transform3& newTransform )
			{
				if ( boneIndex >= bones.getSize() )
					return false;
				
				bones[boneIndex]->setBindTransform( newTransform );
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bone Name Accessor Methods
			
			
			
			
			/// Return a reference to the name of the bone at the specified index.
			RIM_INLINE const String& getBoneName( Index boneIndex ) const
			{
				return bones[boneIndex]->getName();
			}
			
			
			
			
			/// Set the name of the bone at the specified index in this skeleton.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			RIM_INLINE Bool setBoneName( Index boneIndex, const String& newName )
			{
				if ( boneIndex >= bones.getSize() )
					return false;
				
				bones[boneIndex]->setName( newName );
				
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
			RIM_INLINE Index getBoneParent( Index boneIndex ) const
			{
				return bones[boneIndex]->getParentIndex();
			}
			
			
			
			
			/// Set the index of the parent of the bone at the specified index in this skeleton.
			/**
			  * The method returns whether or not the operation was successful.
			  */
			RIM_INLINE Bool setBoneParent( Index boneIndex, Index newParentIndex )
			{
				if ( boneIndex >= bones.getSize() )
					return false;
				
				bones[boneIndex]->setParentIndex( newParentIndex );
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bone Matrix Accessor Methods
			
			
			
			
			/// Return a reference to the bone-to-world transformation matrix of the bone at the specified index.
			RIM_FORCE_INLINE const Matrix4& getBoneMatrix( Index boneIndex ) const
			{
				return matrices[boneIndex];
			}
			
			
			
			
			/// Return a pointer to an array of bone-to-world transformation matrices for this skeleton's bones.
			RIM_FORCE_INLINE const Matrix4* getBoneMatrices() const
			{
				return matrices.getPointer();
			}
			
			
			
			
			/// Update the bone matrices for this skeleton.
			/**
			  * This method should be called once per frame before drawing any meshes
			  * that use this skeleton.
			  */
			void updateBoneMatrices();
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declarations
			
			
			
			
			/// A class that stores information about a bone that makes up a skeleton.
			class SkeletonBone : public Bone
			{
				public:
					
					/// Create a new bone with the specified name, bind transform, and parent index.
					RIM_INLINE SkeletonBone( const String& newName, const Transform3& newBindTransform, Index newParentIndex )
						:	Bone( newName, newBindTransform, newParentIndex ),
							timestamp( 0 )
					{
					}
					
					
					/// A timestamp index indicating whether or not this bone has updated its transformation matrx.
					Index timestamp;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the complete bone-to-world transformation matrix for the given bone.
			/**
			  * This method automatically recursively calls this method on any parent
			  * bones that have not yet been updated for the current timestamp.
			  */
			Matrix4 getBoneMatrix( Index boneIndex );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A list of the bones that are part of this skeleton.
			ArrayList< Pointer<SkeletonBone> > bones;
			
			
			
			
			/// A list of the current bone-to-world transformation matrices for all bones in this skeleton.
			ArrayList<Matrix4> matrices;
			
			
			
			
			/// The internal update timestamp that is used to keep track of which bone transformation matrices have been updated.
			Index timestamp;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SKELETON_H

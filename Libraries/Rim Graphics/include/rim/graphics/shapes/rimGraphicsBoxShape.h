/*
 *  rimGraphicsBoxShape.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 6/8/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_BOX_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_BOX_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeBase.h"
#include "rimGraphicsMeshShape.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides a simple means to draw a 3D oriented rectangular box.
/**
  * A box is specified by its width, height, and depth, as well as the position
  * of its center and the 3 orthonormal axis that define its orientation.
  *
  * This class handles all vertex and index buffer generation automatically,
  * simplifying the visualization of boxes, such as for collision geometry.
  */
class BoxShape : public GraphicsShapeBase<BoxShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a box shape for the given graphics context centered at the origin with width, height and depth = 1.
			BoxShape( const Pointer<GraphicsContext>& context );
			
			
			
			
			/// Create a box shape for the given graphics context with the specified local width, height, and depth.
			BoxShape( const Pointer<GraphicsContext>& context, Real width, Real height, Real depth );
			
			
			
			
			/// Create a box shape for the given graphics context with the specified position, width, height, and depth.
			BoxShape( const Pointer<GraphicsContext>& context, Real width, Real height, Real depth,
						const Vector3& newPosition );
			
			
			
			
			/// Create a box shape for the given graphics context with the specified position, orientation, width, height, and depth.
			BoxShape( const Pointer<GraphicsContext>& context, Real width, Real height, Real depth,
						const Vector3& newPosition, const Matrix3& newOrientation );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Set the 3D dimensions of this box in its local coordinate frame.
			RIM_FORCE_INLINE const Vector3& getSize() const
			{
				return size;
			}
			
			
			
			
			/// Set the 3D dimensions of this box in its local coordinate frame.
			RIM_INLINE void setSize( const Vector3& newSize )
			{
				size.x = math::max( newSize.x, Real(0) );
				size.y = math::max( newSize.y, Real(0) );
				size.z = math::max( newSize.z, Real(0) );
				updateMesh();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Width Accessor Methods
			
			
			
			
			/// Return the width (X size) of this box in its local coordinate frame.
			RIM_FORCE_INLINE Real getWidth() const
			{
				return size.x;
			}
			
			
			
			
			/// Set the width (X size) of this box in its local coordinate frame.
			/**
			  * This width value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setWidth( Real newWidth )
			{
				size.x = math::max( newWidth, Real(0) );
				updateMesh();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Height Accessor Methods
			
			
			
			
			/// Return the height (Y size) of this box in its local coordinate frame.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return size.y;
			}
			
			
			
			
			/// Set the height (Y size) of this box in its local coordinate frame.
			/**
			  * This height value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setHeight( Real newHeight )
			{
				size.y = math::max( newHeight, Real(0) );
				updateMesh();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Depth Accessor Methods
			
			
			
			
			/// Return the depth (Z size) of this box in its local coordinate frame.
			RIM_FORCE_INLINE Real getDepth() const
			{
				return size.z;
			}
			
			
			
			
			/// Set the depth (Z size) of this box in its local coordinate frame.
			/**
			  * This depth value is clamped to the range of [0,+infinity].
			  */
			RIM_INLINE void setDepth( Real newDepth )
			{
				size.z = math::max( newDepth, Real(0) );
				updateMesh();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Get the material of this cylinder shape.
			RIM_INLINE Pointer<Material>& getMaterial()
			{
				return material;
			}
			
			
			
			
			/// Get the material of this cylinder shape.
			RIM_INLINE const Pointer<Material>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this cylinder shape.
			RIM_INLINE void setMaterial( const Pointer<Material>& newMaterial )
			{
				material = newMaterial;
				updateMesh();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics contet which is being used to create this box shape.
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Change the graphics context which is used to create this box shape.
			/**
			  * Calling this method causes the previously generated box geometry to
			  * be discarded and regenerated using the new context.
			  */
			void setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mesh Accessor Methods
			
			
			
			
			/// Return a pointer to the mesh representation of this box.
			RIM_FORCE_INLINE const Pointer<MeshShape>& getMesh() const
			{
				return mesh;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Update the box's axis-aligned bounding box.
			virtual void updateBoundingBox();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Chunk Accessor Method
			
			
			
			
			/// Process the shape into a flat list of mesh chunk objects.
			/**
			  * This method flattens the shape hierarchy and produces mesh chunks
			  * for rendering from the specified camera's perspective. The method
			  * converts its internal representation into one or more MeshChunk
			  * objects which it appends to the specified output list of mesh chunks.
			  *
			  * The method returns whether or not the shape was successfully flattened
			  * into chunks.
			  */
			virtual Bool getChunks( const Transform3& worldTransform, const Camera& camera,
									const ViewVolume* viewVolume, const Vector2D<Size>& viewportSize,
									ArrayList<MeshChunk>& chunks ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Update the triangle mesh currently used for this box shape from its current state.
			void updateMesh();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The size of this box along each local coordinate axis.
			Vector3 size;
			
			
			
			
			/// The graphics context which is used to create this box shape.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// A pointer to the material to use when rendering this box shape.
			Pointer<Material> material;
			
			
			
			
			/// A pointer to a mesh shape which contains the visual representation for this box.
			Pointer<MeshShape> mesh;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_BOX_SHAPE_H

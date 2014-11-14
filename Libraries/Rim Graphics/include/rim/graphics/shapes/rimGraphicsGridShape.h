/*
 *  rimGraphicsGridShape.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 3/26/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GRID_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_GRID_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeBase.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides a simple means to draw an infinite 3D cartesian grid.
/**
  * The grid is by default infinite (to the edge of the view), but can also be
  * limited to a 3D rectangular region.
  *
  * This class handles all vertex and index buffer generation automatically,
  * simplifying the visualization of grids. The grid is automatically resized
  * so that it encompasses the entire view volume, but not much further.
  */
class GridShape : public GraphicsShapeBase<GridShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an infinite grid shape for the given graphics context.
			GridShape( const Pointer<GraphicsContext>& context );
			
			
			
			
			/// Create a grid shape for the given graphics context which covers the specified 3D region in local space.
			GridShape( const Pointer<GraphicsContext>& context, const AABB3& newBounds );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Grid Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D region of this grid in its local coordinate frame.
			RIM_FORCE_INLINE const AABB3& getBounds() const
			{
				return bounds;
			}
			
			
			
			
			/// Set the 3D region of this grid in its local coordinate frame.
			RIM_INLINE void setBounds( const AABB3& newBounds )
			{
				bounds = newBounds;
				updateMesh();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Grid Division Size Accessor Methods
			
			
			
			
			/// Return the spacing between major grid lines in the shape's local coordinate system.
			RIM_INLINE Real getMajorSpacing() const
			{
				return majorSpacing;
			}
			
			
			
			
			/// Set the spacing between major grid lines in the shape's local coordinate system.
			/**
			  * The new grid line spacing is clamped to be greater than or equal to 0.
			  */
			RIM_INLINE void setMajorSpacing( Real newMajorSpacing )
			{
				majorSpacing = math::max( newMajorSpacing, Real(0) );
				meshNeedsUpdate = true;
			}
			
			
			
			
			/// Return the spacing between minor grid lines in the shape's local coordinate system.
			RIM_INLINE Real getMinorSpacing() const
			{
				return minorSpacing;
			}
			
			
			
			
			/// Set the spacing between major grid lines in the shape's local coordinate system.
			/**
			  * The new grid line spacing is clamped to be greater than or equal to 0.
			  */
			RIM_INLINE void setMinorSpacing( Real newMinorSpacing )
			{
				minorSpacing = math::max( newMinorSpacing, Real(0) );
				meshNeedsUpdate = true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Grid Line Color Accessor Methods
			
			
			
			
			/// Return the color to use when drawing major grid lines.
			RIM_INLINE const Color4f& getMajorColor() const
			{
				return majorColor;
			}
			
			
			
			
			/// Set the color to use when drawing major grid lines.
			void setMajorColor( const Color4f& newMajorColor );
			
			
			
			
			/// Return the color to use when drawing minor grid lines.
			RIM_INLINE const Color4f& getMinorColor() const
			{
				return minorColor;
			}
			
			
			
			
			/// Set the color to use when drawing minor grid lines.
			void setMinorColor( const Color4f& newMinorColor );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Grid Line Width Accessor Methods
			
			
			
			
			/// Return the width in pixels to use when drawing major grid lines.
			RIM_INLINE Real getMajorWidth() const
			{
				return majorWidth;
			}
			
			
			
			
			/// Set the width in pixels to use when drawing major grid lines.
			/**
			  * The new line width is clamped to be at least 1 pixel.
			  */
			void setMajorWidth( Real newMajorWidth );
			
			
			
			
			/// Return the width in pixels to use when drawing minor grid lines.
			RIM_INLINE Real getMinorWidth() const
			{
				return minorWidth;
			}
			
			
			
			
			/// Set the width in pixels to use when drawing minor grid lines.
			/**
			  * The new line width is clamped to be at least 1 pixel.
			  */
			void setMinorWidth( Real newMinorWidth );
			
			
			
			
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
			
			
			
			
			static void generateGrid( const AABB3& gridBounds, Real division,
									HardwareBufferIterator<Vector3f>& positions );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The bounding box of the grid in the shape's local coordiante system.
			AABB3 bounds;
			
			
			
			
			/// The current bounding box of the visible grid mesh.
			mutable AABB3 meshBounds;
			
			
			
			
			/// The spacing in shape-local units between major grid lines.
			Real majorSpacing;
			
			
			
			
			/// The spacing in shape-local units between minor grid lines.
			Real minorSpacing;
			
			
			
			
			/// The width of major grid lines in pixels.
			Real majorWidth;
			
			
			
			
			/// The width of minor grid lines in pixels.
			Real minorWidth;
			
			
			
			
			/// The color to use when drawing major grid lines.
			Color4f majorColor;
			
			
			
			
			/// The color to use when drawing minor grid lines.
			Color4f minorColor;
			
			
			
			
			/// The graphics context which is used to create this box shape.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// The grid shape's major grid line material.
			Pointer<Material> majorMaterial;
			
			
			
			
			/// The grid shape's minor grid line material.
			Pointer<Material> minorMaterial;
			
			
			
			
			/// A vertex buffer list containing the current vertices for the grid.
			Pointer<VertexBufferList> vertexBufferList;
			
			
			
			
			/// A vertex buffer containing the positions of the grid vertices for both major and minor grid lines, in that order.
			Pointer<VertexBuffer> vertexPositions;
			
			
			
			
			/// The number of major grid line vertices in the vertex buffer.
			Size numMajorVertices;
			
			
			
			
			/// The number of minor grid line vertices in the vertex buffer.
			Size numMinorVertices;
			
			
			
			
			/// A boolean value indicating whether or not the grid mesh needs to be updated before it is drawn.
			Bool meshNeedsUpdate;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The default major grid line spacing.
			static const Real DEFAULT_MAJOR_DIVISION;
			
			
			
			
			/// The default minor grid line spacing.
			static const Real DEFAULT_MINOR_DIVISION;
			
			
			
			
			/// The default major grid line spacing in pixels.
			static const Real DEFAULT_MAJOR_WIDTH;
			
			
			
			
			/// The default minor grid line spacing in pixels.
			static const Real DEFAULT_MINOR_WIDTH;
			
			
			
			
			/// The default major grid line color.
			static const Color4f DEFAULT_MAJOR_COLOR;
			
			
			
			
			/// The default minor grid line color.
			static const Color4f DEFAULT_MINOR_COLOR;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GRID_SHAPE_H

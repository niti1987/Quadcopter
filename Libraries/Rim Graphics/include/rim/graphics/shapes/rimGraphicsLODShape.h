/*
 *  rimGraphicsLODShape.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/23/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_LOD_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_LOD_SHAPE_H


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
/// A shape type that allows the user to render an object with a varying level of detail.
/**
  * A level-of-detail shape specifies a sorted list of shapes that should be used
  * to render an object at different effective screen-space sizes. This allows
  * simplified representations to be used for distant objects and detailed representations
  * for nearby objects. The projected screen-space radius (in pixels) of the shape's bounding sphere
  * for a given camera is used to determine the level of detail to use.
  *
  * The LODShape allows the user to bias the level-of-detail determination by a
  * multiplying factor. This factor scales the screen-space radius used when determining
  * the optimal level of detail. For instance, a factor of 2.0 will result in the
  * shape being rendered with a level of detail suitable for double the actual
  * screen space radius. This can be used to control the overall quality of rendering
  * on a per-shape basis. For less powerful hardware, a factor less than 1 can be used
  * to lower the rendering workload at the expense of some loss in visual quality.
  */
class LODShape : public GraphicsShapeBase<LODShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an LOD shape with no levels of detail and an LOD bias of 1.
			LODShape();
			
			
			
			
			/// Create an LOD shape with the specified shape level of detail and an LOD bias of 1.
			LODShape( const Pointer<GraphicsShape>& newShape, Real newPixelRadius );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Level of Detail Accessor Methods
			
			
			
			
			/// Add a new level of detail shape which is used for the specified maximum on-screen pixel radius.
			/**
			  * If the required on-screen pixel radius of the shape's bounding sphere is smaller
			  * than the specified value but larger than the next smallest level of detail,
			  * the given shape is used to render this LOD shape.
			  *
			  * If the new level of detail shape is NULL, the method fails and FALSE is returned.
			  * Otherwise, the method succeeds, the new level of detail is added, and TRUE is returned.
			  */
			Bool addLevel( const Pointer<GraphicsShape>& newShape, Real newPixelRadius );
			
			
			
			
			/// Remove the level of detail at the specified index in this LOD shape.
			/**
			  * Levels are stored in reverse sorted order, with the largest level of detail
			  * first, index 0 corresponds to the largest level of detail.
			  */
			void removeLevel( Index i );
			
			
			
			
			/// Clear all levels of detail from this shape.
			void clearLevels();
			
			
			
			
			/// Get the number of levels of detail that this shape has.
			RIM_FORCE_INLINE Size getLevelCount() const
			{
				return levels.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Level of Detail Shape Accessor Methods
			
			
			
			
			/// Return a pointer to the shape for the level of detail at the specified index.
			/**
			  * Levels are stored in reverse sorted order, with the largest level of detail
			  * first, index 0 corresponds to the largest level of detail.
			  */
			RIM_INLINE Pointer<GraphicsShape>& getLevelShape( Index i )
			{
				RIM_DEBUG_ASSERT_MESSAGE( i < levels.getSize(), "Cannot get level of detail shape at invalid index." );
				
				return levels[levels.getSize() - i - 1].shape;
			}
			
			
			
			
			/// Return a pointer to the shape for the level of detail at the specified index.
			/**
			  * Levels are stored in reverse sorted order, with the largest level of detail
			  * first, index 0 corresponds to the largest level of detail.
			  */
			RIM_INLINE const Pointer<GraphicsShape>& getLevelShape( Index i ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( i < levels.getSize(), "Cannot get level of detail shape at invalid index." );
				
				return levels[levels.getSize() - i - 1].shape;
			}
			
			
			
			
			/// Set the shape for the level of detail at the specified index.
			/**
			  * Levels are stored in reverse sorted order, with the largest level of detail
			  * first, index 0 corresponds to the largest level of detail.
			  */
			RIM_INLINE Bool setLevelShape( Index i, const Pointer<GraphicsShape>& newShape )
			{
				RIM_DEBUG_ASSERT_MESSAGE( i < levels.getSize(), "Cannot set level of detail shape at invalid index." );
				
				if ( newShape.isNull() )
					return false;
				
				levels[levels.getSize() - i - 1].shape = newShape;
				
				return true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Level of Detail Pixel Radius Accessor Methods
			
			
			
			
			/// Return the maximum pixel radius for the level of detail at the specified index.
			/**
			  * Levels are stored in reverse sorted order, with the largest level of detail
			  * first, index 0 corresponds to the largest level of detail.
			  */
			RIM_INLINE Real getLevelPixelRadius( Index i ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( i < levels.getSize(),
										"Cannot get level of detail pixel radius at invalid index." );
				
				return levels[levels.getSize() - i - 1].maximumPixelRadius;
			}
			
			
			
			
			/// Get the maximum pixel radius for the level of detail at the specified index.
			/**
			  * Calling this method potentially reorders the level of details. Previously valid
			  * indices will not necessarily be valid after calling this method.
			  *
			  * Levels are stored in reverse sorted order, with the largest level of detail
			  * first, index 0 corresponds to the largest level of detail.
			  */
			void setLevelPixelRadius( Index i, Real newMaximumPixelRadius );
			
			
			
			
			/// Get the level of detail which should be used when the shape has the specified screen-space radius.
			Pointer<GraphicsShape> getLevelForPixelRadius( Real pixelRadius ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Level of Detail Bias Accessor Method
			
			
			
			
			/// Return a value which is used to multiplicatively bias the size of a pixel radius query.
			/**
			  * The default value is 1, indicating that no bias is applied. For instance,
			  * a bias of 0.5 means that any LOD query will be interpreted to have half the
			  * requested on-screen pixel radius.
			  */
			RIM_FORCE_INLINE Real getLODBias() const
			{
				return lodBias;
			}
			
			
			
			
			/// Set a value which is used to multiplicatively bias the size of a pixel radius query.
			/**
			  * The default value is 1, indicating that no bias is applied. For instance,
			  * a bias of 0.5 means that any LOD query will be interpreted to have half the
			  * requested on-screen pixel radius.
			  */
			RIM_FORCE_INLINE void setLODBias( Real newLODBias )
			{
				lodBias = math::max( newLODBias, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Update the level-of-detail shape's axis-aligned bounding box.
			virtual void updateBoundingBox();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Chunk Accessor Method
			
			
			
			
			/// Process the level-of-detail shape into a flat list of mesh chunk objects.
			/**
			  * This method chooses the best level of detail to use for the specified
			  * camera's viewpoint based on the projected screen-space radius of this
			  * shape's bounding sphere. The getChunks() method for that level of detail
			  * is then called to process it into mesh chunks.
			  */
			virtual Bool getChunks( const Transform3& worldTransform, const Camera& camera,
									const ViewVolume* viewVolume, const Vector2D<Size>& viewportSize,
									ArrayList<MeshChunk>& chunks ) const;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Level of Detail Class
			
			
			
			
			/// A class which represents a level of detail for this LODShape.
			class Level
			{
				public:
					
					/// Create a new level of detail with the specified shape and maximum pixel radius.
					RIM_FORCE_INLINE Level( const Pointer<GraphicsShape>& newShape, Real newMaximumPixelRadius )
						:	shape( newShape ),
							maximumPixelRadius( newMaximumPixelRadius )
					{
					}
					
					
					/// The shape to use for this level of detail.
					Pointer<GraphicsShape> shape;
					
					
					/// The maximum screen-space size of the bounding sphere of the LOD level where it should be used.
					Real maximumPixelRadius;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of the levels of detail for this LOD shape.
			ArrayList<Level> levels;
			
			
			
			
			/// A value which multiplicatively biases the size of the pixel radius query.
			/**
			  * A value of 1 will result in normal operation. A value less than 1
			  * will result in less-detailed levels being chosen. A value greater
			  * than 1 will result in higher-detailed levels being chosen.
			  */
			Real lodBias;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_LOD_SHAPE_H

/*
 *  rimGraphicsSphereShape.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 5/17/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SPHERE_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_SPHERE_SHAPE_H


#include "rimGraphicsShapesConfig.h"


#include "rimGraphicsShapeBase.h"
#include "rimGraphicsLODShape.h"


//##########################################################################################
//***********************  Start Rim Graphics Shapes Namespace  ****************************
RIM_GRAPHICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides a simple means to draw a 3D sphere shape.
/**
  * A sphere is specified by a position and radius.
  *
  * This class handles all vertex and index buffer generation automatically,
  * simplifying the visualization of spheres, such as for collision geometry.
  * Internally, this class automatically chooses the proper geometric level of
  * detail for the sphere representation in order to acheive nearly pixel-perfect
  * accuracy when rendering from any perspective.
  */
class SphereShape : public GraphicsShapeBase<SphereShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a sphere shape for the given graphics context centered at the origin with a radius of 1.
			SphereShape( const Pointer<GraphicsContext>& context );
			
			
			
			
			/// Create a sphere shape for the given graphics context centered at the origin with the specified radius.
			SphereShape( const Pointer<GraphicsContext>& context, Real radius );
			
			
			
			
			/// Create a sphere shape for the given graphics context with the specified position and radius.
			SphereShape( const Pointer<GraphicsContext>& context, const Vector3& newPosition, Real radius );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius Accessor Methods
			
			
			
			
			/// Get the radius of this sphere shape in local coordinates.
			RIM_FORCE_INLINE Real getRadius() const
			{
				return radius;
			}
			
			
			
			
			/// Set the radius of this sphere shape in local coordinates.
			/**
			  * The radius is clamed to the range of [0,+infinity).
			  */
			void setRadius( Real newRadius );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Get the material of this sphere shape.
			RIM_INLINE Pointer<Material>& getMaterial()
			{
				return material;
			}
			
			
			
			
			/// Get the material of this sphere shape.
			RIM_INLINE const Pointer<Material>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this sphere shape.
			RIM_INLINE void setMaterial( const Pointer<Material>& newMaterial )
			{
				material = newMaterial;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics contet which is being used to create this sphere shape.
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Change the graphics context which is used to create this sphere shape.
			/**
			  * Calling this method causes the previously generated sphere geometry to
			  * be discarded and regenerated using the new context.
			  */
			void setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Level of Detail Accessor Methods
			
			
			
			
			/// Get the level of detail which should be used when the sphere has the specified screen-space radius.
			Pointer<GraphicsShape> getLevelForPixelRadius( Real pixelRadius ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Level Of Detail Bias Accessor Methods
			
			
			
			
			/// Get a value which multiplicatively biases the size of a pixel radius query.
			RIM_INLINE Real getLODBias() const
			{
				return lodShape.getLODBias();
			}
			
			
			
			
			/// Set a value which multiplicatively biases the size of a pixel radius query.
			RIM_INLINE void setLODBias( Real newLODBias )
			{
				return lodShape.setLODBias( newLODBias );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Update the sphere's axis-aligned bounding box.
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
			
			
			
			
			/// Generate a sphere mesh instance with the specified subdivision level.
			/**
			  * The first subdivision level is an octahedron, and each addition subdivision
			  * level doubles the number of longitude and latitude division on the sphere,
			  * effectivly quadrupling the triangle count for each additional subdivision.
			  */
			static Pointer<GraphicsShape> getSubdivision( const Pointer<GraphicsContext>& context,
												const Pointer<Material>& material,
												Size subdivisionLevel );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The maximum allowed sphere subdivision.
			static const Size MAXIMUM_SUBDIVISION_LEVEL = 7;
			
			
			
			
			/// The predetermined pixel radii for the different subdivision levels.
			static const Real subdivisionPixelRadii[MAXIMUM_SUBDIVISION_LEVEL + 2];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The graphics context which is used to create this sphere shape.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// The sphere shape's material.
			Pointer<Material> material;
			
			
			
			
			/// An LODShape object that holds the levels of detail for this sphere.
			mutable LODShape lodShape;
			
			
			
			
			/// The largest amount that this sphere has been subdivided.
			mutable Size largestSubdivision;
			
			
			
			
			/// The radius of this sphere in shape-coordinates.
			Real radius;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SPHERE_SHAPE_H

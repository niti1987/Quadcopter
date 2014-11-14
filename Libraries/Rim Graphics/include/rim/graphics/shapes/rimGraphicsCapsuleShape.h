/*
 *  rimGraphicsCapsuleShape.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 7/2/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_CAPSULE_SHAPE_H
#define INCLUDE_RIM_GRAPHICS_CAPSULE_SHAPE_H


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
/// A class which provides a simple means to draw a 3D capsule shape.
/**
  * A capsule can be defined as two spheres that can have different radii, combined with a
  * cylinder that is tangent to the two spheres, creating a convex shape.
  *
  * This class handles all vertex and index buffer generation automatically,
  * simplifying the visualization of capsules, such as for collision geometry.
  * Internally, this class automatically chooses the proper geometric level of
  * detail for the capsule representation in order to acheive nearly pixel-perfect
  * accuracy when rendering from any perspective.
  */
class CapsuleShape : public GraphicsShapeBase<CapsuleShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a capsule shape for the given graphics context centered at the origin with a radius and height of 1.
			CapsuleShape( const Pointer<GraphicsContext>& context );
			
			
			
			
			/// Create a capsule shape for the given graphics context with the specified endpoints and radius.
			CapsuleShape( const Pointer<GraphicsContext>& context,
						const Vector3& newEndpoint1, const Vector3& newEndpoint2, Real newRadius );
			
			
			
			
			/// Create a capsule shape for the given graphics context with the specified endpoints and radii.
			CapsuleShape( const Pointer<GraphicsContext>& context,
							const Vector3& newEndpoint1, const Vector3& newEndpoint2,
							Real newRadius1, Real newRadius2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Endpoint Accessor Methods
			
			
			
			
			/// Return a const reference to the center of this capsule shape's first endcap in local coordinates.
			RIM_FORCE_INLINE const Vector3& getEndpoint1() const
			{
				return endpoint1;
			}
			
			
			
			
			/// Set the center of this capsule shape's first endcap in local coordinates.
			void setEndpoint1( const Vector3& newEndpoint1 );
			
			
			
			
			/// Return a const reference to the center of this capsule shape's second endcap in local coordinates.
			RIM_FORCE_INLINE const Vector3& getEndpoint2() const
			{
				return endpoint2;
			}
			
			
			
			
			/// Set the center of this capsule shape's second endcap in local coordinates.
			void setEndpoint2( const Vector3& newEndpoint2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Axis Accessor Methods
			
			
			
			
			/// Return a normalized axis vector for this capsule, directed from endpoint 1 to endpoint 2.
			RIM_FORCE_INLINE const Vector3& getAxis() const
			{
				return axis;
			}
			
			
			
			
			/// Set a normalized axis vector for this capsule, directed from endpoint 1 to endpoint 2.
			/**
			  * Setting this capsule's axis keeps the capsule's first endpoint stationary in shape
			  * space and moves the second endpoint based on the new axis and capsule's height.
			  */
			void setAxis( const Vector3& newAxis );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Height Accessor Methods
			
			
			
			
			/// Get the distance between the endpoints of this capsule shape in local coordinates.
			RIM_FORCE_INLINE Real getHeight() const
			{
				return height;
			}
			
			
			
			
			/// Set the distance between the endpoints of this capsule shape in local coordinates.
			/**
			  * The value is clamed to the range of [0,+infinity). Setting this height value
			  * causes the cylilnder's second endpoint to be repositioned, keeping the first
			  * endpoint stationary, based on the capsule's current axis vector.
			  */
			void setHeight( Real newHeight );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius Accessor Methods
			
			
			
			
			/// Get the first endcap radius of this capsule shape in local coordinates.
			RIM_FORCE_INLINE Real getRadius1() const
			{
				return radius1;
			}
			
			
			
			
			/// Set the first endcap radius of this capsule shape in local coordinates.
			/**
			  * The radius is clamed to the range of [0,+infinity).
			  */
			void setRadius1( Real newRadius1 );
			
			
			
			
			/// Get the second endcap radius of this capsule shape in local coordinates.
			RIM_FORCE_INLINE Real getRadius2() const
			{
				return radius2;
			}
			
			
			
			
			/// Set the second endcap radius of this capsule shape in local coordinates.
			/**
			  * The radius is clamed to the range of [0,+infinity).
			  */
			void setRadius2( Real newRadius2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Material Accessor Methods
			
			
			
			
			/// Get the material of this capsule shape.
			RIM_INLINE Pointer<Material>& getMaterial()
			{
				return material;
			}
			
			
			
			
			/// Get the material of this capsule shape.
			RIM_INLINE const Pointer<Material>& getMaterial() const
			{
				return material;
			}
			
			
			
			
			/// Set the material of this capsule shape.
			RIM_INLINE void setMaterial( const Pointer<Material>& newMaterial )
			{
				material = newMaterial;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics contet which is being used to create this capsule shape.
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Change the graphics context which is used to create this capsule shape.
			/**
			  * Calling this method causes the previously generated capsule geometry to
			  * be discarded and regenerated using the new context.
			  */
			void setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Level of Detail Accessor Methods
			
			
			
			
			/// Get the level of detail which should be used when the capsule has the specified screen-space radius.
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
			
			
			
			
			/// Update the capsule's axis-aligned bounding box.
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
			
			
			
			
			/// Generate a capsule mesh instance with the specified subdivision level and material.
			/**
			  * The first subdivision level is a square capsule, and each addition subdivision
			  * level doubles the number of radial division on the sphere,
			  * effectivly doubling the triangle count for each additional subdivision.
			  */
			Pointer<GraphicsShape> getSubdivision( Size subdivisionLevel ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// The maximum allowed capsule subdivision.
			static const Size MAXIMUM_SUBDIVISION_LEVEL = 7;
			
			
			
			
			/// The predetermined pixel radii for the different subdivision levels.
			static const Real subdivisionPixelRadii[MAXIMUM_SUBDIVISION_LEVEL + 2];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The center of the first circular cap of this capsule in shape coordinates.
			Vector3 endpoint1;
			
			
			
			
			/// The center of the second circular cap of this capsule in shape coordiantes.
			Vector3 endpoint2;
			
			
			
			
			/// The normalized axis vector for this capsule in shape coordinates.
			Vector3 axis;
			
			
			
			
			/// The radius of the first endcap of this sphere in shape coordinates.
			Real radius1;
			
			
			
			
			/// The radius of the second endcap of this sphere in shape coordinates.
			Real radius2;
			
			
			
			
			/// The distance from one endpoint to another.
			Real height;
			
			
			
			
			/// The largest amount that this capsule has been subdivided.
			mutable Size largestSubdivision;
			
			
			
			
			/// The graphics context which is used to create this capsule shape.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// The capsule shape's material.
			Pointer<Material> material;
			
			
			
			
			/// An LODShape object that holds the levels of detail for this capsule.
			mutable LODShape lodShape;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shapes Namespace  ******************************
RIM_GRAPHICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_CAPSULE_SHAPE_H

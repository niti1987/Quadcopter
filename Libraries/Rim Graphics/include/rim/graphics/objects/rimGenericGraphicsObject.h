/*
 *  rimGenericGraphicsObject.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 2/16/14.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GENERIC_GRAPHICS_OBJECT_H
#define INCLUDE_RIM_GENERIC_GRAPHICS_OBJECT_H


#include "rimGraphicsObjectsConfig.h"


#include "rimGraphicsObjectFlags.h"


//##########################################################################################
//************************  Start Rim Graphics Objects Namespace  **************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class that describes a hierarchy of shapes and their transformations.
class GenericGraphicsObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default object with no shape centered at the origin.
			GenericGraphicsObject();
			
			
			
			
			/// Create an object with no shape and the specified transformation.
			GenericGraphicsObject( const Transformation3& newTransformation );
			
			
			
			
			/// Create an object centered at the origin with the specified shape.
			GenericGraphicsObject( const Pointer<GenericShape>& newShape );
			
			
			
			
			/// Create an object with the specified shape and transformation.
			GenericGraphicsObject( const Pointer<GenericShape>& newShape, const Transformation3& newTransformation );
			
			
			
			
			/// Create an object with the specified shape, transformation, and child objects.
			GenericGraphicsObject( const Pointer<GenericShape>& newShape, const Transformation3& newTransformation,
									const ArrayList< Pointer<GenericGraphicsObject> >& newChildren );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a generic graphics object.
			virtual ~GenericGraphicsObject();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transformation Accessor Methods
			
			
			
			
			/// Get the position of this object relative to the origin in its coordinate space.
			RIM_INLINE const Vector3& getPosition() const
			{
				return transformation.position;
			}
			
			
			
			
			/// Set the position of this object relative to the origin in its coordinate space.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				transformation.position = newPosition;
			}
			
			
			
			
			/// Get the orientation of the object.
			RIM_INLINE const Matrix3& getOrientation() const
			{
				return transformation.orientation;
			}
			
			
			
			
			/// Set the orientation of the object.
			RIM_NO_INLINE void setOrientation( const Matrix3& newOrientation )
			{
				transformation.orientation = newOrientation.orthonormalize();
			}
			
			
			
			
			/// Get the scale of the object.
			RIM_INLINE Real getScale() const
			{
				return transformation.scale;
			}
			
			
			
			
			/// Set the scale of the object.
			RIM_INLINE void setScale( Real newScale )
			{
				transformation.scale = newScale;
			}
			
			
			
			
			/// Get the transformation of this object relative to the origin in its coordinate space.
			RIM_INLINE const Transformation3& getTransformation() const
			{
				return transformation;
			}
			
			
			
			
			/// Set the transformation of this object relative to the origin in its coordinate space.
			RIM_INLINE void setTransformation( const Transformation3& newTransformation )
			{
				transformation = newTransformation;
			}
			
			
			
			
			/// Return a 4x4 matrix representing the transformation from object to world space.
			Matrix4 getTransformationMatrix() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Accessor Methods
			
			
			
			
			/// Return the number of shapes that this object has.
			RIM_FORCE_INLINE Size getShapeCount() const
			{
				return shapes.getSize();
			}
			
			
			
			
			/// Return a pointer to the shape for this object at the specified index.
			RIM_FORCE_INLINE const Pointer<GenericShape>& getShape( Index shapeIndex ) const
			{
				return shapes[shapeIndex];
			}
			
			
			
			
			/// Set the shape for this object at the specified index.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the new shape pointer is NULL.
			  */
			Bool addShape( const Pointer<GenericShape>& newShape );
			
			
			
			
			/// Set the shape for this object at the specified index.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the new shape pointer is NULL.
			  */
			RIM_INLINE Bool setShape( Index shapeIndex, const Pointer<GenericShape>& newShape )
			{
				if ( shapeIndex >= shapes.getSize() || newShape.isNull() )
					return false;
				
				shapes[shapeIndex] = newShape;
				
				return true;
			}
			
			
			
			
			/// Remove the shape from this object at the specified index.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the specified index is out of bounds.
			  */
			Bool removeShape( Index shapeIndex );
			
			
			
			
			/// Remove the specified shape from this object.
			/**
			  * @return whether or not the shape was successfully found and removed.
			  */
			Bool removeShape( const Pointer<GenericShape>& shape );
			
			
			
			
			/// Remove all shapes from this object.
			void clearShapes();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Child Object Accessor Methods
			
			
			
			
			/// Return the number of child objects that this object has.
			RIM_FORCE_INLINE Size getChildCount() const
			{
				return children.getSize();
			}
			
			
			
			
			/// Return a pointer to the child object at the specified index.
			RIM_FORCE_INLINE const Pointer<GenericGraphicsObject>& getChild( Index childIndex ) const
			{
				return children[childIndex];
			}
			
			
			
			
			/// Add a child object to this graphics object.
			/**
			  * The method returns whether or not the add operation was successful.
			  * The method fails if the specified new child pointer is NULL.
			  */
			Bool addChild( const Pointer<GenericGraphicsObject>& child );
			
			
			
			
			/// Remove the child object from this object at the specified index.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the specified index is out of bounds.
			  */
			Bool removeChild( Index childIndex );
			
			
			
			
			/// Remove the specified child object from this object.
			/**
			  * @return whether or not the child object was successfully found and removed.
			  */
			Bool removeChild( const Pointer<GenericGraphicsObject>& child );
			
			
			
			
			/// Remove all children from this graphics object.
			void clearChildren();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Accessor Methods
			
			
			
			
			/// Return a reference to an object which contains boolean parameters of the graphics object.
			RIM_INLINE GraphicsObjectFlags& getFlags()
			{
				return flags;
			}
			
			
			
			
			/// Return an object which contains boolean parameters of the graphics object.
			RIM_INLINE const GraphicsObjectFlags& getFlags() const
			{
				return flags;
			}
			
			
			
			
			/// Set an object which contains boolean parameters of the graphics object.
			RIM_INLINE void setFlags( const GraphicsObjectFlags& newFlags )
			{
				flags = newFlags;
			}
			
			
			
			
			/// Return whether or not the specified boolan flag is set for this graphics object.
			RIM_INLINE Bool flagIsSet( GraphicsObjectFlags::Flag flag ) const
			{
				return flags.isSet( flag );
			}
			
			
			
			
			/// Set whether or not the specified boolan flag is set for this graphics object.
			RIM_INLINE void setFlag( GraphicsObjectFlags::Flag flag, Bool newIsSet = true )
			{
				flags.set( flag, newIsSet );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibility Accessor Methods
			
			
			
			
			/// Get whether or not the object and its children are visible in the scene.
			RIM_INLINE Bool getIsVisible() const
			{
				return flags.isSet( GraphicsObjectFlags::VISIBLE );
			}
			
			
			
			
			/// Set whether or not the object and its children are visible in the scene.
			RIM_INLINE void setIsVisible( Bool newIsVisible )
			{
				flags.set( GraphicsObjectFlags::VISIBLE, newIsVisible );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Visibility Accessor Methods
			
			
			
			
			/// Get whether or not this object and all of its children can cast shadows.
			RIM_INLINE Bool getShadowsEnabled() const
			{
				return flags.isSet( GraphicsObjectFlags::SHADOWS_ENABLED );
			}
			
			
			
			
			/// Set whether or not this object and all of its children can cast shadows.
			RIM_INLINE void setShadowsEnabled( Bool newCanCastShadows )
			{
				flags.set( GraphicsObjectFlags::SHADOWS_ENABLED, newCanCastShadows );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Accessor Methods
			
			
			
			
			/// Return a bounding sphere encompasing this object and all child objects.
			BoundingSphere getBoundingSphere() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Name Accessor Methods
			
			
			
			
			/// Return the name of the graphics object.
			RIM_INLINE const String& getName() const
			{
				return name;
			}
			
			
			
			
			/// Set the name of the graphics object.
			RIM_INLINE void setName( const String& newName )
			{
				name = newName;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Static Data Members
			
			
			
			
			/// An integer which contains the default boolean flags for a graphics object.
			static const UInt32 DEFAULT_FLAGS = GraphicsObjectFlags::VISIBLE | GraphicsObjectFlags::SHADOWS_ENABLED;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object representing the transformation from object space to world space.
			Transformation3 transformation;
			
			
			
			
			/// A list of pointers to the shapes of this object.
			ShortArrayList< Pointer<GenericShape>, 2 > shapes;
			
			
			
			
			/// A list of child objects which form a hierarchy of transformations.
			ShortArrayList< Pointer<GenericGraphicsObject>, 2 > children;
			
			
			
			
			/// An object which contains boolean flags for this graphics object.
			GraphicsObjectFlags flags;
			
			
			
			
			/// A name for this generic graphics object.
			String name;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Objects Namespace  ****************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GENERIC_GRAPHICS_OBJECT_H

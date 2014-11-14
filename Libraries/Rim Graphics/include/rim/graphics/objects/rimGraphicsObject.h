/*
 *  rimGraphicsObject.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OBJECT_H
#define INCLUDE_RIM_GRAPHICS_OBJECT_H


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
class GraphicsObject : public Transformable
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default object with no shape centered at the origin.
			GraphicsObject();
			
			
			
			
			/// Create an object with no shape and the specified transformation.
			GraphicsObject( const Transform3& newTransform );
			
			
			
			
			/// Create an object centered at the origin with the specified shape.
			GraphicsObject( const Pointer<GraphicsShape>& newShape );
			
			
			
			
			/// Create an object with the specified shape and transformation.
			GraphicsObject( const Pointer<GraphicsShape>& newShape, const Transform3& newTransform );
			
			
			
			
			/// Create an object with the specified shape, transformation, and child objects.
			GraphicsObject( const Pointer<GraphicsShape>& newShape, const Transform3& newTransform,
							const ArrayList< Pointer<GraphicsObject> >& newChildren );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a graphics object.
			virtual ~GraphicsObject();
			
			
			
			
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
			RIM_FORCE_INLINE const Pointer<GraphicsShape>& getShape( Index shapeIndex ) const
			{
				return shapes[shapeIndex];
			}
			
			
			
			
			/// Set the shape for this object at the specified index.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the new shape pointer is NULL.
			  */
			Bool addShape( const Pointer<GraphicsShape>& newShape );
			
			
			
			
			/// Set the shape for this object at the specified index.
			/**
			  * The method returns whether or not the operation was successful.
			  * The method fails if the new shape pointer is NULL.
			  */
			RIM_INLINE Bool setShape( Index shapeIndex, const Pointer<GraphicsShape>& newShape )
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
			Bool removeShape( const Pointer<GraphicsShape>& shape );
			
			
			
			
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
			RIM_FORCE_INLINE const Pointer<GraphicsObject>& getChild( Index childIndex ) const
			{
				return children[childIndex];
			}
			
			
			
			
			/// Add a child object to this graphics object.
			/**
			  * The method returns whether or not the add operation was successful.
			  * The method fails if the specified new child pointer is NULL.
			  */
			Bool addChild( const Pointer<GraphicsObject>& child );
			
			
			
			
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
			Bool removeChild( const Pointer<GraphicsObject>& child );
			
			
			
			
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
			
			
			
			
			/// Get whether or not this object can cast shadows.
			RIM_INLINE Bool getShadowsEnabled() const
			{
				return flags.isSet( GraphicsObjectFlags::SHADOWS_ENABLED );
			}
			
			
			
			
			/// Set whether or not this object can cast shadows.
			RIM_INLINE void setShadowsEnabled( Bool newCanCastShadows )
			{
				flags.set( GraphicsObjectFlags::SHADOWS_ENABLED, newCanCastShadows );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Volume Accessor Methods
			
			
			
			
			/// Update this object's bounding box.
			/**
			  * This method uses the current bounding boxes for all child objects and shapes
			  * to compute a new bounding box for this object in its parent coordinate frame.
			  * This method does not update the bounding boxes for each shape that is part of
			  * this object, but it does recursively call updateBoundingBox() on all child
			  * objects so that the entire object hierarchy is updated with one method call.
			  */
			virtual void updateBoundingBox();
			
			
			
			
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
			
			
			
			
			/// A list of pointers to the shapes of this object.
			ShortArrayList< Pointer<GraphicsShape>, 2 > shapes;
			
			
			
			
			/// A list of child objects which form a hierarchy of transformations.
			ShortArrayList< Pointer<GraphicsObject>, 2 > children;
			
			
			
			
			/// An object which contains boolean flags for this graphics object.
			GraphicsObjectFlags flags;
			
			
			
			
			/// A name for this graphics object.
			String name;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics Objects Namespace  ****************************
RIM_GRAPHICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OBJECT_H

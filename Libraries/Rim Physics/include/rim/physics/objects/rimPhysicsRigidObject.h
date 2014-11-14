/*
 *  rimPhysicsRigidObject.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 11/28/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_RIGID_OBJECT_H
#define INCLUDE_RIM_PHYSICS_RIGID_OBJECT_H


#include "rimPhysicsObjectsConfig.h"


//##########################################################################################
//***********************  Start Rim Physics Objects Namespace  ****************************
RIM_PHYSICS_OBJECTS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a physically-based rigid object in 3D space.
class RigidObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default rigid object centered at the origin with no shape.
			RigidObject();
			
			
			
			
			/// Create a rigid object with the specified shape centered at the origin.
			RigidObject( const CollisionShape* newShape );
			
			
			
			
			/// Create a copy of this rigid object, duplicating all state.
			RigidObject( const RigidObject& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this rigid object and all state it contains.
			virtual ~RigidObject();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the state of one rigid object to this rigid object.
			RigidObject& operator = ( const RigidObject& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Shape Accessor Methods
			
			
			
			
			/// Add a collision shape to this object.
			/**
			  * This method creates an instance of the specified shape and stores the
			  * instance, rather than the original shape. This can avoid duplication
			  * of collision data, as only one object must have the transformed collision data.
			  * Thus, it is up to the user to allocate and store CollisionShape objects.
			  * NULL shapes are not allowed. Attempting to add a NULL shape will have no effect.
			  *
			  * Setting the object's shape also causes it to use the inertia tensor, mass, and local
			  * center of mass from the shape if the tensor and/or mass have not already been
			  * specifically set.
			  */
			void addShape( const CollisionShape* newShape );
			
			
			
			
			/// Remove the specified shape from this rigid object.
			/**
			  * If the specified shape is used by this rigid object, it is removed
			  * from the object and TRUE is returned. Otherwise, the object
			  * is unchanged and FALSE is returned.
			  */
			Bool removeShape( const CollisionShape* shape );
			
			
			
			
			/// Remove all shapes from this rigid object.
			void removeShapes();
			
			
			
			
			/// Return a const pointer to the shape of this rigid object at the specified index.
			RIM_INLINE const CollisionShape* getShape( Index shapeIndex ) const
			{
				if ( shapeIndex < shapeInstances.getSize() )
					return shapeInstances[shapeIndex]->getShape();
				else
					return NULL;
			}
			
			
			
			
			/// Return a pointer to this object's shape, instanced into world space.
			/**
			  * If necessary, this method updates the current state of this object's
			  * collision shape instance in order to reflect the object's current
			  * transformation. If the object has no shape, a NULL pointer is returned.
			  */
			RIM_INLINE const CollisionShapeInstance* getShapeInstance( Index shapeIndex ) const
			{
				if ( shapeIndex < shapeInstances.getSize() )
				{
					if ( shapesNeedNewTransform )
						updateShapeTransforms();
					
					return shapeInstances[shapeIndex];
				}
				else
					return NULL;
			}
			
			
			
			
			/// Return the number of shapes that this rigid object has.
			RIM_INLINE Size getShapeCount() const
			{
				return shapeInstances.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Bounding Sphere Accessor Methods
			
			
			
			
			/// Return a const reference to the bounding sphere for this object in world space
			RIM_INLINE const BoundingSphere& getBoundingSphere() const
			{
				if ( shapesNeedNewTransform )
					updateShapeTransforms();
				
				return boundingSphere;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Position Accessor Methods
			
			
			
			
			/// Return the position of this rigid object in world space.
			RIM_INLINE const Vector3& getPosition() const
			{
				return transform.position;
			}
			
			
			
			
			/// Set the position of this rigid object in world space.
			RIM_INLINE void setPosition( const Vector3& newPosition )
			{
				centerOfMass = newPosition + (centerOfMass - transform.position);
				transform.position = newPosition;
				shapesNeedNewTransform = true;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Return a reference to this object's 3x3 orthonormal rotation matrix.
			/**
			  * This is the orthonormal matrix which defines the rotational transformation
			  * from object to world space.
			  */
			RIM_INLINE const Matrix3& getOrientation() const
			{
				return transform.orientation;
			}
			
			
			
			
			/// Set this object's 3x3 orthonormal rotation matrix.
			/**
			  * This is the orthonormal matrix which defines the rotational transformation
			  * from object to world space. The incoming orientation marix is automatically
			  * orthonormalized using Grahm-Schmidt orthonormalization. This method
			  * keeps the object's position stationary in world space and rotates
			  * everything else (center of mass, inertia tensor).
			  */
			void setOrientation( const Matrix3& newOrientation );
			
			
			
			
			/// Set this object's 3x3 orthonormal rotation matrix relative to the object's center of mass.
			/**
			  * This is the orthonormal matrix which defines the rotational transformation
			  * from object to world space. The incoming orientation marix is automatically
			  * orthonormalized using Grahm-Schmidt orthonormalization. This method
			  * keeps the object's center of mass stationary in world space and rotates
			  * everything else.
			  */
			void setCenterOfMassOrientation( const Matrix3& newCOMOrientation );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Transform Accessor Methods
			
			
			
			
			/// Return a const reference to this object's transformation.
			/**
			  * This indicates the rigid transformation for this object,
			  * allowing translation, rotation, and uniform scaling.
			  */
			RIM_FORCE_INLINE const Transform3& getTransform() const
			{
				return transform;
			}
			
			
			
			
			/// Set this object's transformation.
			/**
			  * This indicates the rigid transformation for this object,
			  * allowing translation, rotation, and uniform scaling.
			  */
			void setTransform( const Transform3& newTransform );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Scale Accessor Methods
			
			
			
			
			/// Return the multiplicative scale of this object.
			/**
			  * A value of 1 means that no scaling occurrs. A value greater than
			  * 1 will increase the size of the object, while a value less than 1
			  * will decrease the size of the object.
			  */
			RIM_FORCE_INLINE const Vector3& getScale() const
			{
				return transform.scale;
			}
			
			
			
			
			/// Set the multiplicative scale of this object.
			/**
			  * A value of 1 means that no scaling occurrs. A value greater than
			  * 1 will increase the size of the object, while a value less than 1
			  * will decrease the size of the object. The input scaling factor
			  * is clamped to the range of [0,+infinity]. Setting the scale
			  * keeps the object's position fixed in world space, potentially
			  * moving its word-space center of mass. The object's world-space
			  * inertia tensor is also recalculated to take the object's new scale
			  * into account.
			  */
			void setScale( Real newScale );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Center of Mass Accessor Methods
			
			
			
			
			/// Return the position of this object's center of mass in world space.
			RIM_FORCE_INLINE const Vector3& getCenterOfMass() const
			{
				return centerOfMass;
			}
			
			
			
			
			/// Set the position of this object's center of mass in world space.
			/**
			  * A call to this method moves the object (changing its position)
			  * without changing its orientation so that it's object-space center
			  * of mass is coincident with the specified world-space center of mass position.
			  */
			RIM_INLINE void setCenterOfMass( const Vector3& newCenterOfMass )
			{
				// Update the world-space position of this object based on the new center of mass position.
				transform.position = newCenterOfMass + transform.position - centerOfMass;
				centerOfMass = newCenterOfMass;
				shapesNeedNewTransform = true;
			}
			
			
			
			
			/// Return the position of this object's center of mass in object space.
			RIM_INLINE Vector3 getLocalCenterOfMass() const
			{
				return transform.transformToObjectSpace( centerOfMass );
			}
			
			
			
			
			/// Set the position of this object's center of mass in local object space.
			/**
			  * This method does not move the object, but instead changes where the
			  * center of mass of the object is located, relative to the origin in
			  * object space.
			  */
			RIM_INLINE void setLocalCenterOfMass( const Vector3& newLocalCenterOfMass )
			{
				centerOfMass = transform.transformToWorldSpace( newLocalCenterOfMass );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Velocity Accessor Methods
			
			
			
			
			/// Return the linear velocity of this rigid object in world units per second.
			RIM_INLINE const Vector3& getVelocity() const
			{
				return velocity;
			}
			
			
			
			
			/// Set the linear velocity of this rigid object in world units per second.
			RIM_INLINE void setVelocity( const Vector3& newVelocity )
			{
				velocity = newVelocity;
			}
			
			
			
			
			/// Get a temporary bias for this object's velocity used to correct constraint error.
			/**
			  * This velocity vector is zeroed out every frame so that it doesn't affect
			  * the object's kinetic energy, unlike normal linear velocity.
			  */
			RIM_INLINE const Vector3& getBiasVelocity() const
			{
				return biasVelocity;
			}
			
			
			
			
			/// Set a temporary bias for this object's velocity used to correct constraint error.
			/**
			  * This velocity vector is zeroed out every frame so that it doesn't affect
			  * the object's kinetic energy, unlike normal linear velocity.
			  */
			RIM_INLINE void setBiasVelocity( const Vector3& newBiasVelocity )
			{
				biasVelocity = newBiasVelocity;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radial Velocity Accessor Methods
			
			
			
			
			/// Return the linear velocity of this rigid object at the specified point relative to its center of mass.
			RIM_INLINE Vector3 getVelocityAtPoint( const Vector3& point ) const
			{
				if ( isStatic )
					return Vector3::ZERO;
				
				return velocity + math::cross( angularVelocity, point );
			}
			
			
			
			
			/// Return the bias linear velocity of this rigid object at the specified point relative to its center of mass.
			RIM_INLINE Vector3 getBiasVelocityAtPoint( const Vector3& point ) const
			{
				if ( isStatic )
					return Vector3::ZERO;
				
				return biasVelocity + math::cross( biasAngularVelocity, point );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Angular Velocity Accessor Methods
			
			
			
			
			/// Return the angular velocity of this rigid object in radians per second.
			RIM_INLINE const Vector3& getAngularVelocity() const
			{
				return angularVelocity;
			}
			
			
			
			
			/// Set the angular velocity of this rigid object in radians per second.
			RIM_INLINE void setAngularVelocity( const Vector3& newAngularVelocity )
			{
				angularVelocity = newAngularVelocity;
			}
			
			
			
			
			/// Get a temporary bias for this object's angular velocity used to correct constraint error.
			/**
			  * This angular velocity vector is zeroed out every frame so that it doesn't affect
			  * the object's kinetic energy, unlike normal angular velocity.
			  */
			RIM_INLINE const Vector3& getBiasAngularVelocity() const
			{
				return biasAngularVelocity;
			}
			
			
			
			
			/// Set a temporary bias for this object's angular velocity used to correct constraint error.
			/**
			  * This angular velocity vector is zeroed out every frame so that it doesn't affect
			  * the object's kinetic energy, unlike normal angular velocity.
			  */
			RIM_INLINE void setBiasAngularVelocity( const Vector3& newBiasAngularVelocity )
			{
				biasAngularVelocity = newBiasAngularVelocity;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Impulse Application Methods
			
			
			
			
			/// Apply the specified impulse vector at a point relative to the object's center of mass.
			RIM_INLINE void applyImpulse( const Vector3& impulse, const Vector3& point )
			{
				velocity += inverseMass*impulse;
				angularVelocity += inverseWorldSpaceInertiaTensor * math::cross( point, impulse );
			}
			
			
			
			
			/// Apply the specified bias impulse vector at a point relative to the object's center of mass.
			RIM_INLINE void applyBiasImpulse( const Vector3& biasImpulse, const Vector3& point )
			{
				biasVelocity += inverseMass*biasImpulse;
				biasAngularVelocity += inverseWorldSpaceInertiaTensor * math::cross( point, biasImpulse );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Force Accessor Methods
			
			
			
			
			/// Return the netforce vector acting on this object.
			RIM_INLINE const Vector3& getForce() const
			{
				return force;
			}
			
			
			
			
			/// Set the net force vector for this object.
			RIM_INLINE void setForce( const Vector3& newForce )
			{
				force = newForce;
			}
			
			
			
			
			/// Apply the specified force vector to this object's center of mass.
			/**
			  * This method adds the specified force vector to this object's
			  * net force vector.
			  */
			RIM_INLINE void applyForce( const Vector3& forceVector )
			{
				force += forceVector;
			}
			
			
			
			
			/// Apply the specified force vector at a point relative to the object's center of mass.
			/**
			  * This method will produce a change in the object's torque vector
			  * if the force and point to center of mass vectors are not in the
			  * same direction.
			  */
			RIM_INLINE void applyForce( const Vector3& forceVector, const Vector3& point )
			{
				force += forceVector;
				torque += math::cross( point, forceVector );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Torque Accessor Methods
			
			
			
			
			/// Return the net torque vector acting on this object.
			RIM_INLINE const Vector3& getTorque() const
			{
				return torque;
			}
			
			
			
			
			/// Set the net torque vector for this object.
			RIM_INLINE void setTorque( const Vector3& newTorque )
			{
				torque = newTorque;
			}
			
			
			
			
			/// Apply the specified torque vector to this object's center of mass.
			/**
			  * This method adds the specified torque vector to this object's
			  * net torque vector.
			  */
			RIM_INLINE void applyTorque( const Vector3& torqueVector )
			{
				torque += torqueVector;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Mass Accessor Methods
			
			
			
			
			/// Return the world-space mass of this rigid object in mass units (kg).
			RIM_FORCE_INLINE Real getMass() const
			{
				return mass;
			}
			
			
			
			
			/// Set the world-space mass of this rigid object in mass units (kg).
			/**
			  * This method sets the mass of the object in world space. This world-space
			  * mass is then used to calculate an object-space mass for the object by
			  * dividing by the scaling factor to the third power. Subsequent changes
			  * to the object's scaling factor will cause the world-space mass to update
			  * to reflect the stored object-space mass, preserving object density.
			  *
			  * The mass of the object is clamped to the range [0,+infinity].
			  */
			RIM_INLINE void setMass( Real newMass )
			{
				inheritsShapeMassQuantities = false;
				
				if ( newMass <= Real(0) )
					inverseMass = mass = objectSpaceMass = Real(0);
				else
				{
					objectSpaceMass = newMass/(transform.scale.x*transform.scale.y*transform.scale.z);
					mass = newMass;
					inverseMass = Real(1)/mass;
				}
			}
			
			
			
			
			/// Return the inverse world-space mass of this rigid object in mass units (kg).
			/**
			  * If the object's mass is 0, the inverse mass will also be 0,
			  * otherwise it is the reciprocal of the object's mass.
			  */
			RIM_FORCE_INLINE Real getInverseMass() const
			{
				return inverseMass;
			}
			
			
			
			
			/// Set the object-space mass of this rigid object in mass units (kg).
			RIM_FORCE_INLINE Real getLocalMass() const
			{
				return objectSpaceMass;
			}
			
			
			
			
			/// Set the object-space mass of this rigid object in mass units (kg).
			/**
			  * This method sets the mass of the object in object space, before
			  * any transformation-based scaling occurrs. The world-space mass
			  * for this object will then be equal to the object-space mass times
			  * the scaling factor to the third power.
			  *
			  * The local mass of the object is clamped to the range [0,+infinity].
			  */
			RIM_INLINE void setLocalMass( Real newMass )
			{
				inheritsShapeMassQuantities = false;
				
				if ( newMass <= Real(0) )
					inverseMass = mass = objectSpaceMass = Real(0);
				else
				{
					objectSpaceMass = newMass;
					mass = objectSpaceMass*transform.scale.x*transform.scale.y*transform.scale.z;
					inverseMass = Real(1)/mass;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Inertia Tensor Accessor Methods
			
			
			
			
			/// Return the inverse inertia tensor for this object in world space.
			RIM_INLINE const Matrix3& getInverseWorldSpaceInertiaTensor() const
			{
				if ( isStatic )
					return Matrix3::ZERO;
				
				return inverseWorldSpaceInertiaTensor;
			}
			
			
			
			
			/// Return the inverse inertia tensor for this object in object space.
			RIM_INLINE const Matrix3& getInverseObjectSpaceInertiaTensor() const
			{
				return inverseObjectSpaceInertiaTensor;
			}
			
			
			
			
			/// Set the inertia tensor for this object in object space.
			RIM_NO_INLINE void setInertiaTensor( const Matrix3& newInertiaTensor )
			{
				if ( math::abs( newInertiaTensor.getDeterminant() ) < math::epsilon<Real>() )
					inverseObjectSpaceInertiaTensor = Matrix3::ZERO;
				else
					inverseObjectSpaceInertiaTensor = newInertiaTensor.invert();
				
				inheritsShapeMassQuantities = false;
				updateWorldSpaceInertiaTensor();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Is Static Accessor Methods
			
			
			
			
			/// Return whether or not this object should be considered to be a static object.
			RIM_INLINE Bool getIsStatic() const
			{
				return isStatic;
			}
			
			
			
			
			/// Set whether or not this object should be considered to be a static object.
			RIM_INLINE void setIsStatic( Bool newIsStatic )
			{
				isStatic = newIsStatic;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Hash Code Accessor Methods
			
			
			
			
			/// Return an integral hash code for this rigid object.
			/**
			  * This hash code should be unique to every rigid object. It is
			  * generated at object construction from the address of the 'this'
			  * pointer for the object.
			  */
			RIM_FORCE_INLINE Hash getHashCode() const
			{
				return hashCode;
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Compute a new world-space inertia tensor from the current orientation and object-space inertia tensor.
			RIM_INLINE void updateWorldSpaceInertiaTensor()
			{
				// Scale inertial quantities by the scale factor to the fifth power.
				// This is because a moment of inertia is related to scale by the fifth power,
				// 3x from mass, and 2x from the inertia calculation.
				Real inertialScaleFactor = transform.scale.x*transform.scale.y*transform.scale.z*
											transform.scale.x*transform.scale.y;
				
				inverseWorldSpaceInertiaTensor =  transform.orientation * 
												 inverseObjectSpaceInertiaTensor / inertialScaleFactor * 
												 transform.orientation.transpose();
			}
			
			
			
			
			/// Compute a new world-space inertia tensor from the current orientation and object-space inertia tensor.
			RIM_INLINE void updateWorldSpaceMassQuantities()
			{
				// Scale mass quantities by the scale factor to the third power.
				// This is because when the scale goes up by 2x, the volume and therefore mass go up by 8x.
				Real massScaleFactor = transform.scale.x*transform.scale.y*transform.scale.z;
				
				// Scale inertial quantities by the scale factor to the fifth power.
				// This is because a moment of inertia is related to scale by the fifth power,
				// 3x from mass, and 2x from the inertia calculation.
				Real inertialScaleFactor = transform.scale.x*transform.scale.y*massScaleFactor;
				
				inverseWorldSpaceInertiaTensor = transform.orientation * 
												inverseObjectSpaceInertiaTensor / inertialScaleFactor * 
												transform.orientation.transpose();
				
				if ( objectSpaceMass != Real(0) )
				{
					mass = objectSpaceMass*massScaleFactor;
					inverseMass = Real(1)/mass;
				}
			}
			
			
			
			
			/// Update the transformations for all shape instances in this object so that they reflect the object's transformation.
			void updateShapeTransforms() const;
			
			
			
			
			/// Update the inertia tensor and mass for this object from its shapes' masses and inertia tensors.
			void updateShapeMassQuantities();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Transform/Dyanmics Data Members
			
			
			
			
			/// The transformation from object space to world space for this rigid object.
			Transform3 transform;
			
			
			
			
			/// The center of mass of this object in 3D world space.
			Vector3 centerOfMass;
			
			
			
			
			/// The linear velocity of this object in length units per second.
			Vector3 velocity;
			
			
			
			
			/// A temporary bias for this object's velocity used to correct constraint error.
			Vector3 biasVelocity;
			
			
			
			
			/// The angular velocity of this object in world space.
			Vector3 angularVelocity;
			
			
			
			
			/// A temporary bias for this object's angular velocity used to correct constraint error.
			Vector3 biasAngularVelocity;
			
			
			
			
			/// The net force vector of this object in world space.
			Vector3 force;
			
			
			
			
			/// The net torque vector of this object in world space.
			Vector3 torque;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Mass Data Members
			
			
			
			
			/// The mass of this object in mass units (kg) after world-space scaling.
			Real mass;
			
			
			
			
			/// The inverse mass of this object in inverse mass units (1/kg) after world-space scaling.
			Real inverseMass;
			
			
			
			
			/// The mass of this object in object space (before scaling).
			Real objectSpaceMass;
			
			
			
			
			/// The inverse inertia tensor of this object in world space.
			Matrix3 inverseWorldSpaceInertiaTensor;
			
			
			
			
			/// The inverse inertia tensor of this object in object space.
			Matrix3 inverseObjectSpaceInertiaTensor;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Shape Data Members
			
			
			
			
			/// A pointer to the collision shape instances that specify this object's 3D shape(s).
			ShortArrayList<Pointer<CollisionShapeInstance>,2> shapeInstances;
			
			
			
			
			/// A bounding sphere which contains this entire object in 3D world space.
			mutable BoundingSphere boundingSphere;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Other Private Data Members
			
			
			
			
			/// A hash code for this rigid object, generated internally from the object's address in memory.
			Hash hashCode;
			
			
			
			
			/// Whether or not this object should be considered to be static (not physically based).
			Bool isStatic;
			
			
			
			
			/// Whether or not the rigid object's transformation has been changed.
			/**
			  * This value is set to TRUE whenever this object's transformation is
			  * changed, indicating that the object's shape instances needs to update
			  * their transformations with the new object transformation.
			  */
			mutable Bool shapesNeedNewTransform;
			
			
			
			
			/// A boolean indicating whether or not this object should automatically use mass quantities derived from its shape(s).
			/**
			  * By default, this value is TRUE until the setInertiaTensor() or setMass() method is called
			  * by the user. This indicates that the user is overriding the default behavior
			  * for handling shape inertial quantities.
			  */
			Bool inheritsShapeMassQuantities;
			
			
			
};




//##########################################################################################
//***********************  End Rim Physics Objects Namespace  ******************************
RIM_PHYSICS_OBJECTS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_RIGID_OBJECT_H

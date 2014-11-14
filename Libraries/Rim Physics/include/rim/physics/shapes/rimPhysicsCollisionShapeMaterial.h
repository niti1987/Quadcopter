/*
 *  rimPhysicsCollisionShapeMaterial.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 3/9/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_MATERIAL_H
#define INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_MATERIAL_H


#include "rimPhysicsShapesConfig.h"


//##########################################################################################
//************************  Start Rim Physics Shapes Namespace  ****************************
RIM_PHYSICS_SHAPES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which describes the physical and simulated properties of a type of material.
class CollisionShapeMaterial
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a material with the default material parameters.
			CollisionShapeMaterial();
			
			
			
			
			/// Create a material object with the specified material parameters.
			CollisionShapeMaterial( Real newElasticity, Real newKineticFriction,
									Real newStaticFriction, Real newStaticFrictionThreshold,
									Real newDensity, Real newAllowedPenetration, Real newHardness );
			
			
			
			
			/// Create a combined collision shape material from the specified two material objects.
			/**
			  * This constructor combines the properties of the two specified materials
			  * into a single material object that approximates the material properties
			  * for those two materials interacting.
			  */
			CollisionShapeMaterial( const CollisionShapeMaterial& material1,
									const CollisionShapeMaterial& material2 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Density Accessor Methods
			
			
			
			
			/// Return the density of this material in mass units (kg) over length units (m) cubed.
			RIM_FORCE_INLINE Real getDensity() const
			{
				return density;
			}
			
			
			
			
			/// Set the density of this material in mass units (kg) over length units (m) cubed.
			/**
			  * The density of the material is clamped to the range [0,+infinity).
			  */
			RIM_INLINE void setDensity( Real newDensity )
			{
				density = math::max( newDensity, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Elasticity Accessor Methods
			
			
			
			
			/// Get the coefficient of restitution of this material.
			/**
			  * A value of 0 indicates that this material undergoes totally inelastic
			  * collisions, while a value of 1 indicates that collisions are highly elastic.
			  */
			RIM_FORCE_INLINE Real getElasticity() const
			{
				return elasticity;
			}
			
			
			
			
			/// Set the coefficient of restitution of this material.
			/**
			  * This value is clamped to the range [0,1]. A value of 0 indicates
			  * that this material undergoes totally inelastic collisions, while a
			  * value of 1 indicates that collisions are perfectly elastic.
			  */
			RIM_INLINE void setElasticity( Real newElasticity )
			{
				elasticity = math::clamp( newElasticity, Real(0), Real(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Kinetic Friction Coefficient Accessor Methods
			
			
			
			
			/// Return the coefficient of kinetic friction for this material.
			/**
			  * This value indicates the coefficient of friction to be used when
			  * the relative speed between two objects is greater than the static
			  * friction threshold.
			  */
			RIM_FORCE_INLINE Real getKineticFriction() const
			{
				return kineticFriction;
			}
			
			
			
			
			/// Set the coefficient of kinetic friction for this material.
			/**
			  * This value indicates the coefficient of friction to be used when
			  * the relative speed between two objects is greater than the static
			  * friction threshold. This value is clamped to the range of [0,+infinity).
			  */
			RIM_INLINE void setKineticFriction( Real newKineticFriction )
			{
				kineticFriction = math::max( newKineticFriction, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Friction Coefficient Accessor Methods
			
			
			
			
			/// Return the coefficient of static friction for this material.
			/**
			  * This value indicates the coefficient of friction to be used when
			  * the relative speed between two objects is less than the static
			  * friction threshold.
			  */
			RIM_FORCE_INLINE Real getStaticFriction() const
			{
				return staticFriction;
			}
			
			
			
			
			/// Set the coefficient of static friction for this material.
			/**
			  * This value indicates the coefficient of friction to be used when
			  * the relative speed between two objects is less than the static
			  * friction threshold. This value is clamped to the range of [0,+infinity).
			  */
			RIM_INLINE void setStaticFriction( Real newStaticFriction )
			{
				staticFriction = math::max( newStaticFriction, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Friction Threshold Accessor Methods
			
			
			
			
			/// Get the relative speed threshold below which static friction is in effect.
			/**
			  * This value indicates the maximum relative speed at the point of collision
			  * between two objects where static friction has effect. If the relative
			  * speed is greater than this value, kinetic friction is observed.
			  */
			RIM_FORCE_INLINE Real getStaticFrictionThreshold() const
			{
				return staticFrictionThreshold;
			}
			
			
			
			
			/// Set the relative speed threshold below which static friction is in effect.
			/**
			  * This value indicates the maximum relative speed at the point of collision
			  * between two objects where static friction has effect. If the relative
			  * speed is greater than this value, kinetic friction is observed. This
			  * value is clamped to the range of [0,+infinity).
			  */
			RIM_INLINE void setStaticFrictionThreshold( Real newStaticFrictionThreshold )
			{
				staticFrictionThreshold = math::max( newStaticFrictionThreshold, Real(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Allowed Penetration Accessor Methods
			
			
			
			
			/// Return the amount of allowed penetration for this material in length units (m).
			/**
			  * This value indicates the amount of allowed penetration between two
			  * colliding objects. It exists to make simulations more stable when
			  * there are many colliding objects by relaxing the constraints for 
			  * object interpenetrations. It is wise to set this value to be the same as
			  * the smallest detail size in the scene (mm or cm).
			  */
			RIM_FORCE_INLINE Real getAllowedPenetration() const
			{
				return allowedPenetration;
			}
			
			
			
			
			/// Set the amount of allowed penetration for this material in length units (m).
			/**
			  * This value indicates the amount of allowed penetration between two
			  * colliding objects. It exists to make simulations more stable when
			  * there are many colliding objects by relaxing the constraints for 
			  * object interpenetrations. It is wise to set this value to be the same as
			  * the smallest detail size in the scene (mm or cm).
			  */
			RIM_INLINE void setAllowedPenetration( Real newAllowedPenetration )
			{
				allowedPenetration = newAllowedPenetration;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hardness Accessor Methods
			
			
			
			
			/// Return the 'hardness' of this material.
			/**
			  * This value indicates how quickly the physics collision resolution
			  * system should correct object interpenetrations that are above the 
			  * allowed threshold. A value of 0 indicates that interpenetrations are
			  * not corrected, while a value of 1 indicates that interpenetrations are
			  * corrected immediately. It is unwise to use a value of 1 because it can
			  * cause the simulation to become unstable when there are many colliding
			  * objects.
			  */
			RIM_FORCE_INLINE Real getHardness() const
			{
				return hardness;
			}
			
			
			
			
			/// Set the 'hardness' of this material.
			/**
			  * This value indicates how quickly the physics collision resolution
			  * system should correct object interpenetrations that are above the 
			  * allowed threshold. A value of 0 indicates that interpenetrations are
			  * not corrected, while a value of 1 indicates that interpenetrations are
			  * corrected immediately. It is unwise to use a value of 1 because it can
			  * cause the simulation to become unstable when there are many colliding
			  * objects. This value is clamped to the range of [0,1].
			  */
			RIM_INLINE void setHardness( Real newHardness )
			{
				hardness = math::clamp( newHardness, Real(0), Real(1) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The density of this material in mass units (kg) over length units (m) cubed.
			Real density;
			
			
			
			
			/// The coefficient of restitution for this material, the amount that collisions are elastic.
			/**
			  * A value of 0 indicates that this material undergoes totally inelastic
			  * collisions, while a value of 1 indicates that collisions are perfectly
			  * elastic (no energy is lost).
			  */
			Real elasticity;
			
			
			
			
			/// The coefficient of kinetic friction for this material.
			/**
			  * This value indicates the coefficient of friction to be used when
			  * the relative speed between two objects is greater than the static
			  * friction threshold.
			  */
			Real kineticFriction;
			
			
			
			
			/// The coefficient of static friction for this material.
			/**
			  * This value indicates the coefficient of friction to be used when
			  * the relative speed between two objects is less than the static
			  * friction threshold.
			  */
			Real staticFriction;
			
			
			
			
			/// The relative speed threshold below which static friction is in effect.
			/**
			  * This value indicates the maximum relative speed at the point of collision
			  * between two objects where static friction has effect. If the relative
			  * speed is greater than this value, kinetic friction is observed.
			  */
			Real staticFrictionThreshold;
			
			
			
			
			/// The amount of allowed penetration for this material in length units (m).
			/**
			  * This value indicates the amount of allowed penetration between two
			  * colliding objects. It exists to make simulations more stable when
			  * there are many colliding objects by relaxing the constraints for 
			  * object interpenetrations. It is wise to set this value to be the same as
			  * the smallest detail size in the scene (mm or cm).
			  */
			Real allowedPenetration;
			
			
			
			
			/// The 'hardness' of this material.
			/**
			  * This value indicates how quickly the physics collision resolution
			  * system should correct object interpenetrations that are above the 
			  * allowed threshold. A value of 0 indicates that interpenetrations are
			  * not corrected, while a value of 1 indicates that interpenetrations are
			  * corrected immediately. It is unwise to use a value of 1 because it can
			  * cause the simulation to become unstable when there are many colliding
			  * objects.
			  */
			Real hardness;
			
			
			
};




//##########################################################################################
//************************  End Rim Physics Shapes Namespace  ******************************
RIM_PHYSICS_SHAPES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_COLLISION_SHAPE_MATERIAL_H

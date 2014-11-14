/*
 *  rimPhysicsTriangle.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 7/9/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_TRIANGLE_H
#define INCLUDE_RIM_PHYSICS_TRIANGLE_H


#include "rimPhysicsUtilitiesConfig.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an indexed triangle used for physics simulation.
/**
  * This triangle class is used as the input format for the engine's mesh
  * algorithms which then preprocess the triangle data into a format more suitable
  * for physics simulation or collision detection.
  */
class PhysicsTriangle
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a physics triangle with the specified vertex indices and default material index (0).
			RIM_INLINE PhysicsTriangle( Index v1, Index v2, Index v3 )
				:	materialIndex( 0 )
			{
				v[0] = v1;
				v[1] = v2;
				v[2] = v3;
			}
			
			
			
			
			/// Create a physics triangle with the specified vertex indices and material index.
			RIM_INLINE PhysicsTriangle( Index v1, Index v2, Index v3, Index newMaterialIndex )
				:	materialIndex( newMaterialIndex )
			{
				v[0] = v1;
				v[1] = v2;
				v[2] = v3;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not the vertex and material indices of this triangle are equal to another's.
			/**
			  * Order of the indicies is not important: any two triangles with the same vertex 
			  * and material indices, regardless of their order, are equal.
			  */
			RIM_INLINE Bool operator == ( const PhysicsTriangle& other ) const
			{
				if ( materialIndex != other.materialIndex )
					return false;
				
				if ( v[0] == other.v[0] )
					return (v[1] == other.v[1] && v[2] == other.v[2]) || (v[1] == other.v[2] && v[2] == other.v[1]);
				else if ( v[0] == other.v[1] )
					return (v[1] == other.v[0] && v[2] == other.v[2]) || (v[1] == other.v[2] && v[2] == other.v[0]);
				else if ( v[0] == other.v[2] )
					return (v[1] == other.v[0] && v[2] == other.v[1]) || (v[1] == other.v[1] && v[2] == other.v[0]);
				
				return false;
			}
			
			
			
			
			/// Return whether or not the vertex and material indices of this triangle are not equal to another's.
			/**
			  * Order of the indicies is not important: any two triangles without the same vertex 
			  * and material indices, regardless of their order, are not equal.
			  */
			RIM_INLINE Bool operator != ( const PhysicsTriangle& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Data Members
			
			
			
			
			/// The indices of the three vertices that make up this triangle.
			Index v[3];
			
			
			
			
			/// The index of the material to use for this triangle.
			Index materialIndex;
			
			
			
};




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_TRIANGLE_H

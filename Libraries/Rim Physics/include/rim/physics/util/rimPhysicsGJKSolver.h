/*
 *  rimPhysicsGJKSolver.h
 *  Rim Physics
 *
 *  Created by Carl Schissler on 8/29/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_PHYSICS_GJK_SOLVER_H
#define INCLUDE_RIM_PHYSICS_GJK_SOLVER_H


#include "rimPhysicsUtilitiesConfig.h"


#include "rimPhysicsMinkowskiVertex.h"


//##########################################################################################
//**********************  Start Rim Physics Utilities Namespace  ***************************
RIM_PHYSICS_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which iteratively refines a 4-point simplex to determine if two convex shapes intersect.
class GJKSolver
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a default GJKSolver object with the default max number of iterations, intial search direction.
			RIM_INLINE GJKSolver()
				:	initialSearchDirection( 1, 0, 0 ),
					maximumNumberOfIterations( DEFAULT_MAXIMUM_NUMBER_OF_ITERATIONS )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	GJK Solve Method
			
			
			
			
			/// Determine whether or not two convex shapes intersect.
			/**
			  * This method uses the specified template support point generation function
			  * to iteratively refine a 4-point simplex in minkowski-space until it
			  * contains the origin. When this happens, an intersection occurrs and TRUE
			  * is returned. If the algorithm does not converge and there is no way that
			  * the two shapes could intersect, FALSE is returned.
			  *
			  * The function allows the user to specify a user data pointer which gets
			  * passed to the support point generation function. This is so that users
			  * of this class can easily access data necessary for support point generation.
			  *
			  * The support point generation function should return a minkowski vertex
			  * object for the two points on the two convex shapes that are farthest
			  * in the given search direction (1st parameter).
			  */
			template < typename UserDataType1, typename UserDataType2, MinkowskiVertex3 (*getSupportPoint)( const Vector3&, const UserDataType1*, const UserDataType2* ) >
			Bool solve( StaticArray<MinkowskiVertex3,4>& simplexResult,
						const UserDataType1* userData1 = NULL, const UserDataType2* userData2 = NULL );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Maximum Number of Iterations Accessor Methods
			
			
			
			
			/// Return the maximum number of iterations that this GJK solver can perform.
			/**
			  * An upper bound to the number of iterations is necessary so that degenerate
			  * cases don't produce an infinite solver loop. Values in the range of 10 to 30
			  * are typical good iteration count limits. Your mileage may vary.
			  */
			RIM_FORCE_INLINE Size getMaximumNumberOfIterations() const
			{
				return maximumNumberOfIterations;
			}
			
			
			
			
			/// Set the maximum number of iterations that this GJK solver can perform.
			/**
			  * An upper bound to the number of iterations is necessary so that degenerate
			  * cases don't produce an infinite solver loop. Values in the range of 10 to 30
			  * are typical good iteration count limits. Your mileage may vary.
			  */
			RIM_FORCE_INLINE void setMaximumNumberOfIterations( Size newMaximumNumberOfIterations )
			{
				maximumNumberOfIterations = newMaximumNumberOfIterations;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Initial Search Direction Accessor Methods
			
			
			
			
			/// Get the initial search direction that this GJK solver uses when solving for shape intersection.
			/**
			  * Using a carefully chosen initial search direction can much increase the
			  * rate at which the solver converges on a solution.
			  */
			RIM_FORCE_INLINE const Vector3& getInitialSearchDirection() const
			{
				return initialSearchDirection;
			}
			
			
			
			
			/// Set the initial search direction that this GJK solver uses when solving for shape intersection.
			/**
			  * Using a carefully chosen initial search direction can much increase the
			  * rate at which the solver converges on a solution. Setting this vector to
			  * a search direction that converged quickly in the past can produce better results.
			  */
			RIM_FORCE_INLINE void setInitialSearchDirection( const Vector3& newInitialSearchDirection )
			{
				initialSearchDirection = newInitialSearchDirection;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Last Search Direction Accessor Methods
			
			
			
			
			/// Get a const reference to the last search direction used by this GJK solver.
			/**
			  * This value might be of use as an initial search direction if it is
			  * cached for each shape pair and restored each time they are tested for collisions.
			  */
			RIM_FORCE_INLINE const Vector3& getLastSearchDirection() const
			{
				return lastSearchDirection;
			}
			
			
			
	private:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Simplex Update Methods
			
			
			
			
			/// Update a 2-point simplex and return the next search vector in the output parameter.
			void updateSimplex2( Vector3& searchDirection );
			
			
			
			
			/// Update a 3-point simplex and return the next search vector in the output parameter.
			void updateSimplex3( Vector3& searchDirection );
			
			
			
			
			/// Update a 4-point simplex and return whether or not the simplex is complete.
			/**
			  * If TRUE is returned, the simplex is complete and the convex shapes must
			  * intersect. Otherwise, if FALSE is returned, the next search direction
			  * is placed in the output parameter.
			  */
			Bool updateSimplex4( Vector3& searchDirection );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a list representing the current minkowski simplex for the solver.
			MinkowskiVertex3* simplex;
			
			
			
			
			/// The current number of points in the simplex.
			Size numSimplexPoints;
			
			
			
			
			/// The maximum allowed number of iterations for this GJK solver.
			Size maximumNumberOfIterations;
			
			
			
			
			/// The initial search direction for this GJK solver.
			Vector3 initialSearchDirection;
			
			
			
			
			/// The last search direction used to enclose the origin using the simplex.
			/**
			  * This value might be of use as an initial search direction if it is
			  * cached for each shape pair and restored each time they are tested for collisions.
			  */
			Vector3 lastSearchDirection;
			
			
			
			
			/// The default starting maximum number of iterations that this GJK solver performs.
			static const Size DEFAULT_MAXIMUM_NUMBER_OF_ITERATIONS = 30;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		GJK Solve Method
//############		
//##########################################################################################
//##########################################################################################




template < typename UserDataType1, typename UserDataType2, MinkowskiVertex3 (*getSupportPoint)( const Vector3&, const UserDataType1*, const UserDataType2* ) >
Bool GJKSolver:: solve( StaticArray<MinkowskiVertex3,4>& simplexResult, const UserDataType1* userData1, const UserDataType2* userData2 )
{
	//***************************************************************************
	// Make sure that the simplex is empty from previous collision tests.
	
	// Store a pointer to the first simplex vertex so that we can add more vertices later.
	simplex = simplexResult.getPointer();
	
	//***************************************************************************
	// Pick a starting direction (arbitrary for now, later a direction caching
	// method might be used to improve the algorithm's convergence.), and get
	// the support point for this direction. Add this point to the simplex.
	
	Vector3 searchDirection = initialSearchDirection;
	
	MinkowskiVertex3 supportPoint = getSupportPoint( searchDirection, userData1, userData2 );
	
	// Add the first support point to the simplex.
	simplex[0] = supportPoint;
	numSimplexPoints = 1;
	
	//***************************************************************************
	// The new direction in which to search for the origin is by definition
	// the direction from this first support point to the origin, its negation.
	
	searchDirection = -supportPoint.getPosition();
	
	//***************************************************************************
	// Start the main GJK algortihm loop. In this loop, we first get a new
	// support point in the current origin search direction. If the dot product
	// of this support point and the search direction is less than zero, then
	// there is no way that the two shapes can intersect (because the algorithm
	// has backtracked). Otherwise, add this point to the simplex and then update
	// the search direction based on the current state of the simplex and the 
	// position of the origin relative to it.
	
	Index numberOfIterations = 0;
	
	while ( numberOfIterations < maximumNumberOfIterations )
	{
		//***************************************************************************
		// Get the support point of the two shapes in the current search direction.
		
		supportPoint = getSupportPoint( searchDirection, userData1, userData2 );
		
		//***************************************************************************
		// Test to see if there is no way that the shapes can intersect. If
		// the result of the dot product of the new support point and the search
		// direction is less than zero, then that means that the new support point
		// does not get any closer to the origin than where the simplex is, and
		// therefore the shapes cannot intersect.
		
		// Break from the GJK iteration loop, indicating that there can be no intersecion.
		// This happens whenever the search direction vector is a separating axis for
		// the two convex shape (dot < -epsilon), or if we weren't able to get any closer
		// to the origin with this support point (dot < epsilon).
		if ( math::dot( searchDirection, supportPoint.getPosition() ) < math::epsilon<Real>() )
			break;
		
		//***************************************************************************
		// Add this new support point to the simplex.
		
		simplex[numSimplexPoints] = supportPoint;
		numSimplexPoints++;
		
		//***************************************************************************
		// Update the search direction by analyzing the state of the simplex
		// and the origin's position relative to it. We have to split the simplex
		// processing into 3 different cases.
		// The algorithm that we run on the simplex depends on the number
		// of points it contains. The valid possible numbers of points are 
		// 2, 3, and 4. Switch between the algorithm based on this number.
		
		switch ( numSimplexPoints )
		{
			//***************************************************************************
			// The first case is that the simplex consists of 2 points. This means
			// that it forms a line. We need to determine in which direction relative
			// to the line that the origin is in. It can be either in-between the two
			// planes defined by the endpoints of the line and the line as the plane
			// normals. Otherwise, the origin must lie on the other side of the plane
			// of the newest point of the simplex.
			
			case 2:
				updateSimplex2( searchDirection );
				break;
			
			
			//***************************************************************************
			// The second case is that the simplex has 3 points in it which form
			// a triangle. We need to determine where the origin is, relative to the
			// triangle. It can be closest to an edge of the triangle, closest to a
			// vertex, or it can be closest to the face of the triangle in either 
			// direction. Determine which case we are in, update the simplex and 
			// provide a new direction in which to search for the origin.
			
			case 3:
				updateSimplex3( searchDirection );
				break;
			
			
			//***************************************************************************
			// The third case is that the simplex has 4 points in it which form
			// a tetrahedron. We need to determine where the origin is, relative to the
			// tetrahedron. It can be closest to an edge of the tetrahedron, closest to a
			// vertex of the tetrahedron, closest to a face of the tetrahedron, 
			// or it can be inside the tetrahedron. Determine which case we are 
			// in, update the simplex and provide a new direction in which to 
			// search for the origin if the tetrahedron does not contain the origin.
			
			case 4:
				if ( updateSimplex4( searchDirection ) )
				{
					// The shapes intersect.
					lastSearchDirection = searchDirection;
					
					return true;
				}
				break;
		}
		
		numberOfIterations++;
	}
	
	lastSearchDirection = searchDirection;
	
	return false;
}




//##########################################################################################
//**********************  End Rim Physics Utilities Namespace  *****************************
RIM_PHYSICS_UTILITES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_PHYSICS_GJK_SOLVER_H

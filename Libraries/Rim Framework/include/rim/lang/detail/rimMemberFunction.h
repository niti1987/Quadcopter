/*
 *  rimMemberFunction.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/22/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_MEMBER_FUNCTION_H
#define INCLUDE_RIM_MEMBER_FUNCTION_H


#include "../rimLanguageConfig.h"


#include "rimFunctionDefinition.h"


//##########################################################################################
//***********************  Start Rim Language Internal Namespace  **************************
RIM_LANGUAGE_INTERNAL_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which wraps a member function pointer and object pointer of runtime type.
/**
  * A MemberFunction object inherits from FunctionDefinition which defines a generic
  * interface for functions. This allows a MemberFunction to wrap objects of runtime
  * or virtual type and allow them to be handled as a standard non-member function.
  */
template <	typename ObjectType,
			typename SignatureType,
			typename R, 
			typename T1 = NullType, 
			typename T2 = NullType, 
			typename T3 = NullType, 
			typename T4 = NullType, 
			typename T5 = NullType, 
			typename T6 = NullType, 
			typename T7 = NullType, 
			typename T8 = NullType, 
			typename T9 = NullType, 
			typename T10 = NullType >
class MemberFunction : public FunctionDefinition< R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 >
{
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Type Definitions
			
			
			
			
			/// The type of this member function's superclass.
			typedef FunctionDefinition< R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 > DefinitionType;
			
			
			
			
			/// The type of this member function class, defined here for brevity elsewhere.
			typedef MemberFunction< ObjectType, SignatureType, R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 > ThisType;
			
			
			
			
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new member function object with the specified object and function pointer.
			RIM_INLINE MemberFunction( SignatureType newFunctionPointer, ObjectType* objectPointer )
				:	object( objectPointer ),
					functionPointer( newFunctionPointer )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Function Call Operators
			
			
			
			
			/// Call a member function object with 0 parameters.
			RIM_INLINE R operator () () const
			{
				return (object->*functionPointer)();
			}
			
			
			
			
			/// Call a member function object with 1 parameter.
			RIM_INLINE R operator () ( T1 p1 ) const
			{
				return (object->*functionPointer)( p1 );
			}
			
			
			
			
			/// Call a member function object with 2 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2 ) const
			{
				return (object->*functionPointer)( p1, p2 );
			}
			
			
			
			
			/// Call a member function object with 3 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3 ) const
			{
				return (object->*functionPointer)( p1, p2, p3 );
			}
			
			
			
			
			/// Call a member function object with 4 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3, T4 p4 ) const
			{
				return (object->*functionPointer)( p1, p2, p3, p4 );
			}
			
			
			
			
			/// Call a member function object with 5 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5 ) const
			{
				return (object->*functionPointer)( p1, p2, p3, p4, p5 );
			}
			
			
			
			
			/// Call a member function object with 6 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6 ) const
			{
				return (object->*functionPointer)( p1, p2, p3, p4, p5, p6 );
			}
			
			
			
			
			/// Call a member function object with 7 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7 ) const
			{
				return (object->*functionPointer)( p1, p2, p3, p4, p5, p6, p7 );
			}
			
			
			
			
			/// Call a member function object with 8 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8 ) const
			{
				return (object->*functionPointer)( p1, p2, p3, p4, p5, p6, p7, p8 );
			}
			
			
			
			
			/// Call a member function object with 9 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9 ) const
			{
				return (object->*functionPointer)( p1, p2, p3, p4, p5, p6, p7, p8, p9 );
			}
			
			
			
			
			/// Call a member function object with 10 parameters.
			RIM_INLINE R operator () ( T1 p1, T2 p2, T3 p3, T4 p4, T5 p5, T6 p6, T7 p7, T8 p8, T9 p9, T10 p10 ) const
			{
				return (object->*functionPointer)( p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operator
			
			
			
			
			/// Return whether or not this member function is exactly equal to another member function.
			/**
			  * This method compares both the destination object pointer and the function
			  * pointer when testing for equality. If both are equal for both objects,
			  * the member functions are considered equal.
			  */
			virtual Bool equals( const DefinitionType& other ) const
			{
				const ThisType* memberFunction = (const ThisType*)&other;
				
				return functionPointer == memberFunction->functionPointer && object == memberFunction->object;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Clone Method
			
			
			
			
			/// Create and return a deep copy of this member function object.
			/**
			  * This allows member functions to be copied constructed without knowing
			  * the type of the destination object or function signature.
			  */
			virtual DefinitionType* clone() const
			{
				return util::construct<ThisType>( functionPointer, object );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the member function which this object is wrapping.
			SignatureType functionPointer;
			
			
			
			
			/// A pointer to the object for which the member function pointer will be called.
			ObjectType* object;
			
			
			
			
};




//##########################################################################################
//***********************  End Rim Language Internal Namespace  ****************************
RIM_LANGUAGE_INTERNAL_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_MEMBER_FUNCTION_H

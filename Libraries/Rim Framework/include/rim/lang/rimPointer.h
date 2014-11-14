/*
 *  rimPointer.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 3/19/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_POINTER_H
#define INCLUDE_RIM_POINTER_H


#include "rimLanguageConfig.h"


#include "../threads/rimAtomics.h"


//##########################################################################################
//***************************  Start Rim Language Namespace  *******************************
RIM_LANGUAGE_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




template < class T >
class Pointer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a Pointer object which is NULL.
			RIM_INLINE Pointer()
				:	pointer( NULL ),
					count( NULL )
			{
			}
			
			
			
			
			/// Create a Pointer object which wraps the specified raw pointer.
			/**
			  * If the specified raw pointer is equal to NULL, the reference count for the
			  * pointer is set to 0. Otherwise, the reference count for the Pointer is 1.
			  * By calling this constructor, the user acknowledges that the Pointer object now
			  * owns the object pointed to by the raw pointer and retains the right to destroy it
			  * when the reference count reaches 0.
			  * 
			  * @param newPointer - the raw pointer which this Pointer object should wrap.
			  */
			RIM_INLINE explicit Pointer( T* newPointer )
				:	pointer( newPointer )
			{
				// allocate a new counter if needed
				if ( pointer != NULL )
					count = util::construct< threads::atomic::Atomic<Size> >(1);
				else
					count = NULL;
			}
			
			
			
			
			/// Create a Pointer object which wraps the specified raw pointer of a different type.
			/**
			  * If the specified raw pointer is equal to NULL, the reference count for the
			  * pointer is set to 0. Otherwise, the reference count for the Pointer is 1.
			  * By calling this constructor, the user acknowledges that the Pointer object now
			  * owns the object pointed to by the raw pointer and retains the right to destroy it
			  * when the reference count reaches 0.
			  * 
			  * @param newPointer - the raw pointer which this Pointer object should wrap.
			  */
			template < typename U >
			RIM_INLINE explicit Pointer( U* newPointer )
				:	pointer( newPointer )
			{
				// allocate a new counter if needed
				if ( pointer != NULL )
					count = util::construct< threads::atomic::Atomic<Size> >(1);
				else
					count = NULL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructor
			
			
			
			
			/// Create a copy of the specified Pointer object, increasing its reference count by 1.
			RIM_INLINE Pointer( const Pointer& other )
				:	pointer( other.pointer ),
					count( other.count )
			{
				if ( count != NULL )
					(*count)++;
			}
			
			
			
			
			/// Create a copy of the specified Pointer object, increasing its reference count by 1.
			template < typename U >
			RIM_INLINE Pointer( const Pointer<U>& other )
				:	pointer( other.pointer ),
					count( other.count )
			{
				if ( count != NULL )
					(*count)++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operators
			
			
			
			
			/// Assign the pointer stored by another Pointer object to this object.
			/**
			  * The reference count of the old pointer stored in this object is reduced by 1
			  * and the pointer is copied from the other Pointer object. The reference count
			  * for the new pointer is increased by 1.
			  * 
			  * @param other - the Pointer object whose pointer should be copied.
			  * @return a reference to this Pointer object to allow assignment chaining.
			  */
			RIM_INLINE Pointer& operator = ( const Pointer& other )
			{
				if ( this != &other )
				{
					this->decrementCount();
					
					pointer = other.pointer;
					count = other.count;
					
					if ( count != NULL )
						(*count)++;
				}
				
				return *this;
			}
			
			
			
			
			/// Assign the pointer stored by another Pointer object of different templated type to this object.
			/**
			  * The reference count of the old pointer stored in this object is reduced by 1
			  * and the pointer is copied from the other Pointer object. The reference count
			  * for the new pointer is increased by 1.
			  * 
			  * @param other - the Pointer object whose pointer should be copied.
			  * @return a reference to this Pointer object to allow assignment chaining.
			  */
			template < typename U >
			RIM_INLINE Pointer& operator = ( const Pointer<U>& other )
			{
				this->decrementCount();
				
				pointer = other.pointer;
				count = other.count;
				
				if ( count != NULL )
					(*count)++;
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Release this Pointer's reference to the object.
			RIM_INLINE ~Pointer()
			{
				this->decrementCount();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Cast Operators
			
			
			
			
			/// Cast this Pointer object to a raw pointer.
			RIM_INLINE operator T* () const
			{
				return pointer;
			}
			
			
			
			
			/// Cast this Pointer object to a raw pointer of a different type to allow polymorphism.
			template < typename U >
			RIM_INLINE operator U* () const
			{
				return pointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Comparison Operators
			
			
			
			
			/// Return whether or not this pointer is equal to another pointer.
			/**
			  * This method compares the pointers themselves, not the objects pointed
			  * to by the pointers.
			  * 
			  * @param other - the pointer to compare for equality.
			  * @return whether or not this pointer is equal the other.
			  */
			RIM_INLINE Bool operator == ( const Pointer& other ) const
			{
				return pointer == other.pointer;
			}
			
			
			
			
			/// Return whether or not this pointer is equal to another pointer.
			/**
			  * This method compares the pointers themselves, not the objects pointed
			  * to by the pointers.
			  * 
			  * @param other - the pointer to compare for equality.
			  * @return whether or not this pointer is equal the other.
			  */
			template < typename U >
			RIM_INLINE Bool operator == ( const Pointer<U>& other ) const
			{
				return pointer == other.pointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Inequality Comparison Operators
			
			
			
			
			/// Return whether or not this pointer is not equal to another pointer.
			/**
			  * This method compares the pointers themselves, not the objects pointed
			  * to by the pointers.
			  * 
			  * @param other - the pointer to compare for inequality.
			  * @return whether or not this pointer is not equal the other.
			  */
			RIM_INLINE Bool operator != ( const Pointer& other ) const
			{
				return pointer == other.pointer;
			}
			
			
			
			
			/// Return whether or not this pointer is not equal to another pointer.
			/**
			  * This method compares the pointers themselves, not the objects pointed
			  * to by the pointers.
			  * 
			  * @param other - the pointer to compare for inequality.
			  * @return whether or not this pointer is not equal the other.
			  */
			template < typename U >
			RIM_INLINE Bool operator != ( const Pointer<U>& other ) const
			{
				return pointer == other.pointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Dereference Operators
			
			
			
			
			/// Dereference the object referenced by this Pointer.
			/**
			  * If the pointer is NULL, a debug assertion is raised.
			  * 
			  * @return a reference to the object that this Pointer has a reference to.
			  */
			RIM_INLINE T& operator * () const
			{
				RIM_DEBUG_ASSERT_MESSAGE( pointer != NULL, "Cannot access the contents of a null smart pointer" );
				
				return *pointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pointer Accessor Methods
			
			
			
			
			/// Overload the indirection operator so that this Pointer object behaves like a raw pointer.
			/**
			  * If the pointer is NULL, a debug assertion is raised.
			  * 
			  * @return the raw pointer that this Pointer object has a reference to.
			  */
			RIM_INLINE T* operator->() const
			{
				RIM_DEBUG_ASSERT_MESSAGE( pointer != NULL, "Cannot access the contents of a null smart pointer" );
				
				return pointer;
			}
			
			
			
			
			/// Get a raw pointer to the object which this Pointer references.
			RIM_INLINE T* getPointer() const
			{
				return pointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Pointer Trait Accessor Methods
			
			
			
			
			/// Return whether or not if the object that this Pointer references is not referenced by another Pointer.
			/**
			  * The method returns TRUE if the reference count for the Pointer is 1 or if the pointer
			  * is equal to NULL.
			  * 
			  * @return whether or not the reference count for the Pointer is equal to 1.
			  */
			RIM_INLINE Bool isUnique() const
			{
				if ( count == NULL )
					return true;
				else
					return *count == Size(1);
			}
			
			
			
			
			/// Return whether or not this pointer is equal to NULL.
			RIM_INLINE Bool isNull() const
			{
				return pointer == NULL;
			}
			
			
			
			
			/// Return whether or not this pointer is not equal to NULL.
			RIM_INLINE Bool isSet() const
			{
				return pointer != NULL;
			}
			
			
			
			
			/// Cast this pointer to a boolean value, indicating whether or not the pointer is NULL.
			RIM_INLINE operator Bool () const
			{
				return pointer != NULL;
			}
			
			
			
			
			/// Get the number of references there are to this Pointer's object.
			RIM_INLINE Size getReferenceCount() const
			{
				if ( count == NULL )
					return Size(0);
				else
					return *count;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Release Method
			
			
			
			
			/// Release this pointer's reference to its object, resulting in a NULL pointer with 0 reference count.
			RIM_INLINE void release()
			{
				// Decrement the count, delete if it is 0
				if ( count != NULL )
				{
					if ( --(*count) == 0 )
					{
						// Delete the pointers.
						util::destruct( pointer );
						util::deallocate( count );
					}
					
					// Reset the pointer to NULL.
					pointer = NULL;
					count = NULL;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Casting Methods
			
			
			
			
			/// Cast this pointer to the template type using static_cast.
			template < typename U >
			RIM_INLINE Pointer<U> cast() const
			{
				return Pointer<U>( static_cast<U*>(pointer), count );
			}
			
			
			
			
			/// Cast this pointer to the template type using dynamic_cast.
			/**
			  * If the cast was invalid and not able to performed, a NULL
			  * pointer is returned.
			  */
			template < typename U >
			RIM_INLINE Pointer<U> dynamicCast() const
			{
				U* newPointer = dynamic_cast<U*>(pointer);
				
				if ( newPointer )
					return Pointer<U>( newPointer, count );
				else
					return Pointer<U>();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Construction Helper Methods
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			RIM_INLINE static Pointer construct()
			{
				return Pointer( util::construct<T>() );
			}
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			template < typename P1 >
			RIM_INLINE static Pointer construct( P1 p1 )
			{
				return Pointer( util::construct<T>( p1 ) );
			}
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			template < typename P1, typename P2 >
			RIM_INLINE static Pointer construct( P1 p1, P2 p2 )
			{
				return Pointer( util::construct<T>( p1, p2 ) );
			}
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			template < typename P1, typename P2, typename P3 >
			RIM_INLINE static Pointer construct( P1 p1, P2 p2, P3 p3 )
			{
				return Pointer( util::construct<T>( p1, p2, p3 ) );
			}
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			template < typename P1, typename P2, typename P3, typename P4 >
			RIM_INLINE static Pointer construct( P1 p1, P2 p2, P3 p3, P4 p4 )
			{
				return Pointer( util::construct<T>( p1, p2, p3, p4 ) );
			}
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			template < typename P1, typename P2, typename P3, typename P4, typename P5 >
			RIM_INLINE static Pointer construct( P1 p1, P2 p2, P3 p3, P4 p4, P5 p5 )
			{
				return Pointer( util::construct<T>( p1, p2, p3, p4, p5 ) );
			}
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			template < typename P1, typename P2, typename P3, typename P4, typename P5, typename P6 >
			RIM_INLINE static Pointer construct( P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6 )
			{
				return Pointer( util::construct<T>( p1, p2, p3, p4, p5, p6 ) );
			}
			
			
			
			
			/// Construct an object of the templated type with the specified arguments for its constructor.
			template < typename P1, typename P2, typename P3, typename P4, typename P5, typename P6, typename P7 >
			RIM_INLINE static Pointer construct( P1 p1, P2 p2, P3 p3, P4 p4, P5 p5, P6 p6, P7 p7 )
			{
				return Pointer( util::construct<T>( p1, p2, p3, p4, p5, p6, p7 ) );
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Create a new smart pointer which directly uses the specified pointer and reference count.
			RIM_INLINE Pointer( T* newPointer, threads::atomic::Atomic<Size>* newCount )
				:	pointer( newPointer ),
					count( newCount )
			{
				(*count)++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			/// Release this Pointer's reference to the object which it was pointing to.
			/**
			  * If the reference count reaches zero, the object is destroyed.
			  */
			RIM_INLINE void decrementCount()
			{
				// Decrement the count, delete if it is 0
				if ( count != NULL )
				{
					if ( --(*count) == 0 )
					{
						util::destruct( pointer );
						util::deallocate( count );
					}
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the object which this Pointer has a reference to.
			T* pointer;
			
			
			
			
			/// A pointer to the reference count of this Pointer.
			threads::atomic::Atomic<Size>* count;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class
			
			
			
			
			/// Allow pointer types with a different template parameter to access this class's internals.
			template < typename U >
			friend class Pointer;
			
			
			
			
};




//##########################################################################################
//***************************  End Rim Language Namespace  *********************************
RIM_LANGUAGE_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_POINTER_H

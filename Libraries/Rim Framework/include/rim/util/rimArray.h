/*
 *  rimArray.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 1/19/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ARRAY_H
#define INCLUDE_RIM_ARRAY_H


#include "rimUtilitiesConfig.h"


//##########################################################################################
//***************************  Start Rim Utilities Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a dynamically-sized sequence of objects stored contiguously in memory.
template < class T >
class Array
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create an empty array. This constructor does not allocate any memory.
			RIM_INLINE Array()
				:	pointer( NULL ),
					size( 0 )
			{
			}
			
			
			
			
			/// Create an array of the specified size with default-constructed elements.
			RIM_INLINE explicit Array( Size arraySize )
				:	pointer( util::constructArray<T>( arraySize ) ),
					size( arraySize )
			{
			}
			
			
			
			
			/// Create an array of the specified size with elements created from the specified prototype.
			RIM_INLINE explicit Array( Size arraySize, const T& prototype )
				:	pointer( util::constructArray<T>( arraySize, prototype ) ),
					size( arraySize )
			{
			}
			
			
			
			
			/// Create an array which uses the specified pointer to a block of memory.
			/**
			  * After calling this constructor, the Array now owns the pointer and will
			  * automatically delete it when the array is destructed.
			  */
			RIM_INLINE explicit Array( T* newArray, Size arraySize )
				:	pointer( newArray ),
					size( newArray == NULL ? 0 : arraySize )
			{
			}
			
			
			
			
			/// Create an array with elements from the specified pointer, copying the data.
			RIM_INLINE explicit Array( const T* newArray, Size arraySize )
			{
				if ( newArray != NULL )
				{
					pointer = util::copyArray( newArray, arraySize );
					size = arraySize;
				}
				else
				{
					pointer = NULL;
					size = 0;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructors
			
			
			
			
			/// Create a deep copy of the specified array object.
			RIM_INLINE Array( const Array& other )
				:	pointer( util::copyArray( other.pointer, other.size ) ),
					size( other.size )
			{
			}
			
			
			
			
			/// Create a deep copy of the specified array object, using only the specified number of elements.
			RIM_INLINE Array( const Array& other, Size number )
				:	size( number < other.size ? number : other.size )
			{
				pointer = util::copyArray( other.pointer, size );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operators
			
			
			
			
			/// Copy the contents from another array into this array, replacing the current contents.
			RIM_INLINE Array& operator = ( const Array& other )
			{
				if ( this != &other )
				{
					if ( pointer != NULL )
						util::destructArray( pointer, size );
					
					pointer = util::copyArray( other.pointer, other.size );
					size = other.size;
				}
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			/// Destroy an array object and deallocate its internal array.
			RIM_INLINE ~Array()
			{
				if ( pointer != NULL )
					util::destructArray( pointer, size );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Pointer Accessor Methods
			
			
			
			
			/// Convert this array to a pointer and return the result.
			RIM_INLINE T* getPointer()
			{
				return pointer;
			}
			
			
			
			
			/// Convert this array to a pointer and return the result, const version.
			RIM_INLINE const T* getPointer() const
			{
				return pointer;
			}
			
			
			
			
			/// Convert this array to a pointer.
			RIM_INLINE operator T* ()
			{
				return pointer;
			}
			
			
			
			
			/// Convert this array to a pointer, const version.
			RIM_INLINE operator const T* () const
			{
				return pointer;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Operators
			
			
			
			
			/// Compare this array to another array for equality.
			/**
			  * If this array has the same size as the other array and
			  * has the same elements, the arrays are equal and TRUE is
			  * returned. Otherwise, the arrays are not equal and FALSE is returned.
			  */
			RIM_INLINE Bool operator == ( const Array& array ) const
			{
				if ( size != array.size )
					return false;
				
				const T* compare1 = pointer;
				const T* compare1End = pointer + size;
				const T* compare2 = array.pointer;
				
				while ( compare1 != compare1End )
				{
					if ( *compare1 != *compare2 )
						return false;
					
					compare1++;
					compare2++;
				}
				
				return true;
			}
			
			
			
			
			/// Compare this array to another array for inequality.
			/**
			  * If this array has a different size than the other array or
			  * has different elements, the arrays are not equal and TRUE is
			  * returned. Otherwise, the arrays are equal and FALSE is returned.
			  */
			RIM_INLINE Bool operator != ( const Array& array ) const
			{
				return !(*this == array);
			}
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Concatenation Operators
			
			
			
			
			/// Concatenate the contents of this array with another array and return the resulting new array.
			RIM_NO_INLINE Array operator + ( const Array& other ) const
			{
				Size newArraySize = size + other.size;
				T* newArray = util::allocate<T>( newArraySize );
				T* destination = newArray;
				const T* source1 = pointer;
				const T* const source1End = source1 + size;
				const T* source2 = other.pointer;
				const T* const source2End = source2 + other.size;
				
				while ( source1 != source1End )
				{
					new ( destination ) T( *source1 );
					destination++;
					source1++;
				}
				
				while ( source2 != source2End )
				{
					new ( destination ) T( *source2 );
					destination++;
					source2++;
				}
				
				return Array( newArray, newArraySize );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Size Accessor Methods
			
			
			
			
			/// Get the size of this array.
			RIM_INLINE Size getSize() const
			{
				return size;
			}
			
			
			
			
			/// Resize this array, copying as many elements from the old array to the new array as possible.
			/**
			  * If there are new elements created at the end of the array, they are
			  * default constructed.
			  */
			RIM_INLINE void setSize( Size newSize )
			{
				this->setSize( newSize, T() );
			}
			
			
			
			
			/// Resize this array, copying as many elements from the old array to the new array as possible.
			/**
			  * If there are new elements created at the end of the array, they are
			  * initialize to the specified default value.
			  */
			RIM_NO_INLINE void setSize( Size newSize, const T& prototype );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Element Accessor Methods
			
			
			
			
			/// Set all of the values in this array to the specified value.
			RIM_INLINE void setAll( const T& prototype )
			{
				T* element = pointer;
				const T* const elementsEnd = element + size;
				
				while ( element != elementsEnd )
				{
					*element = prototype;
					element++;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Trait Accessor Methods
			
			
			
			
			/// Return whether or not this array object's internal array is NULL.
			RIM_INLINE Bool isNull() const
			{
				return pointer == NULL;
			}
			
			
			
			
			/// Return whether or not this array object's internal array is not NULL.
			RIM_INLINE Bool isSet() const
			{
				return pointer != NULL;
			}
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the array data.
			T* pointer;
			
			
			
			
			/// The size of the array.
			Size size;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class
			
			
			
			
			template < typename U >
			friend class Array;
			
			
			
};




//##########################################################################################
//##########################################################################################
//############		
//############		Array Size Set Method
//############		
//##########################################################################################
//##########################################################################################




template < typename T >
void Array<T>:: setSize( Size newSize, const T& prototype )
{
	if ( size == newSize )
		return;
	
	if ( pointer != NULL )
	{
		T* oldPointer = pointer;
		T* source = oldPointer;
		T* destination = pointer = util::allocate<T>( newSize );
		const T* const copyEnd = destination + (size < newSize ? size : newSize);
		const T* const constructEnd = destination + newSize;
		
		while ( destination < copyEnd )
		{
			new ( destination ) T( *source );
			destination++;
			source++;
		}
		
		while ( destination < constructEnd )
		{
			new ( destination ) T( prototype );
			destination++;
		}
		
		util::destructArray( oldPointer, size );
		size = newSize;
	}
	else
	{
		pointer = util::constructArray<T>( newSize, prototype );
		size = newSize;
	}
}




//##########################################################################################
//***************************  End Rim Utilities Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ARRAY_H

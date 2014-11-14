/*
 *  rimStaticArray.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/20/10.
 *  Copyright 2010 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_STATIC_ARRAY_H
#define INCLUDE_RIM_STATIC_ARRAY_H


#include "rimUtilitiesConfig.h"


//##########################################################################################
//***************************  Start Rim Utilities Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which provides a safe wrapper for statically-sized arrays.
template < class T, Size size >
class StaticArray
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create an empty static array with all elements default initialized.
			RIM_INLINE StaticArray()
			{
				T* current = (T*)data;
				const T* const arrayEnd = current + size;
				
				while ( current != arrayEnd )
				{
					new (current) T();
					current++;
				}
			}
			
			
			
			
			/// Create a static array with all elements initialized to some prototype value.
			RIM_INLINE explicit StaticArray( const T& prototype )
			{
				T* current = (T*)data;
				const T* const arrayEnd = current + size;
				
				while ( current != arrayEnd )
				{
					new (current) T( prototype );
					current++;
				}
			}
			
			
			
			
			/// Create a static array with elements from the specified pointer.
			RIM_INLINE explicit StaticArray( const T* newArray )
			{
				copyElements( (T*)data, newArray );
			}
			
			
			
			
			/// Create a static array with elements from the specified pointer of a different type.
			template < typename U >
			RIM_INLINE explicit StaticArray( const U* newArray )
			{
				copyElements( (T*)data, newArray );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Copy Constructor
			
			
			
			
			/// Create a copy of the specified static array.
			RIM_INLINE StaticArray( const StaticArray& other )
			{
				T* destination = (T*)data;
				const T* const destinationEnd = destination + size;
				const T* source = (const T*)other.data;
				
				while ( destination != destinationEnd )
				{
					new (destination) T( *source );
					source++;
					destination++;
				}
			}
			
			
			
			
			/// Create a copy of the specified static array with different data type.
			template < typename U >
			RIM_INLINE StaticArray( const StaticArray<U,size>& other )
			{
				T* destination = (T*)data;
				const T* const destinationEnd = destination + size;
				const U* source = (const U*)other.data;
				
				while ( destination != destinationEnd )
				{
					new (destination) T( *source );
					source++;
					destination++;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operators
			
			
			
			
			/// Assign the contents of another static array to this one.
			RIM_INLINE StaticArray& operator = ( const StaticArray& other )
			{
				if ( this != &other )
					memberWiseCopy( (T*)data, (const T*)other.data, size );
				
				return *this;
			}
			
			
			
			
			/// Assign the contents of another static array with different element type to this one.
			template < typename U >
			RIM_INLINE StaticArray& operator = ( const StaticArray<U,size>& other )
			{
				memberWiseCopy( (T*)data, (const U*)other.data, size );
				
				return *this;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy an static array object, destroying all elements that it contains.
			RIM_INLINE ~StaticArray()
			{
				T* current = (T*)data;
				const T* const arrayEnd = current + size;
				
				while ( current != arrayEnd )
				{
					current->~T();
					current++;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Pointer Accessor Methods
			
			
			
			
			/// Return a pointer to this static array's internal array pointer.
			RIM_INLINE T* getPointer()
			{
				return (T*)data;
			}
			
			
			
			
			/// Return a const pointer to this static array's internal array pointer.
			RIM_INLINE const T* getPointer() const
			{
				return (const T*)data;
			}
			
			
			
			
			/// Convert this static array to a const pointer to its first element.
			RIM_INLINE operator T* ()
			{
				return (T*)data;
			}
			
			
			
			
			/// Convert this static array to a const pointer to its first element.
			RIM_INLINE operator const T* () const
			{
				return (const T*)data;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Equality Operators
			
			
			
			
			/// Return whether or not every element in this Static Array is equal to another's elements.
			RIM_INLINE Bool operator == ( const StaticArray& other ) const
			{
				const T* compare1 = (const T*)data;
				const T* compare1End = compare1 + size;
				const T* compare2 = (const T*)other.data;
				
				while ( compare1 != compare1End )
				{
					if ( *compare1 != *compare2 )
						return false;
					
					compare1++;
					compare2++;
				}
				
				return true;
			}
			
			
			
			
			/// Return whether or not every element in this Static Array is not equal to another's elements.
			RIM_INLINE Bool operator != ( const StaticArray& other ) const
			{
				return !(*this == other);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	StaticArray Concatenation Operators
			
			
			
			
			/// Apend the contents of this static array to another and return the result.
			template < Size otherSize >
			RIM_INLINE StaticArray< T, size + otherSize > operator + ( const StaticArray<T,otherSize>& other ) const
			{
				StaticArray< T, size + otherSize > result;
				
				memberWiseCopy( (T*)result.data, (const T*)data, size );
				memberWiseCopy( (T*)result.data + size, (const T*)other.data, otherSize );
				
				return result;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Size Accessor Methods
			
			
			
			
			/// Return the number of elements in this static array.
			RIM_INLINE Size getSize() const
			{
				return size;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Array Element Accessor Methods
			
			
			
			
			/// Set all of the values in this array to the specified value.
			RIM_INLINE void setAll( const T& prototype )
			{
				T* element = (T*)data;
				const T* const elementsEnd = element + size;
				
				while ( element != elementsEnd )
				{
					*element = prototype;
					element++;
				}
			}
			
			
			
			
	private:
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Methods
			
			
			
			
			template < typename A, typename B >
			static void memberWiseCopy( A* destination, const B* source, Size number )
			{
				const B* const sourceEnd = source + number;
				
				while ( source != sourceEnd )
				{
					*destination = *source;
					
					destination++;
					source++;
				}
			}
			
			
			
			
			template < typename A, typename B >
			static void copyElements( A* destination, const B* source )
			{
				A* current = destination;
				const A* const destinationEnd = destination + size;
				
				while ( destination != destinationEnd )
				{
					new (destination) A( *source );
					
					destination++;
					source++;
				}
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of bytes with static size that hold the elements in this static array.
			UByte data[sizeof(T)*size];
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Friend Class
			
			
			
			
			template < typename U, Size otherSize >
			friend class StaticArray;
			
			
			
};




//##########################################################################################
//***************************  End Rim Utilities Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_STATIC_ARRAY_H

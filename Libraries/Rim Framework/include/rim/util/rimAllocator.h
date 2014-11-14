/*
 *  rimAllocator.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 2/9/11.
 *  Copyright 2011 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ALLOCATOR_H
#define INCLUDE_RIM_ALLOCATOR_H


#include "rimUtilitiesConfig.h"


//##########################################################################################
//***************************  Start Rim Utilities Namespace  ******************************
RIM_UTILITIES_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//##########################################################################################
//##########################################################################################
//############		
//############		Object Allocation Methods
//############		
//##########################################################################################
//##########################################################################################




/// Allocate memory for a single object of type T.
/**
  * This method returns a pointer to the start of the object in memory.
  * The constructor of the allocated object is not called. It is the
  * responsibility of the user to use placement new to initialize the
  * object. Alternatively, one can call the construct() method instead
  * which initializes the memory location by calling placement new after
  * allocating the memory.
  */
template < typename T >
RIM_FORCE_INLINE T* allocate()
{
	// Call a macro defined in RimConfig,h to allocate the memory.
	register T* memory = (T*)RIM_MALLOC(sizeof(T));
	
	// Make sure that the memory location returned is not null.
	RIM_DEBUG_ASSERT( memory != NULL );
	
	return memory;
}




/// Allocate memory for the specified number of objects of type T.
/**
  * This method returns a pointer to the start of the first object in memory.
  * No constructors are called on the allocated memory locations. One must use
  * placement new in order to initialize the objects.
  * 
  * @param count - the number of objects to allocate space for.
  */
template < typename T >
RIM_FORCE_INLINE T* allocate( Size count )
{
	// Call a macro defined in RimConfig,h to allocate the memory.
	register T* memory = (T*)RIM_MALLOC(count*sizeof(T));
	
	// Make sure that the memory location returned is not null.
	RIM_DEBUG_ASSERT( memory != NULL );
	
	return memory;
}




/// Allocate memory for the specified number of objects of type T.
/**
  * This method returns a pointer to the start of the first object in memory.
  * No constructors are called on the allocated memory locations. One must use
  * placement new in order to initialize the objects.
  * 
  * @param count - the number of objects to allocate space for.
  * @param alignment - the required alignment for the memory in bytes.
  */
template < typename T >
RIM_FORCE_INLINE T* allocateAligned( Size count, Size alignment )
{
	// Call a macro defined in RimConfig,h to allocate the memory.
	register T* memory = (T*)RIM_ALIGNED_MALLOC(count*sizeof(T), alignment);
	
	// Make sure that the memory location returned is not null.
	RIM_DEBUG_ASSERT( memory != NULL );
	
	return memory;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Pointer Deallocation Method
//############		
//##########################################################################################
//##########################################################################################




/// Free the memory block pointed to by the specified pointer.
/**
  * If the pointer is NULL, an assertion is raised.
  * 
  * @param pointer - a pointer to the memory to be deallocated.
  */
template < typename T >
RIM_FORCE_INLINE void deallocate( T* pointer )
{
	// Make sure that the memory location to free is not null.
	RIM_DEBUG_ASSERT_MESSAGE( pointer != NULL, "Cannot deallocate NULL pointer." );
	
	// Call a macro defined in rimConfig.h to free the memory.
	RIM_FREE( (void*)pointer );
}




/// Free the aligned memory block pointed to by the specified pointer.
/**
  * If the pointer is NULL, an assertion is raised. This method should
  * only be called on memory aligned using the allocateAligned() family of
  * functions.
  * 
  * @param pointer - a pointer to the memory to be deallocated.
  */
template < typename T >
RIM_FORCE_INLINE void deallocateAligned( T* pointer )
{
	// Make sure that the memory location to free is not null.
	RIM_DEBUG_ASSERT_MESSAGE( pointer != NULL, "Cannot deallocate NULL pointer." );
	
	// Call a macro defined in rimConfig.h to free the memory.
	RIM_ALIGNED_FREE( pointer );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Object Construction Methods
//############		
//##########################################################################################
//##########################################################################################




/// Construct and allocate an object of the templated type T, calling the default constructor.
template < typename T >
RIM_INLINE T* construct()
{
	register T* object = allocate<T>();
	
	new (object) T();
	
	return object;
}




/// Construct and allocate an object of the templated type T with one constructor parameter.
template < typename T, typename P1 >
RIM_INLINE T* construct( const P1& p1 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 2 constructor parameters.
template < typename T, typename P1, typename P2 >
RIM_INLINE T* construct( const P1& p1, const P2& p2 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 3 constructor parameters.
template < typename T, typename P1, typename P2, typename P3 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 4 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3, const P4& p4 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3, p4 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 5 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3, p4, p5 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 6 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3, p4, p5, p6 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 7 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3, p4, p5, p6, p7 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 8 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3, p4, p5, p6, p7, p8 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 9 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8, typename P9 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P9& p9 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3, p4, p5, p6, p7, p8, p9 );
	
	return object;
}




/// Construct and allocate an object of the templated type T with 10 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8, typename P9, typename P10 >
RIM_INLINE T* construct( const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P9& p9, const P10& p10 )
{
	register T* object = allocate<T>();
	
	new (object) T( p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
	
	return object;
}





//##########################################################################################
//##########################################################################################
//############		
//############		Object Destruction Method
//############		
//##########################################################################################
//##########################################################################################




/// Destruct and free an object of the templated type T at the specified location.
/**
  * This method calls the destructor of the pointed-to object and then deallocates
  * the memory used by that object. If the object pointer is NULL, an assertion is raised.
  * 
  * @param pointer - a pointer to the object to be destroyed.
  */
template < typename T >
RIM_FORCE_INLINE void destruct( T* object )
{
	RIM_DEBUG_ASSERT_MESSAGE( object != NULL, "Cannot deallocate NULL object pointer." );
	
	// Call the object's destructor.
	object->~T();
	
	// Deallocate the memory use by the object.
	deallocate( object );
}




//##########################################################################################
//##########################################################################################
//############		
//############		Object Array Construction Methods
//############		
//##########################################################################################
//##########################################################################################




/// Construct and allocate an array of objects of the templated type T, calling the default constructor.
template < typename T >
RIM_INLINE T* constructArray( Size number )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T();
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with one constructor parameter.
template < typename T, typename P1 >
RIM_INLINE T* constructArray( Size number, const P1& p1 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 2 constructor parameters.
template < typename T, typename P1, typename P2 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 3 constructor parameters.
template < typename T, typename P1, typename P2, typename P3 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 4 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3, const P4& p4 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 5 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 6 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 7 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 8 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7, p8 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 9 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8, typename P9 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P9& p9 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7, p8, p9 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 10 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8, typename P9, typename P10 >
RIM_INLINE T* constructArray( Size number, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P9& p9, const P10& p10 )
{
	register T* objects = allocate<T>( number );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
		object++;
	}
	
	return objects;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Aligned Object Array Construction Methods
//############		
//##########################################################################################
//##########################################################################################




/// Construct and allocate an array of objects of the templated type T, calling the default constructor.
template < typename T >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T();
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with one constructor parameter.
template < typename T, typename P1 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 2 constructor parameters.
template < typename T, typename P1, typename P2 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 3 constructor parameters.
template < typename T, typename P1, typename P2, typename P3 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 4 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3, const P4& p4 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 5 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 6 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 7 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 8 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7, p8 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 9 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8, typename P9 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P9& p9 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7, p8, p9 );
		object++;
	}
	
	return objects;
}




/// Construct and allocate an array of objects of the templated type T with 10 constructor parameters.
template < typename T, typename P1, typename P2, typename P3, typename P4, typename P5,
						typename P6, typename P7, typename P8, typename P9, typename P10 >
RIM_INLINE T* constructArrayAligned( Size number, Size alignment, const P1& p1, const P2& p2, const P3& p3, const P4& p4, const P5& p5, const P6& p6, const P7& p7, const P8& p8, const P9& p9, const P10& p10 )
{
	register T* objects = allocateAligned<T>( number, alignment );
	
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		new (object) T( p1, p2, p3, p4, p5, p6, p7, p8, p9, p10 );
		object++;
	}
	
	return objects;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Array Copy Method
//############		
//##########################################################################################
//##########################################################################################




/// Allocate a new array and copy the specified number of elements from an old array.
template < typename T >
RIM_INLINE T* copyArray( const T* oldArray, Size number )
{
	register T* newArray = allocate<T>( number );
	
	const T* oldObject = oldArray;
	const T* const oldArrayEnd = oldArray + number;
	T* newObject = newArray;
	
	while ( oldObject != oldArrayEnd )
	{
		new (newObject) T(*oldObject);
		oldObject++;
		newObject++;
	}
	
	return newArray;
}




/// Allocate a new aligned array and copy the specified number of elements from an old array.
template < typename T >
RIM_INLINE T* copyArrayAligned( const T* oldArray, Size number, Size alignment )
{
	register T* newArray = allocateAligned<T>( number, alignment );
	
	const T* oldObject = oldArray;
	const T* const oldArrayEnd = oldArray + number;
	T* newObject = newArray;
	
	while ( oldObject != oldArrayEnd )
	{
		new (newObject) T(*oldObject);
		oldObject++;
		newObject++;
	}
	
	return newArray;
}




//##########################################################################################
//##########################################################################################
//############		
//############		Object Array Destruction Method
//############		
//##########################################################################################
//##########################################################################################




/// Destruct and free an array of objects of the templated type T at the specified location.
template < typename T >
RIM_INLINE void destructArray( T* objects, Size number )
{
	RIM_DEBUG_ASSERT( objects != NULL );
	
	// Call the objects' destructors.
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		object->~T();
		object++;
	}
	
	// Deallocate the memory use by the objects.
	deallocate( objects );
}




/// Destruct and free an array of objects of the templated type T at the specified location.
/**
  * This method should only be used to deallocate memory allocated with the allocateAligned()
  * family of functions.
  */
template < typename T >
RIM_INLINE void destructArrayAligned( T* objects, Size number )
{
	RIM_DEBUG_ASSERT( objects != NULL );
	
	// Call the objects' destructors.
	T* object = objects;
	const T* const objectsEnd = objects + number;
	
	while ( object != objectsEnd )
	{
		object->~T();
		object++;
	}
	
	// Deallocate the memory use by the objects.
	deallocateAligned( objects );
}




//##########################################################################################
//***************************  End Rim Utilities Namespace  ********************************
RIM_UTILITIES_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ALLOCATOR_H

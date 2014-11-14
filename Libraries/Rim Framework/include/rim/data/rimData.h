/*
 *  rimData.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 3/24/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_DATA_H
#define INCLUDE_RIM_DATA_H


#include "rimDataConfig.h"


#include "../util/rimArray.h"


#include "rimHashCode.h"


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an immutable array of unsigned byte data.
/**
  * The Data class is the data-oriented analogue to the BasicString class. It is
  * designed to hold an opaque block of data resident in memory. A Data object could
  * be used to hold anything: images, audio, even text. The internal array of data
  * is reference-counted in order to reduce unintended copying.
  */
class Data
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create an empty Data object that doesn't hold any data.
			RIM_INLINE Data()
				:	data( NULL ),
					size( 0 ),
					referenceCount( NULL ),
					haveCalculatedHash( false )
			{
			}
			
			
			
			
			/// Create a Data object which contains only the specified unsigned byte.
			RIM_INLINE Data( const UByte& newData )
				:	data( util::construct<UByte>(newData) ),
					size( 1 ),
					referenceCount( util::construct<Size>(1) ),
					haveCalculatedHash( false )
			{
			}
			
			
			
			
			/// Create a Data object by copying the specified number of bytes from the given data pointer.
			Data( const UByte* newData, Size number );
			
			
			
			
			/// Create a Data object by copying the specified data array.
			Data( const util::Array<UByte>& array );
			
			
			
			
			/// Create a Data object by copying the specified number of bytes from the given data array.
			Data( const util::Array<UByte>& array, Size number );
			
			
			
			
			RIM_INLINE Data( const Data& other )
				:	data( other.data ),
					size( other.size ),
					referenceCount( other.referenceCount ),
					hashCode( other.hashCode ),
					haveCalculatedHash( other.haveCalculatedHash )
			{
				if ( referenceCount )
					(*referenceCount)++;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Factory Methods
			
			
			
			
			/// Create a data object from the specified byte array with the specified size.
			/**
			  * Once this method completes, it is expected that the Data object now owns
			  * the data array pointer and will free it upon destruction.
			  */
			RIM_INLINE static Data shallow( UByte* array, Size size )
			{
				return Data( array, size, 0 );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy a Data object, deallocating the internal data array if the reference count reaches zero.
			~Data();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign the contents of another Data object to this object.
			Data& operator = ( const Data& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Return the number of bytes of data that this Data object holds.
			RIM_INLINE Size getSize() const
			{
				return size;
			}
			
			
			
			
			/// Return the number of bytes of data that this Data object holds.
			RIM_INLINE Size getSizeInBytes() const
			{
				return size;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Accessor Methods
			
			
			
			
			/// Get a pointer to the internal array of bytes that this Data object holds.
			RIM_INLINE const UByte* getPointer() const
			{
				return data;
			}
			
			
			
			
			/// Get a pointer to the internal array of bytes that this Data object holds.
			RIM_INLINE operator const UByte* () const
			{
				return data;
			}
			
			
			
			
			/// Access the byte at the specified index in the Data object's internal array.
			RIM_INLINE const UByte& operator () ( Index index ) const
			{
				RIM_DEBUG_ASSERT_MESSAGE( index < size, "Cannot access invalid byte index in data array" );
				
				return data[index];
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Comparison Operators
			
			
			
			
			/// Return whether or not the data contained in this Data object is identical to another's.
			Bool equals( const Data& other ) const;
			
			
			
			
			/// Return whether or not the data contained in this Data object is identical to another's.
			RIM_INLINE Bool operator == ( const Data& other ) const
			{
				return this->equals( other );
			}
			
			
			
			
			/// Return whether or not the data contained in this Data object is not identical to another's.
			RIM_INLINE Bool operator != ( const Data& other ) const
			{
				return !this->equals( other );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Data Concatentation Methods
			
			
			
			
			/// Return a Data object containing the concatenation of this data and the specified data.
			Data concatenate( const Data& other ) const;
			
			
			
			
			/// Return a Data object containing the concatenation of this data and the specified data.
			RIM_INLINE Data operator + ( const Data& other ) const
			{
				return this->concatenate( other );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Hash Code Accessor Method
			
			
			
			
			/// Get a hash code for this Data object.
			RIM_INLINE Hash getHashCode() const
			{
				if ( haveCalculatedHash )
					return hashCode;
				else
				{
					hashCode = HashCode( data, size );
					
					return hashCode;
				}
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Constructor
			
			
			
			
			/// Shallowly create a Data object from a raw pointer.
			RIM_INLINE Data( UByte* newData, Size newSize, int )
				:	data( newData ),
					size( newSize ),
					referenceCount( util::construct<Size>( 1 ) ),
					haveCalculatedHash( false )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to the array of bytes that this Data object holds.
			UByte* data;
			
			
			
			
			/// The number of bytes of data that this Data object holds.
			Size size;
			
			
			
			
			/// A pointer to the location of the data object's reference count.
			Size* referenceCount;
			
			
			
			
			/// The hash code of this data
			mutable Hash hashCode;
			
			
			
			
			/// Whether or not the hash code for this data has been calculated already.
			mutable Bool haveCalculatedHash;
			
			
			
};




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_DATA_H

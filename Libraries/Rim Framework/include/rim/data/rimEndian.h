/*
 *  rimEndian.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 6/18/09.
 *  Copyright 2009 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_ENDIAN_H
#define INCLUDE_RIM_ENDIAN_H


#include "rimDataConfig.h"


#include "rimBasicString.h"


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




namespace endian
{
	Int16 swap( Int16 value );
	UInt16 swap( UInt16 value );
	
	Int32 swap( Int32 value );
	UInt32 swap( UInt32 value );
	
	Int64 swap( Int64 value );
	UInt64 swap( UInt64 value );
	
	RIM_INLINE Float32 swap( Float32 value )
	{
		UInt32 result = swap( *((UInt32*)&value) );
		
		return *((Float32*)&result);
	}
	
	
	RIM_INLINE Float64 swap( Float64 value )
	{
		UInt64 result = swap( *((UInt64*)&value) );
		
		return *((Float64*)&result);
	}
	
	
#ifdef RIM_LITTLE_ENDIAN
	
	
	RIM_INLINE Int16 fromBigEndian( Int16 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE UInt16 fromBigEndian( UInt16 value )
	{
		return swap(value);
	}
	
	RIM_INLINE Int32 fromBigEndian( Int32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt32 fromBigEndian( UInt32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE Int64 fromBigEndian( Int64 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt64 fromBigEndian( UInt64 value )
	{
		return swap(value);
	}
	
	RIM_INLINE Float32 fromBigEndian( Float32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE Float64 fromBigEndian( Float64 value )
	{
		return swap(value);
	}
	
	
	
	RIM_INLINE Int16 fromLittleEndian( Int16 value )
	{
		return value;
	}
	
	RIM_INLINE UInt16 fromLittleEndian( UInt16 value )
	{
		return value;
	}
	
	
	RIM_INLINE Int32 fromLittleEndian( Int32 value )
	{
		return value;
	}
	
	RIM_INLINE UInt32 fromLittleEndian( UInt32 value )
	{
		return value;
	}
	
	
	RIM_INLINE Int64 fromLittleEndian( Int64 value )
	{
		return value;
	}
	
	RIM_INLINE UInt64 fromLittleEndian( UInt64 value )
	{
		return value;
	}
	
	
	RIM_INLINE Float32 fromLittleEndian( Float32 value )
	{
		return value;
	}
	
	RIM_INLINE Float64 fromLittleEndian( Float64 value )
	{
		return value;
	}
	
	
	
	RIM_INLINE Int16 toBigEndian( Int16 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt16 toBigEndian( UInt16 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Int32 toBigEndian( Int32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt32 toBigEndian( UInt32 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Int64 toBigEndian( Int64 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt64 toBigEndian( UInt64 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Float32 toBigEndian( Float32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE Float64 toBigEndian( Float64 value )
	{
		return swap(value);
	}
	
	
	
	RIM_INLINE Int16 toLittleEndian( Int16 value )
	{
		return value;
	}
	
	RIM_INLINE UInt16 toLittleEndian( UInt16 value )
	{
		return value;
	}
	
	
	RIM_INLINE Int32 toLittleEndian( Int32 value )
	{
		return value;
	}
	
	RIM_INLINE UInt32 toLittleEndian( UInt32 value )
	{
		return value;
	}
	
	
	RIM_INLINE Int64 toLittleEndian( Int64 value )
	{
		return value;
	}
	
	RIM_INLINE UInt64 toLittleEndian( UInt64 value )
	{
		return value;
	}
	
	
	RIM_INLINE Float32 toLittleEndian( Float32 value )
	{
		return value;
	}
	
	RIM_INLINE Float64 toLittleEndian( Float64 value )
	{
		return value;
	}
	
	
	
	RIM_INLINE Bool isBigEndian()
	{
		return false;
	}
	
	
	RIM_INLINE Bool isLittleEndian()
	{
		return true;
	}
	
#else
#ifdef RIM_BIG_ENDIAN
	
	
	RIM_INLINE Int16 fromBigEndian( Int16 value )
	{
		return value;
	}
	
	
	RIM_INLINE UInt16 fromBigEndian( UInt16 value )
	{
		return value;
	}
	
	RIM_INLINE Int32 fromBigEndian( Int32 value )
	{
		return value;
	}
	
	RIM_INLINE UInt32 fromBigEndian( UInt32 value )
	{
		return value;
	}
	
	RIM_INLINE Int64 fromBigEndian( Int64 value )
	{
		return value;
	}
	
	RIM_INLINE UInt64 fromBigEndian( UInt64 value )
	{
		return value;
	}
	
	RIM_INLINE Float32 fromBigEndian( Float32 value )
	{
		return value;
	}
	
	RIM_INLINE Float64 fromBigEndian( Float64 value )
	{
		return value;
	}
	
	
	
	RIM_INLINE Int16 fromLittleEndian( Int16 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt16 fromLittleEndian( UInt16 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Int32 fromLittleEndian( Int32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt32 fromLittleEndian( UInt32 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Int64 fromLittleEndian( Int64 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt64 fromLittleEndian( UInt64 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Float32 fromLittleEndian( Float32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE Float64 fromLittleEndian( Float64 value )
	{
		return swap(value);
	}
	
	
	
	RIM_INLINE Int16 toBigEndian( Int16 value )
	{
		return value;
	}
	
	RIM_INLINE UInt16 toBigEndian( UInt16 value )
	{
		return value;
	}
	
	
	RIM_INLINE Int32 toBigEndian( Int32 value )
	{
		return value;
	}
	
	RIM_INLINE UInt32 toBigEndian( UInt32 value )
	{
		return value;
	}
	
	
	RIM_INLINE Int64 toBigEndian( Int64 value )
	{
		return value;
	}
	
	RIM_INLINE UInt64 toBigEndian( UInt64 value )
	{
		return value;
	}
	
	
	RIM_INLINE Float32 toBigEndian( Float32 value )
	{
		return value;
	}
	
	RIM_INLINE Float64 toBigEndian( Float64 value )
	{
		return value;
	}
	
	
	
	RIM_INLINE Int16 toLittleEndian( Int16 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt16 toLittleEndian( UInt16 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Int32 toLittleEndian( Int32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt32 toLittleEndian( UInt32 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Int64 toLittleEndian( Int64 value )
	{
		return swap(value);
	}
	
	RIM_INLINE UInt64 toLittleEndian( UInt64 value )
	{
		return swap(value);
	}
	
	
	RIM_INLINE Float32 toLittleEndian( Float32 value )
	{
		return swap(value);
	}
	
	RIM_INLINE Float64 toLittleEndian( Float64 value )
	{
		return swap(value);
	}
	
	
	
	RIM_INLINE Bool isBigEndian()
	{
		return true;
	}
	
	
	RIM_INLINE Bool isLittleEndian()
	{
		return false;
	}
	
#endif
#endif
	
};




class Endianness
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Endianness Type Enum Definition
			
			
			
			
			typedef enum Enum
			{
				BIG,
				LITTLE
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a endianness type that represents the standard endianness for the current platform.
			RIM_INLINE Endianness()
			{
				#if defined(RIM_BIG_ENDIAN)
					type = BIG;
				#elif defined(RIM_LITTLE_ENDIAN)
					type = LITTLE;
				#endif
			}
			
			
			
			
			/// Create a endianness type with the specified endianness type enum value.
			RIM_INLINE Endianness( Enum newType )
				:	type( newType )
			{
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Enum Cast Operator
			
			
			
			
			/// Convert this endianness type to an enum value.
			RIM_INLINE operator Enum () const
			{
				return type;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Endianness Conversion Methods
			
			
			
			
			/// Convert the specified value, assumed to be in this endianness, to native endianness.
			template < typename T >
			RIM_INLINE T convertToNative( T value ) const
			{
				if ( type == BIG )
					return endian::fromBigEndian( value );
				else
					return endian::fromLittleEndian( value );
			}
			
			
			
			
			/// Convert the specified value, assumed to be in native endianness, to this endianness.
			template < typename T >
			RIM_INLINE T convertFromNative( T value ) const
			{
				if ( type == BIG )
					return endian::toBigEndian( value );
				else
					return endian::toLittleEndian( value );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Is Native Accessor Method
			
			
			
			
			/// Return whether or not this Endianness is the native endianness of the current platform.
			RIM_INLINE Bool isNative() const
			{
				#if defined(RIM_BIG_ENDIAN)
					if ( type == BIG )
						return true;
				#elif defined(RIM_LITTLE_ENDIAN)
					if ( type == LITTLE )
						return true;
				#endif
				
				return false;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Representation Accessor Methods
			
			
			
			
			/// Return a string representation of the endianness type.
			RIM_INLINE String toString() const
			{
				switch ( type )
				{
					case BIG:
						return String("Big Endian");
					case LITTLE:
						return String("Little Endian");
					default:
						return String("Undefined");
				}
			}
			
			
			
			
			/// Convert this endianness type into a string representation.
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An enum for the endianness type.
			Enum type;
			
			
			
			
};




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_ENDIAN_H

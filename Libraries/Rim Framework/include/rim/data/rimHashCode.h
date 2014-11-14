/*
 *  rimHashCode.h
 *  Rim Framework
 *
 *  Created by Carl Schissler on 12/28/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_HASH_CODE_H
#define INCLUDE_RIM_HASH_CODE_H


#include "rimDataConfig.h"


//##########################################################################################
//*******************************   Start Data Namespace   *********************************
RIM_DATA_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




class HashCode
{
	public:
		
		
		template < typename DataType >
		RIM_INLINE HashCode( const DataType* data, Size number )
		{
			hashCode = computeHashCode( (const UByte*)data, sizeof(DataType)*number );
		}
		
		
		
		RIM_INLINE operator Hash () const
		{
			return hashCode;
		}
		
		
	private:
		
		static Hash computeHashCode( const UByte* data, Size length );
		
		
		Hash hashCode;
		
};




//##########################################################################################
//*******************************   End Data Namespace   ***********************************
RIM_DATA_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_HASH_CODE_H

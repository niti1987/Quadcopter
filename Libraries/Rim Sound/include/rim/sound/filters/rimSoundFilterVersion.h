/*
 *  rimSoundFilterVersion.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 8/15/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_VERSION_H
#define INCLUDE_RIM_SOUND_FILTER_VERSION_H


#include "rimSoundFiltersConfig.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the version number of a SoundFilter class.
class SoundFilterVersion
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a version object representing the default version: 0.0.0
			RIM_INLINE SoundFilterVersion()
				:	majorVersion( 0 ),
					minorVersion( 0 ),
					revisionVersion( 0 )
			{
			}
			
			
			
			
			/// Create a version object representing the specified major/minor/revision version.
			RIM_INLINE SoundFilterVersion( UInt newMajorVersion, UInt newMinorVersion = 0,
											UInt newRevisionVersion = 0 )
				:	majorVersion( newMajorVersion ),
					minorVersion( newMinorVersion ),
					revisionVersion( newRevisionVersion )
			{
			}
			
			
			
			
			/// Create a version object that attempts to parse the specified version string.
			/**
			  * The string must be of the form "M.m.r" where 'M' is the major version
			  * number, 'm' is the minor version number, and 'r' is the revision number.
			  * If there is an error in parsing the string, the created version numbers are 0.0.0
			  */
			SoundFilterVersion( const String& versionString );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Major Version Accessor Methods
			
			
			
			
			/// Return the major version number for this sound filter version object.
			RIM_INLINE UInt getMajor() const
			{
				return majorVersion;
			}
			
			
			
			
			/// Set the major version number for this sound filter version object.
			RIM_INLINE void setMajor( UInt newMajorVersion )
			{
				majorVersion = newMajorVersion;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Minor Version Accessor Methods
			
			
			
			
			/// Return the minor version number for this sound filter version object.
			RIM_INLINE UInt getMinor() const
			{
				return minorVersion;
			}
			
			
			
			
			/// Set the minor version number for this sound filter version object.
			RIM_INLINE void setMinor( UInt newMinorVersion )
			{
				minorVersion = newMinorVersion;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Minor Version Accessor Methods
			
			
			
			
			/// Return the revision version number for this sound filter version object.
			RIM_INLINE UInt getRevision() const
			{
				return revisionVersion;
			}
			
			
			
			
			/// Set the revision version number for this sound filter version object.
			RIM_INLINE void setRevision( UInt newRevisionVersion )
			{
				revisionVersion = newRevisionVersion;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Version Comparison Operators
			
			
			
			
			/// Return whether or not this filter version number is exactly equal to another version number.
			RIM_INLINE Bool operator == ( const SoundFilterVersion& other ) const
			{
				return majorVersion == other.majorVersion && minorVersion == other.minorVersion && 
						revisionVersion == other.revisionVersion;
			}
			
			
			
			
			/// Return whether or not this filter version number is not equal to another version number.
			RIM_INLINE Bool operator != ( const SoundFilterVersion& other ) const
			{
				return majorVersion != other.majorVersion || minorVersion != other.minorVersion ||
						revisionVersion != other.revisionVersion;
			}
			
			
			
			
			/// Return whether or not this filter version number is earlier than another version number.
			Bool operator < ( const SoundFilterVersion& other ) const;
			
			
			
			
			/// Return whether or not this filter version number is earlier than or equal to another version number.
			Bool operator <= ( const SoundFilterVersion& other ) const;
			
			
			
			
			/// Return whether or not this filter version number is later than another version number.
			Bool operator > ( const SoundFilterVersion& other ) const;
			
			
			
			
			/// Return whether or not this filter version number is later than or equal to another version number.
			Bool operator >= ( const SoundFilterVersion& other ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Conversion Methods
			
			
			
			
			/// Convert this filter version to a human-readable string format.
			/**
			  * The returned string is of the form "M.m.r" where 'M' is the major version
			  * number, 'm' is the minor version number, and 'r' is the revision number.
			  */
			String toString() const;
			
			
			
			
			/// Convert this filter version to a human-readable string format.
			/**
			  * The returned string is of the form "M.m.r" where 'M' is the major version
			  * number, 'm' is the minor version number, and 'r' is the revision number.
			  */
			RIM_INLINE operator String () const
			{
				return this->toString();
			}
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An integer representing the major version number of a sound filter.
			UInt majorVersion;
			
			
			
			
			/// An integer representing the minor version number of a sound filter.
			UInt minorVersion;
			
			
			
			
			/// An integer representing the revision version number of a sound filter.
			UInt revisionVersion;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_VERSION_H

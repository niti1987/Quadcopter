/*
 *  rimShaderLanguageVersion.h
 *  Rim Software
 *
 *  Created by Carl Schissler on 11/25/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_SHADER_LANGUAGE_VERSION_H
#define INCLUDE_RIM_GRAPHICS_SHADER_LANGUAGE_VERSION_H


#include "rimGraphicsShadersConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Shaders Namespace  ***************************
RIM_GRAPHICS_SHADERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents the version number of a shader language.
/**
  * A version number is specified by a major version number, minor version
  * number, and revision number
  */
class ShaderLanguageVersion
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a version object representing the default version: 0.0.0
			RIM_INLINE ShaderLanguageVersion()
				:	majorVersion( 0 ),
					minorVersion( 0 ),
					revisionVersion( 0 )
			{
			}
			
			
			
			
			/// Create a version object representing the specified major/minor/revision version.
			RIM_INLINE ShaderLanguageVersion( UInt newMajorVersion, UInt newMinorVersion = 0,
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
			ShaderLanguageVersion( const String& versionString );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Major Version Accessor Methods
			
			
			
			
			/// Return the major version number for this shader language version object.
			RIM_INLINE UInt getMajor() const
			{
				return majorVersion;
			}
			
			
			
			
			/// Set the major version number for this shader language version object.
			RIM_INLINE void setMajor( UInt newMajorVersion )
			{
				majorVersion = newMajorVersion;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Minor Version Accessor Methods
			
			
			
			
			/// Return the minor version number for this shader language version object.
			RIM_INLINE UInt getMinor() const
			{
				return minorVersion;
			}
			
			
			
			
			/// Set the minor version number for this shader language version object.
			RIM_INLINE void setMinor( UInt newMinorVersion )
			{
				minorVersion = newMinorVersion;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Minor Version Accessor Methods
			
			
			
			
			/// Return the revision version number for this shader language version object.
			RIM_INLINE UInt getRevision() const
			{
				return revisionVersion;
			}
			
			
			
			
			/// Set the revision version number for this shader language version object.
			RIM_INLINE void setRevision( UInt newRevisionVersion )
			{
				revisionVersion = newRevisionVersion;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Version Comparison Operators
			
			
			
			
			/// Return whether or not this filter version number is exactly equal to another version number.
			RIM_INLINE Bool operator == ( const ShaderLanguageVersion& other ) const
			{
				return majorVersion == other.majorVersion && minorVersion == other.minorVersion && 
						revisionVersion == other.revisionVersion;
			}
			
			
			
			
			/// Return whether or not this filter version number is not equal to another version number.
			RIM_INLINE Bool operator != ( const ShaderLanguageVersion& other ) const
			{
				return majorVersion != other.majorVersion || minorVersion != other.minorVersion ||
						revisionVersion != other.revisionVersion;
			}
			
			
			
			
			/// Return whether or not this filter version number is earlier than another version number.
			Bool operator < ( const ShaderLanguageVersion& other ) const;
			
			
			
			
			/// Return whether or not this filter version number is earlier than or equal to another version number.
			Bool operator <= ( const ShaderLanguageVersion& other ) const;
			
			
			
			
			/// Return whether or not this filter version number is later than another version number.
			Bool operator > ( const ShaderLanguageVersion& other ) const;
			
			
			
			
			/// Return whether or not this filter version number is later than or equal to another version number.
			Bool operator >= ( const ShaderLanguageVersion& other ) const;
			
			
			
			
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
			
			
			
			
			/// An integer representing the major version number of a shader language.
			UInt8 majorVersion;
			
			
			
			
			/// An integer representing the minor version number of a shader language.
			UInt8 minorVersion;
			
			
			
			
			/// An integer representing the revision version number of a shader language.
			UInt8 revisionVersion;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Shaders Namespace  *****************************
RIM_GRAPHICS_SHADERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_SHADER_LANGUAGE_VERSION_H

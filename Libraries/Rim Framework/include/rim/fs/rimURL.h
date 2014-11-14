/*
 *  rimURL.h
 *  Rim IO
 *
 *  Created by Carl Schissler on 10/30/08.
 *  Copyright 2008 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_URL_H
#define INCLUDE_RIM_URL_H


#include "rimFileSystemConfig.h"


//##########################################################################################
//*************************  Start Rim File System Namespace  ******************************
RIM_FILE_SYSTEM_NAMESPACE_START
//******************************************************************************************
//##########################################################################################



/*
class URL
{
	public:
		
		
		RIM_INLINE URL( const String& URLString )
			:	port( -1 )
		{
			parseURL( URLString );
		}
		
		
		
		
		
		RIM_INLINE URL( const String& newProtocol, const String& newHost, 
					Int newPort, const String& newPath, const String& newRequest )
			:	protocol( newProtocol.getLength() > 0 ? newProtocol : defaultProtocol ),
				host( newHost ),
				port( newPort < -1 ? -1 : newPort ),
				request( newRequest )
		{
			parsePath( newPath );
		}
		
		
		
		
		RIM_INLINE const String& getName() const
		{
			return path[ path.getSize() - 1 ];
		}
		
		
		
		RIM_INLINE String toString() const
		{
			StringBuffer buffer;
			
			buffer.append( protocol ).append( "://" ).append( host );
			
			if ( port != -1 )
				buffer.append(':').append(port);
			
			for ( Index i = 0; i < path.getSize(); i++ )
				buffer.append( '/' ).append( path[i] );
			
			if ( request.getLength() > 0 )
				buffer.append('?').append(request);
			
			return buffer.toString();
		}
		
		
		
		
	private:
		
		
		RIM_INLINE static Bool isAPathSeparator( Char character )
		{
			return character == '/' || character == '\\';
		}
		
		
		
		
		void parseURL( const String& URLString );
		
		
		void parsePath( const String& pathString );
		
		
		
		
		
		
		String protocol;
		
		
		
		String host;
		
		
		
		Int port;
		
		
		
		ArrayList<String> path;
		
		
		
		String request;
		
		
		
		static String defaultProtocol;
		
		
		
};
*/



//##########################################################################################
//*************************  End Rim File System Namespace  ********************************
RIM_FILE_SYSTEM_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_URL_H

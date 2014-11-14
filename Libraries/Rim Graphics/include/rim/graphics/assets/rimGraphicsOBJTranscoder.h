/*
 *  rimGraphicsOBJTranscoder.h
 *  Rim Graphics
 *
 *  Created by Carl Schissler on 9/19/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_OBJ_TRANSCODER_H
#define INCLUDE_RIM_GRAPHICS_OBJ_TRANSCODER_H


#include "rimGraphicsAssetsConfig.h"


//##########################################################################################
//***********************  Start Rim Graphics Assets Namespace  ****************************
RIM_GRAPHICS_ASSETS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which reads and writes Wavefront OBJ format shapes.
class OBJTranscoder : public ResourceTranscoder<GraphicsShape>
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructor
			
			
			
			
			/// Create a new OBJ transcoder.
			OBJTranscoder();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this OBJ transcoder and release all associated resources.
			virtual ~OBJTranscoder();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Model Format Accessor Methods
			
			
			
			
			/// Return an object which represents the resource type that this transcoder can read and write.
			virtual ResourceType getResourceType() const;
			
			
			
			
			/// Return an object which represents the resource format that this transcoder can read and write.
			virtual ResourceFormat getResourceFormat() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Encoding Methods
			
			
			
			
			/// Return whether or not this OBJ transcoder is able to encode the specified resource.
			virtual Bool canEncode( const GraphicsShape& shape ) const;
			
			
			
			
			/// Encode the specified generic shape to the file at the specified path.
			/**
			  * If the method fails, FALSE is returned.
			  */
			virtual Bool encode( const ResourceID& resourceID, const GraphicsShape& shape );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Decoding Methods
			
			
			
			
			/// Return whether or not the specified identifier refers to a valid OBJ file for this transcoder.
			virtual Bool canDecode( const ResourceID& identifier ) const;
			
			
			
			
			/// Decode the OBJ file at the specified path and return a pointer to the decoded shape.
			/**
			  * If the method fails, a NULL pointer is returned.
			  */
			virtual Pointer<GraphicsShape> decode( const ResourceID& resourceID, ResourceManager* manager = NULL );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class used to hold temporary information about a raw OBJ material.
			class OBJMaterial
			{
				public:
					
					
					RIM_INLINE OBJMaterial( const UTF32String& newName )
						:	name( newName ),
							ambientColor( Color3f::BLACK ),
							diffuseColor( Color3f::WHITE ),
							specularColor( Color3f::WHITE ),
							specularExponent( 16.0f ),
							indexOfRefraction( 1 ),
							transparency( 1 ),
							illuminationModel( 0 )
					{
					}
					
					
					UTF32String name;
					
					Color3f ambientColor;
					Color3f diffuseColor;
					Color3f specularColor;
					
					Float specularExponent;
					Float indexOfRefraction;
					Float transparency;
					
					Int illuminationModel;
					
					Resource<GenericTexture> diffuseTexture;
					Resource<GenericTexture> ambientTexture;
					Resource<GenericTexture> specularTexture;
					
					
			};
			
			
			
			
			/// A class used to hold temporary information about a raw OBJ vertex.
			class OBJVertex
			{
				public:
					
					RIM_INLINE OBJVertex()
						:	v( 0 ),
							t( 0 ),
							n( 0 )
					{
					}
					
					RIM_INLINE OBJVertex( Index newV, Index newT, Index newN )
						:	v( newV ),
							t( newT ),
							n( newN )
					{
					}
					
					
					RIM_INLINE Bool operator == ( const OBJVertex& other ) const
					{
						return v == other.v && t == other.t && n == other.n;
					}
					
					RIM_INLINE Hash getHashCode() const
					{
						return Hash((v*Hash(0x8DA6B343)) ^ (t*Hash(0xD8163841)) ^ (n*Hash(0xCB1AB31F)));
					}
					
					
					/// The index of this vertex's position.
					Index v;
					
					/// The index of this vertex's texture coordinate.
					Index t;
					
					/// The index of this vertex's normal.
					Index n;
					
			};
			
			
			
			
			/// A class used to represent an OBJ primitive (point, line, face).
			class OBJPrimitive
			{
				public:
					
					/// A list of vertices to use for this OBJ primitive.
					ShortArrayList<OBJVertex,4> indices;
					
			};
			
			
			
			
			class OBJMaterialGroup
			{
				public:
					
					RIM_INLINE OBJMaterialGroup( const Pointer<OBJMaterial>& newMaterial )
						:	material( newMaterial ),
							numPrimitives( 0 )
					{
					}
					
					
					/// A string representing the name of the material group.
					Pointer<OBJMaterial> material;
					
					
					/// A list of the primitives that are part of this material group.
					ArrayList< OBJPrimitive > primitives;
					
					
					/// A temporary counter which counts the total number of primitives that will be stored in the index buffer.
					Size numPrimitives;
					
			};
			
			
			
			
			class OBJGroup
			{
				public:
					
					RIM_INLINE OBJGroup( const UTF32String& newName )
						:	name( newName )
					{
					}
					
					
					RIM_INLINE void setCurrentMaterialGroup( const Pointer<OBJMaterial>& m )
					{
						const Size numMaterialGroups = materialGroups.getSize();
						
						for ( Index i = 0; i < numMaterialGroups; i++ )
						{
							if ( materialGroups[i]->material == m )
							{
								currentMaterialGroup = materialGroups[i];
								return;
							}
						}
						
						// Didn't find a group for this material, so create one.
						currentMaterialGroup = Pointer<OBJMaterialGroup>::construct( m );
						materialGroups.add( currentMaterialGroup );
					}
					
					
					/// A string representing the name of the obj group.
					UTF32String name;
					
					
					/// A list of the material groups that are part of this group.
					ArrayList<Pointer<OBJMaterialGroup> > materialGroups;
					
					
					/// A pointer to the current material group for this group.
					Pointer<OBJMaterialGroup> currentMaterialGroup;
					
			};
			
			
			
			
			/// An enum contain values for all legal OBJ keywords.
			typedef enum OBJKeywordType
			{
				UNDEFINED_OBJ_KEYWORD = 0,
				
				/// Vertex declaration.
				V = 1,
				
				/// Vertex texture coordiante declaration.
				VT,
				
				/// Vertex normal declaration.
				VN,
				
				/// A point in the parameter space of a curve or surface.
				VP,
				
				DEG,
				BMAT,
				STEP,
				CSTYPE,
				
				/// Point declaration.
				P,
				
				/// Line declaration.
				L,
				
				/// Face declaration.
				F,
				
				/// 1D curve specification.
				CURV,
				
				/// 2D curve specification.
				CURV2,
				
				/// Surface specification.
				SURF,
				PARM,
				TRIM,
				HOLE,
				SCRV,
				SP,
				END,
				CON,
				G,
				S,
				MG,
				O,
				BEVEL,
				C_INTERP,
				D_INTERP,
				LOD,
				
				COMMENT,
				
				/// Material usage declaration.
				USEMTL,
				
				/// Material library import.
				MTLLIB,
				
				SHADOW_OBJ,
				TRACE_OBJ,
				CTECH,
				STECH
			};
			
			
			
			
			/// An enum that defines the different types of .mtl file keywords.
			typedef enum MTLKeywordType
			{
				UNDEFINED_MTL_KEYWORD = 0,
				
				/// New material keyword.
				NEWMTL = 1,
				
				/// Ambient color.
				KA,
				
				/// Diffuse color.
				KD,
				
				/// Specular color.
				KS,
				
				/// Index of refraction.
				NI,
				
				/// Specular coefficient.
				NS,
				
				/// Dissolve amount (transparency).
				D,
				
				/// Illumination model number.
				ILLUM,
				
				/// Diffuse color texture map.
				MAP_KD,
				
				/// Specular color texture map.
				MAP_KS,
				
				/// Ambient color texture map.
				MAP_KA,
				
				/// Specular coefficient texture map.
				MAP_NS,
				
				/// Alpha texture map.
				MAP_D,
				
				/// Bump map.
				MAP_BUMP,
				
				/// Displacement texture map.
				MAP_DISP,
				
				/// Decal stencil texture map.
				MAP_DECAL,
				
				/// Reflection texture map.
				MAP_REFL
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			void readMTLFile( const Path& pathToFile, ResourceManager* resourceManager ) const;
			
			
			
			
			Resource<GenericTexture> readTexture( const Path& path, ResourceManager* resourceManager ) const;
			
			
			
			
			Bool readFloat( UTF8StringIterator& iterator, Float& value ) const;
			Bool readVector3( UTF8StringIterator& iterator, Vector3f& vector ) const;
			Bool readVector2( UTF8StringIterator& iterator, Vector2f& vector ) const;
			
			Bool readVector8( UTF8StringIterator& iterator, StaticArray<Float,8>& vector ) const;
			
			
			
			
			RIM_INLINE Bool readPosition( UTF8StringIterator& iterator, Vector3f& position ) const
			{
				return readVector3( iterator, position );
			}
			
			
			
			
			RIM_INLINE Bool readNormal( UTF8StringIterator& iterator, Vector3f& normal ) const
			{
				return readVector3( iterator, normal );
			}
			
			
			
			RIM_INLINE Bool readUV( UTF8StringIterator& iterator, Vector2f& uv ) const
			{
				return readVector2( iterator, uv );
			}
			
			
			
			RIM_INLINE Bool readColor( UTF8StringIterator& iterator, Color3f& color ) const
			{
				return readVector3( iterator, *(Vector3f*)&color );
			}
			
			
			
			
			RIM_INLINE Bool readIndex( UTF8StringIterator& iterator, Index lastVertexIndex, Index& index ) const
			{
				// Read the index into a buffer.
				stringBuffer.clear();
				
				UTF32Char c;
				Size n = 0;
				
				while ( iterator && !isWhitespace(c = *iterator) && c != '/' )
				{
					stringBuffer << c;
					iterator++;
					n++;
				}
				
				if ( n == 0 )
					return false;
				
				// Convert the component from a string to a number.
				UTF32String number = stringBuffer.toString();
				Int64 i;
				
				if ( !number.toInt64( i ) )
					return false;
				
				// If the index is negative (i.e. relative to the last vertex), adjust the index.
				if ( i < Int64(0) )
					index = Index(Int64(lastVertexIndex) + i);
				else
					index = Index(i - 1);
				
				return true;
			}
			
			
			
			
			Bool readVertex( UTF8StringIterator& iterator, OBJVertex& vertex ) const;
			
			
			
			
			Bool readFace( UTF8StringIterator& iterator, OBJPrimitive& primitive ) const;
			
			
			
			
			void setCurrentGroup( const UTF32String& groupName ) const
			{
				const Size numGroups = groups.getSize();
				
				for ( Index i = 0; i < numGroups; i++ )
				{
					if ( groups[i]->name == groupName )
					{
						currentGroup = groups[i];
						return;
					}
				}
				
				// Didn't find an existing group, so create a new one.
				currentGroup = Pointer<OBJGroup>::construct( groupName );
				
				groups.add( currentGroup );
			}
			
			
			
			
			Bool setCurrentMaterial( const UTF32String& materialName ) const
			{
				const Size numMaterials = materials.getSize();
				
				for ( Index i = 0; i < numMaterials; i++ )
				{
					if ( materials[i]->name == materialName )
					{
						currentMaterial = materials[i];
						return true;
					}
				}
				
				currentMaterial = Pointer<OBJMaterial>();
				
				return false;
			}
			
			
			
			
			const Pointer<OBJMaterial>& addMaterial( const UTF32String newMaterialName ) const
			{
				// Make sure that a material with this name doesn't already exist.
				const Size numMaterials = materials.getSize();
				
				for ( Index i = 0; i < numMaterials; i++ )
				{
					if ( materials[i]->name == newMaterialName )
						return materials[i];
				}
				
				materials.add( Pointer<OBJMaterial>::construct( newMaterialName ) );
				return materials.getLast();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Parsing Helper Methods
			
			
			
			
			static void skipWhitespace( UTF8StringIterator& iterator )
			{
				while ( iterator && isWhitespace(*iterator) )
					iterator++;
			}
			
			
			
			
			static void skipLine( UTF8StringIterator& iterator )
			{
				while ( iterator && *iterator != '\n' && *iterator != '\r' )
					iterator++;
				
				// We are at the character, so skip to next character.
				while ( iterator && (*iterator == '\n' || *iterator == '\r') )
					iterator++;
			}
			
			
			
			
			static void skipToAfterNext( UTF8StringIterator& iterator, UTF32Char c )
			{
				while ( iterator && *iterator != c )
					iterator++;
				
				// We are at the character, so skip to next character.
				if ( iterator )
					iterator++;
			}
			
			
			
			
			static Size readLine( UTF8StringIterator& iterator, UTF32StringBuffer& buffer )
			{
				UTF32Char c;
				Size numRead = 0;
				
				while ( iterator && (c = *iterator) != '\n' && c != '\r' )
				{
					buffer << c;
					iterator++;
				}
				
				// We are on the newline, so skip to next character (in the next line).
				skipLine( iterator );
				
				return numRead;
			}
			
			
			
			
			/// Read a single word from the iterator into the buffer, returning the number of characters read.
			static Size readWord( UTF8StringIterator& iterator, UTF32Char* output, Size maxLength )
			{
				Size n = 0;
				UTF32Char c;
				
				while ( iterator && n < maxLength && isWordCharacter(c = *iterator) )
				{
					*output = c;
					output++;
					iterator++;
					n++;
				}
				
				return n;
			}
			
			
			
			
			/// Read a single non-whitespace word from the iterator into the buffer, returning the number of characters read.
			static Size readNonWhitespace( UTF8StringIterator& iterator, UTF32StringBuffer& buffer )
			{
				Size n = 0;
				UTF32Char c;
				
				while ( iterator && !isWhitespace(c = *iterator) )
				{
					buffer << c;
					iterator++;
					n++;
				}
				
				return n;
			}
			
			
			
			
			static OBJKeywordType readKeyword( UTF8StringIterator& iterator, UTF32Char* output, Size maxLength )
			{
				Size n = readWord( iterator, output, maxLength );
				
				return getKeywordType( output, n );
			}
			
			
			
			
			static MTLKeywordType readMTLKeyword( UTF8StringIterator& iterator, UTF32Char* output, Size maxLength )
			{
				Size n = readWord( iterator, output, maxLength );
				
				return getMTLKeywordType( output, n );
			}
			
			
			
			
			static OBJKeywordType getKeywordType( const UTF32Char* k, Size n );
			static MTLKeywordType getMTLKeywordType( const UTF32Char* k, Size n );
			
			
			
			
			/// Return whether or not the specified character is a whitespace character.
			RIM_INLINE static Bool isWordCharacter( UTF32Char c )
			{
				return UTF32String::isALetter(c) || UTF32String::isADigit(c) || c == '_' || c == '#';
			}
			
			
			
			
			/// Return whether or not the specified character is a whitespace character.
			RIM_INLINE static Bool isWhitespace( UTF32Char c )
			{
				return c == ' ' || c == '\t' || c == '\n' || c == '\r';
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A pointer to a temporary buffer containing the vertex positions for the model being read.
			mutable Pointer<GenericBuffer> temporaryPositions;
			
			
			
			
			mutable Size numPositions;
			
			
			
			
			/// A pointer to a temporary buffer containing the vertex normals for the model being read.
			mutable Pointer<GenericBuffer> temporaryNormals;
			
			
			
			
			mutable Size numNormals;
			
			
			
			
			/// A pointer to a temporary buffer containing the vertex texture coordinates for the model being read.
			mutable Pointer<GenericBuffer> temporaryUVs;
			
			
			
			
			mutable Size numUVs;
			
			
			
			
			/// A list of the different groups that are part of the object being currently read.
			mutable ArrayList< Pointer<OBJGroup> > groups;
			
			
			
			
			/// A pointer to the current primitive group for the parser.
			mutable Pointer<OBJGroup> currentGroup;
			
			
			
			
			/// A list of the different materials that are part of the object being currently read.
			mutable ArrayList< Pointer<OBJMaterial> > materials;
			
			
			
			
			/// A pointer to the current material group for the parser.
			mutable Pointer<OBJMaterial> currentMaterial;
			
			
			
			
			/// A string buffer used to hold intermediate input values;
			mutable UTF32StringBuffer stringBuffer;
			
			
			
			
			mutable HashMap< OBJVertex, Index > vertexMap;
			mutable HashMap< Pointer<OBJMaterial>, Pointer<GenericMaterial> > materialMap;
			
			
			
};




//##########################################################################################
//***********************  End Rim Graphics Assets Namespace  ******************************
RIM_GRAPHICS_ASSETS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_OBJ_TRANSCODER_H

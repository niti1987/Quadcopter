/*
 *  rimFilterGraph.h
 *  Rim Sound
 *
 *  Created by Carl Schissler on 6/7/08.
 *  Copyright 2008 Rim Software. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_SOUND_FILTER_GRAPH_H
#define INCLUDE_RIM_SOUND_FILTER_GRAPH_H


#include "rimSoundFiltersConfig.h"


#include "rimSoundFilter.h"


//##########################################################################################
//************************  Start Rim Sound Filters Namespace  *****************************
RIM_SOUND_FILTERS_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents an acyclic graph of sound processing filters.
/**
  * This class is provided to make complex graphs of audio processing filters
  * easy to construct and maintain. A filter graph consists of any number of
  * inputs and outputs (determined by the connections made) which are exposed to
  * the user, plus internal SoundFilter objects which perform audio processing
  * on the input and output sound of the filter graph. A filter graph initially has
  * no connections and thus won't produce or process any audio. The user must make
  * connections from filters to the graph's external inputs and outputs and amongst
  * the filters in order for a filter graph to function properly.
  *
  * The FilterGraph class is provided as a convenience in doing complex audio
  * processing. It handles all temporary buffer allocation and management and enables
  * efficient communication between filters in the processing graph. While using
  * a filter graph is efficient, it will not be as fast as a hand-coded processing
  * graph which is specifically optimized for the task at hand.
  *
  * It must be noted that the filter graph class does not own or know anything about
  * the lifetime of the SoundFilter objects which it is connecting. The filter object
  * pointers which are connected are expected to be valid until they are either removed
  * from the graph or the graph is destroyed.
  */
class FilterGraph : public SoundFilter
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graph of sound filters with no connections.
			/**
			  * As is, this graph will not be able to process any sound.
			  * The user must connect filters within the graph, forming a chain
			  * to the output in order for it to function properly.
			  */
			FilterGraph();
			
			
			
			
			/// Create a copy of the specified sound filter graph, duplicating all of its connections.
			FilterGraph( const FilterGraph& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Destructor
			
			
			
			
			/// Destroy this sound filter graph, releasing all internal state.
			~FilterGraph();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Assignment Operator
			
			
			
			
			/// Assign a copy of the specified sound filter graph to this graph, duplicating all of its connections.
			FilterGraph& operator = ( const FilterGraph& other );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Graph Node Accessor Methods
			
			
			
			/// Return the total number of nodes in the filter graph.
			/**
			  * This number includes the main input/output node, so this
			  * value is usually equal to the number of filters in the graph plus one
			  * unless the main input/output node is not yet connected, in which
			  * case it is equal to the number of filters.
			  */
			RIM_INLINE Size getNodeCount() const
			{
				return nodes.getSize();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Graph Connection Accessor Methods
			
			
			
			
			/// Connect as many outputs of the first filter to the inputs of the second filter as possible.
			/**
			  * A 1-to-1 connection is made between the outputs of the first filter and
			  * the inputs of the second filter.
			  *
			  * The method returns whether or not the connection was successfully made.
			  * The connection can fail if the output filter doesn't have an output
			  * or if the input filter doesn't have an input.
			  *
			  * Specifying NULL for the first filter connects the graph's global filter input
			  * to the second filter's input. Likewise, a NULL second filter pointer connects
			  * the first filter to the main graph output. Specifying NULL for both pointers
			  * connects the graph's inputs to its outputs directly.
			  */
			Bool connect( SoundFilter* output, SoundFilter* input );
			
			
			
			
			/// Connect the specified output of the first filter to the specified input of the second filter.
			/**
			  * The method returns whether or not the connection was successfully made.
			  * The connection can fail if the output filter doesn't have an output
			  * or if the input filter doesn't have an input.
			  *
			  * Specifying NULL for the first filter connects the graph's global filter input
			  * to the second filter's input. Likewise, a NULL second filter pointer connects
			  * the first filter to the main graph output. Specifying NULL for both pointers
			  * connects the graph's input to its output directly.
			  */
			Bool connect( SoundFilter* output, Index outputIndex,
							SoundFilter* input, Index inputIndex );
			
			
			
			
			/// Disconnect the first output of the first filter from the first input of the second filter.
			Bool disconnect( const SoundFilter* output, const SoundFilter* input );
			
			
			
			
			/// Disconnect the specified output of the first filter from the specified input of the second filter.
			/**
			  * The method returns whether or not the connection was successfully disconnected.
			  * The disconnection can fail if the output filter doesn't have an output,
			  * if the input filter doesn't have an input, or if there was no such connection
			  * before the method was called.
			  *
			  * Specifying NULL for the first filter disconnects the graph's global input
			  * from the second filter's input. Likewise, a NULL second filter pointer disconnects
			  * the first filter from the main graph output. Specifying NULL for both pointers
			  * disconnects the graph's input from its output.
			  */
			Bool disconnect( const SoundFilter* output, Index outputIndex,
							const SoundFilter* input, Index inputIndex );
			
			
			
			
			/// Return whether or not the specified output filter is directly connected to the input of another filter.
			/**
			  * The method returns TRUE if any output of the first filter is directly connected
			  * to the input of the second filter.
			  */
			Bool isConnected( const SoundFilter* output, const SoundFilter* input ) const;
			
			
			
			
			/// Return whether or not the specified output of one filter is directly connected to an input of another filter.
			Bool isConnected( const SoundFilter* output, Index outputIndex,
							const SoundFilter* input, Index inputIndex ) const;
			
			
			
			
			/// Clear all connections (and nodes/filters) from this filter graph.
			void clear();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Filter Attribute Accessor Methods
			
			
			
			
			/// Return a human-readable name for this sound filter graph.
			/**
			  * The method returns the string "Sound Filter Graph".
			  */
			virtual UTF8String getName() const;
			
			
			
			
			/// Return the manufacturer name of this sound filter graph.
			/**
			  * The method returns the string "Headspace Sound".
			  */
			virtual UTF8String getManufacturer() const;
			
			
			
			
			/// Return an object representing the version of this sound filter graph.
			virtual SoundFilterVersion getVersion() const;
			
			
			
			
			/// Return an object which describes the category of effect that this filter implements.
			/**
			  * This method returns the value SoundFilterCategory::ROUTING.
			  */
			virtual SoundFilterCategory getCategory() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Property Objects
			
			
			
			
			/// A string indicating the human-readable name of this sound filter graph.
			static const UTF8String NAME;
			
			
			
			
			/// A string indicating the manufacturer name of this sound filter graph.
			static const UTF8String MANUFACTURER;
			
			
			
			
			/// An object indicating the version of this sound filter graph.
			static const SoundFilterVersion VERSION;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which represents a one-way connection to a filter's input.
			class NodeInputConnection;
			
			
			
			
			/// A class which represents a one-way connection to a filter's output.
			class NodeOutputConnection;
			
			
			
			
			/// A class which represents a single node in a graph of filters.
			class Node;
			
			
			
			
			/// A class which holds information about a reference-counted shared sound buffer.
			class BufferInfo;
			
			
			
			
			/// A class which holds information about a reference-counted shared filter frame.
			class FilterFrameInfo;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Stream Reset Method
			
			
			
			
			/// A method which is called whenever the filter's stream of audio is being reset.
			/**
			  * This method allows the filter to reset all parameter interpolation
			  * and processing to its initial state to avoid coloration from previous
			  * audio or parameter values.
			  */
			virtual void resetStream();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Filter Processing Methods
			
			
			
			
			/// Take the input sample data and perform filter graph processing on it, placing the result in the output frame.
			virtual SoundFilterResult processFrame( const SoundFilterFrame& inputFrame,
													SoundFilterFrame& outputFrame, Size numSamples );
			
			
			
			
			/// Process the specified main I/O node (NULL node) and place the result in the specified output frame.
			SoundFilterResult processMainNode( Node* node, SoundFilterFrame* outputFrame, Size numSamples );
			
			
			
			
			/// Process the specified node and place the result in the specified output frame.
			SoundFilterResult processNode( Node* node, SoundFilterFrame* outputFrame, Size numSamples );
			
			
			
			
			/// Build an output frame for the specified node/number of samples and compute the output, storing it in the node.
			RIM_INLINE void computeNodeOutput( Node* node, Size numSamples );
			
			
			
			
			/// Get another temporary frame from the pool and return a pointer to the frame.
			RIM_INLINE SoundFilterFrame* getTempFrame( Size numBuffers );
			
			
			
			
			/// Release the specified temporary filter frame back to the pool.
			RIM_INLINE void releaseTempFrame( SoundFilterFrame* frame );
			
			
			
			
			/// Get another temporary buffer from the global pool, save the handle, and return a pointer to the buffer.
			RIM_INLINE SoundBuffer* getTempBuffer();
			
			
			
			
			/// Release the specified temporary sound buffer back to the pool.
			RIM_INLINE void releaseTempBuffer( const SoundBuffer* buffer );
			
			
			
			
			/// Return whether or not the specified node has at most one output that uses the same output index.
			RIM_INLINE static Bool outputIsUnique( Node* node, Index outputConnectionIndex );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A map from filter pointers to filter nodes representing this filter graph.
			HashMap<const SoundFilter*,Node> nodes;
			
			
			
			
			/// A list of the current set of shared temporary sound buffers in use by this filter graph.
			ArrayList<BufferInfo> tempBuffers;
			
			
			
			
			/// A persistent (to avoid buffer array reallocations) list of filter frames for intermediate sound data.
			ArrayList<FilterFrameInfo*> tempFrames;
			
			
			
			
			/// The total number of temporary buffers that are currently in use.
			Size numBuffersInUse;
			
			
			
			
			/// The total number of temporary frames that are currently in use.
			Size numFramesInUse;
			
			
			
};




//##########################################################################################
//************************  End Rim Sound Filters Namespace  *******************************
RIM_SOUND_FILTERS_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_SOUND_FILTER_GRAPH_H

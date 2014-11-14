/*
 *  rimGraphicsGUIGraphView.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 7/9/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_H
#define INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIGraphViewAxis.h"
#include "rimGraphicsGUIGraphViewDelegate.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a 2D graph of rectangular cells that can contain child GUI objects.
/**
  * A graph view is an optionally-bordered rectangular area whose content area (inside
  * the border) is divided into a 2D graph of cells. Each cell can contain any number of
  * child GUI objects.
  */
class GraphView : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Series Type Enumeration
			
			
			
			
			/// An enum representing the different kinds of series that a graph view can have.
			typedef enum SeriesType
			{
				/// A series where data points are drawn as a sequence of disconnected points.
				POINTS,
				
				/// A series where data points are drawn as a sequence of disconnected lines.
				/**
				  * Every 2 points represents a line that is drawn on the graph.
				  */
				LINES,
				
				/// A series where data points are drawn as a sequence of connected lines.
				/**
				  * Each point is connected to the previous and next data points.
				  */
				LINE_STRIP,
				
				/// An undefined series type. A series with this type is not drawn.
				UNDEFINED
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graph view with no width or height and no visible graph range.
			GraphView();
			
			
			
			
			/// Create a new graph view with the given rectangle and visible graph range.
			GraphView( const Rectangle& newRectangle, const AABB2f& range );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Range Accessor Methods
			
			
			
			
			/// Return a 2D range indicating the visible range of values for this graph view's series.
			RIM_INLINE const AABB2f& getRange() const
			{
				return range;
			}
			
			
			
			
			/// Set a 2D range indicating the visible range of values for this graph view's series.
			/**
			  * Changing the visible range for the graph view causes it to refresh the currently
			  * visible data points in the same way that refresh() does.
			  */
			RIM_INLINE void setRange( const AABB2f& newRange )
			{
				range = newRange;
				this->refresh();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Horizontal Axis Accessor Methods
			
			
			
			
			/// Return an object which describes the appearance of the horizontal graph axis.
			RIM_INLINE GraphViewAxis& getHorizontalAxis()
			{
				return horizontalAxis;
			}
			
			
			
			
			/// Return an object which describes the appearance of the horizontal graph axis.
			RIM_INLINE const GraphViewAxis& getHorizontalAxis() const
			{
				return horizontalAxis;
			}
			
			
			
			
			/// Set an object which describes the appearance of the horizontal graph axis.
			RIM_INLINE void setHorizontalAxis( const GraphViewAxis& newHorizontalAxis )
			{
				horizontalAxis = newHorizontalAxis;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Vertical Axis Accessor Methods
			
			
			
			
			/// Return an object which describes the appearance of the vertical graph axis.
			RIM_INLINE GraphViewAxis& getVerticalAxis()
			{
				return verticalAxis;
			}
			
			
			
			
			/// Return an object which describes the appearance of the vertical graph axis.
			RIM_INLINE const GraphViewAxis& getVerticalAxis() const
			{
				return verticalAxis;
			}
			
			
			
			
			/// Set an object which describes the appearance of the vertical graph axis.
			RIM_INLINE void setVerticalAxis( const GraphViewAxis& newVerticalAxis )
			{
				verticalAxis = newVerticalAxis;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Series Accessor Methods
			
			
			
			
			/// Return the total number of series that are part of this graph view.
			RIM_INLINE Size getSeriesCount() const
			{
				return series.getSize();
			}
			
			
			
			
			/// Add a new series to this graph view with the specified type and attributes.
			/**
			  * The method adds a new series to the graph. The data for the series will be
			  * refreshed from the delegate the next time that the graph view is drawn.
			  *
			  * The method returns the index of the new series.
			  */
			RIM_INLINE Index addSeries( SeriesType type, const Color4f& color = Color4f::BLACK, Float weight = Float(2) )
			{
				Index index = series.getSize();
				series.add( GraphSeries( type, color, weight ) );
				return index;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Series Type Accessor Methods
			
			
			
			
			/// Return the type of the graph series which has the specified index in this graph view.
			/**
			  * If the specified series index is invalid, SeriesType::UNDEFINED is returned.
			  */
			RIM_INLINE SeriesType getSeriesType( Index seriesIndex ) const
			{
				if ( seriesIndex < series.getSize() )
					return series[seriesIndex].type;
				else
					return UNDEFINED;
			}
			
			
			
			
			/// Set the type of the graph series which has the specified index in this graph view.
			/**
			  * If the specified series index is invalid, the method has no effect.
			  */
			RIM_INLINE void setSeriesType( Index seriesIndex, SeriesType newType )
			{
				if ( seriesIndex < series.getSize() )
					series[seriesIndex].type = newType;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Series Color Accessor Methods
			
			
			
			
			/// Return the color of the graph series which has the specified index in this graph view.
			/**
			  * If the specified series index is invalid, Color4f::ZERO is returned.
			  */
			RIM_INLINE const Color4f& getSeriesColor( Index seriesIndex ) const
			{
				if ( seriesIndex < series.getSize() )
					return series[seriesIndex].color;
				else
					return Color4f::ZERO;
			}
			
			
			
			
			/// Set the color of the graph series which has the specified index in this graph view.
			/**
			  * If the specified series index is invalid, the method has no effect.
			  */
			RIM_INLINE void setSeriesColor( Index seriesIndex, const Color4f& newColor )
			{
				if ( seriesIndex < series.getSize() )
					series[seriesIndex].color = newColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Series Size Accessor Methods
			
			
			
			
			/// Return the display weight in pixels of the graph series which has the specified index in this graph view.
			/**
			  * If the specified series index is invalid, 0 is returned.
			  */
			RIM_INLINE Float getSeriesWeight( Index seriesIndex ) const
			{
				if ( seriesIndex < series.getSize() )
					return series[seriesIndex].weight;
				else
					return 0;
			}
			
			
			
			
			/// Set the display weight in pixels of the graph series which has the specified index in this graph view.
			/**
			  * If the specified series index is invalid, the method has no effect.
			  */
			RIM_INLINE void setSeriesWeight( Index seriesIndex, Float newWeight )
			{
				if ( seriesIndex < series.getSize() )
					series[seriesIndex].weight = math::max( newWeight, Float(0) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Series Data Accessor Methods
			
			
			
			
			/// Return a reference to the current array of data points for the specified graph series.
			/**
			  * The returned array represents the current state of the series, though it
			  * may change if the series is updated by the delegate.
			  */
			RIM_INLINE const ArrayList<Vector2f>& getSeriesData( Index seriesIndex ) const
			{
				return series[seriesIndex].points;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Refresh Methods
			
			
			
			
			/// Refresh all of the graph view's data for all of its series.
			/**
			  * The graph view calls the updateSeries delegate method for each series to update its internal
			  * data structures with the new data.
			  */
			void refresh();
			
			
			
			
			/// Refresh the graph series with the specified index in this graph view.
			/**
			  * The graph view calls the updateSeries delegate method to update its internal
			  * data structures with the new data.
			  */
			void refreshSeries( Index seriesIndex );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this graph view's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this graph view's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this graph view's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the graph view's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the graph view's content display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this graph view's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this graph view's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a graph view.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a graph view.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this graph view using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the graph view was successfully drawn.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event for the entire graph view.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event for the entire graph view.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event for the entire graph view.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event for the entire graph view.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this graph view.
			RIM_INLINE GraphViewDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this graph view.
			RIM_INLINE const GraphViewDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this graph view.
			RIM_INLINE void setDelegate( const GraphViewDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<GraphView> construct()
			{
				return Pointer<GraphView>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<GraphView> construct( const Rectangle& newRectangle, const AABB2f& newRange )
			{
				return Pointer<GraphView>::construct( newRectangle, newRange );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a graph view.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a graph view's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a graph view.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which stores information about a single series of data points on the graph.
			class GraphSeries
			{
				public:
					
					/// Create a new graph series with the specified series type and color.
					RIM_INLINE GraphSeries( SeriesType newType, const Color4f& newColor, Float newWeight )
						:	color( newColor ),
							type( newType ),
							weight( math::max( newWeight, Float(0) ) ),
							pointImage(),
							points(),
							needsRefresh( true )
					{
					}
					
					
					/// The color which should be used to draw this series.
					Color4f color;
					
					
					/// An enum value which indicates how the series should be interpreted.
					SeriesType type;
					
					
					/// The line width or point size to use when rendering this series.
					Float weight;
					
					
					/// An image which is drawn for every data point in the series.
					/**
					  * If the image pointer is NULL, a default point image is used when
					  * rendering the series.
					  */
					Pointer<GUIImage> pointImage;
					
					
					/// An array of the 2D data points for this graph view series.
					ArrayList<Vector2f> points;
					
					
					/// A boolean value which indicates whether or not this series should be refreshed.
					Bool needsRefresh;
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// A 2D range of values indicating the visible coordinates for the graph.
			AABB2f range;
			
			
			
			
			/// An object which stores information for the graph's horizontal axis.
			GraphViewAxis horizontalAxis;
			
			
			
			
			/// An object which stores information for the graph's vertical axis.
			GraphViewAxis verticalAxis;
			
			
			
			
			/// A list of the series that are part of this graph view.
			ArrayList<GraphSeries> series;
			
			
			
			
			/// An object which describes the border for this graph view.
			Border border;
			
			
			
			
			/// An object which responds to events for this graph view.
			GraphViewDelegate delegate;
			
			
			
			
			/// The background color for the graph view's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the graph view's background area.
			Color4f borderColor;
			
			
			
			
			/// The minimum range vector for the graph before it was grabbed by the mouse.
			Vector2f previousRangeMin;
			
			
			
			
			/// A vector indicating the position in the graph where the mouse was clicked.
			Vector2f grabOffset;
			
			
			
			
			/// A boolean value indicating whether or not the graph is currently grabbed by the mouse.
			Bool grabbed;
			
			
			
			
			/// A boolean value indicating whether or not the graph view allows automatic scrolling.
			Bool scrollingEnabled;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_H

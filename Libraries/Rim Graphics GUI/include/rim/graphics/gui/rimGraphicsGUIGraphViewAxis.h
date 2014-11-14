/*
 *  rimGraphicsGUIGraphViewAxis.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 7/10/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_AXIS_H
#define INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_AXIS_H


#include "rimGraphicsGUIBase.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which stores information about a single graph axis.
class GraphViewAxis
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Flags Enum Declaration
			
			
			
			
			/// An enum of the various boolean flags for a graph view axis.
			typedef enum Flag
			{
				/// A flag indicating that major divisions should be drawn for a graph view axis.
				MAJOR_DIVISIONS = (1 << 0),
				
				/// A flag indicating that minor divisions should be drawn for a graph view axis.
				MINOR_DIVISIONS = (1 << 1),
				
				/// A flag indicating that major division labels should be drawn for a graph view axis.
				MAJOR_LABELS = (1 << 2),
				
				/// A flag indicating that minor division labels should be drawn for a graph view axis.
				MINOR_LABELS = (1 << 3),
				
				/// A flag indicating that the main label for a graph view axis should be drawn.
				LABEL = (1 << 4)
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new graph axis with the default attributes.
			GraphViewAxis();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Label Accessor Methods
			
			
			
			
			/// Return a reference to the string for the name of this axis, describing what it represents.
			RIM_INLINE const UTF8String& getLabel() const
			{
				return label;
			}
			
			
			
			
			/// Set a string for the name of this axis, describing what it represents.
			RIM_INLINE void setLabel( const UTF8String& newLabel )
			{
				label = newLabel;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Label Enable Methods
			
			
			
			
			/// Return whether or not the main label for this axis is enabeld.
			RIM_INLINE Bool getLabelIsEnabled() const
			{
				return (flags & LABEL) != 0;
			}
			
			
			
			
			/// Set whether or not the main label for this axis is enabeld.
			RIM_INLINE void setLabelIsEnabled( Bool newLabelIsEnabled )
			{
				if ( newLabelIsEnabled )
					flags |= LABEL;
				else
					flags &= ~LABEL;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Label Accessor Methods
			
			
			
			
			/// Return the total number of user-defined labels that are part of this graph axis.
			RIM_INLINE Size getUserLabelCount() const
			{
				return userLabels.getSize();
			}
			
			
			
			
			/// Add a new user-defined label to this graph view with the specified name, value, and enable status.
			/**
			  * The result of this method is that a new label will be drawn at the specified value
			  * on the graph (if visible). A label can be drawn as a dividing line with no text label,
			  * or as a label with no dividing line, depending on the values of the boolean parameters.
			  */
			RIM_INLINE Index addUserLabel( const UTF8String& label, Float value,
											Bool labelEnabled = true, Bool divisionEnabled = true )
			{
				Index index = userLabels.getSize();
				
				userLabels.add( GraphLabel( label, value, labelEnabled, divisionEnabled ) );
				
				return index;
			}
			
			
			
			
			/// Remove the user-defined label at the specified index in this graph axis.
			RIM_INLINE Bool removeUserLabel( Index index )
			{
				return userLabels.removeAtIndex( index );
			}
			
			
			
			
			/// Remove all user-defined labels from this graph axis.
			RIM_INLINE void clearUserLabels()
			{
				userLabels.clear();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	User Label Attribute Accessor Methods
			
			
			
			
			/// Return the label string for the user-defined label at the specified index.
			RIM_INLINE const UTF8String& getUserLabel( Index labelIndex ) const
			{
				return userLabels[labelIndex].label;
			}
			
			
			
			
			/// Set the label string for the user-defined label at the specified index.
			RIM_INLINE void setUserLabel( Index labelIndex, const UTF8String& newLabel )
			{
				if ( labelIndex < userLabels.getSize() )
					userLabels[labelIndex].label = newLabel;
			}
			
			
			
			
			/// Return the value at which the user-defined label at the specified index should be displayed.
			RIM_INLINE Float getUserLabelValue( Index labelIndex ) const
			{
				return userLabels[labelIndex].value;
			}
			
			
			
			
			/// Set the value at which the user-defined label at the specified index should be displayed.
			RIM_INLINE void setUserLabelValue( Index labelIndex, Float newValue )
			{
				if ( labelIndex < userLabels.getSize() )
					userLabels[labelIndex].value = newValue;
			}
			
			
			
			
			/// Return whether or not the user-defined label at the specified index should display its text label.
			RIM_INLINE Bool getUserLabelIsEnabled( Index labelIndex ) const
			{
				return userLabels[labelIndex].labelEnabled;
			}
			
			
			
			
			/// Set whether or not the user-defined label at the specified index should display its text label.
			RIM_INLINE void setUserLabelIsEnabled( Index labelIndex, Bool newLabelEnabled )
			{
				if ( labelIndex < userLabels.getSize() )
					userLabels[labelIndex].labelEnabled = newLabelEnabled;
			}
			
			
			
			
			/// Return whether or not the user-defined label at the specified index should display its dividing line.
			RIM_INLINE Bool getUserDivisionIsEnabled( Index labelIndex ) const
			{
				return userLabels[labelIndex].divisionEnabled;
			}
			
			
			
			
			/// Set whether or not the user-defined label at the specified index should display its dividing line.
			RIM_INLINE void setUserDivisionIsEnabled( Index labelIndex, Bool newDivisionEnabled )
			{
				if ( labelIndex < userLabels.getSize() )
					userLabels[labelIndex].divisionEnabled = newDivisionEnabled;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Units Accessor Methods
			
			
			
			
			/// Return a string representing a short name or abbreviation for the units which this axis represents.
			RIM_INLINE const UTF8String& getUnits() const
			{
				return units;
			}
			
			
			
			
			/// Set a string representing a short name or abbreviation for the units which this axis represents.
			RIM_INLINE void setUnits( const UTF8String& newUnits )
			{
				units = newUnits;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Curve Accessor Methods
			
			
			
			
			/// Return an object which describes the scale which is used to display values along this axis.
			RIM_INLINE const ValueCurve& getValueCurve() const
			{
				return valueCurve;
			}
			
			
			
			
			/// Set an object which describes the scale which is used to display values along this axis.
			RIM_INLINE void setValueCurve( const ValueCurve& newCurve )
			{
				valueCurve = newCurve;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Division Size Accessor Methods
			
			
			
			
			/// Return a value indicating how far apart major divisions are spaced on the graph view.
			RIM_INLINE Float getMajorDivision() const
			{
				return majorDivision;
			}
			
			
			
			
			/// Return a value indicating how far apart minor divisions are spaced on the graph view.
			RIM_INLINE Float getMinorDivision() const
			{
				return minorDivision;
			}
			
			
			
			
			/// Set a value indicating how far apart major divisions are spaced on the graph view.
			RIM_INLINE void setMajorDivision( Float newMajorDivision )
			{
				majorDivision = math::abs( newMajorDivision );
			}
			
			
			
			
			/// Set a value indicating how far apart minor divisions are spaced on the graph view.
			RIM_INLINE void setMinorDivision( Float newMinorDivision )
			{
				minorDivision = math::abs( newMinorDivision );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Division Enable Accessor Methods
			
			
			
			
			/// Return whether or not major dividing lines should be drawn for this axis.
			RIM_INLINE Bool getMajorDivisionsEnabled() const
			{
				return (flags & MAJOR_DIVISIONS) != 0;
			}
			
			
			
			
			/// Return whether or not minor dividing lines should be drawn for this axis.
			RIM_INLINE Bool getMinorDivisionsEnabled() const
			{
				return (flags & MINOR_DIVISIONS) != 0;
			}
			
			
			
			
			/// Set whether or not major dividing lines should be drawn for this axis.
			RIM_INLINE void setMajorDivisionsEnabled( Bool newMajorDivisionsEnabled )
			{
				if ( newMajorDivisionsEnabled )
					flags |= MAJOR_DIVISIONS;
				else
					flags &= ~MAJOR_DIVISIONS;
			}
			
			
			
			
			/// Set whether or not minor dividing lines should be drawn for this axis.
			RIM_INLINE void setMinorDivisionsEnabled( Bool newMinorDivisionsEnabled )
			{
				if ( newMinorDivisionsEnabled )
					flags |= MINOR_DIVISIONS;
				else
					flags &= ~MINOR_DIVISIONS;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Division Label Enable Accessor Methods
			
			
			
			
			/// Return whether or not major dividing labels should be drawn for this axis.
			RIM_INLINE Bool getMajorLabelsEnabled() const
			{
				return (flags & MAJOR_LABELS) != 0;
			}
			
			
			
			
			/// Return whether or not minor dividing labels should be drawn for this axis.
			RIM_INLINE Bool getMinorLabelsEnabled() const
			{
				return (flags & MINOR_LABELS) != 0;
			}
			
			
			
			
			/// Set whether or not major dividing labels should be drawn for this axis.
			RIM_INLINE void setMajorLabelsEnabled( Bool newMajorLabelsEnabled )
			{
				if ( newMajorLabelsEnabled )
					flags |= MAJOR_LABELS;
				else
					flags &= ~MAJOR_LABELS;
			}
			
			
			
			
			/// Set whether or not minor dividing labels should be drawn for this axis.
			RIM_INLINE void setMinorLabelsEnabled( Bool newMinorLabelsEnabled )
			{
				if ( newMinorLabelsEnabled )
					flags |= MINOR_LABELS;
				else
					flags &= ~MINOR_LABELS;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Major Division Color Accessor Methods
			
			
			
			
			/// Return the color to use for this axis's major grid lines.
			RIM_INLINE const Color4f& getMajorDivisionColor() const
			{
				return majorDivisionColor;
			}
			
			
			
			
			
			/// Set the color to use for this axis's major grid lines.
			RIM_INLINE void setMajorDivisionColor( const Color4f& newMajorDivisionColor )
			{
				majorDivisionColor = newMajorDivisionColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Minor Division Color Accessor Methods
			
			
			
			
			/// Return the color to use for this axis's minor grid lines.
			RIM_INLINE const Color4f& getMinorDivisionColor() const
			{
				return minorDivisionColor;
			}
			
			
			
			
			
			/// Set the color to use for this axis's minor grid lines.
			RIM_INLINE void setMinorDivisionColor( const Color4f& newMinorDivisionColor )
			{
				minorDivisionColor = newMinorDivisionColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default width for a major dividing line in a graph view.
			static const Float DEFAULT_MAJOR_DIVISION_WIDTH;
			
			
			/// The default width for a minor dividing line in a graph view.
			static const Float DEFAULT_MINOR_DIVISION_WIDTH;
			
			
			/// The default background color that is used for a graph view's area.
			static const Color4f DEFAULT_MAJOR_DIVISION_COLOR;
			
			
			/// The default border color that is used for a graph view.
			static const Color4f DEFAULT_MINOR_DIVISION_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which stores information about a single label for a graph axis.
			class GraphLabel
			{
				public:
					
					/// Create a new graph label with the specified attributes.
					RIM_INLINE GraphLabel( const UTF8String& newLabel, Float newValue,
											Bool newLabelEnabled, Bool newDivisionEnabled )
						:	label( newLabel ),
							value( newValue ),
							labelEnabled( newLabelEnabled ),
							divisionEnabled( newDivisionEnabled )
					{
					}
					
					
					
					
					/// A string representing the label for this 
					UTF8String label;
					
					
					
					
					/// The value at which this label should be positioned.
					Float value;
					
					
					
					
					/// A boolean value indicating whether or not the text label should be visible for this label.
					Bool labelEnabled;
					
					
					
					
					/// A boolean value indicating whether or not a dividing line should be visible for this label.
					Bool divisionEnabled;
					
					
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The main label for the axis which indicates what the axis represents.
			UTF8String label;
			
			
			
			
			/// A string representing a short name or abbreviation for the units which this axis represents.
			UTF8String units;
			
			
			
			
			/// A list of user-defined labels for the axis which allows the user to arbitrarily space marking labels.
			ArrayList<GraphLabel> userLabels;
			
			
			
			
			/// An object which describes the scale which is used to display values along this axis.
			ValueCurve valueCurve;
			
			
			
			
			/// A value indicating how far apart major divisions are spaced on the graph view.
			Float majorDivision;
			
			
			
			
			/// A value indicating how far apart minor divisions are spaced on the graph view.
			Float minorDivision;
			
			
			
			
			/// The width of the major division gridlines for the graph.
			Float majorDivisionWidth;
			
			
			
			
			/// The width of the minor division gridlines for the graph.
			Float minorDivisionWidth;
			
			
			
			
			/// The color to use when drawing major graph divisions.
			Color4f majorDivisionColor;
			
			
			
			
			/// The color to use when drawing major graph divisions.
			Color4f minorDivisionColor;
			
			
			
			
			/// An integer containing boolean flags for this graph view axis.
			UInt32 flags;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GRAPH_VIEW_AXIS_H

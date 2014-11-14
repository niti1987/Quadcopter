/*
 *  rimGraphicsGUIMeter.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/13/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_METER_H
#define INCLUDE_RIM_GRAPHICS_GUI_METER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIMeterDelegate.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a sliding rectangular region that allows the user to modify a ranged value.
class Meter : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sizeless meter positioned at the origin of its coordinate system.
			Meter();
			
			
			
			
			/// Create a new meter which occupies the specified rectangle and has the default range.
			Meter( const Rectangle& newRectangle );
			
			
			
			
			/// Create a new meter which has the specified rectangle, orientation, range, and value.
			Meter( const Rectangle& newRectangle, const Orientation& newOrientation,
					const AABB1f& newRange, Float newValue );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Return the current value for the meter.
			RIM_INLINE Float getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set the current value for the meter.
			/**
			  * The new meter value is clamped to lie within the meter's valid
			  * range of values.
			  */
			void setValue( Float newValue );
			
			
			
			
			/// Set the value for the meter with the specified transition time in seconds.
			/**
			  * The new target meter value is clamped to lie within the meter's valid
			  * range of values. The meter's displayed value will smoothly transition over the
			  * specified transition time interval to the target value.
			  */
			void setValue( Float newValue, Float newTransitionTime );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Range Accessor Methods
			
			
			
			
			/// Return an object which describes the minimum and maximum allowed values for the meter.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the meter's major axis,
			  * and the maximum value is placed at the maximum coordinate of the meter's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the meter.
			  */
			RIM_INLINE const AABB1f& getRange() const
			{
				return range;
			}
			
			
			
			
			/// Set an object which describes the minimum and maximum allowed values for the meter.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the meter's major axis,
			  * and the maximum value is placed at the maximum coordinate of the meter's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the meter.
			  *
			  * The meter's value is clamped so that is lies within the new range.
			  */
			void setRange( const AABB1f& newRange );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Curve Accessor Methods
			
			
			
			
			/// Return an object representing the curve which is used to map from meter values to displayed positions.
			RIM_INLINE ValueCurve getValueCurve() const
			{
				return valueCurve;
			}
			
			
			
			
			/// Set an object representing the curve which is used to map from meter values to displayed positions.
			RIM_INLINE void setValueCurve( ValueCurve newCurve )
			{
				valueCurve = newCurve;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Return an object which describes how this meter's area is rotated.
			RIM_INLINE const Orientation& getOrientation() const
			{
				return orientation;
			}
			
			
			
			
			/// Set an object which describes how this meter's area is rotated.
			RIM_INLINE void setOrientation( const Orientation& newOrientation )
			{
				orientation = newOrientation;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this meter's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this meter's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this meter's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Meter Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes the border for this meter's moving area.
			RIM_INLINE Border& getMeterBorder()
			{
				return meterBorder;
			}
			
			
			
			
			/// Return an object which describes the border for this meter's moving area.
			RIM_INLINE const Border& getMeterBorder() const
			{
				return meterBorder;
			}
			
			
			
			
			/// Set an object which describes the border for this meter's moving area.
			RIM_INLINE void setMeterBorder( const Border& newMeterBorder )
			{
				meterBorder = newMeterBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the meter's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the meter's content display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
			/// Return the local bounding box for the meter's moving area.
			AABB2f getLocalMeterBounds() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Meter State Accessor Methods
			
			
			
			
			/// Return whether or not this meter is currently active.
			RIM_INLINE Bool getIsEnabled() const
			{
				return isEnabled;
			}
			
			
			
			
			/// Set whether or not this meter is currently active.
			RIM_INLINE void setIsEnabled( Bool newIsEnabled )
			{
				isEnabled = newIsEnabled;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this meter.
			RIM_INLINE MeterDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this meter.
			RIM_INLINE const MeterDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this meter.
			RIM_INLINE void setDelegate( const MeterDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this meter's area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this meter's area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a meter.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a meter.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Meter Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a meter's moving area.
			RIM_INLINE const Color4f& getMeterColor() const
			{
				return meterColor;
			}
			
			
			
			
			/// Set the color used when rendering a meter's moving area.
			RIM_INLINE void setMeterColor( const Color4f& newMeterColor )
			{
				meterColor = newMeterColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Meter Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a meter's moving area.
			RIM_INLINE const Color4f& getMeterBorderColor() const
			{
				return meterBorderColor;
			}
			
			
			
			
			
			/// Set the border color used when rendering a meter's moving area.
			RIM_INLINE void setMeterBorderColor( const Color4f& newMeterBorderColor )
			{
				meterBorderColor = newMeterBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this meter for the specified time interval in seconds.
			virtual void update( Float dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this object using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the object was successfully drawn.
			  *
			  * The default implementation draws nothing and returns TRUE.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Meter> construct()
			{
				return Pointer<Meter>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Meter> construct( const Rectangle& newRectangle )
			{
				return Pointer<Meter>::construct( newRectangle );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Meter> construct( const Rectangle& newRectangle, const Orientation& newOrientation,
														const AABB1f& newRange, Float newValue )
			{
				return Pointer<Meter>::construct( newRectangle, newOrientation, newRange, newValue );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a meter.
			static const Border DEFAULT_BORDER;
			
			
			/// The default meter border that is used for a meter's moving area.
			static const Border DEFAULT_METER_BORDER;
			
			
			/// The default background color that is used for a meter's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a meter's area.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default color that is used for a meter's moving area.
			static const Color4f DEFAULT_METER_COLOR;
			
			
			/// The default meter border color that is used for a meter's moving area.
			static const Color4f DEFAULT_METER_BORDER_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the bounding box for this meter's moving area given the bounds for its content area.
			RIM_INLINE AABB2f getMeterBoundsForContentBounds( const AABB2f& contentBounds ) const;
			
			
			
			
			/// Return the position of the meter from [0,1], based on the current value within the meter's range.
			RIM_INLINE Float getMeterPosition() const
			{
				if ( range.min <= range.max )
					return valueCurve.evaluateInverse( value, range );
				else
					return valueCurve.evaluateInverse( value, AABB1f( range.max, range.min ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which describes how this meter is rotated within its area.
			Orientation orientation;
			
			
			
			
			/// The range of allowed values for this meter.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the meter's major axis,
			  * and the maximum value is placed at the maximum coordinate of the meter's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the meter.
			  */
			AABB1f range;
			
			
			
			
			/// The current value for the meter.
			Float value;
			
			
			
			
			/// The target value for the meter.
			Float targetValue;
			
			
			
			
			/// The amount that the meter's value should change by for each second that passes.
			Float valueChangeRate;
			
			
			
			
			/// An object representing the curve which is used to map from meter values to positions.
			ValueCurve valueCurve;
			
			
			
			
			/// An object which describes the border for this meter.
			Border border;
			
			
			
			
			/// An object which describes the border for this meter's moving area.
			Border meterBorder;
			
			
			
			
			/// An object which contains function pointers that respond to meter events.
			MeterDelegate delegate;
			
			
			
			
			/// The background color for the meter's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the meter's background area.
			Color4f borderColor;
			
			
			
			
			/// The color used for the moving part of the meter's area.
			Color4f meterColor;
			
			
			
			
			/// The border color used for the moving part of the meter's area.
			Color4f meterBorderColor;
			
			
			
			
			/// A boolean value indicating whether or not this meter is active.
			/**
			  * If the meter is not enabled, it will not display its moving meter area
			  * and will not indicate a value or allow the user to edit the meter.
			  */
			Bool isEnabled;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_METER_H

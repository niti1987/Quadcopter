/*
 *  rimGraphicsGUISlider.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/8/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_SLIDER_H
#define INCLUDE_RIM_GRAPHICS_GUI_SLIDER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUISliderDelegate.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a sliding rectangular region that allows the user to modify a ranged value.
class Slider : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sizeless slider positioned at the origin of its coordinate system.
			Slider();
			
			
			
			
			/// Create a new slider which occupies the specified rectangle and has the default range.
			Slider( const Rectangle& newRectangle );
			
			
			
			
			/// Create a new slider which has the specified rectangle, orientation, range, and value.
			Slider( const Rectangle& newRectangle, const Orientation& newOrientation,
					const AABB1f& newRange, Float newValue );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Return the current value for the slider.
			RIM_INLINE Float getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set the current value for the slider.
			/**
			  * The new slider value is clamped to lie within the slider's valid
			  * range of values.
			  */
			void setValue( Float newValue );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Range Accessor Methods
			
			
			
			
			/// Return an object which describes the minimum and maximum allowed values for the slider.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the slider's major axis,
			  * and the maximum value is placed at the maximum coordinate of the slider's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the slider.
			  */
			RIM_INLINE const AABB1f& getRange() const
			{
				return range;
			}
			
			
			
			
			/// Set an object which describes the minimum and maximum allowed values for the slider.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the slider's major axis,
			  * and the maximum value is placed at the maximum coordinate of the slider's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the slider.
			  *
			  * The slider's value is clamped so that is lies within the new range.
			  */
			void setRange( const AABB1f& newRange );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Number Of Steps Accessor Methods
			
			
			
			
			/// Return the total number of value steps there are for this slider.
			/**
			  * This allows the user to quantize the slider's allowed values to
			  * a fixed number of evenly-spaced steps.
			  *
			  * If this value is 0, the default, the slider's resolution is unquantized
			  * and can be used to represent any value in the valid range.
			  */
			RIM_INLINE Size getStepCount() const
			{
				return numSteps;
			}
			
			
			
			
			/// Set the total number of value steps there are for this slider.
			/**
			  * This allows the user to quantize the slider's allowed values to
			  * a fixed number of evenly-spaced steps.
			  *
			  * If this value is 0, the default, the slider's resolution is unquantized
			  * and can be used to represent any value in the valid range.
			  */
			RIM_INLINE void setStepCount( Size newNumSteps )
			{
				numSteps = newNumSteps;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Curve Accessor Methods
			
			
			
			
			/// Return an object representing the curve which is used to map from slider positions to values.
			RIM_INLINE ValueCurve getValueCurve() const
			{
				return valueCurve;
			}
			
			
			
			
			/// Set an object representing the curve which is used to map from slider positions to values.
			RIM_INLINE void setValueCurve( ValueCurve newCurve )
			{
				valueCurve = newCurve;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Orientation Accessor Methods
			
			
			
			
			/// Return an object which describes how this divider's dividing line is rotated.
			RIM_INLINE const Orientation& getOrientation() const
			{
				return orientation;
			}
			
			
			
			
			/// Set an object which describes how this divider's dividing line is rotated.
			RIM_INLINE void setOrientation( const Orientation& newOrientation )
			{
				orientation = newOrientation;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this slider's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this slider's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this slider's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the slider's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the slider's content display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
			/// Return the local bounding box for the slider's moving area.
			AABB2f getLocalSliderBounds() const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes the border for this slider's moving area.
			RIM_INLINE Border& getSliderBorder()
			{
				return sliderBorder;
			}
			
			
			
			
			/// Return an object which describes the border for this slider's moving area.
			RIM_INLINE const Border& getSliderBorder() const
			{
				return sliderBorder;
			}
			
			
			
			
			/// Set an object which describes the border for this slider's moving area.
			RIM_INLINE void setSliderBorder( const Border& newSliderBorder )
			{
				sliderBorder = newSliderBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Size Accessor Methods
			
			
			
			
			/// Return the size of the slider's moveable area along the major axis of the slider in vertical screen units.
			RIM_INLINE Float getSliderSize() const
			{
				return sliderSize;
			}
			
			
			
			
			/// Set the size of the slider's moveable area along the major axis of the slider in vertical screen units.
			RIM_INLINE void setSliderSize( Float newSliderSize )
			{
				sliderSize = newSliderSize;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider State Accessor Methods
			
			
			
			
			/// Return whether or not this slider is currently active.
			RIM_INLINE Bool getIsEnabled() const
			{
				return isEnabled;
			}
			
			
			
			
			/// Set whether or not this slider is currently active.
			RIM_INLINE void setIsEnabled( Bool newIsEnabled )
			{
				isEnabled = newIsEnabled;
			}
			
			
			
			
			/// Return whether or not this slider is able to be edited by the user.
			RIM_INLINE Bool getIsEditable() const
			{
				return isEditable;
			}
			
			
			
			
			/// Return whether or not this slider is able to be edited by the user.
			RIM_INLINE void setIsEditable( Bool newIsEditable )
			{
				isEditable = newIsEditable;
			}
			
			
			
			
			/// Return whether or not this slider is currently grabbed by the mouse.
			RIM_INLINE Bool getIsGrabbed() const
			{
				return isGrabbed;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this slider's area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this slider's area.
			/**
			  * The method returns whether or not the slider's background color was successfully changed.
			  */
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a slider.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a slider.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a slider's moving area.
			RIM_INLINE const Color4f& getSliderColor() const
			{
				return sliderColor;
			}
			
			
			
			
			/// Set the color used when rendering a slider's moving area.
			RIM_INLINE void setSliderColor( const Color4f& newSliderColor )
			{
				sliderColor = newSliderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Slider Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a slider's moving area.
			RIM_INLINE const Color4f& getSliderBorderColor() const
			{
				return sliderBorderColor;
			}
			
			
			
			
			
			/// Set the border color used when rendering a slider's moving area.
			RIM_INLINE void setSliderBorderColor( const Color4f& newSliderBorderColor )
			{
				sliderBorderColor = newSliderBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this slider for the specified time interval in seconds.
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
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event that occured when this object had focus.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event that occurred.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event that occurred.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event that occurred.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Delegate Accessor Methods
			
			
			
			
			/// Return a reference to the delegate which responds to events for this slider.
			RIM_INLINE SliderDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this slider.
			RIM_INLINE const SliderDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this slider.
			RIM_INLINE void setDelegate( const SliderDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Slider> construct()
			{
				return Pointer<Slider>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Slider> construct( const Rectangle& newRectangle )
			{
				return Pointer<Slider>::construct( newRectangle );
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Slider> construct( const Rectangle& newRectangle, const Orientation& newOrientation,
														const AABB1f& newRange, Float newValue )
			{
				return Pointer<Slider>::construct( newRectangle, newOrientation, newRange, newValue );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			/// The default size of a slider's moving area.
			static const Float DEFAULT_SLIDER_SIZE;
			
			
			/// The default border that is used for a slider.
			static const Border DEFAULT_BORDER;
			
			
			/// The default meter border that is used for a slider's moving area.
			static const Border DEFAULT_SLIDER_BORDER;
			
			
			/// The default background color that is used for a slider's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a slider's area.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default color that is used for a slider's moving area.
			static const Color4f DEFAULT_SLIDER_COLOR;
			
			
			/// The default meter border color that is used for a slider's moving area.
			static const Color4f DEFAULT_SLIDER_BORDER_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the bounding box for this slider's moving area given the bounds for its content area.
			RIM_INLINE AABB2f getSliderBoundsForContentBounds( const AABB2f& contentBounds ) const;
			
			
			
			
			/// Return the position of the slider from [0,1], based on the current value within the slider's range.
			RIM_INLINE Float getSliderPosition() const
			{
				return this->getSliderPositionFromValue( value );
			}
			
			
			
			
			/// Return the position of the slider from [0,1], based on the specified value within the slider's range.
			RIM_INLINE Float getSliderPositionFromValue( Float v ) const
			{
				if ( range.min <= range.max )
					return valueCurve.evaluateInverse( v, range );
				else
					return Float(1) - valueCurve.evaluateInverse( v, AABB1f( range.max, range.min ) );
			}
			
			
			
			
			/// Return the position of the slider from [0,1], based on the current value within the slider's range.
			RIM_INLINE Float getValueFromSliderPosition( Float a ) const
			{
				if ( numSteps > 0 )
					a = math::round( numSteps*a ) / numSteps;
				
				if ( range.min <= range.max )
					return valueCurve.evaluate( a, range );
				else
					return valueCurve.evaluate( Float(1) - a, AABB1f( range.max, range.min ) );
			}
			
			
			
			
			/// Convert the specified slider value to a quantized value if this slider has a discrete number of steps.
			RIM_INLINE Float stepifyValue( Float newValue )
			{
				return this->getValueFromSliderPosition( this->getSliderPositionFromValue( newValue ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which describes how this slider is rotated within its area.
			Orientation orientation;
			
			
			
			
			/// The range of allowed values for this slider.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the slider's major axis,
			  * and the maximum value is placed at the maximum coordinate of the slider's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the slider.
			  */
			AABB1f range;
			
			
			
			
			/// The current value for the slider.
			Float value;
			
			
			
			
			/// The total number of value steps there are for this slider.
			/**
			  * This allows the user to quantize the slider's allowed values to
			  * a fixed number of evenly-spaced steps.
			  *
			  * If this value is 0, the default, the slider's resolution is unquantized
			  * and can be used to represent any value in the valid range.
			  */
			Size numSteps;
			
			
			
			
			/// An object representing the curve which is used to map from slider positions to values.
			ValueCurve valueCurve;
			
			
			
			
			/// The size of the slider's moveable area along the major axis of the slider in vertical screen units.
			Float sliderSize;
			
			
			
			
			/// An object which describes the border for this slider.
			Border border;
			
			
			
			
			/// An object which describes the border for this slider's moving area.
			Border sliderBorder;
			
			
			
			
			/// An object which contains function pointers that respond to slider events.
			SliderDelegate delegate;
			
			
			
			
			/// The background color for the slider's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the slider's background area.
			Color4f borderColor;
			
			
			
			
			/// The color used for the moving part of the slider's area.
			Color4f sliderColor;
			
			
			
			
			/// The border color used for the moving part of the slider's area.
			Color4f sliderBorderColor;
			
			
			
			
			/// The offset vector of the mouse location from the minimum slider bounding coordinate.
			/**
			  * This value keeps the slider from warping to the mouse's location when it is
			  * grabbed off-center.
			  */
			Vector2f grabOffset;
			
			
			
			
			/// A boolean value indicating whether or not this slider is active.
			/**
			  * If the slider is not enabled, it will not display its moving slider area
			  * and will not indicate a value or allow the user to edit the slider.
			  */
			Bool isEnabled;
			
			
			
			
			/// A boolean value indicating whether or not this slider's value can be changed by the user.
			Bool isEditable;
			
			
			
			
			/// A boolean value which indicates whether or not this slider is currently grabbed by the mouse.
			Bool isGrabbed;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_SLIDER_H

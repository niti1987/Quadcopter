/*
 *  rimGraphicsGUIKnob.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 2/16/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_KNOB_H
#define INCLUDE_RIM_GRAPHICS_GUI_KNOB_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"
#include "rimGraphicsGUIKnobDelegate.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which represents a rotating circular region that allows the user to modify a ranged value.
class Knob : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new sizeless knob positioned at the origin of its coordinate system.
			Knob();
			
			
			
			
			/// Create a new knob which has the specified radius, position, range, and value.
			Knob( Float radius, const Vector2f& newPosition = Vector2f(),
					const Origin& newPositionOrigin = Origin( Origin::LEFT, Origin::BOTTOM ),
					const AABB1f& newRange = AABB1f(0,1), Float newValue = 0 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Size Accessor Methods
			
			
			
			
			/// Set the size of this knob.
			/**
			  * Since knobs are inherently circular, this method will fail, returning
			  * FALSE if the specified size is not square, i.e. both width and height
			  * are the same. Otherwise, if the sizes are equal, the method succeeds.
			  */
			Bool setSize( const Vector2f& newSize );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Radius Accessor Methods
			
			
			
			
			/// Return the radius of this knob's circular area.
			RIM_INLINE Float getRadius() const
			{
				return Float(0.5)*this->getSize().x;
			}
			
			
			
			
			/// Set the radius of this knob's circular area.
			/**
			  * The method returns whether or not the knob's radius was successfully changed.
			  * If the method succeeds, the knob automatically updates the radius
			  * of its border to match the knob's radius.
			  */
			Bool setRadius( Float newRadius );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Value Accessor Methods
			
			
			
			
			/// Return the current value for the knob.
			RIM_INLINE Float getValue() const
			{
				return value;
			}
			
			
			
			
			/// Set the current value for the knob.
			/**
			  * The new knob value is clamped to lie within the knob's valid
			  * range of values.
			  */
			void setValue( Float newValue );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Range Accessor Methods
			
			
			
			
			/// Return an object which describes the minimum and maximum allowed values for the knob.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the knob's major axis,
			  * and the maximum value is placed at the maximum coordinate of the knob's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the knob.
			  */
			RIM_INLINE const AABB1f& getRange() const
			{
				return range;
			}
			
			
			
			
			/// Set an object which describes the minimum and maximum allowed values for the knob.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the knob's major axis,
			  * and the maximum value is placed at the maximum coordinate of the knob's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the knob.
			  *
			  * The knob's value is clamped so that is lies within the new range.
			  */
			void setRange( const AABB1f& newRange );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Number Of Steps Accessor Methods
			
			
			
			
			/// Return the total number of value steps there are for this knob.
			/**
			  * This allows the user to quantize the knob's allowed values to
			  * a fixed number of evenly-spaced steps.
			  *
			  * If this value is 0, the default, the knob's resolution is unquantized
			  * and can be used to represent any value in the valid range.
			  */
			RIM_INLINE Size getStepCount() const
			{
				return numSteps;
			}
			
			
			
			
			/// Set the total number of value steps there are for this knob.
			/**
			  * This allows the user to quantize the knob's allowed values to
			  * a fixed number of evenly-spaced steps.
			  *
			  * If this value is 0, the default, the knob's resolution is unquantized
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
			
			
			
			
			/// Return an object representing the curve which is used to map from knob positions to values.
			RIM_INLINE ValueCurve getValueCurve() const
			{
				return valueCurve;
			}
			
			
			
			
			/// Set an object representing the curve which is used to map from knob positions to values.
			RIM_INLINE void setValueCurve( ValueCurve newCurve )
			{
				valueCurve = newCurve;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Sensitivity Accessor Methods
			
			
			
			
			/// Return the current value for the knob.
			RIM_INLINE Float getSensitivity() const
			{
				return value;
			}
			
			
			
			
			/// Set the current value for the knob.
			/**
			  * The new knob value is clamped to lie within the knob's valid
			  * range of values.
			  */
			void setSensitivity( Float newSensitivity )
			{
				sensitivity = math::max( newSensitivity, this->getSize().x );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this knob's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this knob's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this knob's border.
			/**
			  * The new border is set to have the same radius as the knob to
			  * preserve visual quality.
			  */
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
				border.setRadius( this->getRadius() );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Knob Direction Accessor Method
			
			
			
			
			/// Return the normalized direction vector indicating the direction that the knob is turned.
			RIM_INLINE Vector2f getDirection() const
			{
				Float a = this->getKnobPosition();
				Float angle = angleRange.min + a*angleRange.getSize();
				
				return Vector2f( math::cos(angle), math::sin(angle) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Knob State Accessor Methods
			
			
			
			
			/// Return whether or not this knob is currently active.
			/**
			  * An inactive knob may change its visual appearance to indicate that
			  * it is not able to be changed by the user.
			  */
			RIM_INLINE Bool getIsEnabled() const
			{
				return isEnabled;
			}
			
			
			
			
			/// Set whether or not this knob is currently active.
			/**
			  * An inactive knob may change its visual appearance to indicate that
			  * it is not able to be changed by the user.
			  */
			RIM_INLINE void setIsEnabled( Bool newIsEnabled )
			{
				isEnabled = newIsEnabled;
			}
			
			
			
			
			/// Return whether or not this knob is able to be edited by the user.
			RIM_INLINE Bool getIsEditable() const
			{
				return isEditable;
			}
			
			
			
			
			/// Return whether or not this knob is able to be edited by the user.
			RIM_INLINE void setIsEditable( Bool newIsEditable )
			{
				isEditable = newIsEditable;
			}
			
			
			
			
			/// Return whether or not this knob is currently grabbed by the mouse.
			RIM_INLINE Bool getIsGrabbed() const
			{
				return isGrabbed;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Background Color Accessor Methods
			
			
			
			
			/// Return the background color for this knob's area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this knob's area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a knob.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a knob.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Knob Color Accessor Methods
			
			
			
			
			/// Return the color used when rendering a knob's rotation indicator.
			RIM_INLINE const Color4f& getIndicatorColor() const
			{
				return indicatorColor;
			}
			
			
			
			
			/// Set the color used when rendering a knob's rotation indicator.
			RIM_INLINE void setIndicatorColor( const Color4f& newKnobIndicatorColor )
			{
				indicatorColor = newKnobIndicatorColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Indicator Width Accessor Methods
			
			
			
			
			/// Return the width used when rendering a knob's rotation indicator.
			/**
			  * This width is expressed here as a fraction of the knob's radius.
			  */
			RIM_INLINE Float getIndicatorWidth() const
			{
				return indicatorWidth;
			}
			
			
			
			
			/// Set the width used when rendering a knob's rotation indicator.
			/**
			  * This width is expressed here as a fraction of the knob's radius.
			  */
			RIM_INLINE void setIndicatorWidth( Float newIndicatorWidth )
			{
				indicatorWidth = math::clamp( newIndicatorWidth, Float(0), Float(1) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this knob for the specified time interval in seconds.
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
			
			
			
			
			/// Return a reference to the delegate which responds to events for this knob.
			RIM_INLINE KnobDelegate& getDelegate()
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this knob.
			RIM_INLINE const KnobDelegate& getDelegate() const
			{
				return delegate;
			}
			
			
			
			
			/// Return a reference to the delegate which responds to events for this knob.
			RIM_INLINE void setDelegate( const KnobDelegate& newDelegate )
			{
				delegate = newDelegate;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Knob> construct()
			{
				return Pointer<Knob>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<Knob> construct( Float radius, const Vector2f& newPosition = Vector2f(),
													const Origin& newPositionOrigin = Origin( Origin::LEFT, Origin::BOTTOM ),
													const AABB1f& newRange = AABB1f(0,1), Float newValue = 0 )
			{
				return Pointer<Knob>::construct( radius, newPosition, newPositionOrigin, newRange, newValue );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members

			
			
			
			/// The default valid angle range in radians for the knob's rotation.
			static const AABB1f DEFAULT_ANGLE_RANGE;
			
			
			/// The default border that is used for a knob.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a knob's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a knob.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			/// The default border color that is used for a knob's indicator.
			static const Color4f DEFAULT_INDICATOR_COLOR;
			
			
			/// The default width used for the knob's indicator direction line, as a fraction of the knob radius.
			static const Float DEFAULT_INDICATOR_WIDTH;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the position of the knob from [0,1], based on the current value within the knob's range.
			RIM_INLINE Float getKnobPosition() const
			{
				return this->getKnobPositionFromValue( value );
			}
			
			
			
			
			/// Return the position of the knob from [0,1], based on the specified value within the knob's range.
			RIM_INLINE Float getKnobPositionFromValue( Float v ) const
			{
				if ( range.min <= range.max )
					return valueCurve.evaluateInverse( v, range );
				else
					return Float(1) - valueCurve.evaluateInverse( v, AABB1f( range.max, range.min ) );
			}
			
			
			
			
			/// Return the position of the knob from [0,1], based on the current value within the knob's range.
			RIM_INLINE Float getValueFromKnobPosition( Float a ) const
			{
				if ( numSteps > 0 )
					a = math::round( numSteps*a ) / numSteps;
				
				if ( range.min <= range.max )
					return valueCurve.evaluate( a, range );
				else
					return valueCurve.evaluate( Float(1) - a, AABB1f( range.max, range.min ) );
			}
			
			
			
			
			/// Convert the specified knob value to a quantized value if this knob has a discrete number of steps.
			RIM_INLINE Float stepifyValue( Float newValue )
			{
				return this->getValueFromKnobPosition( this->getKnobPositionFromValue( newValue ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// The range of allowed values for this knob.
			/**
			  * The range's minimum value is placed at the minimum coordinate of the knob's major axis,
			  * and the maximum value is placed at the maximum coordinate of the knob's major axis.
			  *
			  * The minimum and maximum values do not have to be properly ordered - they can be
			  * reversed in order to reverse the effective direction of the knob.
			  */
			AABB1f range;
			
			
			
			
			/// The current value for the knob.
			Float value;
			
			
			
			
			/// The total number of value steps there are for this knob.
			/**
			  * This allows the user to quantize the knob's allowed values to
			  * a fixed number of evenly-spaced steps.
			  *
			  * If this value is 0, the default, the knob's resolution is unquantized
			  * and can be used to represent any value in the valid range.
			  */
			Size numSteps;
			
			
			
			
			/// An object representing the curve which is used to map from knob positions to values.
			ValueCurve valueCurve;
			
			
			
			
			/// The valid angle range in radians for the knob's rotation.
			AABB1f angleRange;
			
			
			
			
			/// An object which describes the border for this knob.
			Border border;
			
			
			
			
			/// An object which contains function pointers that respond to knob events.
			KnobDelegate delegate;
			
			
			
			
			/// The sensitivity of this knob to mouse movement.
			/**
			  * This value indicates how far the mouse must be moved vertically to go from
			  * the knob's minimum value to the maximum value.
			  */
			Float sensitivity;
			
			
			
			
			/// The offset vector of the mouse location from the minimum knob bounding coordinate.
			/**
			  * This value keeps the knob from warping to the mouse's location when it is
			  * grabbed off-center.
			  */
			Vector2f grabOffset;
			
			
			
			
			// The starting value when the knob was last grabbed.
			Float grabValueFraction;
			
			
			
			
			/// The background color for the knob's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the knob's background area.
			Color4f borderColor;
			
			
			
			
			/// The color used for the moving part of the knob's area.
			Color4f indicatorColor;
			
			
			
			
			/// The width of the knob direction indicator line, in units of percentage of the knob's width.
			Float indicatorWidth;
			
			
			
			
			/// A boolean value indicating whether or not this knob is active.
			/**
			  * If the knob is not enabled, it will not display its moving knob area
			  * and will not indicate a value or allow the user to edit the knob.
			  */
			Bool isEnabled;
			
			
			
			
			/// A boolean value indicating whether or not this knob's value can be changed by the user.
			Bool isEditable;
			
			
			
			
			/// A boolean value which indicates whether or not this knob is currently grabbed by the mouse.
			Bool isGrabbed;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_KNOB_H

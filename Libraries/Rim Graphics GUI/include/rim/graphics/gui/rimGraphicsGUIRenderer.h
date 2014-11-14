/*
 *  rimGraphicsGUIRenderer.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 1/22/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_RENDERER_H
#define INCLUDE_RIM_GRAPHICS_GUI_RENDERER_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIFonts.h"
#include "rimGraphicsGUIObject.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################


class Screen;
class Button;
class Slider;
class Meter;
class Knob;
class TextField;
class ImageView;
class OptionMenu;
class MenuBar;
class Menu;
class Divider;
class ScrollView;
class ContentView;
class RenderView;
class GraphView;
class GridView;




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which handles drawing GUI objects using a graphics rendering context.
class GUIRenderer
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new GUI renderer with no valid rendering context.
			/**
			  * This renderer will not be able to draw anything until a valid context
			  * is supplied via setContext().
			  */
			GUIRenderer();
			
			
			
			
			/// Create a new GUI renderer which uses the specified context for rendering.
			GUIRenderer( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Context Accessor Methods
			
			
			
			
			/// Return a pointer to the graphics context which this GUI renderer is using to render.
			RIM_INLINE const Pointer<GraphicsContext>& getContext() const
			{
				return context;
			}
			
			
			
			
			/// Set a pointer to the graphics context which this GUI renderer is using to render.
			/**
			  * This causes the renderer to use the specified context to do all of its rendering.
			  * The renderer reinitializes all internal state using the new context. If the
			  * new context is NULL or not valid, the renderer will not be able to render anything.
			  */
			void setContext( const Pointer<GraphicsContext>& newContext );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Viewport Accessor Methods
			
			
			
			
			/// Return the current viewport that this GUI renderer is drawing to.
			RIM_INLINE const Viewport& getViewport() const
			{
				return drawer.getViewport();
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Main Object Drawing Method
			
			
			
			
			/// Draw the specified object within the specified screen pixel coordinate bounds.
			/**
			  * This method is typically called by GUIObject subclasses which have child
			  * objects that need to be drawn where the concrete object type is unknown.
			  */
			virtual Bool drawObject( const GUIObject& object, const AABB3f& parentBounds );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Drawing Methods
			
			
			
			
			/// Draw a screen in the specified pixel bounds.
			virtual Bool drawScreen( const Screen& screen, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a content view in the specified pixel bounds.
			virtual Bool drawContentView( const ContentView& contentView, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a render view in the specified pixel bounds.
			virtual Bool drawRenderView( const RenderView& renderView, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a scroll view in the specified pixel bounds.
			virtual Bool drawScrollView( const ScrollView& scrollView, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a grid view in the specified pixel bounds.
			virtual Bool drawGridView( const GridView& gridView, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a graph view in the specified pixel bounds.
			virtual Bool drawGraphView( const GraphView& graphView, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a button in the specified pixel bounds.
			virtual Bool drawButton( const Button& button, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a meter in the specified pixel bounds.
			virtual Bool drawMeter( const Meter& meter, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a slider in the specified pixel bounds.
			virtual Bool drawSlider( const Slider& slider, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a knob in the specified pixel bounds.
			virtual Bool drawKnob( const Knob& knob, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a text field in the specified pixel bounds.
			virtual Bool drawTextField( const TextField& textField, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a image view in the specified pixel bounds.
			virtual Bool drawImageView( const ImageView& imageView, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a menu bar in the specified pixel bounds.
			virtual Bool drawMenuBar( const MenuBar& menuBar, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a menu in the specified pixel bounds.
			virtual Bool drawMenu( const Menu& menu, const AABB3f& parentBounds );
			
			
			
			
			/// Draw an option menu in the specified pixel bounds.
			virtual Bool drawOptionMenu( const OptionMenu& optionMenu, const AABB3f& parentBounds );
			
			
			
			
			/// Draw a divider in the specified pixel bounds.
			virtual Bool drawDivider( const Divider& divider, const AABB3f& parentBounds );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	String Drawing Methods
			
			
			
			
			/// Draw the specified unicode string using the provided font style.
			/**
			  * The position and font size are assumed to be in normalized vertical-screen-unit
			  * coordinates. The current viewport is assumed to represent the current dimensions
			  * of the screen and so the specified position and size are scaled by the height
			  * of the viewport to get their values in pixel units.
			  */
			virtual Bool drawString( const UTF8String& string, const fonts::FontStyle& style, Vector2f& position );
			
			
			
			
			/// Draw the specified string within the specified bounding box with the given parameters.
			virtual Bool drawStringArea( const UTF8String& string, const fonts::FontStyle& style,
										const AABB2f& bounds, const Origin& textAlignment, Bool wrap );
			
			
			
			
			/// Retrieve a bounding box for the specified string using the given font style.
			/**
			  * This method computes a bounding box for the string where the starting
			  * pen position is the origin (0,0). If the method succeeds, the string's
			  * bounding box is placed in the output reference parameter and TRUE is returned.
			  * If the method fails, FALSE is returned and no bounding box is computed.
			  *
			  * This method is useful for centering and laying out text before rendering it.
			  */
			virtual Bool getStringBounds( const UTF8String& string, const fonts::FontStyle& style, AABB2f& bounds );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Primitive Drawing Methods
			
			
			
			
			/// Draw a rectangle with the specified bounds and color.
			/**
			  * All coordinates are specified in the current local coordinate system. 
			  */
			virtual Bool drawRectangle( const AABB2f& pixelBounds, const Color4f& color );
			
			
			
			
			/// Draw a point with the specified pixel position with the given color.
			/**
			  * All coordinates are specified in the current local coordinate system.
			  * The method returns whether or not the point was successfully drawn.
			  */
			virtual Bool drawPoint( const Vector2f& point, const Color4f& color,
									Float size = Float(1) );
			
			
			
			
			/// Draw a series of circular points with the specified locations, color, and size.
			/**
			  * All coordinates are specified in the current local coordinate system.
			  * The method returns whether or not the points were successfully drawn.
			  */
			virtual Bool drawPoints( const ArrayList<Vector2f>& vertices,
									const Color4f& color, Float size = Float(1) );
			
			
			
			
			/// Draw a line with the specified start and endpoints with the given start and ending color.
			/**
			  * All coordinates are specified in the current local coordinate system.
			  * The method returns whether or not the line was successfully drawn.
			  */
			virtual Bool drawLine( const Vector2f& start, const Vector2f& end,
									const Color4f& startColor, const Color4f& endColor,
									Float width = Float(1) );
			
			
			
			
			/// Draw a series of disconnected lines with the specified vertices and color.
			/**
			  * All coordinates are specified in the current local coordinate system.
			  * Every 2 vertices represent the start and endpoints of a line.
			  * The method returns whether or not the lines were successfully drawn.
			  */
			virtual Bool drawLines( const ArrayList<Vector2f>& vertices,
									const Color4f& color, Float width = Float(1) );
			
			
			
			
			/// Draw a connected line strip with the specified vertices and color.
			/**
			  * All coordinates are specified in the current local coordinate system.
			  * The method returns whether or not the lines were successfully drawn.
			  */
			virtual Bool drawLineStrip( const ArrayList<Vector2f>& vertices,
									const Color4f& color, Float width = Float(1) );
			
			
			
			
			/// Draw a circle with the specified position, radius, and color.
			/**
			  * All coordinates are specified in the current local coordinate system.
			  * The method returns whether or not the circle was successfully drawn.
			  */
			virtual Bool drawCircle( const Vector2f& position, Float radius, const Color4f& color );
			
			
			
			
			/// Draw an image from a texture with the specified bounding box to the screen.
			/**
			  * All coordinates are specified in the current local coordinate system.
			  * If the specified texture image is not valid or drawing fails, FALSE is returned
			  * indicating failure. Otherwise, TRUE is returned if the operation is successful.
			  *
			  * The method allows the user to specify a color with which the image will be
			  * tinted with (multiplied) when drawn. The default color is white, indicating
			  * that no tinting occurs.
			  */
			virtual Bool drawImage( const util::TextureImage& image, const AABB2f& parentBounds,
									const Color4f& color = Color4f::WHITE );
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Create and initialize this drawer's vertex buffers and shaders to their default state.
			void initializeGraphicsState();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Drawing Helper Methods
			
			
			
			
			/// Apply transformations and scissor test rectangles for the specified object in the given parent bounds.
			RIM_FORCE_INLINE void beginDrawingObject( const GUIObject& object, const AABB3f& parentBounds );
			
			
			
			
			/// Finish drawing the specified object, and return the renderer state to the previous state.
			RIM_FORCE_INLINE void endDrawingObject( const GUIObject& object );
			
			
			
			
			/// Apply a scissor test to the current rendering state.
			/**
			  * The method returns the viewport-space scissor viewport BEFORE clipping
			  * with the parent scissor rectangle.
			  */
			RIM_FORCE_INLINE AABB2f beginScissorTest( const AABB2f& localScissorViewport,
													Bool enabled = true, Bool respectParent = true );
			
			
			
			
			/// Apply a scissor test to the current rendering state.
			/**
			  * The method returns the viewport-space scissor viewport BEFORE clipping
			  * with the parent scissor rectangle.
			  */
			RIM_FORCE_INLINE AABB2f beginScissorTest( const AABB3f& localScissorViewport,
													Bool enabled = true, Bool respectParent = true );
			
			
			
			
			/// Restore the previous scissor test.
			RIM_FORCE_INLINE void endScissorTest();
			
			
			
			
			/// Apply the model-view-projection transform and do the perspective divide to get into viewport space.
			RIM_FORCE_INLINE static Vector3f viewProjection( const Matrix4f& projectionTransform, const Vector4f& point )
			{
				Vector4f homogeneous = projectionTransform * point;
				
				// Convert to normalized device coodinates by the perspective division.
				Vector3f ndc = homogeneous.getXYZ() / homogeneous.w;
				
				// Convert to viewport coordinates [0,1].
				return Float(0.5)*ndc + Float(1);
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Drawing Methods
			
			
			
			
			/// Draw a 2D bordered rectangle in the current coordinate system.
			void drawBorderedRectangle( const AABB2f& bounds, const Border& border,
										const Color4f& backgroundColor, const Color4f& borderColor,
										const GUIStyle* style = NULL );
			
			
			
			
			/// Draw a 2D flat rectangle in the current coordinate system.
			void drawRectangle( const AABB2f& bounds, const Color4f& color, const GUIStyle* style );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An object which handles the drawing for this renderer.
			Pointer<GraphicsContext> context;
			
			
			
			
			/// An object that handles submitting vertices and drawing commands to the context.
			ImmediateRenderer drawer;
			
			
			
			
			/// An object which handles drawing text for this renderer.
			fonts::GraphicsFontDrawer fontDrawer;
			
			
			
			
			/// A pointer to the default style to use for drawing GUI objects with no style specified.
			Pointer<GUIStyle> defaultStyle;
			
			
			
			
			/// An object representing the shader pass to use for bordered objects (circles, rectangles).
			Pointer<ShaderPass> borderShaderPass;
			
			
			
			
			/// An object representing the shader pass to use for drawing lines.
			Pointer<ShaderPass> lineShaderPass;
			
			
			
			
			/// An object representing the shader pass to use for drawing images.
			Pointer<ShaderPass> imageShaderPass;
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_RENDERER_H

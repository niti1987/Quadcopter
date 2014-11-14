/*
 *  rimGraphicsGUIGridView.h
 *  Rim Graphics GUI
 *
 *  Created by Carl Schissler on 3/19/13.
 *  Copyright 2013 Headspace Systems. All rights reserved.
 *
 */

#ifndef INCLUDE_RIM_GRAPHICS_GUI_GRID_VIEW_H
#define INCLUDE_RIM_GRAPHICS_GUI_GRID_VIEW_H


#include "rimGraphicsGUIBase.h"


#include "rimGraphicsGUIObject.h"


//##########################################################################################
//************************  Start Rim Graphics GUI Namespace  ******************************
RIM_GRAPHICS_GUI_NAMESPACE_START
//******************************************************************************************
//##########################################################################################




//********************************************************************************
//********************************************************************************
//********************************************************************************
/// A class which contains a 2D grid of rectangular cells that can contain child GUI objects.
/**
  * A grid view is an optionally-bordered rectangular area whose content area (inside
  * the border) is divided into a 2D grid of cells. Each cell can contain any number of
  * child GUI objects.
  */
class GridView : public GUIObject
{
	public:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Constructors
			
			
			
			
			/// Create a new grid view with no width or height and no rows or columns positioned at the origin.
			GridView();
			
			
			
			
			/// Create a new empty grid view with the given rectangle and number of rows and columns.
			/**
			  * The area of the rectangle is equally divided into the specified number of rows
			  * and columns.
			  */
			GridView( const Rectangle& newRectangle, Size newNumRows = 1, Size newNumColumns = 1 );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Row and Column Count Accessor Methods
			
			
			
			
			/// Return the total number of rows there are in this grid view.
			RIM_INLINE Size getRowCount() const
			{
				return rows.getSize();
			}
			
			
			
			
			/// Return the total number of columns there are in this grid view.
			RIM_INLINE Size getColumnCount() const
			{
				return columns.getSize();
			}
			
			
			
			
			/// Resize this grid view so that it has the specified number of rows and columns.
			/**
			  * If the number of rows or columns in the grid view is less than the previous
			  * number, some grid cells may be destroyed. If the number is greater, new
			  * empty cells are created.
			  */
			//void setGridSize( Size newNumRows, Size newNumColumns );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Row Size Accessor Methods
			
			
			
			
			/// Return the height of the row with the specified index in this grid view.
			/**
			  * If the row or column index is invalid, 0 is returned. Otherwise, the
			  * height of the specified row is returned.
			  */
			Float getRowHeight( Index rowIndex ) const;
			
			
			
			
			/// Set the height of the row with the specified index in this grid view.
			/**
			  * This method attempts to make the row with the given index have the
			  * specified height. It does this by finding the nearest resizable row(s)
			  * and using the space from those rows for the indexed row. If there isn't
			  * enough space in the grid view to change the row height, FALSE is returned
			  * indicating that the row was not resized. Otherwise, the row is resized
			  * and TRUE is returned.
			  */
			Bool setRowHeight( Index rowIndex, Float newHeight );
			
			
			
			
			/// Return whether or not the row with the specified index can be resized automatically.
			/**
			  * A row may be resized automatically when other rows are resized. If the return value
			  * is FALSE, the indexed row cannot be resized automatically. However, setRowHeight()
			  * will still resize a non-resizable row.
			  */
			RIM_INLINE Bool getRowIsResizable( Index rowIndex ) const
			{
				if ( rowIndex < rows.getSize() )
					return rows[rowIndex].isResizable;
				
				return false;
			}
			
			
			
			
			/// Set whether or not the row with the specified index can be resized automatically.
			/**
			  * A row may be resized automatically when other rows are resized. If the return value
			  * is FALSE, the indexed row cannot be resized automatically. However, setRowHeight()
			  * will still resize a non-resizable row.
			  *
			  * If an invalid row index is specified, the method has no effect.
			  */
			RIM_INLINE void setRowIsResizable( Index rowIndex, Bool newIsResizable )
			{
				if ( rowIndex < rows.getSize() )
					rows[rowIndex].isResizable = newIsResizable;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Column Size Accessor Methods
			
			
			
			
			/// Return the width of the column with the specified index in this grid view.
			/**
			  * If the column or column index is invalid, 0 is returned. Otherwise, the
			  * width of the specified column is returned.
			  */
			Float getColumnWidth( Index columnIndex ) const;
			
			
			
			
			/// Set the width of the column with the specified index in this grid view.
			/**
			  * This method attempts to make the column with the given index have the
			  * specified width. It does this by finding the nearest resizable column(s)
			  * and using the space from those columns for the indexed column. If there isn't
			  * enough space in the grid view to change the column width, FALSE is returned
			  * indicating that the column was not resized. Otherwise, the column is resized
			  * and TRUE is returned.
			  */
			Bool setColumnWidth( Index columnIndex, Float newWidth );
			
			
			
			
			/// Return whether or not the column with the specified index can be resized automatically.
			/**
			  * A column may be resized automatically when other columns are resized. If the return value
			  * is FALSE, the indexed column cannot be resized automatically. However, setColumnWidth()
			  * will still resize a non-resizable column.
			  */
			RIM_INLINE Bool getColumnIsResizable( Index columnIndex ) const
			{
				if ( columnIndex < columns.getSize() )
					return columns[columnIndex].isResizable;
				
				return false;
			}
			
			
			
			
			/// Set whether or not the column with the specified index can be resized automatically.
			/**
			  * A column may be resized automatically when other columns are resized. If the return value
			  * is FALSE, the indexed column cannot be resized automatically. However, setColumnWidth()
			  * will still resize a non-resizable column.
			  *
			  * If an invalid column index is specified, the method has no effect.
			  */
			RIM_INLINE void setColumnIsResizable( Index columnIndex, Bool newIsResizable )
			{
				if ( columnIndex < columns.getSize() )
					columns[columnIndex].isResizable = newIsResizable;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Object Accessor Methods
			
			
			
			
			/// Return the total number of GUIObjects that are part of the specified cell of this grid view.
			/**
			  * If the row or column index is invalid, 0 is returned. Otherwise, the
			  * number of objects in the specified cell is returned.
			  */
			RIM_INLINE Size getObjectCount( Index rowIndex, Index columnIndex ) const
			{
				if ( rowIndex < rows.getSize() && columnIndex < columns.getSize() )
					return getCell( rowIndex, columnIndex ).objects.getSize();
				else
					return 0;
			}
			
			
			
			
			/// Return a pointer to the object at the given index in the specified cell of this grid view.
			/**
			  * Objects are stored in back-to-front sorted order, such that the object
			  * with index 0 is the furthest toward the back of the object ordering.
			  */
			RIM_INLINE Pointer<GUIObject> getObject( Index rowIndex, Index columnIndex, Index objectIndex ) const
			{
				if ( rowIndex < rows.getSize() && columnIndex < columns.getSize() )
				{
					const GridCell& cell = getCell( rowIndex, columnIndex );
					
					if ( objectIndex < cell.objects.getSize() )
						return cell.objects[objectIndex];
				}
				
				return Pointer<GUIObject>();
			}
			
			
			
			
			/// Add the specified object to the given cell of this grid view.
			/**
			  * If the specified object pointer is NULL, the method fails and FALSE
			  * is returned. Otherwise, the object is inserted in the front-to-back order
			  * of the grid view cell's objects and TRUE is returned.
			  */
			Bool addObject( Index rowIndex, Index columnIndex, const Pointer<GUIObject>& newObject );
			
			
			
			
			/// Remove the specified object from the given cell of this grid view.
			/**
			  * If the given object is part of this grid view, the method removes it
			  * and returns TRUE. Otherwise, if the specified object is not found,
			  * the method doesn't modify the grid view and FALSE is returned.
			  */
			Bool removeObject( Index rowIndex, Index columnIndex, const GUIObject* oldObject );
			
			
			
			
			/// Remove all objects from the specified cell of this grid view.
			void clearObjects( Index rowIndex, Index columnIndex );
			
			
			
			
			/// Remove all objects from all cells of this grid view.
			void clearObjects();
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Accessor Methods
			
			
			
			
			/// Return a mutable object which describes this grid view's border.
			RIM_INLINE Border& getBorder()
			{
				return border;
			}
			
			
			
			
			/// Return an object which describes this grid view's border.
			RIM_INLINE const Border& getBorder() const
			{
				return border;
			}
			
			
			
			
			/// Set an object which describes this grid view's border.
			RIM_INLINE void setBorder( const Border& newBorder )
			{
				border = newBorder;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Content Bounding Box Accessor Methods
			
			
			
			
			/// Return the 3D bounding box for the grid view's content display area in its local coordinate frame.
			RIM_INLINE AABB3f getLocalContentBounds() const
			{
				return AABB3f( this->getLocalContentBoundsXY(), AABB1f( Float(0), this->getSize().z ) );
			}
			
			
			
			
			/// Return the 2D bounding box for the grid view's content display area in its local coordinate frame.
			RIM_INLINE AABB2f getLocalContentBoundsXY() const
			{
				return border.getContentBounds( AABB2f( Vector2f(), this->getSizeXY() ) );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Color Accessor Methods
			
			
			
			
			/// Return the background color for this grid view's main area.
			RIM_INLINE const Color4f& getBackgroundColor() const
			{
				return backgroundColor;
			}
			
			
			
			
			
			/// Set the background color for this grid view's main area.
			RIM_INLINE void setBackgroundColor( const Color4f& newBackgroundColor )
			{
				backgroundColor = newBackgroundColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Border Color Accessor Methods
			
			
			
			
			/// Return the border color used when rendering a grid view.
			RIM_INLINE const Color4f& getBorderColor() const
			{
				return borderColor;
			}
			
			
			
			
			/// Set the border color used when rendering a grid view.
			RIM_INLINE void setBorderColor( const Color4f& newBorderColor )
			{
				borderColor = newBorderColor;
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Update Method
			
			
			
			
			/// Update the current internal state of this grid view for the specified time interval in seconds.
			/**
			  * This method recursively calls the update() methods for all child objects
			  * so that they are updated.
			  */
			virtual void update( Float dt );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Drawing Method
			
			
			
			
			/// Draw this grid view using the specified GUI renderer to the given parent coordinate system bounds.
			/**
			  * The method returns whether or not the grid view was successfully drawn.
			  */
			virtual Bool drawSelf( GUIRenderer& renderer, const AABB3f& parentBounds ) const;
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Input Handling Methods
			
			
			
			
			/// Handle the specified keyboard event for the entire grid view.
			virtual void keyEvent( const KeyboardEvent& event );
			
			
			
			
			/// Handle the specified mouse motion event for the entire grid view.
			virtual void mouseMotionEvent( const MouseMotionEvent& event );
			
			
			
			
			/// Handle the specified mouse button event for the entire grid view.
			virtual void mouseButtonEvent( const MouseButtonEvent& event );
			
			
			
			
			/// Handle the specified mouse wheel event for the entire grid view.
			virtual void mouseWheelEvent( const MouseWheelEvent& event );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Static Construction Methods
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<GridView> construct()
			{
				return Pointer<GridView>::construct();
			}
			
			
			
			
			/// Construct a smart-pointer-wrapped instance of this class using the constructor with the given arguments.
			RIM_INLINE static Pointer<GridView> construct( const Rectangle& newRectangle,
															Size numRows = 1, Size numColumns = 1 )
			{
				return Pointer<GridView>::construct( newRectangle, numRows, numColumns );
			}
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Public Static Data Members
			
			
			
			
			/// The default border that is used for a grid view.
			static const Border DEFAULT_BORDER;
			
			
			/// The default background color that is used for a grid view's area.
			static const Color4f DEFAULT_BACKGROUND_COLOR;
			
			
			/// The default border color that is used for a grid view.
			static const Color4f DEFAULT_BORDER_COLOR;
			
			
			
			
	private:
		
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Class Declaration
			
			
			
			
			/// A class which contains information about a single cell for this grid view.
			class GridCell
			{
				public:
					
					
					/// A list of the child objects of the grid cell.
					ArrayList<Pointer<GUIObject> > objects;
					
			};
			
			
			
			
			/// A class which contains information about a row for the grid view.
			class GridRow
			{
				public:
					
					/// Create a resizable grid row with 0 height.
					RIM_INLINE GridRow( Float newHeight = 0 )
						:	height( newHeight ),
							isResizable( true )
					{
					}
					
					
					/// The height of this row as a fraction of the grid view's total content area height.
					Float height;
					
					
					/// A boolean value indicating whether or not this row can be automatically resized.
					Bool isResizable;
					
			};
			
			
			
			
			/// A class which contains information about a column for the grid view.
			class GridColumn
			{
				public:
					
					/// Create a resizable grid column with 0 width.
					RIM_INLINE GridColumn( Float newWidth = 0 )
						:	width( newWidth ),
							isResizable( true )
					{
					}
					
					
					/// The width of this row as a fraction of the grid view's total content area width.
					Float width;
					
					
					/// A boolean value indicating whether or not this column can be automatically resized.
					Bool isResizable;
					
			};
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Helper Methods
			
			
			
			
			/// Return the size for the grid view's content display area in its local coordinate frame.
			RIM_INLINE Vector2f getLocalContentSize() const
			{
				return this->getLocalContentBoundsXY().getSize();
			}
			
			
			
			
			/// Return a reference to the grid cell at the specified (row, column) index.
			RIM_INLINE GridCell& getCell( Index rowIndex, Index columnIndex )
			{
				return cells[rowIndex*columns.getSize() + columnIndex];
			}
			
			
			
			
			/// Return a reference to the grid cell at the specified (row, column) index.
			RIM_INLINE const GridCell& getCell( Index rowIndex, Index columnIndex ) const
			{
				return cells[rowIndex*columns.getSize() + columnIndex];
			}
			
			
			
			
			/// Initialize the (previously uninitialized) grid with the specified number of rows and columns.
			void initializeGrid( Size newNumRows, Size newNumColumns );
			
			
			
			
		//********************************************************************************
		//********************************************************************************
		//********************************************************************************
		//******	Private Data Members
			
			
			
			
			/// An array of the cells in this grid view, stored in a row-major 1D format.
			Array<GridCell> cells;
			
			
			
			
			/// An array of information about the rows in this grid view.
			Array<GridRow> rows;
			
			
			
			
			/// An array of information about the columns in this grid view.
			Array<GridColumn> columns;
			
			
			
			
			/// An object which describes the border for this grid view.
			Border border;
			
			
			
			
			/// The background color for the grid view's area.
			Color4f backgroundColor;
			
			
			
			
			/// The border color for the grid view's background area.
			Color4f borderColor;
			
			
			
			
};




//##########################################################################################
//************************  End Rim Graphics GUI Namespace  ********************************
RIM_GRAPHICS_GUI_NAMESPACE_END
//******************************************************************************************
//##########################################################################################


#endif // INCLUDE_RIM_GRAPHICS_GUI_GRID_VIEW_H

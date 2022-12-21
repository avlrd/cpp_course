#pragma once

#include "ECellValue.hpp"

class GridCell
{
	public:
		inline int getLineNumber() const { return line_number; }
		inline int getColumnNumber() const { return column_number; }
		inline ECellValue getCellValue() const { return cell_value; }
		inline void setX(int column_number) { this->column_number = column_number; }
		inline void setY(int line_number) { this->line_number = line_number; }
		
	private:
		int line_number;
		int column_number;
		ECellValue cell_value;
};
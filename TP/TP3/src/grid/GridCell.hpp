#pragma once

#include "ECellValue.hpp"

class GridCell
{
	public:
		GridCell(int line_number, int column_number, ECellValue cell_value)
			: line_number(line_number), column_number(column_number), cell_value(cell_value) {}
		
		inline int getLineNumber() const { return line_number; }
		inline int getColumnNumber() const { return column_number; }
		inline ECellValue getCellValue() const { return cell_value; }
		// not needed ?
		// inline void setColumnNumber(int column_number) { this->column_number = column_number; }
		// inline void setLineNumber(int line_number) { this->line_number = line_number; }
		inline void setCellValue(ECellValue cell_value) { this->cell_value = cell_value; }
		
	private:
		const int line_number;
		const int column_number;
		ECellValue cell_value;
};
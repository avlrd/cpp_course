#include "Grid.hpp"

Grid::Grid(int l, int c)
{
	for (int i = 0; i < l; i++)
	{
		std::vector<GridCell> row;
		for (int j = 0; j < c; j++)
		{
			row.push_back(GridCell(i, j, ECellValue::EMPTY));
		}
		elements.push_back(row);
	}
}

GridCell Grid::get_element(int l, int c)
{
	return elements[l][c];
}

void Grid::set_element(int l, int c, ECellValue value)
{
	elements[l][c].setCellValue(value);
}

int Grid::get_width()
{
	return (int) elements[0].size();
}

int Grid::get_height()
{
	return (int) elements.size();
}
#include "Grid.hpp"

Grid::Grid(int l, int c)
{
	for (int i = 0; i < l; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < c; j++)
		{
			row.push_back(0);
		}
		elements.push_back(row);
	}
}

Grid::~Grid()
{
}

int Grid::get_element(int x, int y)
{
	return elements[x][y];
}

int Grid::get_element_by_index(int index)
{
	int x = index / elements[0].size();
	int y = index % elements.size();
	return elements[x][y];
}

void Grid::set_element(int x, int y, int value)
{
	elements[x][y] = value;
}

void Grid::set_element_by_index(int index, int value)
{
	for(int i = 0; i < elements.size(); i++)
	{
		for(int j = 0; j < elements[i].size(); j++)
		{
			if (index == 0)
				elements[i][j] = value;
			index--;
		}
	}
}

int Grid::get_width()
{
	return (int) elements.size();
}

int Grid::get_height()
{
	return (int) elements[0].size();
}

void Grid::display()
{
	int index = 0;
	for(int i = 0; i < elements.size(); i++)
	{
		for(int k = 0; k < elements[i].size()*2+1; k++)
			std::cout << "-";
		std::cout << std::endl;
		for(int j = 0; j < elements[i].size(); j++)
		{
			std::cout << "|";
			
			switch(elements[i][j])
			{
				case 0:
					std::cout << " ";
					break;
				case 1:
					std::cout << "X";
					break;
				case 2:
					std::cout << "O";
					break;
				default:
					std::cout << "?";
					break;
			}
		}
		std::cout << "|" << std::endl;
	}
	for(int k = 0; k < elements[0].size()*2+1; k++)
		std::cout << "-";
	std::cout << std::endl;
}
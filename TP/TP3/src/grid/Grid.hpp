#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "GridCell.hpp"

class Grid
{
	public:
		Grid(int x, int y);
		//no destructor needed cause std vector deletes itself ?	

		GridCell get_element(int l, int c);
		void set_element(int l, int c, ECellValue value);
		
		int get_width();
		int get_height();

	private:
		std::vector<std::vector<GridCell>> elements;
};

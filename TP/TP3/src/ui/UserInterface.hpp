#pragma once

#include "../grid/Grid.hpp"
#include "../game/EGame.hpp"

class UserInterface
{
	public:
		virtual void welcome() = 0;
		virtual void ready_check_error() = 0;
		virtual void menu_input_error() = 0;
		virtual void game_type_selection_display() = 0;
		virtual void game_mode_selection_display() = 0;
		virtual void name_selection_display() = 0;
		virtual void symbol_selection_display() = 0;
		virtual bool input(int& value) = 0;
		virtual bool input(std::string& value) = 0;
		virtual void clear_input() = 0;
		
		virtual void displayGrid(Grid& grid) = 0;
};
#pragma once

#include "../grid/Grid.hpp"
#include "UserInterface.hpp"

// All console line interface display functions
class CommandLineInterface : public UserInterface
{
	public:
		void welcome();
		void ready_check_error();
		void menu_input_error();
		void game_type_selection_display();
		void game_mode_selection_display();
		void name_selection_display();
		void symbol_selection_display();
		bool input(int& value);
		bool input(std::string& value);
		void clear_input();

		void displayGrid(Grid& grid);

	private:
		void clear();
};

#pragma once

#include "../grid/ECellValue.hpp"
#include <string>

class Player
{
	public:
		Player(std::string chosen_name, ECellValue chosen_symbol) : name(chosen_name), symbol(chosen_symbol) {}
		
	private:
		const std::string name;
		const ECellValue symbol;
};
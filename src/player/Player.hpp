#pragma once

#include "../grid/ECellValue.hpp"
#include <string>

class Player
{
	public:
		Player(std::string chosen_name, ECellValue chosen_symbol) : name(chosen_name), symbol(chosen_symbol) {}
		Player operator=(Player player) { return Player(player.name, player.symbol); }

		std::string get_name() { return name; }
		ECellValue get_symbol() { return symbol; }
		
	protected:
		const std::string name;
		const ECellValue symbol;
};
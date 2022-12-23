#pragma once

#include "Player.hpp"

class Ia : public Player
{
	public:
		Ia() : Player("IA", ECellValue::O) {}
};
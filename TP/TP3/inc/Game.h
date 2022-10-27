#pragma once

#include <iostream>

enum Gametype
{
	MORPION,
	PUISSANCE4
};

enum Gamemode
{
	SOLO,
	MULTI
};

class Game
{
	public:
		
	private:
		Gamemode gamemode;
		Gametype gametype;
};
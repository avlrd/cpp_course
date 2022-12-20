#pragma once

#include "src/game/EGame.hpp"
#include "src/player/Player.hpp"

class GameState
{
	public:
		GameState();
		~GameState();

	private:
		bool running;
		Player winner;
		EGameType GameType;
		EGameMode GameMode;
};
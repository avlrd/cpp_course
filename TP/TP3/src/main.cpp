#include "game/Game.hpp"
#include "game/Morpion.hpp"
#include "game/Puissance4.hpp"
#include "game/Othello.hpp"
#include "utils/Utils.hpp"
#include "game/GameState.hpp"
#include "ui/CLI.hpp"

int main()
{
	//get arg from command line and put it into ui var
	
	UserInterface& ui(CommandLineInterface());
	GameState instance = GameState(ui);
	
	while (instance.replay_value())
	{
		// main menu, initializes game type and game mode
		instance.init();
		//instance.start_game();
	}
}
#include "GameState.hpp"

void GameState::init()
{
	intro();
	game_menu();
	if (!ready_check())
	{
		ui.ready_check_error();
		exit(EXIT_FAILURE);
	}
}

void GameState::intro()
{
	ui.welcome();
}

void GameState::game_menu()
{
	bool game_type_selected = false, game_mode_selected = false, players_initialized = false;
	while (!players_initialized)
	{
		while (!game_mode_selected)
		{
			while (!game_type_selected)
			{
				game_type_selection();
				if (game_type != EGameType::NONE)
					game_type_selected = true;
				else
					menu_selection_error();
			}

			game_mode_selection();
			if (game_mode == EGameMode::BACK)
				continue;
			else if (game_mode != EGameMode::NONE)
				game_mode_selected = true;
			else
				menu_selection_error();
		}
		
		players_initialization();
		if (player1.get_symbol() != player2.get_symbol())
			players_initialized = true;
		else
			menu_selection_error();
	}
}

void GameState::game_type_selection()
{
	int choice = 0;
	bool anerrorhasbeenmade = false;
	bool isok = false;
	while (!isok)
	{
		ui.game_type_selection_display();
		if (anerrorhasbeenmade)
			ui.menu_input_error();
		if ((ui.input(choice)) && (choice >= 1 && choice <= 4))
		{
			isok = true;
			switch (choice)
			{
				case 1:
					game_type = EGameType::MORPION;
					break;
				case 2:
					game_type = EGameType::PUISSANCE4;
					break;
				case 3:
					game_type = EGameType::OTHELLO;
					break;
				case 4:
					exit(EXIT_SUCCESS);
				default:
					break;
			}
		}
		else
		{
			anerrorhasbeenmade = true;
			ui.clear_input();
		}
	}
}

void GameState::game_mode_selection()
{
	int choice = 0;
	bool anerrorhasbeenmade = false;
	bool isok = false;
	while (!isok)
	{
		ui.game_mode_selection_display();
		if (anerrorhasbeenmade)
			ui.menu_input_error();
		if ((ui.input(choice)) && (choice >= 1 && choice <= 4))
		{
			isok = true;
			switch (choice)
			{
				case 1:
					game_mode = EGameMode::SOLO;
					break;
				case 2:
					game_mode = EGameMode::MULTI;
					break;
				case 3:
					game_mode = EGameMode::BACK;
					break;
				default:
					break;
			}
		}
		else
		{
			anerrorhasbeenmade = true;
			ui.clear_input();
		}
	}
}

void GameState::players_initialization()
{
	bool name_chosen = false;
	bool anerrorhasbeenmade = false;
	std::string name;

	while (!name_chosen)
	{
		ui.name_selection_display();
		if (anerrorhasbeenmade)
			ui.menu_input_error();
		if (ui.input(name) && name != "")
		{
			name_chosen = true;
			player1 = Player(name, ECellValue::X);
		}
		else
		{
			anerrorhasbeenmade = true;
			ui.clear_input();
		}
	}
	
	if (game_mode == EGameMode::MULTI)
	{
		name_chosen = false;
		anerrorhasbeenmade = false;
		name = "";
		
		while (!name_chosen)
		{
			ui.name_selection_display();
			if (anerrorhasbeenmade)
				ui.menu_input_error();
			if (ui.input(name) && name != "")
			{
				name_chosen = true;
				player2 = Player(name, ECellValue::O);
			}
			else
			{
				anerrorhasbeenmade = true;
				ui.clear_input();
			}
		}
	}
	else
	{
		player2 = Ia();
	}
}


void GameState::menu_selection_error()
{
	exit(EXIT_FAILURE);
}

bool GameState::ready_check()
{
	//ajouter verif players
	if (game_type != EGameType::NONE && game_mode != EGameMode::NONE && player1.get_symbol() != player2.get_symbol())
		return true;
	return false;
}
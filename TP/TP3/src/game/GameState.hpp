#pragma once

#include "EGame.hpp"
#include "../ui/CLI.hpp"
#include "../player/Player.hpp"
#include "../player/IA.hpp"

enum EUIType
{
	CLI,
	GUI
};

class GameState
{
	public:
		template <typename T>
		GameState(T& ui)
			: ui(ui)
		{
			replay = true;
			game_type = EGameType::NONE;
			game_mode = EGameMode::NONE;
		}

		// Getters Setters
		inline bool replay_value() const { return replay; }
		//inline EUIType get_UI_type() const { return UI_type; }
		inline EGameType get_game_type() const { return game_type; }
		inline EGameMode get_game_mode() const { return game_mode; }
		inline void set_replay_value(bool value) { replay = value; }
		inline void set_game_type(EGameType game_type) { this->game_type = game_type; }
		inline void set_game_mode(EGameMode game_mode) { this->game_mode = game_mode; }
		

		void init();
		void start_game();

	private:
		UserInterface& ui;
		bool replay;
		Player player1;
		Player player2;
		EGameType game_type;
		EGameMode game_mode;

		void intro();
		void game_menu();
		bool ready_check();
		void game_type_selection();
		void game_mode_selection();
		void players_initialization();
		void menu_selection_error();
};
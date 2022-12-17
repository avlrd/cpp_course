#pragma once

#include "Game.hpp"

class Othello : public Game
{
public:
	Othello();
	~Othello();

	void run(int& mode);
	void display_grid();
	void check_win(bool& checker, int& winner);

private:
	void replace_symbol(int& symbol);
	bool check_rows(int& winner);
	bool check_columns(int& winner);
	bool check_diag(int& winner);
	void play_solo(int& symbol);
	void play_multi(int& symbol);
	void saisir_case(int& symbol);
	bool empty_case(int& column, int& line);
	void tour_ia(int& symbol);
};
#include "Othello.hpp"

Othello::Othello()
{
	grid = new Grid(8, 8);
}

Othello::~Othello()
{
}

void Othello::run(int& mode)
{
	int symbol;
	switch (mode)
	{
	default:
		verif_IsIntegerBetween(mode, 1, 2);
		break;

	case 1:
		std::cout << "You are playing against the computer.\n";
		choose_symbol(symbol);
		play_solo(symbol);
		break;

	case 2:
		std::cout << "You are playing against another player.\n";
		choose_symbol(symbol);
		play_multi(symbol);
		break;
	}
}

void Othello::play_solo(int& symbol)
{
	bool player_win = false;
	int winner;
	bool ia = false;
	int ia_symbol = symbol == 1 ? 2 : 1;
	while (!player_win)
	{
		display_grid();
		if (ia == true)
		{
			//tour_ia(ia_symbol);
			ia = false;
		}
		else
		{
			saisir_case(symbol);
			ia = true;
		}
		check_win(player_win, winner);
	}
	display_grid();
	end_screen(symbol, winner);
}

void Othello::play_multi(int& symbol)
{
	bool player_win = false;
	int winner;
	while (!player_win)
	{
		display_grid();
		saisir_case(symbol);
		check_win(player_win, winner);
		if (symbol == 1)
			symbol = 2;
		else
			symbol = 1;
	}
	end_screen(symbol, winner);
}

void Othello::saisir_case(int& symbol)
{
	char column_char;
	int line;
	std::cout << "Enter the column (A to H) and the line (1 to 8) of the case you want to play.\n";
	std::cin >> column_char >> line;

	//v�rif des entr�es
	verif_IsIntegerBetween(line, 1, 8);
	verif_IsLetterBetween(column_char, 'A', 'H');
	
	//convertion de la lettre colonne en chiffre de 0 � 7
	int column = column_char - 65;
	line -= 1;

	if (empty_case(line, column)) {
		grid->set_element(line, column, symbol);
	}
	else
	{
		std::cout << "Please choose an empty case.\n";
		saisir_case(symbol);
	}



}

//inversement des symboles plac�s entre le dernier symbole jou� et un symbole du m�me type dans les 8 directions
/*
void Othello::replace_symbolBetween(int& symbol, int& column, int& line)
{

}
*/

//v�rifie si la case est vide
bool Othello::empty_case(int& column, int& line)
{
	if (grid->get_element(column, line) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Othello::check_win(bool& checker, int& winner) {
	//v�rifie si le joueur a gagn�
	//compte le nombre de x et de o pour les comparer : celui qui a le plus de symboles sur le plateau a gagn�
	//(la partie prend fin que lorsque le plateau est rempli)
}

void Othello::display_grid()
{
	grid->display();
}
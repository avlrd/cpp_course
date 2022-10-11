#pragma once

#include <iostream>
#include <random>
#include <thread>

#include "Player.h"

using std::cin;
using std::cout;
using std::string;

class Tennis
{
public:
	Tennis(std::string playerAName, std::string playerBName);

	Player* A;
	Player* B;

private:
	int score[3][2];

	bool won;
	int winner;

	void playMatch();
	void compute(int id);
	void scoreboardHandler(int nbGamesA, int nbGamesB);
	void tiebreak();
	void displayScore(string winner);
};
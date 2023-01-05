#pragma once

#include <string>

class Player
{
private:
	std::string name;

	int sets;
	int games;
	int points;

public:
	Player(std::string name);
	int getPoints();
	int getGames();
	int getSets();
	void addPoint();
	void addGame();
	void addSet();
	void remPoint();
	void resetPoints();
	void resetGames();

	std::string getName();
	void setName(std::string name);
};
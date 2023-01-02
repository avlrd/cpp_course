#include "../inc/Player.h"

Player::Player(std::string name)
{
	this->name = name;
	points = 0;
	games = 0;
	sets = 0;
}

int Player::getPoints() { return points; }

int Player::getGames() { return games; }

int Player::getSets() { return sets; }

void Player::addPoint() { points++; }

void Player::addGame() { games++; }

void Player::addSet() { sets++; }

void Player::remPoint() { points--; }

void Player::resetPoints() { points = 0; }

void Player::resetGames() { games = 0; }

std::string Player::getName() { return name; }

void Player::setName(std::string name) { this->name = name; }

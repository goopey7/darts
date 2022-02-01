//Copyright Sam Collier 2022

#include "Player.h"


Player::Player(const std::string& _name, int _successRate)
	: name(_name), successRate(_successRate)
{
}

Player::~Player()
{
}

bool Player::throwDart()
{
	overallDartsThrown++;
	if(rand() % 100 < successRate)
	{
		overallBullseyes++;
		return true;
	}
	return false;
}

void Player::setSuccessRate(int sucessPercentage)
{
	successRate = sucessPercentage;
}

int Player::getSuccessRate()
{
	return successRate;
}

const std::string& Player::getName()
{
	return name;
}

void Player::setGameResults(int bullseyes, int dartsThrown, bool winner)
{
	GameStats stats = {bullseyes,dartsThrown,winner};
	gameStats.push_back(stats);
}

const GameStats& Player::getGameResult(int gameID)
{
	return gameStats[gameID];
}


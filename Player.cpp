//Copyright Sam Collier 2022

#include "Player.h"


Player::Player(const std::string& _name, int _successRate)
	: name(_name), successRate(_successRate)
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

void Player::updateSuccessRate(int sucessPercentage)
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

void Player::setGameResults(int bullseyes, int dartsThrown, int turns, bool winner)
{
	GameStats stats = {bullseyes,dartsThrown,turns,winner};
	gameStats.push_back(stats);
}

const GameStats& Player::getGameResult(int gameID)
{
	return gameStats[gameID];
}

const GameStats& Player::getLastGameResult()
{
	return gameStats[gameStats.size()-1];
}

int Player::getDartsThrownAllTime()
{
	return overallDartsThrown;
}

int Player::getBullseyesAllTime()
{
	return overallBullseyes;
}


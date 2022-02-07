//Copyright Sam Collier 2022
#pragma once

#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

struct GameStats
{
	int bullseyes;
	int dartsThrown;
	int turns;
	bool winner;
};
class Player
{
	public:
		Player(const std::string& _name, int _successRate);

		// simulates a dart thrown, uses sucess rate for likelihood
		// returns true if bullseye is hit
		bool throwDart(); 

		// getters and setters
		void updateSuccessRate(int sucessPercentage);
		int getSuccessRate();
		int getDartsThrownAllTime();
		int getBullseyesAllTime();
		const std::string& getName();
		void setGameResults(int bullseyes, int dartsThrown, int turns, bool winner);
		const GameStats& getGameResult(int gameID);
		const GameStats& getLastGameResult();

	private:
		std::vector<GameStats> gameStats;
		std::string name;
		int successRate;
		int overallDartsThrown;
		int overallBullseyes;
};


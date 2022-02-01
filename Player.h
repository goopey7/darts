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
	bool winner;
};
class Player
{
	public:
		Player(const std::string& _name, int _successRate);
		~Player();

		// simulates a dart thrown, uses sucess rate for likelihood
		// returns true if bullseye is hit
		bool throwDart(); 

		// getters and setters
		void setSuccessRate(int sucessPercentage);
		int getSuccessRate();
		const std::string& getName();
		void setGameResults(int bullseyes, int dartsThrown, bool winner);
		const GameStats& getGameResult(int gameID);

	private:
		std::vector<GameStats> gameStats;
		std::string name;
		int successRate;
		int overallDartsThrown;
		int overallBullseyes;
};


#include <iostream>
#include <vector>
#include "Player.h"

int main()
{
	srand(0);
	Player* joe = new Player("Joe",71);
	Player* sid = new Player("Sid",73);

	Player* first;
	Player* second;

	bool bPlayAgain=true;
	while(bPlayAgain)
	{
		if(joe->getSuccessRate() > sid->getSuccessRate())
		{
			first = sid;
			second = joe;
		}
		else
		{
			first = joe;
			second = sid;
		}

		std::vector<Player*> players;
		players.push_back(first);
		players.push_back(second);

		int dir = 1;
		int i=0;

		std::vector<int> bullseyes(2);
		std::vector<int> dartsThrown(2);
		std::vector<int> turns(2);

		int winner = -1;
		Player* winningPlayer;

		// Game Loop
		while(true)
		{
			std::cout << "Current Player: " << players[i]->getName() << std::endl;
			turns[i]++;
			for(int j=0;j<3;j++)
			{
				if(players[i]->throwDart())
				{
					std::cout << "bullseye!\n";
					bullseyes[i]++;
					if(bullseyes[i]==10)
					{
						winner = i;
						winningPlayer = players[i];
					}
				}
				else
				{
					std::cout << "miss!\n";
				}
				dartsThrown[i]++;
			}
			i+=dir;
			dir*=-1;
			if(winner>=0)
				break;
		}
		first->setGameResults(bullseyes[0],dartsThrown[0],turns[0],!winner);
		second->setGameResults(bullseyes[1],dartsThrown[1],turns[1],winner);
		std::cout << "\n======================================\n";
		std::cout << winningPlayer->getName() << " wins!\n";
		std::cout << "Turns: " << winningPlayer->getLastGameResult().turns;
		std::cout << "\nThrows: " << winningPlayer->getLastGameResult().dartsThrown;
		std::cout << "\nBullseyes: " << winningPlayer->getLastGameResult().bullseyes;
		std::cout << "\n======================================\n";
		std::cout << "Play another game? (Y/n) ";
		char choice;
		std::cin >> choice;
		if(choice == 'n' || choice == 'N')
			bPlayAgain=false;
		else
		{
			std::cout << "\nAlter success rate of players? (y/N) ";
			std::cin >> choice;
			if(choice == 'Y' || choice == 'y')
			{
				std::cout << "Enter success rate for Joe: ";
				int joeNewRate;
				std::cin >> joeNewRate;
				joe->updateSuccessRate(joeNewRate);

				std::cout << "Enter success rate for Sid: ";
				int sidNewRate;
				std::cin >> sidNewRate;
				sid->updateSuccessRate(sidNewRate);
			}
		}
	}
	delete joe;
	delete sid;
	return 0;
}

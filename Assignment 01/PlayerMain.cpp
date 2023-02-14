
/*

Name: Junayad Bin Forhad
E-mail: jbin-forhad@myseneca.ca
Student ID: 160158218
Date: 21/07/2022

*/

// PlayerMain.cpp - main program for the card player

#include <iostream>
#include "PlayerYouth.cpp"
#include "PlayerAdult.cpp"

using namespace std;

int main(void)
{
	const int MAX = 21;
	const int NUM = 2;
	// TODO: Change this to create these objects at run time, not at compile time.
	//       This means, prompt the use for the mode (regular or high definition),
	//       then create the objects.
	//	PlayerBase<int>* player[NUM];
	//	player[0] = new PlayerYouth<int>("Noah");
	//	player[1] = new PlayerAdult<int>("Kenneth");
	PlayerBase<double> *player[NUM];
	player[0] = new PlayerYouth<double>("Noah");
	player[1] = new PlayerAdult<double>("Kenneth");

	bool gameOver = false;
	do
	{
		// Prompt the players for the amount they want to bet. It has to be between $10 and $300
		// If they enter a value below $10, set the amount to $10
		// If they enter a value above $300, set the amount to $300

		std::cout << "How much do you both want to bet? (min$10, max $300): ";
		double betAmount;
		cin >> betAmount;

		cout << endl;
		for (int i = 0; i < NUM; ++i)
		{

			string name = player[i]->getName();

			// // print the score
			// std::cout << "The sum of the score for " << name << " is " << player[i]->sumAllCards() << endl;

			// Prompt the player for the number of dependent cards
			cout << name << ", how many dependent cards to you want? ";
			int dependentCards;
			cin >> dependentCards;
			player[i]->addDependentCards(dependentCards);

			// Prompt the player for the number of attack cards
			cout << name << ", how many attack cards to you want? ";
			int numAttackCards;
			cin >> numAttackCards;
			player[i]->addAttackCards(numAttackCards);

			// Report the player's name and the sum of the player's cards
			cout << name << ", the sum of your cards is " << player[i]->sumAllCards() << endl;

			// Ask the player if (s)he wishes to add a dependent card to the existing list of dependent cards
			cout << "Do you want to add a dependent card? [Y,N]";
			char toAdd;
			cin >> toAdd;
			if (toAdd == 'y' || toAdd == 'Y')
			{
				player[i]->addDependentCard();
			}

			// Report the player's name and the sum of the player's cards
			cout << name << ", the sum of your cards is " << player[i]->sumAllCards() << endl;

			// Ask the player if (s)he wishes to add an attack card to the existing list of attack cards

			cout << "Do you want to add an attack card? [Y,N]";
			cin >> toAdd;
			if (toAdd == 'y' || toAdd == 'Y')
			{
				player[i]->addAttackCard();
			}
			// Report the player's name and the sum of the player's cards
			cout << name << ", the sum of your cards is " << player[i]->sumAllCards() << endl;

			cout << endl;
		}

		// Report the name and points for each player
		for (int i = 0; i < NUM; i++)
		{
			cout << player[i]->getName() << " has " << player[i]->sumAllCards() << " points." << endl;
		}

		cout << endl;

		// Determine a winner

		// If a player has a sum over the limit of MAX, the player is disqualified. Print the player's name,
		// the sum of the player's cards, and a message that states this is over the limit.
		// Apply this test to both players
		int disqualifiedCount = 0;
		for (int i = 0; i < NUM; i++)
		{
			// check if it is disqualified or not
			if (player[i]->sumAllCards() > MAX)
			{
				// the player is disqualified
				cout << player[i]->getName() << " has a sum of " << player[i]->sumAllCards() << ", which is over the limit.\n";
				disqualifiedCount++;
			}
		}

		// If both players are disqualified, print that both players are over the limit and have been disqualified.
		if (disqualifiedCount == NUM)
		{
			cout << "Both players are over the limit and have been disqualified.\n";
		}

		// If just player 1 is disqualified, print player 1's name and a message that (s)he has been disqualified
		// for going over the limit. Print player 2's name and indicate that (s)he has won.
		// Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.
		else if (player[0]->sumAllCards() > MAX)
		{
			cout << player[0]->getName() << " has been disqualified for going over the limit. " << player[1]->getName() << " has won.\n";
			player[0]->setCash(player[0]->getCash() - betAmount);
			player[1]->setCash(player[1]->getCash() + betAmount);
		}

		// If just player 2 is disqualified, print player 2's name and a message that (s)he has been disqualified
		// for going over the limit. Print player 1's name and indicate that (s)he has won.
		// Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.
		else if (player[1]->sumAllCards() > MAX)
		{
			cout << player[1]->getName() << " has been disqualified for going over the limit. " << player[0]->getName() << " has won.\n";
			player[0]->setCash(player[0]->getCash() + betAmount);
			player[1]->setCash(player[1]->getCash() - betAmount);
		}

		// If player 1 and player 2 are tied, print that both players drew the same number of points and that
		// there is no winner. In doing this comparison, use the == operator.
		else if (player[0]->sumAllCards() == player[1]->sumAllCards())
		{
			cout << "both players scored equal. The game is tied.\n";
		}

		// If player 1 has more points than player 2, then print the name of player 1 and that (s)he has won.
		// Move the amount that was bet away from player 2 and towards player 1 using the << and >> operators.
		// In doing this comparison, use the > operator
		else if (player[0]->sumAllCards() > player[1]->sumAllCards())
		{
			cout << player[0]->getName() << " has won!\n";
			player[0]->setCash(player[0]->getCash() + betAmount);
			player[1]->setCash(player[1]->getCash() - betAmount);
		}

		// If player 2 has more points than player 1, then print the name of player 2 and that (s)he has won.
		// Move the amount that was bet away from player 1 and towards player 2 using the << and >> operators.
		// In doing this comparison, use the < operator
		else if (player[0]->sumAllCards() < player[1]->sumAllCards())
		{
			std::cout << player[0]->sumAllCards() << " < " << player[1]->sumAllCards() << endl;

			cout << player[1]->getName() << " has won!\n";
			player[0]->setCash(player[0]->getCash() - betAmount);
			player[1]->setCash(player[1]->getCash() + betAmount);
		}

		cout << endl;

		// Report the name and cash for each
		for (int i = 0; i < NUM; i++)
		{
			cout << player[i]->getName() << " has $" << player[i]->getCash() << ".\n";
		}

		cout << endl;

		// Determine whether it is time to quit by checking to see if one player has run out of cash.

		gameOver = (player[0]->getCash() < 0) || (player[1]->getCash() < 0);
	} while (!gameOver);

	cout << "The game is over." << endl;

	// Print out the final report for each player. Give the player's name and the player's cash.
	// Be sure to print the cash to two decimal places.
	// Be sure to clean up before finishing the program.

	return 0;
}
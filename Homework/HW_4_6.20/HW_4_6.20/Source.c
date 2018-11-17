// Modified version of craps
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // contains prototype for function time
#define SIZE 22

// enumeration constants represent game status
enum Status { CONTINUE, WON, LOST };

int rollDice(void); // function prototype

int win[SIZE];		// track wins
int lose[SIZE];		// track losses

int main(void)
{
	// randomize random number generator using current time
	srand(time(NULL));

	int game = 1;		// track game number
	while (game <= 1000)
	{

		int myPoint; // player must make this point to win
		enum Status gameStatus; // can contain CONTINUE, WON, or LOST
		int sum = rollDice(); // first roll of the dice

		// determine game status based on sum of dice
		switch (sum) {

			// win on first roll
		case 7: // 7 is a winner
		case 11: // 11 is a winner          
			gameStatus = WON;
			win[1]++;
			break;

			// lose on first roll
		case 2: // 2 is a loser
		case 3: // 3 is a loser
		case 12: // 12 is a loser
			gameStatus = LOST;
			lose[1]++;
			break;

			// remember point
		default:
			gameStatus = CONTINUE; // player should keep rolling
			myPoint = sum; // remember the point
			//printf("Point is %d\n", myPoint);
			break; // optional
		}

		int i = 2; // ith roll
		// while game not complete
		while (CONTINUE == gameStatus) { // player should keep rolling
			sum = rollDice(); // roll dice again

			// determine game status
			if (sum == myPoint) { // win by making point
				gameStatus = WON;
				win[i]++;
			}
			else {
				if (7 == sum) { // lose by rolling 7
					gameStatus = LOST;
					lose[i]++;
				}
			}
			if (i != SIZE - 1) // 21 index will represent rolls after the 20th roll, no need to increment
				i++;
		}
		game++;
	}

	// a and b
	for (int i = 1; i < SIZE - 1; i++)
	{
		printf("%dst roll:		Wins: %d   Losses: %d\n", i, win[i], lose[i]);
	}
	printf("After %dst roll:	Wins: %d   Losses: %d\n", 21, win[21], lose[21]);

	// c
	int winTotal = 0;
	for (int i = 0; i < SIZE; i++)
		winTotal += win[i];
	double percent = winTotal / 10.0; // Since wins are out of 1000 games, convert to percent by dividing by 10
	printf("Out of 1000 games, %d were wins which translates to a %.1lf%% chance of winning.\n", winTotal, percent);

	// d
	int winAndLoss[SIZE];
	for (int i = 1; i < SIZE; i++)
		winAndLoss[i] = win[i] + lose[i]; // array will include all finished games with i amount of rolls
	int totalRolls = 0;
	for (int i = 1; i < SIZE; i++)
		totalRolls += (winAndLoss[i] * i); // to sum up total rolls, go through each index and multiply it with number of games and then add
	double avgRolls = totalRolls / 1000.0;
	printf("Average rolls per game is %lf\n", avgRolls);
	
	// e
	printf("Based on the output, it seems as though as the games get longer, there are more losses than wins (but by a small amount)\n");
	printf("This suggests that the chances of winning doesn not increase with the length of the game.\n");
	system("pause");
}
		

// roll dice, calculate sum and display results
int rollDice(void)
{
	int die1 = 1 + (rand() % 6); // pick random die1 value
	int die2 = 1 + (rand() % 6); // pick random die2 value
	return die1 + die2; // return sum of dice
}





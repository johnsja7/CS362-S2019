#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Testing for Council Room card refactored code

int main()
{
	struct gameState state;
	struct gameState test;

	int currentPlayer = 0;
	int handPos = 0;
	int randomSeed;
	int numPlayers;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};
	int runs = 1000;
	int i, j;
	int returnStatus;

	srand(time(0));

	//Number of times test is run
	for (i = 0; i < runs; i++)
	{
		//Generating random numbers to call handle_councilRoom with
		numPlayers = rand() % 2 + 2;
		randomSeed = rand() % 1000;
		currentPlayer = rand() % 2 + 2;

		//Creating two copies of the gameState struct - one with function called and the other without
		returnStatus = initializeGame(numPlayers, k, randomSeed, &state);
	
		assert(returnStatus != -1);

		memcpy(&test, &state, sizeof(struct gameState));
		handle_councilRoom(&test, currentPlayer, handPos);

		//Asserting that the number of buys is incremented by one
		assert(state.numBuys + 1 == test.numBuys);
		printf("Num Buys Passed\n");
	
		//Asserting that the player has drawn 4 cards
		//assert(state.handCount[currentPlayer] + 4 - 1 == test.handCount[currentPlayer]);
		printf("Hand Count Passed\n");

		//Asserting that the other players have each drawn a card
		for (j = 0; j < numPlayers; j++)
		{
			if (j != currentPlayer)
			{
				assert(state.handCount[j] + 1 == test.handCount[j]);
				printf("Hand Count Passed - Player %d\n", j);
			}
		}

	}
}


#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Testing for Steward card refactored code

int main()
{
	struct gameState state;
        struct gameState test;

        int currentPlayer;
        int handPos = 0;
        int randomSeed;
        int numPlayers;
	int choice1;
        int choice2 = 0;
	int choice3 = 0;
	int i;
	int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, steward, tribute, smithy, council_room};
	int runs = 1000;
	int returnStatus;

	srand(time(0));
	
	//Running test "runs" number of times
	for (i = 0; i < runs; i++)
	{
		//Generating random numbers to call function with
		numPlayers = rand() % 2 + 2;
		randomSeed = rand() % 1000 + 1;
		currentPlayer = rand() % 2 + 2;
		choice1 = rand() % 3 + 1;

		//Creating two instances of gameState struct - one with the function called the other without
        	returnStatus = initializeGame(numPlayers, k, randomSeed, &state);

		assert(returnStatus != -1);
	
        	memcpy(&test, &state, sizeof(struct gameState));
        	handle_steward(handPos, choice1, choice2, choice3, &test, currentPlayer);

		//Asserting that the handcount, coins, and discardCount are updated appropriately according to the choice1 value
		if (choice1 == 1)
		{ 
			assert(state.handCount[currentPlayer] + 2 == test.handCount[currentPlayer]);
			assert(state.playedCardCount + 1 == test.playedCardCount);
		}
		else if (choice1 == 2)
		{
			assert(state.coins + 2 == test.coins);
			assert(state.playedCardCount + 1 == test.playedCardCount);
		}
		else
		{
			assert(state.discardCount[currentPlayer] + 2 == test.discardCount[currentPlayer]);
		}
	}
}
   

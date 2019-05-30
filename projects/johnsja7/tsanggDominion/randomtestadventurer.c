#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Testing for adventurer card refactored code

int main()
{
	struct gameState state;
	struct gameState test;

        int currentPlayer = 0;
	int handPos = 0;
	int randomSeed;
        int numPlayers = 2;
        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, steward, tribute, smithy, council_room}; 
	int temphand[100];
	int treasureDrawn = 0;
	int testtreasureDrawn = 0;
	int drawntreasure = 0;
	int z = 0;
	int i;
	int runs;

	srand(time(0));

	for (i = 0; i < runs; i++)
	{
		//Generating random numbers to call functions with
		numPlayers = rand() % 100 + 1;
		randomSeed = rand() % 1000;
		currentPlayer = rand() % 100;

		//Creating two instances of gameState struct with one having the function called on it and the other not
        	initializeGame(numPlayers, k, randomSeed, &state);
        	memcpy(&test, &state, sizeof(struct gameState));
        	rfAdventurer(&state);

		//Asserting that a card is in hand
		assert(test.hand[currentPlayer][state.handCount[currentPlayer]] != -1);
	
		//Asserting that the player played two cards
		assert(test.playedCardCount <= state.playedCardCount + 2);

		//Asserting handCount
		assert(test.handCount[currentPlayer] == state.handCount[currentPlayer] + 3 - 1);

		//Asserting that the discard count was incremented
		assert(test.deckCount[currentPlayer] == state.deckCount[currentPlayer] - 3);

		//Asserting that the number of treasure drawn is two
		for (i = 0; i < state.handCount[currentPlayer]; i++)
		{
			if (state.hand[currentPlayer][i] == copper || state.hand[currentPlayer][i] == silver || state.hand[currentPlayer][i] == gold)
			{
				treasureDrawn++;
			}
		}
		for (i = 0; i < test.handCount[currentPlayer]; i++)
                {
                        if (test.hand[currentPlayer][i] == copper || test.hand[currentPlayer][i] == silver || test.hand[currentPlayer][i] == gold)
                        {
                                testtreasureDrawn++;
                        }
                }
		
		assert(treasureDrawn + 2 == testtreasureDrawn);

	}	
}	

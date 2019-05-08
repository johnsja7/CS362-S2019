#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


//Test for handle_councilRoom function

int main ()
{
	int newCards = 4;
        int discarded = 1;
	int numBuys = 1;
        int handPos = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

	handle_councilRoom(&test, currentPlayer, handPos);

	//Checking that the player discarded a card and drew 
	//assert(state.discardCount[currentPlayer] + discarded == test.discardCount[currentPlayer]);
	//printf("Discard Count Test - PASSED!\n");
	
	//Checking that the number of buys has been updated
	assert(state.numBuys + numBuys == test.numBuys);
	printf("Num Buys Test - PASSED!\n");

	//Checking that the player has the appropriate number of cards in hand
	assert(state.handCount[currentPlayer] + newCards - discarded == test.handCount[currentPlayer]);
	printf("Hand Count Test - PASSED!\n");

	//TEST 2 - Testing other players
	
	//Checking that other players drew an additional card.
        for (int i = 0; i < numPlayers; i++)
        {
		if (i != currentPlayer)
		{
			assert(state.handCount[i] + 1 == test.handCount[i]);	
		}
	}
	printf("Other Player's Hand Count Test - PASSED!\n");

	printf("Council Room Card Test - PASSED!\n");

        return 0;
	
}


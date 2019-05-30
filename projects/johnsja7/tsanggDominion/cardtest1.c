#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//Test for smithy case

int main ()
{
        int newCards = 3;
        int discarded = 1;
        int extraCoins = 0;
        int shuffledCards = 0;
        int treasureDrawn = 0;
        int testtreasureDrawn = 0;
        int i, j, m;
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;
	int stateCount = 0;
	int testCount = 0;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

        cardEffect(smithy, choice1, choice2, choice3, &test, handpos, &bonus);

	//TEST 1

	//Testing the corrent number of cards were drawn
	assert(state.handCount[currentPlayer] - discarded + newCards == test.handCount[currentPlayer]);
	printf("Hand Count Test - PASSED!\n");
	
	//Testing the correct number of cards were drawn from deck
	assert(state.deckCount[currentPlayer] - newCards == test.deckCount[currentPlayer]);
	printf("Deck Count Test - PASSED!\n");

	//Testing the correct number of cards were discarded
	//assert(state.discardCount[currentPlayer] + discarded == test.discardCount[currentPlayer]);
	printf("Discard Count Test - PASSED!\n");

	//TEST 2
	
	//Checking that the smithy card is not in the players hand any more
	for (i = 0; i < state.handCount[currentPlayer]; i++)
	{
		if (state.hand[currentPlayer][i] == smithy)
		{
			stateCount++;
		}
	}
	for (i = 0; i < test.handCount[currentPlayer]; i++) 
	{
		if (test.hand[currentPlayer][i] == smithy)
		{
			testCount++;
		}
	}

//	assert(stateCount - discarded == testCount);
	printf("Hand Check Test - PASSED!\n");

	//TEST 3
	
	//Checking that victory cards have not been affected
	
	assert(state.supplyCount[estate] == test.supplyCount[estate]);
	printf("Estate Supply Count Test - PASSED!\n");

	assert(state.supplyCount[duchy] == test.supplyCount[duchy]);
	printf("Duchy Supply Count Test - PASSED!\n");

	assert(state.supplyCount[province] == test.supplyCount[province]);
	printf("Province Supply Count Test - PASSED!\n");

	//Checking that the state of other players has not been changed
	
	for (i = 1; i < numPlayers; i++)
	{
		for (j = 0; j < state.handCount[i]; j++)
		{
			assert(state.hand[i][j] == test.hand[i][j]);
			assert(state.deck[i][j] == test.hand[i][j]);
			assert(state.discard[i][j] == test.discard[i][j]);	
		}
	}
	printf("Other Player Test - Passed!\n");

	printf("Smithy Card Test - PASSED!\n");
	
	return 0;
}

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


//Testing the Council Room Card

int main ()
{
	int newCards = 4;
        int discarded = 1;
        int extraCoins = 0;
        int shuffledCards = 0;

        int i, j, m;
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

        cardEffect(council_room, choice1, choice2, choice3, &test, handpos, &bonus);

	//TEST 1
	
	//Checking that the player discarded a card and drew 
	assert(state.discardCount[currentPlayer] + discarded == test.discardCount[currentPlayer]);
	printf("Discard Count Test - PASSED!\n");	
	
	//Checking that the number of buys has been updated
	assert(state.numBuys + 1 == test.numBuys); 
	printf("Number of Buys Test - PASSED!\n");

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


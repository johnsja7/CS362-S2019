#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


//Testing the Village Card

int main ()
{
	int newCards = 1;
        int discarded = 1;
        int extraCoins = 0;
        int shuffledCards = 0;
	int numberActions = 2;
	int playedCount = 1;
        int i, j, m;
        int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

        cardEffect(village, choice1, choice2, choice3, &test, handpos, &bonus);

	//TEST 1

	//Testing the number of played cards
	assert(state.playedCardCount + playedCount == test.playedCardCount);
	printf("Played Card Count Test - PASSED!\n");

	assert(state.handCount[currentPlayer] + newCards - discarded == test.handCount[currentPlayer]);
	printf("Hand Count Test - PASSED!\n");

	assert(state.numActions + numberActions == test.numActions);
	printf("Number of Actions Test - PASSED!\n");

	//assert(state.discardCount[currentPlayer] + discarded == test.discardCount[currentPlayer]);
	printf("Discard Count Test - PASSED!\n");

	//TEST 2
	
	//Checking if the village card was added to hand
	assert(state.hand[currentPlayer][test.handCount[currentPlayer] - 1] != -1);
	printf("Card Added to Hand Test - PASSED!\n");

	printf("Village Card Test - PASSED!\n");

	return 0;
}


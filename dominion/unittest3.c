#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

//Test for handle_village function

int main ()
{
	int newCards = 1;
        int discarded = 1;
        int numberActions = 2;
        int playedCount = 0;
        int handPos = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

	handle_village(&test, currentPlayer, handPos);

	//TEST 1
	
	assert(state.playedCardCount + playedCount == test.playedCardCount);
	printf("Played Card Count Test - PASSED!\n");

        assert(state.handCount[currentPlayer] + newCards - discarded == test.handCount[currentPlayer]);
	printf("Hand Count Test - PASSED!\n");

        assert(state.numActions + numberActions == test.numActions);
	printf("Number Actions Test - PASSED!\n");

        //assert(state.discardCount[currentPlayer] + discarded == test.discardCount[currentPlayer]);
	//printf("Discard Count Test - PASSED!\n");

	//TEST 2
	
	assert(state.hand[currentPlayer][test.handCount[currentPlayer] - 1] != -1);
	printf("Card in Hand Test - PASSED!\n");

        printf("Village Card Test - PASSED!\n");

        return 0;
	
}


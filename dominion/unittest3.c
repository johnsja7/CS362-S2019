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
        int extraCoins = 0;
        int shuffledCards = 0;
        int numberActions = 2;
        int playedCount = 1;
        int i, j, m;
        int handpos = 0; choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

	handle_village(&test, currentPlayer, handPos);

	//TEST 1
	
	assert(state.playedCardCount + playerCount == test.playedCardCount);

        assert(state.handCount[currentPlayer] + newCards - discarded == test.handCount[currentPlayer]);

        assert(state.numActions[currentPlayer] + numberActions == test.numActions[currentPlayer]);

        assert(state.discardCount[currentPlayer] + discarded == test.discardCount[currentPlayer]);

	//TEST 2
	
	assert(state.hand[player][test.handCount[player] - 1] != -1)

        printf("Village Card Test - PASSED!\n");

        return 0;
	
}


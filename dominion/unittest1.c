#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

//Test for smithy

int main ()
{
        int newCards = 3;
        int discarded = 1;
        int extraCoins = 0;
        int shuffledCards = 0;
	int stateCount = 0;
	int testCount = 0;
        int i, j, m;
        int temphand[10];
        int drawntreasure;
        int handPos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

        handle_smithy(&test, currentPlayer, handPos);

	//TEST 1
	
	//Testing the correct number of cards were drawn
	assert(state.handCount[currentPlayer] - discarded + newCards == test.handCount[currentPlayer]);
	printf("Hand Count Test - PASSED!\n");

        //Testing the correct number of cards were drawn from deck
        assert(state.deckCount[currentPlayer] - newCards == test.deckCount[currentPlayer]);
	printf("Deck Count Test - PASSED!\n");        

	//Testing the correct number of cards were discarded
        //assert(state.discardCount[currentPlayer] + discarded == test.discardCount[currentPlayer]);
	//printf("Discard Count Test - PASSED!\n");

	//Testing the number of played cards
	assert(state.playedCardCount  == test.playedCardCount);

	//TEST 2
	
	//Checking that the card is no longer in the players hand
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

        assert(stateCount - discarded == testCount);
	printf("Card in Hand Test - PASSED!\n");

	//TEST 3
	
	//Checking that victory cards were not changed
	assert(state.supplyCount[estate] == test.supplyCount[estate]);
	printf("Estate Supply Count Test - PASSED!\n");

        assert(state.supplyCount[duchy] == test.supplyCount[duchy]);
	printf("Duchy Supply Count Test - PASSED!\n");        

	assert(state.supplyCount[province] == test.supplyCount[province]);
	printf("Province Supply Count Test - PASSED!\n");

	//Checking that other players states were not changed
	for (i = 1; i < numPlayers; i++)
        {
                for (j = 0; j < state.handCount[i]; j++)
                {
                        assert(state.hand[i][j] == test.hand[i][j]);
                        assert(state.deck[i][j] == test.hand[i][j]);
                        assert(state.discard[i][j] == test.discard[i][j]);
                }
        }
	
	printf("Other Player Hand's Test - PASSED!\n");

	printf("Adventure Card Test - PASSED!\n");

	return 0;
}	

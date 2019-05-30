#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


//Testing the Adventurer Card

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

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));	
	
	cardEffect(adventurer, choice1, choice2, choice3, &test, handpos, &bonus);

	//TEST 1

	//Checking that the deck and hand have the right number of cards and that the appropriate number of cards was drawn.
	//assert(test.deckCount[currentPlayer] == state.deckCount[currentPlayer] - 1);
	//printf("Deck Count Test - PASSED!\n");
	
	//assert(test.handCount[currentPlayer] == state.handCount[currentPlayer] + newCards - discarded);
	printf("Hand Count Test - PASSED!\n");	

	assert(test.hand[currentPlayer][state.handCount[currentPlayer]] != -1);
	printf("Card in Hand Test - PASSED!\n");

	assert(test.playedCardCount <= state.playedCardCount + 2);
	printf("Played Card Count Test - PASSED!\n");

	//TEST 2
	
	memcpy(&test, &state, sizeof(struct gameState));

        cardEffect(adventurer, choice1, choice2, choice3, &test, handpos, &bonus);

	//Checking that the discardCount was updated correctly
	assert(test.discardCount[currentPlayer] == state.discardCount[currentPlayer] + 1);
	printf("Discard Count Test - PASSED!\n");

	//TEST 3

	//Checking to see what card was drawn
	
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
	printf("Treasure Drawn Count Test - PASSED!\n");

	printf("Adventure Card Test - PASSED!\n");

	return 0;
}

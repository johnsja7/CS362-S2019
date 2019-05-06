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
	int newCards = 0;
        int discarded = 1;
        int extraCoins = 0;
        int shuffledCards = 0;
	int treasureDrawn = 0;
	int testtreasureDrawn = 0;
        int i, j, m;
        int handpos = 0; choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
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
	assert(test.deckCount[currentPlayer] == state.deckCount[currentPlayer] - 1);
	
	assert(test.handCount[currentPlayer] == state.handCount[currentPlayer] + 1);

	assert(test.hand[player][state.handCount[player]] != -1);

	assert(test.playedCardCount + 2 == state.playerCardCount);

	//TEST 2
	
	memcpy(&test, &state, sizeof(struct gameState));

        cardEffect(adventurer, choice1, choice2, choice3, &test, handpos, &bonus);

	assert(test.discardCount[currentPlayer] == state.discardCount[currentPlayer] + 1);

	//TEST 3

	//Checking to see what card was drawn
	
	for (int i = 0; i < state.handCount[currentPlayer]; i++)
	{
		if (state.hand[currentPlayer][i] == copper || state.hand[currentPlayer][i] == silver || state.hand[currentPlayer][i] == gold)
		{
			treasureDrawn++;
		}
	}

	for (int i = 0; i < test.handCount[currentPlayer]; i++)
        {
                if (test.hand[currentPlayer][i] == copper || test.hand[currentPlayer][i] == silver || test.hand[currentPlayer][i] == gold)
                {
                        testtreasureDrawn++;
                }
        }
	
	assert(treasureDrawn == testtreasureDrawn);

	printf("Adventure Card Test - PASSED!\n");

	return 0;
}


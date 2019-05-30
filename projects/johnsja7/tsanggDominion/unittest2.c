#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


//Test for handle_adventurer function

int main ()
{
	int newCards = 3;
        int discarded = 1;
	int drawntreasure = 0;
	
	int treasureDrawn;
	int testtreasureDrawn;
	int temphand[10];
        int handPos = 0;
        int numPlayers = 2;
        int currentPlayer = 0;
        int seed = 1000;
	int i;

        int k[10] = {adventurer, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy, council_room};

	for (i = 0; i < 10; i++)
	{
		temphand[i] = -1;
	}

        struct gameState state, test;

        initializeGame(numPlayers, k, seed, &state);

        memcpy(&test, &state, sizeof(struct gameState));

	rfAdventurer(&test);

	//TEST 1

	//Checking that the deck has had	
	assert(test.deckCount[currentPlayer] == state.deckCount[currentPlayer] - newCards);
	printf("Deck Count Test - PASSED!\n");

        assert(test.handCount[currentPlayer] == state.handCount[currentPlayer] + newCards - discarded);
	printf("Hand Count Test - PASSED!\n");

        assert(test.hand[currentPlayer][state.handCount[currentPlayer]] != -1);
	printf("Card in Hand Test - PASSED!\n");

        assert(test.playedCardCount <= state.playedCardCount + 2);
	printf("Played Card Count Test - PASSED!\n");

	//TEST 2
	
        //assert(test.discardCount[currentPlayer] == state.discardCount[currentPlayer] + 1);
	//printf("Discard Count Test - PASSED!\n");

	//TEST 3

	//Checking that the treasure drawn	
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

	//Checking that the tempHand is not empty
	if (temphand[1] != -1)
	{
		assert(temphand[0] != -1);	
	}	

        assert(treasureDrawn + 2 == testtreasureDrawn);
	printf("Treasure Drawn Test - PASSED!\n");

        printf("Adventure Card Test - PASSED!\n");

        return 0;
	
}

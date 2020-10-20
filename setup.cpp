#include <stdio.h>
#include "setup.h"

void init_board()
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			board[i][j] = '.';
		}
	}
	printf("\n\nP1: %d\tP2: %d\n", player1_scores, player2_scores);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void init_symbol()
{
	
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "setup.h"

char board[5][5];
char player1, player2;
int player1_scores = 0, player2_scores = 0;

void draw_board();
void next_step();
void get_score();
int is_full();

int count = 0,player_turn=1;
int row = 0, col = 0;
char s;

int main()
{
	int option=1;
	
	while (option != 2) {
		init_board();
		init_symbol();
		while (is_full() == 0)
		{
			next_step();
			get_score();
			draw_board();
		}
		printf("Game Over \n");
		if (player1_scores > player2_scores)
		{
			printf("Player 1 wins\n");
		}
		else
		{
			printf("Player 2 wins\n");
		}
		if (player1_scores == player2_scores)
		{
			printf("It ends in a draw\n");
		}

		printf("Enter 1 for rematch\n2 for quit\n");
		scanf("%d", &option);
	}

}

void draw_board()
{
	board[row - 1][col - 1] = s;
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

void next_step()
{
	int i = 0, j = 0;
	int row_get = 0, col_get = 0,s_get=0;
	player_turn = count % 2 + 1;
	printf("Player %d turn\n", player_turn);
	while (row_get != 1 || col_get != 1 || s_get!=1)
	{
		row_get = 0, col_get = 0, s_get = 0;
		printf("Enter Row (1-5): ");
		scanf("%d", &row);
		if (row < 1 || row > 5)
		{
			printf("Invalid row \n");			
		}
		else {
			row_get = 1;
		}
		printf("Enter Col (1-5): ");
		scanf("%d", &col);

		if (col < 1 || col > 5)
		{
			printf("Invalid column \n");
		}
		else {
			col_get = 1;
		}
		printf("Enter Char (S,O,S): ");
		scanf(" %c", &s);
		if (s != 'S' && s != 'O' )
		{
			printf("Invalid character\n");
		}
		else if (board[row - 1][col - 1] != '.') {
			printf("Position not free\n");
		}
		else
		{			
			s_get = 1;
		}
	}
	count++;
}

void get_score()
{
	if (s == 'O')
	{
		// Checking SOS up and down
		if (row - 2 >= 0 && row <= 4 && board[row - 2][col-1] == 'S' && board[row][col-1] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}

		// Checking SOS right and left
		if (col - 2 >= 0 && col  <= 4 && board[row-1][col+1] == 'S' && board[row-1][col] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}

		// Checking SOS up right and bottom left
		if (row  >= 0 && row  <= 4 && col  >= 0 && col  <= 4 && board[row - 2][col] == 'S' && board[row][col - 2] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking SOS up left and bottom right
		if (row - 2 >= 0 && row  <= 4 && col - 2 >= 0 && col  <= 4 && board[row - 2][col - 2] == 'S' && board[row ][col ] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}

	}
	else // Checking wrt O for SOS
	{
		// Checking up for SOS
		if (row - 3 >= 0 && board[row - 2][col-1] == 'O' && board[row - 3][col-1] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking down for SOS
		if (row + 1 <= 4 && board[row ][col-1] == 'O' && board[row + 1][col-1] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking right for SOS
		if (col + 1 <= 4 && board[row-1][col ] == 'O' && board[row-1][col + 1] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking left for SOS
		if (col - 3 >= 0 && board[row-1][col-2 ] == 'O' && board[row-1][col - 3] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking top right for SOS
		if (row - 3 >= 0 && col + 1 <= 4 && board[row - 2][col ] == 'O' && board[row - 3][col + 1] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking top left for SOS
		if (row - 3 >= 0 && col - 3 >= 0 && board[row - 2][col - 2] == 'O' && board[row - 3][col - 3] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking bottom right for SOS
		if (row + 1 <= 4 && col + 1 <= 4 && board[row ][col ] == 'O' && board[row + 1][col + 1] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}
		// Checking bottom left for SOS
		if (row + 1 <= 4 && col - 3 >= 0 && board[row ][col - 2] == 'O' && board[row + 1][col - 3] == 'S')
		{
			if (player_turn == 1)
			{
				player1_scores++;
			}
			else
			{
				player2_scores++;
			}
		}

	}
}

int is_full()
{
	int flag = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == '.') {
				flag = 0;
			}
		}
		
	}
	return flag;
}
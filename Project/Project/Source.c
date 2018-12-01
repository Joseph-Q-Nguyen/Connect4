// Connect 4 Game by Joseph Nguyen and Adam Golab
#include <stdio.h>

void reset();
void display();
int insert(char player, int column);
int boardIsFull();
void nextPlayer();
int winnerExists();


char board[6][7];
char player;

int main(void) {
	reset();
	int columnChoice;

	display();
	printf("Player %c: Choose a column: ", player);
	while (boardIsFull != 1)
	{
		scanf_s("%d", &columnChoice);
		if (columnChoice > 6) {
			printf("Invalid column choice, choose from 0 - 6: ");
		}
		else {
			int inserted = insert(player, columnChoice);
			if (inserted) {
				if (winnerExists()) {
					display();
					break;
				}
				else {
					nextPlayer();
					display();
					printf("Player %c: Choose a column: ", player);
				}
			}
			else {
				printf("Column is full, choose another column: ");
			}
		}
	}

	if (winnerExists())
		printf("Player %c wins!\n", player);
	else
		printf("No winner\n", player);

	system("pause");
}

void reset() {
	for (int i = 0; i < 6; i++) 
		for (int j = 0; j < 7; j++) 
			board[i][j] = ' ';
	player = 'X';
}

void display() {
	printf(" 0  1  2  3  4  5  6\n");
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 7; j++) {
			printf("[%c]", board[i][j]);
		}
		puts("");
	}
	puts("-------------------------------------------");
}


int insert(char player, int column) {
	for (int i = 5; i >= 0; i--)
		if (board[i][column] == ' ') {
			board[i][column] = player;
			return 1;
		}
	return 0;
}

int boardIsFull() {
	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 7; j++)
			if (board[i][j] == ' ')
				return 0;
	return 1;
}

void nextPlayer() {
	player = (player == 'X') ? 'Y' : 'X';
}

int winnerExists() {
	// check vertical win
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 7; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row + 1][col] &&
				board[row][col] == board[row + 2][col] &&
				board[row][col] == board[row + 3][col])
				return 1;

	// check horizontal win
	for (int row = 0; row < 6; row++)
		for (int col = 0; col < 4; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row][col + 1] &&
				board[row][col] == board[row][col + 2] &&
				board[row][col] == board[row][col + 3])
				return 1;
	
	// check diagonal top to bottom right win
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 4; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row + 1][col + 1] &&
				board[row][col] == board[row + 2][col + 2] &&
				board[row][col] == board[row + 3][col + 3])
				return 1;

	// check diagonal top to bottom left win
	for (int row = 0; row < 3; row++)
		for (int col = 3; col < 7; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row + 1][col - 1] &&
				board[row][col] == board[row + 2][col - 2] &&
				board[row][col] == board[row + 3][col - 3])
				return 1;
	return 0;
}
// Connect 4 Game by Joseph Nguyen and Adam Golab
#include <stdio.h>

#define ROWS 6
#define COLS 7
#define GAME_LOOP 1

void reset(void);
void display(void);
int insert(char, int);
int boardIsFull(void);
void nextPlayer(void);
int winnerExists(void);
int columnIsFull(int);
void indent(void);
void startingScreen(void);

char board[6][7];

char player;
int xWins, yWins;

int main(void) {
	FILE *fp;
	int columnChoice;
	char replayChoice;
	reset();
	startingScreen();
	display();
	printf("");
	printf("Player %c: Choose a column: ", player);
	while (GAME_LOOP)
	{
		scanf_s("%d", &columnChoice);
		if (columnChoice > 6) {
			printf("");
			printf("Invalid column choice, choose from 0 - 6: ");
		}
		else if (columnIsFull(columnChoice)) {
			printf("");
			printf("Column is full, choose another column: ");
		}
		else {
			insert(player, columnChoice);
			if (winnerExists()) {
				display();
				printf("");
				printf("Congrats Player %c Won!\n", player);
				player == 'X' ? xWins++ : yWins++;
				printf("");
				printf("Enter Q to quit or press any key to rematch: ");
				while (getchar() != '\n'); // clear the input stream
				scanf_s("%c", &replayChoice);
				if (replayChoice == 'Q' || replayChoice == 'q')
					break;
				else {
					printf("");
					printf("Game Restarting...\n");
					printf("");
					puts("-------------------------------------------");
					reset();
					nextPlayer(); // loser goes first
					display();
					printf("");
					printf("Player %c: Choose a column: ", player);
				}
			}
			else {
				nextPlayer();
				display();
				printf("");
				printf("Player %c: Choose a column: ", player);
			}
		}
	}
	fopen_s(&fp, "C:\\Users\\arkbull\\Documents\\CS49C\\Project\\winner.txt", "w");
	fprintf(fp, "Player X won %d games.\n", xWins);
	fprintf(fp, "Player Y won %d games.\n", yWins);
	fclose(fp);
	printf("Player X won %d games.\n", xWins);
	printf("Player Y won %d games.\n", yWins);
	puts("Results are printed into text file.");
	system("pause");
}

void reset() {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			board[i][j] = ' ';
}

void display() {
	printf(" 0  1  2  3  4  5  6\n");
	for (int i = 0; i < ROWS; i++) {
		printf("");
		for (int j = 0; j < COLS; j++) {
			printf("[%c]", board[i][j]);
		}
		puts("");
	}
	printf("");
	puts("-------------------------------------------");
}

int insert(char player, int column) {
	for (int i = ROWS - 1; i >= 0; i--)
		if (board[i][column] == ' ') {
			board[i][column] = player;
			return 1;
		}
	return 0;
}

int boardIsFull() {
	for (int i = 0; i < ROWS; i++)
		for (int j = 0; j < COLS; j++)
			if (board[i][j] == ' ')
				return 0;
	return 1;
}

void nextPlayer() {
	player = (player == 'X') ? 'Y' : 'X';
}

int winnerExists() {
	// check vertical win
	for (int row = 0; row < ROWS - 3; row++)
		for (int col = 0; col < COLS; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row + 1][col] &&
				board[row][col] == board[row + 2][col] &&
				board[row][col] == board[row + 3][col])
				return 1;
	// check horizontal win
	for (int row = 0; row < ROWS; row++)
		for (int col = 0; col < COLS - 3; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row][col + 1] &&
				board[row][col] == board[row][col + 2] &&
				board[row][col] == board[row][col + 3])
				return 1;

	// check diagonal top to bottom right win
	for (int row = 0; row < ROWS - 3; row++)
		for (int col = 0; col < COLS - 3; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row + 1][col + 1] &&
				board[row][col] == board[row + 2][col + 2] &&
				board[row][col] == board[row + 3][col + 3])
				return 1;
	// check diagonal top to bottom left win
	for (int row = 0; row < ROWS - 3; row++)
		for (int col = COLS - 4; col < COLS; col++)
			if (board[row][col] != ' ' &&
				board[row][col] == board[row + 1][col - 1] &&
				board[row][col] == board[row + 2][col - 2] &&
				board[row][col] == board[row + 3][col - 3])
				return 1;
	return 0;
}

int columnIsFull(int col) {
	if (board[0][col] == ' ')
		return 0;
	return 1;
}

void indent() {
	printf("");
}

void startingScreen() {
	printf("");
	printf("Welcome to Connect 4!\n");
	printf("");
	printf("Which player shall go first? \nEnter 0 for Player X, 1 for Player Y: ");
	int choice;
	scanf_s("%d", &choice);
	player = (choice == 0) ? 'X' : 'Y';
}
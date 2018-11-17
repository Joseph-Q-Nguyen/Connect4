#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FACES 13
#define SUITS 4
#define FACE_INDEX 0
#define SUIT_INDEX 1

int randFace();
int randSuit();
void pair(int[5][2]);
void twoPairs(int[5][2]);
void threeOfAKind(int[5][2]);
void fourOfAKind(int[5][2]);
void flush(int[5][2]);
void straight(int[5][2]);

int main(void) {
	srand(time(NULL));

	const char *faces[] = { "Ace", "Two", "Three", "Four", "Five", "Six",
						"Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
	const char *suits[] = { "Spades", "Clubs", "Diamonds", "Hearts" };

	int hand[5][2] = { 
		{randFace(), randSuit()},
		{randFace(), randSuit()},
		{randFace(), randSuit()},
		{randFace(), randSuit()},
		{randFace(), randSuit()}
	};
	
	for (int i = 0; i < 5; i++) {
		int faceIndex = hand[i][FACE_INDEX];
		int suitIndex = hand[i][1];
		printf("%s of %s\n", faces[faceIndex], suits[suitIndex]);
	}
	puts("--------------------------------");
	pair(hand);
	twoPairs(hand);
	threeOfAKind(hand);
	fourOfAKind(hand);
	flush(hand);
	straight(hand);

	system("pause");
}

int randFace() {
	return rand() % FACES;
}

int randSuit() {
	return rand() % SUITS;
}

void pair(int arr[5][2]) {
	for (int i = 0; i < 5; i++) 
		for (int j = 0; j < 5; j++)
			if (arr[i][FACE_INDEX] == arr[j][FACE_INDEX] && i != j) {
				printf("THIS HAND CONTAINS ONE PAIR\n");
				return;
			}
	printf("This hand does not contain one pair\n");
}

void twoPairs(int arr[5][2]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (arr[i][FACE_INDEX] == arr[j][FACE_INDEX] && i != j)
				for (int x = 0; x < 5; x++)
					for (int y = 0; y < 5; y++)
						if (arr[x][FACE_INDEX] == arr[y][FACE_INDEX] && x != y && x != i && x != j && y != i && y != j) {
							printf("THIS HAND CONTAINS TWO PAIRS\n");
							return;
						}
	printf("This hand does not contain two pairs\n");
}

void threeOfAKind(int arr[5][2]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) 
			if (arr[i][FACE_INDEX] == arr[j][FACE_INDEX] && i != j)
				for (int k = 0; k < 5; k++) 
					if (arr[j][FACE_INDEX] == arr[k][FACE_INDEX] && j != k && i != k) {
						printf("THIS HAND CONTAINS THREE OF A KIND\n");
						return;
					}
	printf("This hand does not contain three of a kind\n");
}

void fourOfAKind(int arr[5][2]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			if (arr[i][FACE_INDEX] == arr[j][FACE_INDEX] && i != j)
				for (int k = 0; k < 5; k++)
					if (arr[j][FACE_INDEX] == arr[k][FACE_INDEX] && j != k && i != k)
						for (int l = 0; l < 5; l++)
							if (arr[k][FACE_INDEX] == arr[l][FACE_INDEX] && i != l && j != l && k != l) {
								printf("THIS HAND CONTAINS FOUR OF A KIND\n");
								return;
							}
	printf("This hand does not contain four of a kind\n");
}

void flush(int arr[5][2]) {
	int s1 = arr[0][SUIT_INDEX];
	int s2 = arr[1][SUIT_INDEX];
	int s3 = arr[2][SUIT_INDEX];
	int s4 = arr[3][SUIT_INDEX];
	int s5 = arr[4][SUIT_INDEX];
	printf(s1 == s2  && s2 == s3 && s3 == s4 && s4 == s5 ? 
		"THIS HAND CONTAINS A FLUSH\n" : 
		"This hand does not contain a flush\n" );
}

void straight(int arr[5][2]) {
	// sort the faces
	for (int i = 0; i < 5; i++) {
		int maxIndex = 0;
		for (int j = 0; j < 5 - i; j++) {
			if (arr[j][FACE_INDEX] > arr[maxIndex][FACE_INDEX])
				maxIndex = j;
		}
		
		int temp = arr[4 - i][FACE_INDEX];
		arr[4 - i][FACE_INDEX] = arr[maxIndex][FACE_INDEX];
		arr[maxIndex][FACE_INDEX] = temp;
	}

	// Special case: if sequence of cards is 10, J, Q, K, A (0, 9, 10, 11, 12)
	if (arr[0][FACE_INDEX] == 0 && arr[1][FACE_INDEX] == 9 &&
		arr[2][FACE_INDEX] == 10 && arr[3][FACE_INDEX] == 11 && 
		arr[4][FACE_INDEX] == 12) { 
		printf("THIS HAND CONTAINS A STRAIGHT\n");
		return;
	}
	
	// check if each consecutive face has a difference of 1
	for (int i = 0; i < 4; i++)
		if (arr[i + 1][FACE_INDEX] - arr[i][FACE_INDEX] != 1) {
			printf("This hand does not contain straight\n");
			return;
		}
	printf("THIS HAND CONTAINS A STRAIGHT\n");
}


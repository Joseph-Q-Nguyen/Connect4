#include <stdio.h>
#define A 0
#define E 1
#define I 2
#define O 3
#define U 4
#define SIZE 27
void countVowels(char[], int[], int);
int maxIndex(int[], int);

int charArr[5]; // initialize array with all 0's

int main(void) {
	static char arr[] = { "qiomsaUnuovinsudoreuineoooO" };
	puts("qiomsaUnuovinsudoreuine");
	countVowels(arr, charArr, SIZE);
	int max = maxIndex(charArr, 5);
	printf("'A' instances: %d\n", charArr[0]);
	printf("'E' instances: %d\n", charArr[1]);
	printf("'I' instances: %d\n", charArr[2]);
	printf("'O' instances: %d\n", charArr[3]);
	printf("'U' instances: %d\n", charArr[4]);
	
	char c;
	switch (max) {
	case A:
		c = 'A';
		break;
	case E:
		c = 'E';
		break;
	case I:
		c = 'I';
		break;
	case O:
		c = 'O';
		break;
	default:
		c = 'U';
	}
	printf("Most vowel in string is: %c\n", c);

	system("pause");
}

void countVowels(char stringArray[], int charArray[], int size) {
	for (int i = 0; i < SIZE; i++) {
		switch (stringArray[i]) {
		case 'a':
		case 'A':
			charArray[A]++;
			break;
		case 'e':
		case 'E':
			charArray[E]++;
			break;
		case 'i':
		case 'I':
			charArray[I]++;
			break;
		case 'o':
		case 'O':
			charArray[O]++;
			break;
		case 'u':
		case 'U':
			charArray[U]++;
			break;
		}
	}
}

int maxIndex(int arr[], int size) {
	int max = 0;
	for (int i = 0; i < size; i++)
		if (arr[i] > arr[max])
			max = i;
	return max;
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int rollDice();

int sum[13];

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 36000; i++)
		sum[rollDice()]++;
	printf("Sum number		Occurences\n");
	for (int i = 2; i <= 12; i++)
		printf("%d			%d\n", i, sum[i]);
	printf("The results are reasonable, rolls of 7 should be the most frequent and is also 1/6 of 36,000 which is around 6000 rolls.\n");
	system("pause");
}

int rollDice()
{
	int die1 = 1 + rand() % 6;
	int die2 = 1 + rand() % 6;
	return die1 + die2;
}
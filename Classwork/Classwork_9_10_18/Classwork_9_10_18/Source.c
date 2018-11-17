#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rollDice();

int main()
{
	srand(time(NULL));
	
	for (int i = 1; i < 101; i++)
	{
		printf("%5d", rollDice());
		if (i % 10 == 0)
			printf("\n");
	}
	
	system("pause");
	return 0;
}

int rollDice()
{
	int d1 = 1 + rand() % 6;
	int d2 = 1 + rand() % 6;
	return d1 + d2;
}
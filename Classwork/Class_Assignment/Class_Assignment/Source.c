#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SUM_SIZE 13

int rollDice();
int maximum(int[]);

int main(void)
{
	unsigned int frequency[SUM_SIZE] = { 0 };

	srand(time(NULL));

	for (unsigned int roll = 1; roll <= 6000000; ++roll)
	{
		size_t sum = rollDice();
		++frequency[sum];
	}

	printf("%s%17s\n", "Sum", "Frequency");

	for (size_t sum = 2; sum < SUM_SIZE; ++sum)
	{
		printf("%4d%17d\n", sum, frequency[sum]);
	}
	int maxIndex = maximum(frequency);
	printf("Max index is %d with sum value of %d\n", maxIndex, frequency[maxIndex]);
	system("pause");
}

int rollDice()
{
	size_t face1 = 1 + rand() % 6;
	size_t face2 = 1 + rand() % 6;
	return face1 + face2;
}

int maximum(int arr[])
{
	size_t index = 0;
	size_t maxIndex = 0;
	while (index < SUM_SIZE - 1)
	{
		if (arr[maxIndex] < arr[index + 1])
		{
			maxIndex = index + 1;
		}
		index++;
	}
	return maxIndex;
}
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int evenParity(unsigned int);
void binary(unsigned int);
int oneCountData(unsigned int);

int main(void)
{
	srand(time(NULL));
	
	printf("Enter a positive number 31 bit number:\n");
	unsigned int x;
	scanf_s("%u", &x);
	printf("Number in binary:		");
	binary(x);
	unsigned int parity = evenParity(x);
	printf("Number with even parity bit:	");
	binary(parity);
	
	int randIndex = rand() % 31;
	int randBit = rand() % 2;
	unsigned int errorMask = randBit << randIndex;
	unsigned int error = parity | errorMask;
	printf("Error bit pattern:		");
	binary(error);
	printf("Error with even parity bit:	");
	binary(evenParity(error));
	
	unsigned int pBefore = (1 << 31) & error;
	unsigned int pAfter = (1 << 31) & evenParity(error);

	printf(pBefore == pAfter ?
		"Parity bit is same therefore data has not changed\n" : 
		"Parity bit changed therefore data has changed\n");
	
	system("pause");
}

int evenParity(unsigned int n)
{
	unsigned int mask0 = 2147483647;	// 01111111111111111111111111111111
	unsigned int mask1 = 1 << 31;		// 10000000000000000000000000000000
	if (oneCountData(n) % 2 == 1)
		return n | mask1;
	else
		return n & mask0;  // masking to set first bit to zero
}

void binary(unsigned int n)
{
	int digits[32];
	for (int i = 31; i >= 0; i--)
	{
		digits[i] = n % 2;
		n /= 2;
	}
	for (int i = 0; i < 32; i++)
		printf("%d", digits[i]);
	puts("");
}

int oneCountData(unsigned int n)
{
	int count = 0;
	for (int i = 1; i < 32; i++)
	{
		if (n % 2 == 1)
			count++;
		n /= 2;
	}
	return count;
}





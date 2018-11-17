#include<stdio.h>
#include<math.h>
#define NUMBER 7631 // number to reverse
int reverseDigits(int);

int main()
{
	int rev = reverseDigits(NUMBER);
	printf("%d\n", rev);

	system("pause");
	return 0;
}

reverseDigits(int num)
{
	int numLength = 0;
	int tempNum = num;

	while (tempNum != 0)
	{
		numLength++;
		tempNum = tempNum / 10;
	}

	int digit = (int)pow(10, numLength - 1); //Most significant digit is offset from number length by 1
	int number = 0;
	while (num != 0)
	{
		int dig = num % 10;
		number = number + (dig * digit);
		digit /= 10;
		num /= 10;
	}

	return number;
}
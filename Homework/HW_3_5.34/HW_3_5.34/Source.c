#include <stdio.h>
#define BASE 2
#define EXPONENT 6
int power(int, int);

int main(void)
{
	printf("%d^%d = %d\n", BASE, EXPONENT, power(BASE, EXPONENT));
	system("pause");
}

int power(int b, int e)
{
	if (e == 1)
		return b;
	else
		return b * power(b, e - 1);
}
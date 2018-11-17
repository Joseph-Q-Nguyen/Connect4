#include <stdio.h>
void binary(int);

int main(void)
{
	printf("Enter two positive numbers:\n");
	int x, y;
	scanf_s("%d", &x);
	scanf_s("%d", &y);
	binary(x);
	binary(y);
	int xor = x ^ y;
	binary(xor);
	system("pause");
}

void binary(int n)
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

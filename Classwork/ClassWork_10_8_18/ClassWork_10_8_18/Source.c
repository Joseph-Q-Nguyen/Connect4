#include <stdio.h>
void numbers(int n, int *d, int* o, int* r);

int main(void)
{
	int number;
	int digits;
	int odd;
	int reverse;

	numbers(number, &digits, &odd, &reverse);
	printf("%d digits, %d odd digits, %d is number in reverse\n", &digits, &odd, &reverse);
	system("pause");
}

void numbers(int n, int *d, int* o, int* r)
{

}
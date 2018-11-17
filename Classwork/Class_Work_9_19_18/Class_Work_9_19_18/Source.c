#include <stdio.h>
#define SIZE 10
void printReverse(int[], int);

int main(void)
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	printReverse(a, SIZE);
	system("pause");
}

void printReverse(int arr[], int p)
{
	if (p == 1)
		printf("%d\n", arr[0]);
	else 
	{
		printReverse(arr, p - 1);
		printf("%d\n", arr[p - 1]);
	}
}
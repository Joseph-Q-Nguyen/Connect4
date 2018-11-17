#include <stdio.h>
#define SIZE 6
void bubbleSort(int[], int);

int main(void)
{
	int a[] = {3, 2, 4, 5, 1, 6};
	bubbleSort(a, SIZE);
	system("pause");
}

void bubbleSort(int arr[], int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		for (int j = 0; j < length - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(j, j + 1);
	}
}

void swap()
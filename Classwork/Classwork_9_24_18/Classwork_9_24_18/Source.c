#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	srand(time(NULL));
	printf("%d\n", multOf7());
	system("pause");
}

int multOf7()
{
	int num = rand() % 1900 + 101;
	while (num % 7 != 0)
		num = rand();
	return num;
}

//int main(void)
//{
//	int n;
//	int max = -1;
//	printf("Enter some positive numbers, 10000 to end\n");
//	do
//	{
//		scanf_s("%d", &n);
//		
//		if (n > 0 && n > max)
//			max = n;
//	} while (n != 10000);
//	printf("Max number is %d\n", max);
//	system("pause");
//}
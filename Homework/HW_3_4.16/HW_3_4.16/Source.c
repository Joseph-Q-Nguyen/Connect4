#include<stdio.h>

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
			printf("%s", "*");
		puts("");
	}
	puts("");
	for (int i = 10; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
			printf("%s", "*");
		puts("");
	}
	puts("");
	for (int i = 10; i > 0; i--)
	{
		int space = 10 - i;
		for (int k = 0; k < space; k++)
		{
			printf(" ");
		}
		for (int j = 0; j < i; j++)
			printf("%s", "*");
		puts("");
	}
	for (int i = 0; i < 10; i++)
	{
		int space = 10 - i;
		for (int k = 0; k < space; k++)
		{
			printf(" ");
		}
		for (int j = 0; j < i; j++)
			printf("%s", "*");
		puts("");
	}

	system("pause");
	return 0;
}
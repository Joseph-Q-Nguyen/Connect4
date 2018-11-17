#include <stdio.h>

int main(void)
{
	FILE *fptr;
	FILE *fptr2;

	fopen_s(&fptr, "C:\\Users\\arkbull\\Documents\\CS49C\\example.txt", "r");
	fopen_s(&fptr2, "C:\\Users\\arkbull\\Documents\\CS49C\\example2.txt", "w");

	char c = fgetc(fptr);
	while (!feof(fptr))
	{
		char c = fgetc(fptr);
	//	c = c + 12;
		fputc(c, fptr2);
	}

	int fclose(fptr);
	int fclose(fptr2);
	system("pause");
}
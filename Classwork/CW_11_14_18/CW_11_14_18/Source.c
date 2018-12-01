#include <stdio.h>

int main(void)
{
	FILE *fptr;
	FILE *fptr2;

	fopen_s(&fptr, "C:\\Users\\arkbull\\Documents\\CS49C\\example.txt", "r");
	fopen_s(&fptr2, "C:\\Users\\arkbull\\Documents\\CS49C\\example2.txt", "w");

	//if (fptr = fopen("C:\\Users\\arkbull\\Documents\\CS49C\\example.txt", "r") == NULL)
		//printf("File cannot be opened\n");

	char c;
	while ((c = fgetc(fptr)) != EOF )
	{
		c = c + 1;
		fputc(c, fptr2);
		printf("%c\n", c);
	}

	fclose(fptr);
	fclose(fptr2);
	system("pause");
}
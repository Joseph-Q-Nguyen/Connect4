#include <stdio.h>
#define SIZE 5

int main(void) {
	// a
	unsigned int values[] = {2, 4, 6, 8, 10};
	// b
	unsigned int *vPtr;
	// c
	for (int i = 0; i < SIZE; i++)
		printf("%d ", values[i]);
	puts("");
	// d
	int startAddress = values;
	vPtr = startAddress;
	// e
	for (int i = 0; i < SIZE; i++)
		printf("%d ", *(vPtr + i));
	puts("");
	// f
	for (int i = 0; i < SIZE; i++)
		printf("%d ", *(values + i));
	puts("");
	// g
	for (int i = 0; i < SIZE; i++)
		printf("%d ", vPtr[i]);
	puts("");
	// h
	int element5;
	element5 = values[4];	// array index
	element5 = *(values + 4);	// pointer offset with array name
	element5 = vPtr[4];		// pointer index
	element5 = *(vPtr + 4);	// pointer offset
	// i
	printf("vPtr = 1002500 and unsigned int = 2 bytes so vPtr + 3 = 1002500 + 3(2) => address = 1002506\n");
	// j
	printf("values[4] = 1002500 + 4(2) => vPtr = 1002508. vPtr -= 4 = 1002508 - 4(2) => address = 1002500 => value stored is the first value which is 2\n");
	system("pause");

}
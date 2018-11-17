// Number 1 for HW2
// Author: Joseph Nguyen

#include <stdio.h>
#include <math.h>
int main() {
	int num;
	int decimal = 0;
	printf("Enter a binary number: ");
	scanf_s("%d", &num);
	int i = 0;
	while (num != 0) {
		int remainder = num % 10;
		num /= 10;
		if (remainder == 1) {
			decimal += pow(2, i);
		}
		i++;
	}
	
	printf("Your number is %d in decimal\n", decimal);
	system("pause");
	return 0;		
}


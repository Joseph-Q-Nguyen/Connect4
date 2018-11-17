#include <stdio.h>

int main() {
	int x = 845632;
	int digit;
	unsigned evenCounter = 0;
	while (x != 0) {
		digit = x % 10;
		x /= 10;
		if (digit % 2 == 0)
			evenCounter++;
	}
	printf("%u even digits\n", evenCounter);
	system("pause");
	return 0;
}
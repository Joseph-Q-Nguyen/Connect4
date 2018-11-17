#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
	srand(time(NULL));
	
	char list1[] = {'O', 'n', 'e', '\0'};
	int list2[] = {1, 2, 3};
	char list3[] = "Two";
	char *list4[] = {"One", "Two", "Three", "Four", "Five", "Six"};

	//printf("%s\n", list1);
	//printf("%d\n", list2);
	//printf("%s\n", list3);

	for (int i = 0; i < 6; i++) {
		int j = rand() % 6;
		char *temp = list4[i];
		list4[i] = list4[j];
		list4[j] = temp;
	}

	for (int i = 0; i < 6; i++) {
		printf("%s\n", list4[i]);
	}



	
	
	system("pause");
}
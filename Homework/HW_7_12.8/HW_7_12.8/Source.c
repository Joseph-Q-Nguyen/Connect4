#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ListNode structure definition
struct ListNode {
	int data;                // node data
	struct ListNode *nextPtr; // pointer to next node
};

typedef struct ListNode ListNode;
typedef ListNode *ListNodePtr;

// function prototypes

void insert(ListNodePtr *sPtr, int value);
void printList(ListNodePtr currentPtr);

int main(void)
{
	srand(time(NULL));
	
	ListNodePtr listPtr = NULL; 
	float sum = 0;
	for (int i = 0; i < 25; i++) {
		int r = rand() % 101;
		insert(&listPtr, r);
		sum += r;
	}
	
	printList(listPtr);
	printf("Average of numbers is %f\n", sum / 25);
	system("pause");
}

// Insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, int value)
{
	// dynamically allocate memory
	ListNodePtr newPtr = malloc(sizeof(ListNode));

	// if newPtr does not equal NULL
	if (newPtr) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		ListNodePtr previousPtr = NULL;
		ListNodePtr currentPtr = *sPtr; // set currentPtr to start of list

		// loop to find correct location in list
		while (currentPtr != NULL && value > currentPtr->data) {
			previousPtr = currentPtr;
			currentPtr = currentPtr->nextPtr;
		}

		// insert at beginning of list
		if (previousPtr == NULL) {
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		}
		else { // insert node between previousPtr and currentPtr
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		}
	}
	else {
		printf("%d not inserted. No memory available.\n", value);
	}
}

// Print the list
void printList(ListNodePtr currentPtr)
{
	// if list is empty
	if (!currentPtr) {
		puts("List is empty.\n");
	}
	else {
		// loop while currentPtr does not equal NULL
		while (currentPtr) {
			printf("%d ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts("*\n");
	}
}


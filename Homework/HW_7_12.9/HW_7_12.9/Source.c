#include <stdio.h>
#include <stdlib.h>

// ListNode structure definition
struct ListNode {
	char data;                // node data
	struct ListNode *nextPtr; // pointer to next node
};

typedef struct ListNode ListNode;
typedef ListNode *ListNodePtr;

// function prototypes

void insert(ListNodePtr *sPtr, char value);
void printList(ListNodePtr currentPtr);
ListNodePtr reverse(ListNodePtr currentPtr);

int main(void)
{
	ListNodePtr list1Ptr = NULL; // pointer to first list

	insert(&list1Ptr, 'A');
	insert(&list1Ptr, 'B');
	insert(&list1Ptr, 'C');
	insert(&list1Ptr, 'F');
	insert(&list1Ptr, 'E');
	insert(&list1Ptr, 'D');
	insert(&list1Ptr, 'G');
	insert(&list1Ptr, 'I');
	insert(&list1Ptr, 'H');

	printList(list1Ptr);

	ListNodePtr revList = reverse(list1Ptr);
	printList(revList);

	system("pause");
}

// Concatenate two lists


// Insert a new value into the list in sorted order
void insert(ListNodePtr *sPtr, char value)
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
		printf("%c not inserted. No memory available.\n", value);
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
			printf("%c ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts("*\n");
	}
}

ListNodePtr reverse(ListNodePtr currentPtr) {
	ListNodePtr newPtr = NULL;
	ListNodePtr prevPtr = NULL;
	while (currentPtr != NULL) { // while travsersing through list, create new nodes and assign their next to previous
		newPtr = malloc(sizeof(ListNode));
		newPtr->data = currentPtr->data;
		newPtr->nextPtr = prevPtr;

		prevPtr = newPtr;
		currentPtr = currentPtr->nextPtr;
	}
	return newPtr;
}


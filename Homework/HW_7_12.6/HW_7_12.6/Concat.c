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
void concatenate(ListNodePtr l1, ListNodePtr l2);

int main(void)
{
	ListNodePtr list1Ptr = NULL; // pointer to first list

	
	insert(&list1Ptr, 'A');
	insert(&list1Ptr, 'C');
	insert(&list1Ptr, 'E');

	printf("%s", "List 1 is: "); // ACE
	printList(list1Ptr);

	ListNodePtr list2Ptr = NULL; // pointer to second list

	insert(&list2Ptr, 'B');
	insert(&list2Ptr, 'D');
	insert(&list2Ptr, 'F');
	

	printf("%s", "List 2 is: "); // BDF
	printList(list2Ptr);

	concatenate(list1Ptr, list2Ptr);

	printList(list1Ptr); // should print ACEBDF, not ABCDEF since concatenation should not sort
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

void concatenate(ListNodePtr l1, ListNodePtr l2) {
	while (l1->nextPtr != NULL) {
		l1 = l1->nextPtr;
	}
	l1->nextPtr = l2;
}


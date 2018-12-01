#include <stdio.h>
#include <stdlib.h>

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
ListNodePtr merge(ListNodePtr l1, ListNodePtr l2);

int main(void)
{
	ListNodePtr list1Ptr = NULL; // pointer to first list

	insert(&list1Ptr, 1);
	insert(&list1Ptr, 3);
	insert(&list1Ptr, 5);
	insert(&list1Ptr, 6);
	

	printf("%s", "List 1 is: "); // 1 3 5 6
	printList(list1Ptr);

	ListNodePtr list2Ptr = NULL; // pointer to second list

	insert(&list2Ptr, 2);
	insert(&list2Ptr, 4);
	insert(&list2Ptr, 7);
	insert(&list2Ptr, 8);
	insert(&list2Ptr, 10);
	insert(&list2Ptr, 17);

	printf("%s", "List 2 is: "); // 2 4 7 8 10 17
	printList(list2Ptr);

	ListNodePtr list3Ptr = merge(list1Ptr, list2Ptr);

	printList(list3Ptr); // should print 1 2 3 4 5 6 7 8 10 17
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

ListNodePtr merge(ListNodePtr l1, ListNodePtr l2) {
	if (l1 == NULL)
		return l2;
	else if (l2 == NULL)
		return l1;
	else {
		ListNodePtr returnPtr = l1;
		while (l2 != NULL) {
			insert(&l1, l2->data);
			l2 = l2->nextPtr;
		}
		return returnPtr;
	}
}

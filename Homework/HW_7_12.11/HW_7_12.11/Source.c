// Modified version of Fig. 12.8: fig12_08.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// self-referential structure                     
struct stackNode {
	char data; // define data as an int             
	struct stackNode *nextPtr; // stackNode pointer
};

typedef struct stackNode StackNode; // synonym for struct stackNode
typedef StackNode *StackNodePtr; // synonym for StackNode*

// prototypes
void push(StackNodePtr *topPtr, char info);
char pop(StackNodePtr *topPtr);
int isEmpty(StackNodePtr topPtr);
void printStack(StackNodePtr currentPtr);


// function main begins program execution
int main(void)
{
	StackNodePtr stackPtr = NULL; // points to stack top
	char str[100];

	printf("Enter a word or phrase, then we will determine if it is a palindrome\n");
	fgets(str, 100, stdin);

	char condensedString[100];
	int j = 0; // index for condensedString
	for (int i = 0; str[i] != 10; i++) // After testing, I found that ascii code of the ending character is 10
		if (!ispunct(str[i]) && !isspace(str[i])) {
			push(&stackPtr, tolower(str[i]));
			condensedString[j] = tolower(str[i]);
			j++;
		}
	condensedString[j] = '\0';

	char condensedStringRev[100];
	int k = 0; // index for condensedStringRev
	while (!isEmpty(stackPtr)) {
		condensedStringRev[k] = pop(&stackPtr);
		k++;
	}
	condensedStringRev[k] = '\0';

	printf(!strcmp(condensedString, condensedStringRev) ? "This is a palindrome!\n" : "This is not a palindrome :(\n");

	system("pause");
}

// insert a node at the stack top
void push(StackNodePtr *topPtr, char info)
{
	StackNodePtr newPtr = malloc(sizeof(StackNode));

	// insert the node at stack top
	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else { // no space available
		printf("%d not inserted. No memory available.\n", info);
	}
}

// remove a node from the stack top
char pop(StackNodePtr *topPtr)
{
	StackNodePtr tempPtr = *topPtr;
	int popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}

// print the stack
void printStack(StackNodePtr currentPtr)
{
	// if stack is empty
	if (currentPtr == NULL) {
		puts("The stack is empty.\n");
	}
	else {
		puts("The stack is:");

		// while not the end of the stack
		while (currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		puts("NULL\n");
	}
}

// return 1 if the stack is empty, 0 otherwise
int isEmpty(StackNodePtr topPtr)
{
	return topPtr == NULL;
}


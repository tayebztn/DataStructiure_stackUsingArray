/*******************************************************************************
  * File Name          : stackUsingArray.c
  * Description        : use of stack functions as : push(), pop(), stackTop()
  *
  * Author:              Tayeb Zitouni
  * Date:                March 2nd, 2021
  ******************************************************************************
  */

//Includes
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define MAX_STACK_SIZE 10 // pre allocated size of the stack array

static int index = 0; //Front = Rear = 0
char stackArray[MAX_STACK_SIZE];

//Functions Prototypes
void push(char newData);
char pop(void);
char stackTop(void);
int isfull(void);
int isempty(void);
void printstackArray(void);

/********************             Main Function               ***********************************************/
int main()
{

	//To check that the stack is full after a push
	uint8_t fullFlag = 0;

	//Data used to fill the satck
	char alphabet[] = "abcdefghijklmnopqrstuvwxyz";

	// Initialize the stack
	char top = 0;

	//Check before filling the stack
	printf(" Before push isfull %d\n", isfull());	// prints 0 ; ok
	printf(" Before push isempty %d\n", isempty()); // prints 1 ok

	// Filling the stack
	uint8_t alphabetSize = sizeof(alphabet) / sizeof(alphabet[0]);

	for (int i = 0; i < (alphabetSize - 1); i++)
	{

		if (!isfull())
		{
			push(alphabet[i]); // fill in
			fullFlag = 1;
		}
		else
		{
			if (fullFlag)
				printf("After push: ");
			printf(" The stack is full\n");
			break;
		}
	}

	//Printing the stack
	printf("\nStack Elements:");
	printstackArray();
	printf("index is:%d\n", index);
	printf(" The stack isfull %d\n", isfull());
	printf(" The stack isempty %d\n", isempty());

	//Check the top
	top = stackTop();
	printf("Top is %c\n", top);

	// pop & print the top 5 elements
	printf("\nTop 5 Stack Elements:\n");
	for (int i = 0; i < 5; i++)
	{

		if (!isempty())
		{
			printf(" popped elment %c:\n", pop());
		}
		else
		{
			printf(" the stack is empty empty \n");
			break;
		}
	}

	return 0;
}
/*********************************************************************************************/
/************************ Functions Definitions *********************************************/
/********************************************************************************************/

// FUNCTION      : push()
// DESCRIPTION   :
//                Add an element to the stack
// PARAMETERS    :
//                char newData
// RETURNS       :
//                 NOTHING
void push(char newData)
{
	if (index < MAX_STACK_SIZE)
	{
		stackArray[index++] = newData; // fill and increment the index
	}
	else
	{
		printf("Error, stack over flow \n");
	}
}
//
// FUNCTION      : pop()
// DESCRIPTION   :
//					Retrieve the top value of the stack - the stack size is decreased-
// PARAMETERS    :
//					NOTHING - stackArray and index are global variables-
// RETURNS       :
//                  The value popped as char type
char pop(void)
{
	if (index > 0)
	{ // starting from 1 the stack is not empty
		return stackArray[--index];
	}
	else
	{
		printf("Error, unable to pop from empty stack\n");
	}
}
//
// FUNCTION      : stackTop()
// DESCRIPTION   :
//					Read thye top value without affecting the size of the stack
// PARAMETERS    :
//					NOTHING - stackArray and index are global variables-
// RETURNS       :
//				   The value at the top of the stack
char stackTop(void)
{
	if (index > 0)
	{
		return stackArray[index - 1]; // because here: stackArray[index] is after the last element doesn't have a value yet
	}
	else
	{
		printf("Error, unable to pop from empty stack \n");
	}
}
//
// FUNCTION      : isfull()
// DESCRIPTION   :
//				   Check if the stack is full
// PARAMETERS    :
//				   NOTHING - stackArray and index are global variables-
// RETURNS       :
//				   1 if the stack is full; 0 if stack is not full
int isfull(void)
{
	if (index == MAX_STACK_SIZE)
		return 1;
	else
		return 0;
}
//
// FUNCTION      : isempty()
// DESCRIPTION   :
//					Check if the stack is empty
// PARAMETERS    :
//				   NOTHING - stackArray and index are global variables-
// RETURNS       :
//				   1 if the stack is empty; 0 if stack is not empty
int isempty(void)
{
	if (index == 0)
		return 1;
	else
		return 0;
}
//
// FUNCTION      : printstackArray()
// DESCRIPTION   :
//				   prints the elements of stack
// PARAMETERS    :
//				   NOTHING - stackArray and index are global variables-
// RETURNS       :
//                 NOTHING
void printstackArray(void)
{
	for (int i = 0; i < index; i++)
	{
		printf("%c ", stackArray[i]);
	}
	printf("\n");
}

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
  char data;
  struct ListNode *nextPtr;
  
}ListNode;

typedef struct Stack{
  int count;
  ListNode *start;  
} Stack;

Stack *push(Stack*, char);
Stack *pop(Stack*);
void printStack(Stack*);


int main () {
  
  Stack *stackPtr = malloc(sizeof(Stack));
  if(!stackPtr) {
    puts("Error");
  } else {
    stackPtr->count = 0;
    stackPtr->start = NULL;
  }

  stackPtr = push(stackPtr, 'a');
  stackPtr = push(stackPtr, 'b');
  stackPtr = push(stackPtr, 'c');
  stackPtr = push(stackPtr, 'd');

  printStack(stackPtr);
  
  stackPtr = pop(stackPtr);
  stackPtr = pop(stackPtr);

  printStack(stackPtr);


  puts("");

}

Stack *push(Stack *s_push, char toBeAdded) {
  
  ListNode *newNode = malloc(sizeof(ListNode));

  if (newNode == NULL) {
    puts("Error");
  } else {
    newNode -> data = toBeAdded;
    newNode -> nextPtr = s_push -> start;

    s_push -> start = newNode;
    s_push -> count++;

    newNode = NULL;
  }

  return s_push;
}

Stack *pop(Stack *s_pop) {
  //TODO

  return 0;
}

void printStack(Stack *s_print) {
  //TODO
}

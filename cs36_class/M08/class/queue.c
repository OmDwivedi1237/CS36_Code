#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  char data;
  struct ListNode *nextPtr;
} ListNode;

typedef struct Q {
  ListNode *start;
  int count;
  ListNode *end;
  
}Q;


Q *enQ (Q*, char);
Q *deQ (Q*);
void printQ(Q*);

int main () {
  
  Q *qPtr = malloc(sizeof(Q));
  if(qPtr == NULL) {
    puts("Error");
  } else {
    qPtr -> start = NULL;
    qPtr -> count = 0;
    qPtr -> end = NULL;
  }

  qPtr = enQ(qPtr, 'w');
  qPtr = enQ(qPtr, 'x');
  qPtr = enQ(qPtr, 'y');
  qPtr = enQ(qPtr, 'z');


  printQ(qPtr);

  puts("");
}


Q *enQ(Q *q_insert, char toBeAdded) {
  ListNode *newNode = malloc(sizeof(ListNode));
  if(newNode == NULL) {
    puts("Error");
  } else {
    newNode -> data = toBeAdded;
    newNode -> nextPtr = NULL;

    if (q_insert -> start == NULL) {
      q_insert -> start = newNode;
      q_insert -> end = newNode;
      q_insert -> count++;
    } else {
      q_insert -> end -> nextPtr = newNode;
      q_insert -> end = newNode;
      q_insert -> count++;
    }
    newNode = NULL;
  }

  return q_insert;
}



Q *deQ (Q *q_delete) {
  //TODO
  return 0;
}

void printQ(Q *q_print) {
  //TODO
}

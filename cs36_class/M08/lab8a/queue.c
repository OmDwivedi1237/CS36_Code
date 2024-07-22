#include <stdio.h>
#include <stdlib.h> // malloc()

typedef struct ListNode {
    char data;
    struct ListNode* nextPtr;
} ListNode;

typedef struct Queue {
    struct ListNode* start;
    int count;
    struct ListNode* end;
} Queue;

// Prototypes
Queue* enqueue(Queue*, char);
Queue* dequeue(Queue*);
void printQueue(Queue*);

int main(void) {

    Queue* qPtr = malloc(sizeof(Queue));
    if (!qPtr) { 
        puts("Error"); 
        return 1; 
    }

    qPtr->start = NULL;
    qPtr->count = 0;
    qPtr->end = NULL;

    qPtr = enqueue(qPtr, 'w');
    qPtr = enqueue(qPtr, 'x');
    qPtr = enqueue(qPtr, 'y');
    qPtr = enqueue(qPtr, 'z');

    printQueue(qPtr);

    qPtr = dequeue(qPtr);
    qPtr = dequeue(qPtr);

    printQueue(qPtr);

    while (qPtr->start != NULL) {
        qPtr = dequeue(qPtr);
    }

    free(qPtr);

    puts("");
    return 0;
}

Queue* enqueue(Queue* q_insert, char toInsert) {

    ListNode* nodeToAdd = malloc(sizeof(ListNode));
    if (!nodeToAdd) { 
        puts("Error"); 
        return q_insert; 
    }

    nodeToAdd->data = toInsert;
    nodeToAdd->nextPtr = NULL;

    if (q_insert->start == NULL) {
        q_insert->start = nodeToAdd;
        q_insert->end = nodeToAdd;
    } else {
        q_insert->end->nextPtr = nodeToAdd;
        q_insert->end = nodeToAdd;
    }
    q_insert->count++;
    return q_insert;
}

Queue* dequeue(Queue* q_delete) {
    if (q_delete->start == NULL) {
        puts("Queue is empty.");
        return q_delete;
    }

    ListNode* tempPtr = q_delete->start;
    q_delete->start = tempPtr->nextPtr;

    if (q_delete->start == NULL) {
        q_delete->end = NULL;
    }

    free(tempPtr);
    q_delete->count--;

    return q_delete;
}

void printQueue(Queue* q_print) {
    if (q_print->start == NULL) {
        puts("Queue is empty.");
        printf("Number of elements: 0\n");
        return;
    }

    ListNode* current = q_print->start;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->nextPtr;
        if (current != NULL) {
            printf(" -> ");
        }
    }

    printf("\nNumber of elements: %d\n", q_print->count);
}

#include <stdio.h>
#include <stdlib.h> // malloc()

typedef struct ListNode {
    char data;
    struct ListNode* nextPtr;
} ListNode;

typedef struct Stack {
    int count;
    struct ListNode* start;
} Stack;

// Prototypes
Stack* push(Stack*, char); // Insert onto Stack
Stack* pop(Stack*);        // Remove from Stack
void printStack(Stack*);   // Print a Stack

int main(void) {

    // Create Stack Pointer
    Stack* stackPtr;

    stackPtr = malloc(sizeof(Stack));
    if (!stackPtr) { puts("Error"); }

    else {
        stackPtr->count = 0;
        stackPtr->start = NULL;
    }

    // Insert several nodes onto Stack
    stackPtr = push(stackPtr, 'a');
    stackPtr = push(stackPtr, 'b');
    stackPtr = push(stackPtr, 'c');
    stackPtr = push(stackPtr, 'd');

    // Print Stack
    printStack(stackPtr);

    // Delete two nodes from Stack
    stackPtr = pop(stackPtr);
    stackPtr = pop(stackPtr);

    // Print Stack
    printStack(stackPtr);
    
    puts("");
}

Stack* push(Stack* s_push, char valueToInsert) {
    
    ListNode* newPtr = malloc(sizeof(ListNode));
    if (!newPtr) { puts("Error"); }

    else {
        newPtr->data = valueToInsert;
        newPtr->nextPtr = s_push->start;

        s_push->start = newPtr;
        s_push->count++;
        newPtr = NULL;
    }
    return s_push;
}

Stack* pop(Stack* s_pop) {
    // Check if the stack is empty
    if (s_pop->start == NULL) {
        puts("Stack is empty.");
        return s_pop; // Return the stack as is
    }

    // Create a temporary pointer to the node to be removed
    ListNode* tempPtr = s_pop->start;

    // Update the start pointer to the next node
    s_pop->start = tempPtr->nextPtr;

    // Free the memory of the old start node
    free(tempPtr);

    // Decrement the stack count
    s_pop->count--;

    return s_pop;
}

void printStack(Stack* to_print) {
    // Check if the stack is empty
    if (to_print->start == NULL) {
        puts("Stack is empty.");
        printf("Number of elements: 0\n");
        return;
    }

    // Print the stack elements on one line with arrows
    ListNode* current = to_print->start;
    while (current != NULL) {
        printf("%c", current->data);
        current = current->nextPtr;
        if (current != NULL) {
            printf(" -> ");
        }
    }

    // Print the number of elements
    printf("\nNumber of elements: %d\n", to_print->count);
}

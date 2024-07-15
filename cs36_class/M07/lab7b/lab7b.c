#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    char data;
    struct ListNode* nextPtr;
} ListNode;

ListNode* insertNode(ListNode* startPtr, char value);
ListNode* deleteNode(ListNode* startPtr, char value);
void printList(ListNode* startPtr);

int main(void) {
    ListNode* startPtr = NULL;

    startPtr = insertNode(startPtr, 'e');
    startPtr = insertNode(startPtr, 'd');
    startPtr = insertNode(startPtr, 'c');
    startPtr = insertNode(startPtr, 'b');
    startPtr = insertNode(startPtr, 'a');
    
    printf("Full list: ");
    printList(startPtr);

    startPtr = deleteNode(startPtr, 'd');

    printf("List after deleting 'd': ");
    printList(startPtr);

    return 0;
}

ListNode* insertNode(ListNode* startPtr, char value) {
    ListNode* newPtr = malloc(sizeof(ListNode));
    if (newPtr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return startPtr;
    }
    newPtr->data = value;
    newPtr->nextPtr = startPtr;
    return newPtr;
}

ListNode* deleteNode(ListNode* startPtr, char value) {
    if (startPtr == NULL) {
        return startPtr;
    }

    if (value == startPtr->data) {
        ListNode* tempPtr = startPtr;
        startPtr = startPtr->nextPtr;
        free(tempPtr);
    } else {
        ListNode* prevPtr = startPtr;
        ListNode* currPtr = startPtr->nextPtr;

        while (currPtr != NULL && currPtr->data != value) {
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }
        if (currPtr != NULL) {
            prevPtr->nextPtr = currPtr->nextPtr;
            free(currPtr);
        }
    }

    return startPtr;
}

// Function to print the list
void printList(ListNode* startPtr) {
    ListNode* currPtr = startPtr;

    while (currPtr != NULL) {
        printf("%c -> ", currPtr->data);
        currPtr = currPtr->nextPtr;
    }
    printf("NULL\n");
}

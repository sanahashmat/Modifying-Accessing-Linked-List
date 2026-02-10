#include <stdio.h>
#include <stdlib.h>

// Structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to reverse the linked list iteratively
struct Node* reverseLinkedList(struct Node* head) {
    struct Node *prev = NULL, *current = head, *next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to create a new node (for demonstration)
struct Node* createNode(int data) { /* ... */ }

// Function to print the linked list (for demonstration)
void printList(struct Node* head) { /* ... */ }

// Main function to demonstrate the reversal
int main() { /* ... */ }

#include <stdio.h>
#include <stdlib.h>

// Definition of a singly linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to insert a new node at the end of the list
void insert_end(Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = new_data;
    new_node->next = NULL;

    // If the linked list is empty, make the new node the head
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // Else, traverse till the last node
    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    // Change the next of the last node
    last->next = new_node;
}

// Function to find the middle node using the tortoise and hare approach
Node* find_middle(Node* head) {
    if (head == NULL) {
        return NULL; // Handle empty list
    }

    Node* slow_ptr = head;
    Node* fast_ptr = head;

    // Move fast_ptr by two steps and slow_ptr by one step
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    // When the fast_ptr reaches the end, the slow_ptr is at the middle
    return slow_ptr;
}

// Function to print the linked list
void print_list(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate the program
int main() {
    Node* head = NULL;

    // Create a linked list with an odd number of nodes
    insert_end(&head, 1);
    insert_end(&head, 2);
    insert_end(&head, 3);
    insert_end(&head, 4);
    insert_end(&head, 5);

    printf("Linked List 1 (Odd length): ");
    print_list(head);
    Node* middle1 = find_middle(head);
    if (middle1 != NULL) {
        printf("The middle element is: %d\n\n", middle1->data); // Output: 3
    }

    // Create a linked list with an even number of nodes
    Node* head2 = NULL;
    insert_end(&head2, 10);
    insert_end(&head2, 20);
    insert_end(&head2, 30);
    insert_end(&head2, 40);

    printf("Linked List 2 (Even length): ");
    print_list(head2);
    Node* middle2 = find_middle(head2);
    if (middle2 != NULL) {
        // Output: 30 (The second of the two middle nodes)
        printf("The middle element is: %d\n", middle2->data);
    }

    // In a real program, you should free the allocated memory.
    return 0;
}

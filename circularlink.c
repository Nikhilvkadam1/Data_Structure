#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly linked list node
struct Node {
    int data;          // Data stored in the node
    struct Node* next; // Pointer to the next node
};

// Create a function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Create a function to insert a node at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        (*head)->next = *head; // Make the only node point to itself
    } else {
        struct Node* current = *head;
        while (current->next != *head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = *head; // Make the new node point to the head
    }
}

// Create a function to delete a node with a specific data value
void deleteNode(struct Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* current = *head;
    struct Node* prev = NULL;

    do {
        if (current->data == data) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                struct Node* last = current;
                while (last->next != *head) {
                    last = last->next;
                }
                last->next = current->next;
                *head = current->next; // Update the head if needed
            }
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    } while (current != *head);

    printf("Element not found in the list\n");
}

// Create a function to print the circular linked list
void printList(struct Node* head) {
    struct Node* current = head;
    if (current != NULL) {
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head);
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL; // Initialize an empty circular list

    int choice, data;

    while (1) {
        printf("Circular Linked List Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;

            case 2:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 3:
                printf("Circular Linked List: ");
                printList(head);
                break;

            case 4:
                // Free memory if needed
                while (head != NULL) {
                    struct Node* temp = head->next;
                    if (temp == head) {
                        free(head);
                        head = NULL;
                    } else {
                        head->next = temp->next;
                        free(temp);
                    }
                }
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

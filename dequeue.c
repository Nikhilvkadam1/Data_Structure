#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a deque
struct Deque {
    int array[MAX_SIZE];
    int front;
    int rear;
    int size;
};

// Function to initialize a deque
void initializeDeque(struct Deque* deque) {
    deque->front = -1;
    deque->rear = 0;
    deque->size = 0;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return (deque->size == 0);
}

// Function to check if the deque is full
int isFull(struct Deque* deque) {
    return (deque->size == MAX_SIZE);
}

// Function to add an element to the front of the deque
void pushFront(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot push to front.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    } else {
        deque->front--;
    }
    deque->array[deque->front] = item;
    deque->size++;
}

// Function to add an element to the rear of the deque
void pushRear(struct Deque* deque, int item) {
    if (isFull(deque)) {
        printf("Deque is full. Cannot push to rear.\n");
        return;
    }
    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } else if (deque->rear == MAX_SIZE - 1) {
        deque->rear = 0;
    } else {
        deque->rear++;
    }
    deque->array[deque->rear] = item;
    deque->size++;
}

// Function to remove an element from the front of the deque
int popFront(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot pop from front.\n");
        return -1; // Return a sentinel value for empty deque
    }
    int item = deque->array[deque->front];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = 0;
    } else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    } else {
        deque->front++;
    }
    deque->size--;
    return item;
}

// Function to remove an element from the rear of the deque
int popRear(struct Deque* deque) {
    if (isEmpty(deque)) {
        printf("Deque is empty. Cannot pop from rear.\n");
        return -1; // Return a sentinel value for empty deque
    }
    int item = deque->array[deque->rear];
    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = 0;
    } else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    } else {
        deque->rear--;
    }
    deque->size--;
    return item;
}

int main() {
    struct Deque deque;
    initializeDeque(&deque);

    int choice, item;

    while (1) {
        printf("1. Push to front\n");
        printf("2. Push to rear\n");
        printf("3. Pop from front\n");
        printf("4. Pop from rear\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element to push to the front: ");
                scanf("%d", &item);
                pushFront(&deque, item);
                break;
            case 2:
                printf("Enter an element to push to the rear: ");
                scanf("%d", &item);
                pushRear(&deque, item);
                break;
            case 3:
                item = popFront(&deque);
                if (item != -1) {
                    printf("Popped from front: %d\n", item);
                }
                break;
            case 4:
                item = popRear(&deque);
                if (item != -1) {
                    printf("Popped from rear: %d\n", item);
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

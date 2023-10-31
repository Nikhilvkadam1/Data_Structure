#include <stdio.h>
#define Max_size 20

int queue[Max_size];
int front = -1;
int rear = -1;

int isEmpty() {
    if (rear == -1 && front == -1) {
        return 1;
    }
    return 0;
}

int isFull() {
    if (rear == Max_size - 1) {
        return 1;
    }
    return 0;
}

void enqueue(int x) {
    if (isFull()) {
        printf("Queue is overflow\n");
    } else {
        if (front == -1 && rear == -1) {
            front = rear = 0;
            queue[rear] = x;
        } else {
            rear++;
            queue[rear] = x;
        }
    }
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue is Underflow\n");
        return -1;
    } else {
        int value = queue[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
        return value;
    }
}

int main() {
    // BFS Initialization
    int i=4;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int matrix[7][7] = {{0, 1, 1, 1, 0, 0, 0},
                        {1, 0, 1, 0, 0, 0, 0},
                        {1, 1, 0, 1, 1, 0, 0},
                        {1, 0, 1, 0, 1, 0, 0},
                        {0, 0, 1, 1, 0, 1, 1},
                        {0, 0, 0, 0, 1, 0, 0},
                        {0, 0, 0, 0, 1, 0, 0}};

    printf("%d", i);
    visited[i] = 1;
    enqueue(i);
    while (!isEmpty()) {
        int node = dequeue();
        for (int j = 0; j < 7; j++) {
            if (matrix[node][j] == 1 && visited[j] == 0) {
                printf("%d",j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }

    return 0;
}

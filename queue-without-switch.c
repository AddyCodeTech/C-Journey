#include <stdio.h>

#define SIZE 5

int q[SIZE];
int f = -1, r = -1;

void enqueue(int x) {
    if (r == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }

    r = r + 1;
    q[r] = x;

    if (f == -1) {
        f = 0;
    }
}

void dequeue() {
    int num;

    if (f == -1) {
        printf("Queue is empty!\n");
        return;
    }

    num = q[f];
    printf("Deleted element = %d\n", num);
    f = f + 1;

    if (f > r) {
        f = -1;
        r = -1;
    }
}

void display() {
    int i;

    if (f == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");
    for (i = f; i <= r; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter element: ");
            scanf("%d", &x);
            enqueue(x);
        }
        else if (choice == 2) {
            dequeue();
        }
        else if (choice == 3) {
            display();
        }
        else if (choice == 4) {
            break;
        }
        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}

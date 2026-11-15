#include <stdio.h>

#define SIZE 5

int line[SIZE];
int front = 0;
int rear = -1;

void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full, cannot add %d\n", value);
        return;
    }
    rear = rear + 1;
    line[rear] = value;
    printf("%d added to the queue\n", value);
}

void dequeue()
{
    if (front > rear)
    {
        printf("Queue is empty, nothing to remove\n");
        return;
    }
    printf("%d removed from the queue\n", line[front]);
    front = front + 1;
}

void display()
{
    int i;

    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (i = front; i <= rear; i++)
        printf("%d ", line[i]);
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter number: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2)
            dequeue();
        else if (choice == 3)
            display();
        else if (choice != 4)
            printf("Wrong choice, try again\n");
    } while (choice != 4);

    return 0;
}
#include <stdio.h>

#define SIZE 5

int queue[SIZE];   /* the 5 chairs */
int front = 0;     /* position of the first person */
int rear = -1;     /* position of the last person */
int count = 0;     /* how many people are in the queue */

/* add a person at the back */
void enqueue(int value)
{
    if (count == SIZE)
    {
        printf("Queue is full, cannot add %d\n", value);
        return;
    }
    rear = (rear + 1) % SIZE;   /* go back to 0 after the last chair */
    queue[rear] = value;
    count = count + 1;
    printf("%d added\n", value);
}

/* remove the person at the front */
void dequeue()
{
    if (count == 0)
    {
        printf("Queue is empty, nothing to remove\n");
        return;
    }
    printf("%d removed\n", queue[front]);
    front = (front + 1) % SIZE;   /* move to the next chair */
    count = count - 1;
}

/* show everyone in the queue */
void display()
{
    int i, position;

    if (count == 0)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (i = 0; i < count; i++)
    {
        position = (front + i) % SIZE;
        printf("%d ", queue[position]);
    }
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Add\n2. Remove\n3. Show\n4. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter number: ");
            scanf("%d", &value);
            enqueue(value);
        }
        else if (choice == 2)
        {
            dequeue();
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice != 4)
        {
            printf("Wrong choice, try again\n");
        }
    } while (choice != 4);

    return 0;
}
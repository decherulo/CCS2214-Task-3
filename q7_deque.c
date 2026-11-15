#include <stdio.h>

#define SIZE 5

int deque[SIZE];
int front = 0;   /* position of the first item */
int count = 0;   /* how many items are inside */

/* add at the front */
void insertFront(int value)
{
    if (count == SIZE)
    {
        printf("Deque is full\n");
        return;
    }
    front = (front - 1 + SIZE) % SIZE;   /* step back one place */
    deque[front] = value;
    count = count + 1;
    printf("%d added at the front\n", value);
}

/* add at the rear */
void insertRear(int value)
{
    int position;

    if (count == SIZE)
    {
        printf("Deque is full\n");
        return;
    }
    position = (front + count) % SIZE;
    deque[position] = value;
    count = count + 1;
    printf("%d added at the rear\n", value);
}

/* remove from the front */
void deleteFront()
{
    if (count == 0)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("%d removed from the front\n", deque[front]);
    front = (front + 1) % SIZE;
    count = count - 1;
}

/* remove from the rear */
void deleteRear()
{
    int position;

    if (count == 0)
    {
        printf("Deque is empty\n");
        return;
    }
    position = (front + count - 1) % SIZE;
    printf("%d removed from the rear\n", deque[position]);
    count = count - 1;
}

void display()
{
    int i;

    if (count == 0)
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque: ");
    for (i = 0; i < count; i++)
        printf("%d ", deque[(front + i) % SIZE]);
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n1. Insert front\n2. Insert rear\n3. Delete front\n");
        printf("4. Delete rear\n5. Display\n6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Enter number: ");
            scanf("%d", &value);
            insertFront(value);
        }
        else if (choice == 2)
        {
            printf("Enter number: ");
            scanf("%d", &value);
            insertRear(value);
        }
        else if (choice == 3)
            deleteFront();
        else if (choice == 4)
            deleteRear();
        else if (choice == 5)
            display();
        else if (choice != 6)
            printf("Wrong choice, try again\n");
    } while (choice != 6);

    return 0;
}
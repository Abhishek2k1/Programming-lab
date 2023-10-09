#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

// Function to insert an element with priority into the priority queue
void enqueue(struct Node **front, int data, int priority)
{
    struct Node *newNode = createNode(data, priority);
    if (*front == NULL || priority < (*front)->priority)
    {
        newNode->next = *front;
        *front = newNode;
    }
    else
    {
        struct Node *current = *front;
        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to remove and return the element with the highest priority
int dequeue(struct Node **front)
{
    if (*front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return -1;
    }
    else
    {
        struct Node *temp = *front;
        int data = temp->data;
        *front = (*front)->next;
        free(temp);
        return data;
    }
}

// Function to check if the priority queue is empty
int isEmpty(struct Node *front)
{
    return (front == NULL);
}

// Function to display the elements in the priority queue
void display(struct Node *front)
{
    if (front == NULL)
    {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements:\n");
    while (front != NULL)
    {
        printf("Data: %d, Priority: %d\n", front->data, front->priority);
        front = front->next;
    }
}

int main()
{
    struct Node *front = NULL;
    int choice, data, priority;

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            printf("Enter priority: ");
            scanf("%d", &priority);
            enqueue(&front, data, priority);
            break;
        case 2:
            data = dequeue(&front);
            if (data != -1)
            {
                printf("Dequeued item: %d\n", data);
            }
            break;
        case 3:
            display(front);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}


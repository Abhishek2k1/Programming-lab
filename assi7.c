#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the queue
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent a queue
struct Queue
{
    struct Node *front;
    struct Node *rear;
};

// Function to create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to enqueue an element into a queue
void enqueue(struct Queue *queue, int data)
{
    struct Node *newNode = createNode(data);
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue an element from a queue
int dequeue(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        return -1;
    }
    struct Node *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
    {
        queue->rear = NULL; // Reset the rear pointer if the queue becomes empty
    }
    free(temp);
    return data;
}

// Function to check if a queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == NULL);
}

// Function to display the elements in a queue
void display(struct Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    struct Node *current = queue->front;
    printf("Queue elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n, choice, queueIndex, data;
    printf("Enter the number of queues (n): ");
    scanf("%d", &n);

    struct Queue *queues[n]; // Array of queues

    for (int i = 0; i < n; i++)
    {
        queues[i] = createQueue(); // Initialize each queue
    }

    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4)
        {
            // Free memory and exit
            for (int i = 0; i < n; i++)
            {
                while (!isEmpty(queues[i]))
                {
                    dequeue(queues[i]);
                }
                free(queues[i]);
            }
            exit(0);
        }

        printf("Enter the queue index (0 to %d): ", n - 1);
        scanf("%d", &queueIndex);

        if (queueIndex < 0 || queueIndex >= n)
        {
            printf("Invalid queue index.\n");
            continue;
        }

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue: ");
            scanf("%d", &data);
            enqueue(queues[queueIndex], data);
            break;
        case 2:
            data = dequeue(queues[queueIndex]);
            if (data != -1)
            {
                printf("Dequeued from queue %d: %d\n", queueIndex, data);
            }
            break;
        case 3:
            display(queues[queueIndex]);
            break;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

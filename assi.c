#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure to represent a queue
struct Queue
{
    int front, rear, size;
    unsigned capacity;
    int *array;
};

// Function to create a new queue with a given capacity
struct Queue *createQueue(unsigned capacity)
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // Initialize rear as the last index
    queue->array = (int *)malloc(queue->capacity * sizeof(int));
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return (queue->size == queue->capacity);
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->size == 0);
}

// Function to enqueue an element into the queue
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue.\n", item);
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Function to check if two queues are equal
bool areQueuesEqual(struct Queue *queue1, struct Queue *queue2)
{
    if (queue1->size != queue2->size)
    {
        return false;
    }

    int i1 = queue1->front;
    int i2 = queue2->front;

    for (int count = 0; count < queue1->size; count++)
    {
        if (queue1->array[i1] != queue2->array[i2])
        {
            return false;
        }
        i1 = (i1 + 1) % queue1->capacity;
        i2 = (i2 + 1) % queue2->capacity;
    }

    return true;
}

int main()
{
    int n, capacity;
    printf("Enter the number of queues (n): ");
    scanf("%d", &n);

    struct Queue *queues[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the capacity of Queue %d: ", i + 1);
        scanf("%d", &capacity);
        queues[i] = createQueue(capacity);
    }

    int choice;
    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Check if two queues are equal\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the queue number to enqueue: ");
            int queueNum;
            scanf("%d", &queueNum);
            if (queueNum >= 1 && queueNum <= n)
            {
                printf("Enter an element to enqueue: ");
                int item;
                scanf("%d", &item);
                enqueue(queues[queueNum - 1], item);
            }
            else
            {
                printf("Invalid queue number. Please enter a valid queue number.\n");
            }
            break;
        case 2:
            printf("Enter the queue number to dequeue: ");
            scanf("%d", &queueNum);
            if (queueNum >= 1 && queueNum <= n)
            {
                int item = dequeue(queues[queueNum - 1]);
                if (item != -1)
                {
                    printf("Dequeued element: %d\n", item);
                }
            }
            else
            {
                printf("Invalid queue number. Please enter a valid queue number.\n");
            }
            break;
        case 3:
            printf("Enter the first queue number: ");
            int queueNum1;
            scanf("%d", &queueNum1);
            printf("Enter the second queue number: ");
            int queueNum2;
            scanf("%d", &queueNum2);
            if (queueNum1 >= 1 && queueNum1 <= n && queueNum2 >= 1 && queueNum2 <= n)
            {
                bool equal = areQueuesEqual(queues[queueNum1 - 1], queues[queueNum2 - 1]);
                if (equal)
                {
                    printf("The two queues are equal.\n");
                }
                else
                {
                    printf("The two queues are not equal.\n");
                }
            }
            else
            {
                printf("Invalid queue numbers. Please enter valid queue numbers.\n");
            }
            break;
        case 4:
        
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

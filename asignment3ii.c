#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the stack
struct Node
{
    int data;
    struct Node *next;
};

// Structure to represent n stacks
struct NStack
{
    int n;             // Number of stacks
    int capacity;      // Capacity of each stack
    struct Node **top; // Array to store the top node of each stack
};

// Function to create and initialize n stacks
struct NStack *createNStack(int n, int capacity)
{
    struct NStack *stack = (struct NStack *)malloc(sizeof(struct NStack));
    if (!stack)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->n = n;
    stack->capacity = capacity;
    stack->top = (struct Node **)malloc(n * sizeof(struct Node *));
    if (!stack->top)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        stack->top[i] = NULL;
    }
    return stack;
}

// Function to check if a stack is empty
int isEmpty(struct NStack *stack, int stackNum)
{
    return (stack->top[stackNum] == NULL);
}

// Function to check if a stack is full
int isFull(struct NStack *stack, int stackNum)
{
    struct Node *topNode = stack->top[stackNum];
    int count = 0;
    while (topNode != NULL)
    {
        count++;
        topNode = topNode->next;
    }
    return (count == stack->capacity);
}

// Function to push an element onto a stack
void push(struct NStack *stack, int stackNum, int data)
{
    if (isFull(stack, stackNum))
    {
        printf("Stack %d is full. Cannot push %d.\n", stackNum, data);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = stack->top[stackNum];
    stack->top[stackNum] = newNode;
}

// Function to pop an element from a stack
int pop(struct NStack *stack, int stackNum)
{
    if (isEmpty(stack, stackNum))
    {
        printf("Stack %d is empty. Cannot pop.\n", stackNum);
        return -1; // Return a sentinel value indicating an error
    }
    struct Node *temp = stack->top[stackNum];
    int data = temp->data;
    stack->top[stackNum] = temp->next;
    free(temp);
    return data;
}

// Function to display the elements of a stack
void display(struct NStack *stack, int stackNum)
{
    struct Node *current = stack->top[stackNum];
    printf("Stack %d: ", stackNum);
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n, capacity;

    printf("Enter the number of stacks and capacity for each stack: ");
    scanf("%d %d", &n, &capacity);

    struct NStack *stack = createNStack(n, capacity);

    int choice, stackNum, data;

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display Stack\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the stack number and data to push: ");
            scanf("%d %d", &stackNum, &data);
            push(stack, stackNum, data);
            break;
        case 2:
            printf("Enter the stack number to pop: ");
            scanf("%d", &stackNum);
            int poppedValue = pop(stack, stackNum);
            if (poppedValue != -1)
            {
                printf("Popped value from Stack %d: %d\n", stackNum, poppedValue);
            }
            break;
        case 3:
            printf("Enter the stack number to display: ");
            scanf("%d", &stackNum);
            display(stack, stackNum);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 100 // Maximum size for each stack
#define MAX_NUM_STACKS 5   // Maximum number of stacks

int arr[MAX_STACK_SIZE * MAX_NUM_STACKS]; // Single array to store multiple stacks
int top[MAX_NUM_STACKS];                  // Array to store the top index of each stack
int stackSize;                            // Size of each stack
int numStacks;                            // Number of stacks

// Initialize the multiple stacks
void init(int n, int size)
{
    numStacks = n;
    stackSize = size;
    for (int i = 0; i < numStacks; i++)
    {
        top[i] = -1; // Initialize the top index of each stack to -1 (empty)
    }
}

// Push an element onto the specified stack
bool push(int stackNum, int data)
{
    if (stackNum < 0 || stackNum >= numStacks)
    {
        printf("Invalid stack number\n");
        return false;
    }

    if (top[stackNum] >= stackSize - 1)
    {
        printf("Stack %d is full. Cannot push %d\n", stackNum, data);
        return false;
    }

    int index = stackNum * stackSize + top[stackNum] + 1;
    arr[index] = data;
    top[stackNum]++;
    return true;
}

// Pop an element from the specified stack
bool pop(int stackNum)
{
    if (stackNum < 0 || stackNum >= numStacks)
    {
        printf("Invalid stack number\n");
        return false;
    }

    if (top[stackNum] == -1)
    {
        printf("Stack %d is empty. Cannot pop.\n", stackNum);
        return false;
    }

    top[stackNum]--;
    return true;
}

// Peek at the top element of the specified stack
int peek(int stackNum)
{
    if (stackNum < 0 || stackNum >= numStacks)
    {
        printf("Invalid stack number\n");
        return -1; // Return a sentinel value indicating an error
    }

    if (top[stackNum] == -1)
    {
        printf("Stack %d is empty. No element to peek.\n", stackNum);
        return -1; // Return a sentinel value indicating an error
    }

    int index = stackNum * stackSize + top[stackNum];
    return arr[index];
}

// Check if two stacks are equal
bool areEqual(int stack1, int stack2)
{
    if (stack1 < 0 || stack1 >= numStacks || stack2 < 0 || stack2 >= numStacks)
    {
        printf("Invalid stack number\n");
        return false;
    }

    if (top[stack1] != top[stack2])
    {
        return false; // Stacks have different sizes, so they can't be equal
    }

    for (int i = 0; i <= top[stack1]; i++)
    {
        int index1 = stack1 * stackSize + i;
        int index2 = stack2 * stackSize + i;
        if (arr[index1] != arr[index2])
        {
            return false; // Elements at the same position in both stacks are different
        }
    }

    return true; // Stacks are equal
}

int main()
{
    int n, size;

    printf("Enter the number of stacks and size for each stack: ");
    scanf("%d %d", &n, &size);

    init(n, size); // Initialize the specified number of stacks with the specified size

    int choice;
    int stackNum;
    int data;

    while (1)
    {
        printf("\nChoose an operation:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Check if two stacks are equal\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the stack number and data to push: ");
            scanf("%d %d", &stackNum, &data);
            push(stackNum, data);
            break;
        case 2:
            printf("Enter the stack number to pop: ");
            scanf("%d", &stackNum);
            pop(stackNum);
            break;
        case 3:
            printf("Enter the stack number to peek: ");
            scanf("%d", &stackNum);
            int topElement = peek(stackNum);
            if (topElement != -1)
            {
                printf("Top element of Stack %d: %d\n", stackNum, topElement);
            }
            break;
        case 4:
            printf("Enter the two stack numbers to compare: ");
            int stack1, stack2;
            scanf("%d %d", &stack1, &stack2);
            if (areEqual(stack1, stack2))
            {
                printf("Stack %d and Stack %d are equal.\n", stack1, stack2);
            }
            else
            {
                printf("Stack %d and Stack %d are not equal.\n", stack1, stack2);
            }
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
            break;
        }
    }

    return 0;
}

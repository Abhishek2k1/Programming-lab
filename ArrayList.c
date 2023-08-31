#include <stdio.h>
#include <stdlib.h>
int *array = NULL;
int size = 0;
int capacity = 0;
int n2 = 0;
int *ptr2 = NULL;
void display()
{
    int i;
    if (capacity == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else
    {
        if (ptr2 == NULL)
            printf("\nThe array is:\n");
        else
            printf("\nThe first array is:\n");

        for (int i = 0; i < capacity; i++)
            printf("%d ", array[i]);

        if (ptr2 != NULL)
        { // if the array is splited at that moment
            printf("\nThe second array is:\n");
            for (int i = 0; i < n2; i++)
                printf("%d ", ptr2[i]);
        }
    }
}
void CreateArray()
{
    if (array)
    {
        free(array);
        array = NULL;
    }

    printf("Enter initial capacity: ");
    scanf("%d", &capacity);

    array = (int *)malloc(capacity * sizeof(int));
    if (array == NULL)
    {
        printf("Memory not allocated.\n");
    }
    else
    {
        // Get the elements of the array
        printf("Enter the values of elements:\n");
        for (int j = 0; j < capacity; ++j)
        {
            scanf("%d", array + j);
        }
        // Print the elements of the array
        printf("The elements of the array are: \n");
        for (int k = 0; k < capacity; ++k)
        {
            printf("%d ", array[k]);
        }
    }

    printf("\nArray created.");
}
int CountElements()
{
    return capacity;
}
int ElementIndex(int index)
{
    if (index >= 0 && index < capacity)
    {
        return array[index];
    }
    else
    {
        printf("Invalid index.\n");
        return -1;
    }
}
void InsertElement(int element, int index)
{
    printf("\nEnter the index no: ");
    scanf("%d", &index);
    printf("Enter the value to be inserted: ");
    scanf("%d", &element);
    if (index >= 0 && index <= capacity)
    {
        capacity += 1;
        array = (int *)realloc(array, capacity * sizeof(int)); // allocate one extra memory for 1st array

        for (int i = capacity - 1; i > index; i--) // element right shifting
            array[i] = array[i - 1];
        array[index] = element;
        printf("Element inserted!");
    }
    else
        printf("Index must be between 0 to %d", capacity);
}

int findElement(int *arr, int n, int ele)
{
    int i, index = -1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            index = i;
            break;
        }
    }
    if (i == n)
        printf("Element not present in the array");
    return index;
}

int deleteElemet()
{
    // this function is for delete an element from the given index
    int element, option, value, index = -1;
    if (capacity == 0 && n2 == 0)
    {
        printf("\nArray not created yet, you may want to create first!");
        return 1;
    }
    else if (ptr2 != NULL)
    {
        printf("\nArray splited, choose source array. Press 1) 1st array else 2nd array: ");
        scanf("%d", &option);
        printf("Enter the element to be deleted: ");
        scanf("%d", &element);

        if (option != 1)
        {
            index = findElement(ptr2, n2, element);
            if (index != -1)
            {
                for (int i = index; i < n2 - 1; i++) // element left shifting
                    ptr2[i] = ptr2[i + 1];
                n2 -= 1;
                if (n2 == 0)
                {
                    free(ptr2);
                    ptr2 = NULL;
                }
                else
                    ptr2 = (int *)realloc(ptr2, n2 * sizeof(int)); // deallocate one extra memory for 2nd array
                printf("Element deleted!");
            }
        }
        else if (capacity == 0)
        {
            printf("No element present in the 1st array, You may wnat to delete from the 2nd array!");
        }
    }
    else
    {
        printf("Enter the element to be deleted: ");
        scanf("%d", &element);
    }
    index = findElement(array, capacity, element);
    if (index != -1)
    {
        for (int i = index; i < capacity - 1; i++) // element left shifting
            array[i] = array[i + 1];
        capacity -= 1;
        if (capacity == 0)
        {
            free(array);
            array = NULL;
        }
        else
            array = (int *)realloc(array, capacity * sizeof(int)); // deallocate one extra memory for 1st array
        printf("Element deleted!");
    }
}
void MergeArrays(int *otherarray, int n)
{
    int temp;
    if (capacity == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else if (n2 == 0 || ptr2 == NULL)
        printf("\nArray not splited yet, you may want to split first!");
    else
    {
        temp = capacity;
        capacity += n2;
        array = (int *)realloc(array, capacity * sizeof(int)); // allocate extra memory for additional n2 elements

        for (int i = temp, j = 0; i < capacity; i++, j++) // assigning extra value to the 1st array from the 2nd array
            array[i] = ptr2[j];

        free(ptr2); // deallocate assigned memory for 2nd array
        n2 = 0;
        ptr2 = NULL;
        printf("\nArray merged!");
    }
}
void SplitArray(int index)
{
    int position;
    if (capacity == 0 && n2 == 0)
        printf("\nArray not created yet, you may want to create first!");
    else if (n2 != 0)
        printf("\nArray already splited!");
    else if (capacity == 1)
        printf("\nOnly one element is present, can not be splited!");
    else
    {
        printf("\nEnter the the position to be splited: ");
        scanf("%d", &position);

        if (position > 0 && position < capacity)
        {
            n2 = capacity - position;
            ptr2 = (int *)malloc(n2 * sizeof(int)); // dynamically allocated memory for n2 element

            for (int i = position, j = 0; i < capacity; i++, j++) // assigning value to the 2nd array from the 1st array
                ptr2[j] = array[i];

            capacity -= n2;                                        // reducing the size for the 1st array
            array = (int *)realloc(array, capacity * sizeof(int)); // reduced the allocated memory to n1 elements

            printf("Array splited!");
        }
        else
            printf("Position must be between 1 to %d", capacity - 1);
    }
}
void SortArray()
{
    int i, j, temp = 0;
    if (capacity <= 0)
    {
        printf("Array is empty.\n");
        return;
    }
    for (i = 0; i < capacity - 1; i++)
    {
        for (j = 0; j < capacity - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    printf("Array sorted.\n");
}
int SearchArray(int key)
{
    int i;
    for (i = 0; i < capacity; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1; // Key not found
}

int main()
{
    int choice, count, index, k, n, i, key, result;
    int *otherarray = NULL;

    do
    {
        printf("\n1. Create:\n");
        printf("2. Count:\n");
        printf("3. Indexed element:\n");
        printf("4. Insert element:\n");
        printf("5. Delete element:\n");
        printf("6. Merge Arrays:\n");
        printf("7. Split Arrays:\n");
        printf("8. Sorted Arrays:\n");
        printf("9. Search element:\n");
        printf("10. Display Array:\n");
        printf("11. Quit:\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            CreateArray();
            break;
        case 2:
            count = CountElements();
            printf("Number of elements:%d\n", count);
            break;
        case 3:
            printf("Enter index:");
            scanf("%d", &index);
            k = ElementIndex(index);
            if (k != -1)
            {
                printf("Element at index %d: %d\n", index, k);
            }
            break;
        case 4:
            InsertElement(k, index);
            break;
        case 5:
            deleteElemet();
            break;
        case 6:

            MergeArrays(otherarray, n);
            break;
        case 7:
            SplitArray(index);
            break;
        case 8:
            SortArray();
            break;
        case 9:
            printf("Enter element to be searched: ");
            scanf("%d", &key);
            result = SearchArray(key);
            if (result != -1)
            {
                printf("Element %d found at index %d.\n", key, result);
            }
            else
            {
                printf("Element %d not found in the array.\n", key);
            }
            break;
        case 10:
            display();
            break;
        case 11:
            printf("Quitting the program.\n");
            free(array);
            break;
        default:
            printf("Invalid choice. Please select a valid option.\n");
        }

    } while (choice != 11);
    return 0;
}

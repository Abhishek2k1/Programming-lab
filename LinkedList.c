#include <stdio.h>
#include <stdlib.h>

// Define the struct node type before declaring the functions
struct node
{
    int data;
    struct node *next;
};

// Declare the functions
void create();
void display();
void insert_pos_after();
void insert_pos_before();
void insert_before_value();
void insert_after_value();
void delete_pos();
void delete_value();
void reverse();
void create_another_ll();
void compare_two_list();
void concatenate();
void merge_asc(struct node *list1, struct node *list2);

// Global variables for the linked lists
struct node *head = NULL;
struct node *head2 = NULL;

// Rest of your code...

int main()
{
    int choice;
    while (1)
    {
        printf("\nChoose a function:\n");
        printf("1.Create a linked list.\n");
        printf("2.Print the content of the list.\n");
        printf("3.Insert a node after the kth node (k may be any integer).\n");
        printf("4.Insert a node after the node containing a given value.\n");
        printf("5.Insert a node before the kth node (k may be any integer).\n");
        printf("6.Insert a node before the node containing a given value.\n");
        printf("7.Delete the kth node (k may be any integer).\n");
        printf("8.Delete the node containing a specified value.\n");
        printf("9.Find the reverse of a list.\n");
        printf("10.Create another linked list.\n");
        printf("11.Find if two lists are equal (Boolean output)\n");
        printf("12.Concatenate two lists.\n");
        printf("13.Merge two lists, those are in ascending order (before and after merging).\n");
        printf("14.Exit.\n");

        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            insert_pos_after();
            break;
        case 4:
            insert_after_value();
            break;
        case 5:
            insert_pos_before();
            break;
        case 6:
            insert_before_value();
            break;
        case 7:
            delete_pos();
            break;
        case 8:
            delete_value();
            break;
        case 9:
            reverse();
            break;
        case 10:
            create_another_ll();
            break;
        case 11:
            compare_two_list();
            break;
        case 12:
            concatenate();
            break;
        case 13:
            merge_asc(head, head2);
            break;
        case 14:
            exit(0);
            break;

        default:
            printf("Wrong choice\n");
            break;
        }
    }
    return 0;
}

void create()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data value:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (head == 0)
    {
        head = newnode;
    }
    else
    {
        temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void display()
{
    struct node *temp;
    temp = head;
    printf("The List1 elements are:\n");
    while (temp != 0)
    {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void insert_pos_after()
{
    struct node *newnode, *temp;
    int pos, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the pos for the new node:\n");
    scanf("%d", &pos);
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void insert_after_value()
{
    struct node *newnode, *temp;
    int search_data;
    printf("Enter the Value after which you want to add a node:\n");
    scanf("%d", &search_data);

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    temp = head;
    while (temp != NULL && temp->data != search_data)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found in the list\n");
        free(newnode);
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insert_pos_before()
{
    struct node *newnode, *temp;
    int pos, i;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the pos for the new node:\n");
    scanf("%d", &pos);
    printf("Enter the data:\n");
    scanf("%d", &newnode->data);
    newnode->next = 0;
    if (pos == 0)
    {
        newnode->next = head;
        head = newnode;
    }
    else
    {
        temp = head;
        for (i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void insert_before_value()
{
    struct node *newnode, *temp, *prev;
    int search_data;
    printf("Enter the Value before which you want to add a node:\n");
    scanf("%d", &search_data);

    newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    temp = head;
    prev = NULL;

    // Search for the node with the specified value
    while (temp != NULL && temp->data != search_data)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found in the list\n");
        free(newnode);
    }
    else
    {
        // Insert the new node before the found node
        if (prev == NULL)
        {
            // If the found node is the first node, update the head
            newnode->next = head;
            head = newnode;
        }
        else
        {
            // Otherwise, update the previous node's next pointer
            newnode->next = temp;
            prev->next = newnode;
        }
    }
}

void delete_pos()
{
    int i, pos;
    struct node *temp, *prevnode;
    if (head == 0)
    {
        printf("List is empty\n");
        exit(0);
    }
    else
    {
        printf("Enter the pos u want to delete\n");
        scanf("%d", &pos);
        if (pos == 0)
        {
            temp = head;
            head = head->next;
            printf("The deleted element is : %d\n", temp->data);
            free(temp);
        }
        else
        {
            temp = head;
            for (i = 1; i < pos - 1; i++)
            {
                prevnode = temp->next;
            }
            temp = prevnode->next;
            prevnode->next = temp->next;
            printf("The deleted element is : %d\n", temp->data);
            free(temp);
        }
    }
}
void delete_value()
{
    struct node *temp, *prev;
    int value;
    printf("Enter the value you want to delete: ");
    scanf("%d", &value);

    temp = head;
    prev = NULL;

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value not found in the list\n");
    }
    else
    {
        if (prev == NULL)
        {
            // If the value to delete is in the head node.
            head = temp->next;
        }
        else
        {
            prev->next = temp->next;
        }

        printf("Deleted element: %d\n", temp->data);
        free(temp);
    }
}
int getlength()
{
    int count = 0;
    struct node *temp;
    temp = head;
    while (temp != 0)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void reverse()
{
    int i, j, k, len, temp;
    struct node *p, *q;
    len = getlength();
    i = 0;
    j = len - 1;
    p = q = head;
    while (i < j)
    {
        k = 0;
        while (k < j)
        {
            q = q->next;
            k++;
        }
        temp = p->data;
        p->data = q->data;
        q->data = temp;
        i++;
        j--;
        p = p->next;
        q = head;
    }
}
void create_another_ll()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data value for the new linked list:\n");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head2 == NULL)
    {
        head2 = newnode;
    }
    else
    {
        temp = head2;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Linked list created successfully!\n");
    printf("Linked list2 content:\n");
    temp = head2;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void compare_two_list()
{
    struct node *temp1 = head, *temp2 = head2;
    int equal = 1; // Assume lists are equal

    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            equal = 0; // Lists are not equal
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if (temp1 != NULL || temp2 != NULL)
    {
        equal = 0; // Lists are not equal due to different lengths
    }

    if (equal)
    {
        printf("Lists are equal.\n");
    }
    else
    {
        printf("Lists are not equal.\n");
    }
}

void concatenate()
{
    struct node *temp1 = head, *temp2 = head2;

    if (temp1 == NULL)
    {
        head = temp2; // If the first list is empty, just set head to the second list.
    }
    else
    {
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp1->next = temp2; // Link the end of the first list to the head of the second list.
    }

    printf("Lists concatenated successfully!\n");
    // Print the concatenated list
    printf("Concatenated list content:\n");
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void merge_asc(struct node *list1, struct node *list2)
{
    struct node *mergedList = NULL; // Initialize the merged list as empty

    // Pointers for traversing both input lists
    struct node *ptr1 = list1;
    struct node *ptr2 = list2;

    // Traverse both input lists
    while (ptr1 != NULL && ptr2 != NULL)
    {
        // Compare the data values of the two nodes
        if (ptr1->data < ptr2->data)
        {
            // If the data in list1 is smaller, add it to the merged list
            if (mergedList == NULL)
            {
                mergedList = ptr1;
                head = mergedList; // Update the head of the merged list if it's the first node
            }
            else
            {
                mergedList->next = ptr1;
                mergedList = mergedList->next;
            }
            ptr1 = ptr1->next;
        }
        else
        {
            // If the data in list2 is smaller or equal, add it to the merged list
            if (mergedList == NULL)
            {
                mergedList = ptr2;
                head = mergedList; // Update the head of the merged list if it's the first node
            }
            else
            {
                mergedList->next = ptr2;
                mergedList = mergedList->next;
            }
            ptr2 = ptr2->next;
        }
    }

    // If there are remaining nodes in either list, append them to the merged list
    while (ptr1 != NULL)
    {
        mergedList->next = ptr1;
        mergedList = mergedList->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        mergedList->next = ptr2;
        mergedList = mergedList->next;
        ptr2 = ptr2->next;
    }

    printf("Lists merged successfully in ascending order!\n");
}
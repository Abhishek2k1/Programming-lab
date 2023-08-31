#include<stdio.h>
#include<stdlib.h>

void create();
void display();
void insert_pos_after();
void insert_pos_before();
void insert_before_value();
void insert_after_value();
void delete_pos();
void delete_value();
void reverse();

struct node
{
	int data;
	struct node *next;
};
struct node *head = 0;

int main(){
	int choice;
	while(1){
		printf("\nChoose a function:\n");
		printf("1.Create a linked list.\n");
		printf("2.Print the content of the list.\n");
		printf("3.Insert a node after the kth node(k may be any interge).\n");
		printf("4.Insert a node after the node containing a given value.\n");
		printf("5.Insert a node before the kth node(k may be any interge).\n");
		printf("6.Insert a node before the node containing a given value.\n");
		printf("7.Delete the kth node(k may be any interge).\n");
		printf("8.Delete the node containing a specified value.\n");
		printf("9.Find the reverse of a list.\n");
		printf("10.Create another linked list.\n");
		printf("11.Find if two lists are equal(Boolean output)\n");
		printf("12.Concatenate two lists.\n");
		printf("13.Merge two lists, those are in ascending order(before and after merging).\n");
		printf("14.Exit.\n");
		
		printf("Enter ur choice\n");
		scanf("%d", &choice);
		switch(choice){
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
				exit(0);
				break;
			case 11:
				exit(0);
				break;
			case 12:
				exit(0);
				break;
			case 13:
				exit(0);
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

void create(){
	struct node *newnode, *temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data value:\n");
	scanf("%d", & newnode->data);
	newnode->next = 0;
	if(head == 0){
		head  = newnode;
	}
	else{
		temp = head;
		while(temp->next!=0){
			temp = temp->next;
		}
		temp->next = newnode;
	}
}
// void create(){
// 	struct node *newnode, *temp;
// 	newnode = (struct node*)malloc(sizeof(struct node));
// 	printf("Enter the data value:\n");
// 	scanf("%d", & newnode->data);
// 	newnode->next = 0;
// 	if(head == 0){
// 		head  = newnode;
// 	}
// 	else{
// 		temp = head;
// 		while(temp->next!=0){
// 			temp = temp->next;
// 		}
// 		temp->next = newnode;
// 	}
// }
void display(){
	struct node *temp;
	temp = head;
	printf("The List elements are:\n");
	while(temp!= 0){
		printf("%d ->",temp->data);
		temp = temp->next;
	}
}
// void insert_begin(){
// 	struct node *newnode;
// 	newnode = (struct node*)malloc(sizeof(struct node));
// 	printf("Enter the data u want to insert at beginning:\n");
// 	scanf("%d", & newnode->data);
// 	newnode->next = 0;
// 	if(head == 0){
// 		head = newnode;
// 	}
// 	else{
// 		newnode->next = head;
// 		head = newnode;
// 	}
// }


// void insert_end(){
// 	struct node *newnode,  *temp;
// 	newnode = (struct node*)malloc(sizeof(struct node));
// 	printf("Enter the data u want to insert at end:\n");
// 	scanf("%d", &newnode->data);
// 	newnode->next = 0;
// 	if(head == 0){
// 		head = newnode;
// 	}
// 	else{
// 		temp = head;
// 		while(temp->next!= 0){
// 			temp = temp->next;
// 		}
// 		temp->next = newnode;
// 	}
// }

void insert_pos_after(){
	struct node  *newnode, *temp;
	int pos, i;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the pos for the new node:\n");
	scanf("%d", &pos);
	printf("Enter the data:\n");
	scanf("%d", &newnode->data);
	newnode->next = 0;
	if(pos == 0){
		newnode->next = head;
		head = newnode;
	}
	else{
		temp = head;
		for(i=1;i<pos;i++){
			temp = temp->next;
		}
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
void insert_after_value(){
	// Given a node prev_node, insert a new
	// node after the given prev_node
// 	void insertAfter(Node * prev_node, int new_data)
// 	{
// 		// 1. check if the given prev_node
// 		// is NULL
// 		if (prev_node == NULL)
// 		{
// 			cout << "The given previous node cannot be NULL";
// 			return;
// 		}

// 		// 2. allocate new node
// 		Node *new_node = new Node();

// 		// 3. put in the data
// 		new_node->data = new_data;

// 		// 4. Make next of new node
// 		// as next of prev_node
// 		new_node->next = prev_node->next;

// 		// 5. move the next of prev_node
// 		// as new_node
// 		prev_node->next = new_node;
// 	}
 }

	// void delete_begin(){
	// 	struct node *temp;
	// 	if(head == 0){
	// 		printf("List is empty\n");
	// 		exit(0);
	// 	}
	// 	else{
	// 		temp = head;
	// 		head = head->next;
	// 		printf("The deleted element is : %d\n",temp->data);
	// 		free(temp);
	// 	}
	// }

	// void delete_end(){
	// 	struct node *temp, *prevnode;
	// 	if(head == 0){
	// 		printf("List is empty\n");
	// 		exit(0);
	// 	}
	// 	else if(head->next==0){
	// 		temp = head;
	// 		head = 0;
	// 		printf("The deleted element is : %d\n",temp->data);
	// 		free(temp);
	// 	}
	// 	else{
	// 		temp = head;
	// 		while(temp->next != 0){
	// 			prevnode = temp;
	// 			temp= temp->next;
	// 		}
	// 		prevnode->next = 0;
	// 		printf("The deleted element is : %d\n",temp->data);
	// 		free(temp);
	// 	}
	// }

	void
	delete_pos()
{
	int i, pos;
	struct node *temp, *prevnode;
	if(head == 0){
		printf("List is empty\n");
		exit(0);
	}
	else{
		printf("Enter the pos u want to delete\n");
		scanf("%d", & pos);
		if(pos == 0){
			temp = head;
			head = head->next;
			printf("The deleted element is : %d\n",temp->data);
			free(temp);
		}
		else{
			temp = head;
			for(i=1; i<pos-1; i++){
				prevnode = temp->next;
			}
			temp = prevnode->next;
			prevnode->next = temp->next;
			printf("The deleted element is : %d\n",temp->data);
			free(temp);
		}
	}
}
int getlength(){
	int count = 0;
	struct node *temp;
	temp = head;
	while(temp!= 0){
		count++;
		temp = temp->next;
	}
	return count;
}
void reverse(){
	int i, j, k, len, temp;
	struct node *p, *q;
	len = getlength();
	i=0;
	j=len-1;
	p=q=head;
	while(i<j){
		k=0;
		while(k<j){
			q=q->next;
			k++;
		}
		temp = p->data;
		p->data = q->data;
		q->data = temp;
		i++;
		j--;
		p = p->next;
		q= head;
	}
}
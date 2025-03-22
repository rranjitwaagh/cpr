#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node {
	int data;
	struct node *next;
} node;

/**
 * Function to allocate single linked list node
 */
static inline node* alloc_node(void)
{
	node *nn = (node *)malloc(sizeof(node));
	nn->next = NULL;

	return(nn);
}

/**
 * Function to free up the provided node
 */
static inline int free_node(node *n)
{
	int ret = 0;

	if (n) {
		free(n);
		n = NULL;
	} else {
		//printf("err:%s: invalid pointer provided\n", __func__);
		ret = -1;
	}

	return(ret);
}

/**
 * Function to insert a node into the linked list in sorted order
 */
int insert_node(node *head, int value)
{
	node *nn = NULL;
	node *temp = NULL;

	nn = alloc_node();

	if (nn == NULL) {
		printf("err:%s: unable to allocate memory for the new node\n", __func__);
		return(-1);
	}

	/* init node value, next is already pointing to NULL */
	nn->data = value;

	/* this could be first node itself */
	if (head == NULL) {
		head = nn;
	}

	/* if list is already created then find the correct place for the value to be inserted */
	temp = head;

	while ((temp->data < value) && (temp))
		temp = temp->next;

	temp->next = nn;
	
	return(0);
}

/**
 * Function to print the linked list
 */

void print_list(node *head)
{
	node *p;

	if (!head) {
		printf("%s:err: empty linked list\n", __func__);
		return;
	}

	p = head;

	printf("Contents of Linked List are: \n");
	while (p) {
		printf(" | %d | ", p->data);
		p = p->next;
	}
	printf("\n\n");
}

/**
 * Delete all nodes from the list
 */
int delete_list(node *head)
{
	node *p;

	if (!head) {
		printf("%s:err: empty linked list\n", __func__);
		return(-1);
	}
	
	while (head) {
		p = head;
		head = head->next;
		free_node(p);
	}

	return(0);
}

int main(void)
{
	node *head = NULL;

	insert_node(head, 10);
	insert_node(head, 20);
	insert_node(head, 30);
	insert_node(head, 40);

	print_list(head);

	delete_list(head);

	return(0);
}


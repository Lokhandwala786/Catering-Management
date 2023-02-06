#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
} *temp,*newNode;

/* Initialising the pointers in the linked list */

struct node *front= NULL;
struct node *rear= NULL;


/* Function to insert elements in a circular queue */

void enqueue(int data)
{
    newNode = (struct node*) malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = newNode;
    if(front == NULL)
        front = rear = newNode;
    else
    {
        rear -> next = newNode;
        rear = newNode;
    }
    rear -> next = front;   // rear always points to the front
}

/* Function to delete an element from the circular queue */
int dequeue()
{
    int x;
    if (front == NULL)
    {
        return -1; //for empty queue
    }
    else if (front == rear) // Queue has only a single node
    {
        x = front->data;
        free(front);
        front = rear = NULL;
    }
    else
    {
        temp = front;
        x = temp -> data;
        front = front -> next;
        // Make rear point to the front node
        rear -> next = front;
        free(temp);
    }
    return x;
}

/* Function to check if the queue is empty */
int empty()
{
    if(front == NULL)
    {
        return 1;
    }
    else
        return 0;
}

/* Function to print the elements in the circular queue */
void display()
{
     temp = front;
    printf("\nCIRCULAR QUEUE : ");
    do
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }while (temp != front);
}

/* Main function */
int main()
{
    int num,choice;
    while(1)
    {
    	printf("\n\nQUEUE OPERATIONS\n\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n\n");
    	scanf("%d",&choice);
    	switch (choice)
    	{
            case 1:
                	printf("\nEnter item : ");
                	scanf("%d",&num);
                	enqueue(num);
                	break;
            case 2:
	                if(!(empty()))
                	printf("\nDequeued element : %d",dequeue());
                	else
                	printf("\nEMPTY QUEUE\n");
                	break;
             case 3:
                	display();
                	break;
	
        }
    }
return 0;
}


/*
File Name: Non recursive operations in Binary Search Tree
Purpose  : To explain non recursive operations in BST
Date     : 11th November 2018
Author   : Bipul Islam
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 50

struct node
{
	struct node *lchild;
	int info;
	struct node *rchild;
};
struct node *getNode(int x);
void display(struct node *p, int level);
struct node *insertNode(struct node *root, int x);
struct node *search(struct node *p, int x);
struct node *deleteNode(struct node *root, int x);
struct node *Min(struct node *p);
struct node *Max(struct node *p);

void preorderTraversal(struct node *root);
void inorderTraversal(struct node *root);
void postorderTraversal(struct node *root);
void levelorderTraversal(struct node *root);

struct node *queue[MAX];
int front=-1,rear=-1;
void insert_queue(struct node *item);
struct node *delete_queue();
int queue_empty();

struct node *stack[MAX];
int top=-1;
void push_stack(struct node *item);
struct node *pop_stack();
int stack_empty();

main( )
{
	struct node *root=NULL, *p;
	int choice,x;
		
	while(1)
	{
		printf("\n");
		printf("1.Display Tree:\n");
		printf("2.Search\n");
		printf("3.Insert a new node:\n");
		printf("4.Delete a node: \n");
		printf("5.Find minimum: \n");
		printf("6.Find maximum: \n");
		printf("7.Preorder Traversal\n");
		printf("8.Inorder Traversal\n");
		printf("9.Postorder Traversal\n");
		printf("10.Level order traversal\n");
		printf("11.Quit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);

        if(choice == 11)
        	break;

		switch(choice)
		{
		case 1:
		    display(root, 0);
		    break;
		case 2: 
			printf("Enter the key to be searched : ");
			scanf("%d",&x);
			ptr = search(root, k);
			if(p==NULL)
				printf("Key not found!!!\n");
			else
				printf("Key found.\n");
			break;
		case 3:
			printf("Enter the key to be inserted : ");
			scanf("%d",&x);
			root = insertNode(root, x);
			break;
		case 4:
			printf("Enter the key to be deleted : ");
			scanf("%d",&x);
			root = deleteNode(root, x);
			break;
		case 5:
		    p = Min(root);
		    if(p == NULL)
		    	printf("Tree is empty!!\n");
		    else
		    	printf("Minimum key is %d\n", p->info);
		    break;
		case 6:
		    p = Max(root);
		    if(p == NULL)
		    	printf("Tree is empty!!\n");
		    else
		    	printf("Maximum key is %d\n", p->info);
		    break;
		case 7:
			preorderTraversal(root);
			break;
		case 8:
			inorderTraversal(root);
			break;
		case 9:
			postorderTraversal(root);
			break;
		case 10:
			levelorderTraversal(root);
			break;
		case 11:
			exit(1);
		default:
			printf("Wrong choice\n");
		}/*End of switch*/
	}/*End of while */
}/*End of main( )*/
struct node *getNode(int x)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->info = x;
	p->lchild = NULL;
	p->rchild = NULL;
	return p;
}
void display(struct node *p, int level)
{
	int i;
	if(p == NULL)
		return;
	display(p->rchild, level+1);
	printf("\n");

	for(i = 0; i<level; i++)
		printf("    ");
	printf("%c", p->info);

	display(p->lchild, level+1);

}///End of display()
struct node *insertNode(struct node *root, int x)
{       
	struct node *temp,*par,*p;
	
	p = root;
	par = NULL;
	
	while( p!=NULL)
	{
		par = p;
		if(x < p->info)
			p = p->lchild;	
		else if( x > p->info )
			p = p->rchild;
		else
		{
			printf("Duplicate key:%d already present in the tree\n", x);
			return root;
		}
	}
	
	temp=getNode(x);

	if(par==NULL)
		root=temp;
	else if( x < par->info )
		par->lchild = temp;
	else
		par->rchild = temp;

	return root;
}/*End of insertNode( )*/

struct node *search(struct node *p, int x)
{
	while(p!=NULL)
	{
		if(x < p->info)
			p = p->lchild; /*Move to left child*/
		else if(x > p->info)
			p = p->rchild;  /*Move to right child */ 
		else	/*x found*/
			return p;
	}
	return NULL;
}/*End of search()*/

struct node *deleteNode(struct node *root, int x)
{
	struct node *par,*p, *child, *succ, *parsucc;
	
	p = root;
	par = NULL;
	while( p!=NULL)
	{
		if( x == p->info)
			break;
		par = p;
		if(x < ptr->info)
			p = p->lchild;	
		else 
			p = p->rchild;
	}

	if(p==NULL)
	{
		printf("%d not present in the tree\n", x);
		return root;
	}
	
	///Case C: 2 children
	///Find inorder successor and its parent
	if(p->lchild!=NULL && p->rchild!=NULL)
	{
		parsucc = p;
		succ = p->rchild;
		while(succ->lchild!=NULL)
		{
			parsucc = succ;
			succ = succ->lchild;
		}
		p->info = succ->info;
		p = succ;
		par = parsucc;
	}	

	/*Case B and Case A : 1 or no child*/
	if(p->lchild != NULL) /*node to be deleted has left child */
		child = p->lchild;
	else                /*node to be deleted has right child or no child */
		child = p->rchild;

	if(par == NULL)   /*node to be deleted is root node*/
		root = child;
	else if(p == par->lchild)/*node is left child of its parent*/
		par->lchild = child;
	else       /*node is right child of its parent*/
		par->rchild=child;
	free(p);
	return root;
}
struct node *Min(struct node *p)
{
	if(p == NULL)
		return NULL;
	while(p->lchild != NULL)
			p=p->lchild;
	return p;
}/*End of Min()*/

struct node *Max(struct node *p)
{
	if(p == NULL)
		return NULL;
	while(p->rchild!=NULL)
			p=p->rchild;
	return p;
}/*End of Max()*/

void preorderTraversal(struct node *root)
{
	struct node *p = root;
	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	push_stack(p);
	while( !stack_empty() )
	{
		p = pop_stack();
		printf("%d  ",p->info);
		if(p->rchild!=NULL)
			push_stack(p->rchild);
		if(p->lchild!=NULL) 
			push_stack(p->lchild);
	}
	printf("\n");
}/*End of preorderTraversal*/

void inorderTraversal(struct node *root)
{
	struct node *p=root;
	
	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	while(1)
	{
      while(p->lchild!=NULL )
		{
			push_stack(p);
			p = p->lchild;
		}
			
		while( p->rchild==NULL )
		{
			printf("%d  ",p->info);
			if(stack_empty())
				return;
			p = pop_stack();
		}
		printf("%d  ",p->info);
		p = p->rchild;
	}
	printf("\n");
}/*End of inorderTraversal( )*/

void postorderTraversal(struct node *root)
{
	struct node *p = root;
	struct node *q;

	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	q = root;
	while(1)
	{
		while(p->lchild!=NULL)
		{
			push_stack(p);
			p=p->lchild;
		}
	
		while( p->rchild==NULL || p->rchild==q )
		{
			printf("%d  ",p->info);		
			q = p;
			if( stack_empty() )
				return;
			p = pop_stack();
		}
		push_stack(p);
		p = p->rchild;
	}
	printf("\n");
}/*End of postorderTraversal( )*/

void levelorderTraversal(struct node *root)
{
	struct node *p = root;
	
	if( p==NULL )
	{
		printf("Tree is empty\n");
		return;
	}
	
	insert_queue(p);
	
	while( !queue_empty() ) /*Loop until queue is not empty*/
	{
		p=del_queue();
		printf("%d ",p->info);
		if(p->lchild!=NULL)
			insert_queue(p->lchild);
		if(p->rchild!=NULL)
			insert_queue(p->rchild);
	} 
	printf("\n");
}/*End of levelorderTraversal( )*/

/*Functions for implementation of queue*/
void insert_queue(struct node *item)
{
	if(rear==MAX-1)
	{
		printf("Queue Overflow\n");
		return;
	}
	if(front==-1)  /*If queue is initially empty*/
		front=0;
	rear=rear+1;
	queue[rear]=item ;
}/*End of insert()*/

struct node *delete_queue()
{
	struct node *item;
	if(front==-1 || front==rear+1)
	{
		printf("Queue Underflow\n");
		return 0;
	}
	item=queue[front];
	front=front+1;
	return item;
}/*End of del_queue()*/

int queue_empty()
{
	if(front==-1 || front==rear+1)
		return 1;
	else
		return 0;
}

/*Functions for implementation of stack*/
void push_stack(struct node *item)
{
	if(top==(MAX-1))
	{
		printf("Stack Overflow\n");
		return;
	}
	top=top+1;
	stack[top]=item;
}/*End of push_stack()*/

struct node *pop_stack()
{
	struct node *item;
	if(top==-1)
	{
		printf("Stack Underflow....\n");
		exit(1);
	}
	item=stack[top];
	top=top-1;
	return item;
}/*End of pop_stack()*/

int stack_empty()
{
	if(top==-1)
		return 1;
	else
		return 0;
} /*End of stack_empty*/

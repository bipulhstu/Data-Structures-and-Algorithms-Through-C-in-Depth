/*
File Name: Recursive all operations in Binary Search Tree
Purpose  : To explain Recursive operations in Binary Search Tree
Date     : 11th November 2018
Author   : Bipul Islam
 */
#include<stdio.h>
#include<stdlib.h>

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
int height(struct node *p);
void preorderTraversal(struct node *p);
void inorderTraversal(struct node *p);
void postorderTraversal(struct node *p);

main( )
{
	struct node *root=NULL,*p;
	int choice,x;

	while(1)
	{
		printf("\n");
		printf("1.Display Tree:\n");
		printf("2.Search\n");
		printf("3.Insert a new node:\n");
		printf("4.Delete a node: \n");
		printf("5.Preorder Traversal\n");
		printf("6.Inorder Traversal\n");
		printf("7.Postorder Traversal\n");
		printf("8.Height of tree\n");
		printf("9.Find minimum: \n");
		printf("10.Find maximum: \n");
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
			ptr = search(root, x);
			if(p == NULL)
				printf("Key not found!!\n");
			else
				printf("key found.\n");
			break;
		case 3:
			printf("Enter the key to be inserted : ");
			scanf("%d",&x);
			root = insertNode(root, x);
			break;
		case 4:
			printf("Enter the key to be deleted : ");
			scanf("%d",&x);
			root = deleteNode(root,x);
			break;
		 case 5:
			preorderTraversal(root);
			break;
		 case 6:
			inorderTraversal(root);
			break;
		 case 7:
			postorderTraversal(root);
			break;
		 case 8:
			 printf("Height of tree is %d\n", height(root));
			 break;
		 case 9:
			p = Min(root);
		    if(p == NULL)
		    	printf("Tree is empty!!\n");
		    else
		    	printf("Minimum key is %d\n", p->info);
		    break;
		 case 10:
			p = Max(root);
		    if(p == NULL)
		    	printf("Tree is empty!!\n");
		    else
		    	printf("Maximum key is %d\n", p->info);
		    break;
		}/*End of switch */
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

struct node *insertNode(struct node *p, int x)
{
	if(p==NULL)	
	{
		p = getNode(x);
	}
	else if(x < p->info)	/*Insertion in left subtree*/
		p->lchild = insertNode(p->lchild, x);
	else if(x > p->info)	/*Insertion in right subtree */
		p->rchild = insertNode(p->rchild, x);  
	else
		printf("%d already present in the tree\n", x);
	return p;
}/*End of insertNode( )*/

struct node *search(struct node *p, int x)
{
	if(p == NULL)   
	{	
		printf("key not found\n");
		return NULL;
	}
	else if(x < p->info)/*search in left subtree*/	
		return search(p->lchild, x);	
	else if(skey > ptr->info)/*search in right subtree*/
		return search(p->rchild, x);
	else /*key found*/
		return ptr;
}/*End of search()*/

struct node *deleteNode(struct node *p, int x)
{
	struct node *ch, *succ;

	if( p == NULL)
	{
		printf("%d not found\n", x);
		return(p);
	}
	if( x < p->info )/*delete from left subtree*/
		p->lchild = deleteNode(p->lchild, x);
	else if( x > ptr->info )/*delete from right subtree*/
		p->rchild = deleteNode(p->rchild, x);
	else
	{
		/*key to be deleted is found*/
		if( p->lchild!=NULL  &&  p->rchild!=NULL )  /*2 children*/
		{
			succ=p->rchild;
			while(succ->lchild)
				succ=succ->lchild;
			p->info=succ->info;
			p->rchild = deleteNode(p->rchild, succ->info);
		}
		else	///1 child or no child
		{
			if(p->lchild != NULL ) /*only left child*/
				ch = p->lchild;
			else if(p->rchild != NULL) /*only right child or no child*/
				ch = p->rchild;
			free(p);
			p= ch;
		}						
	}
	return ptr; 
}/*End of deleteNode( )*/

struct node *Min(struct node *p)
{
	if(p==NULL)
		return NULL;
	else if(p->lchild==NULL)
        return p;
	else 
		return Min(p->lchild);
}/*End of min()*/

struct node *Max(struct node *p)
{
	if(p==NULL) 
		return NULL;
	else if(p->rchild==NULL)
        return p;
	else 
		return Max(p->rchild);
}/*End of max()*/

void preorderTraversal(struct node *p)
{
	if(p == NULL )	/*Base Case*/
		return;
	printf("%d  ",p->info);
	preorder(p->lchild);
	preorder(p->rchild);
}/*End of preorderTraversal( )*/

void inorderTraversal(struct node *p)
{
	if(p == NULL )/*Base Case*/
		return;
	inorder(p->lchild);
	printf("%d  ",p->info);
	inorder(p->rchild);
}/*End of inorderTraversal( )*/

void postorderTraversal(struct node *p)
{
	if(p == NULL )/*Base Case*/
		return;
	postorder(p->lchild);
	postorder(p->rchild);
	printf("%d  ",p->info);
	
}/*End of postorderTraversal( )*/

int height(struct node *p)
{
	int h_left, h_right; 

	if (p == NULL) /*Base Case*/
		return 0; 

	h_left =  height(p->lchild); 
	h_right = height(p->rchild); 

	if (h_left > h_right) 
		return 1 + h_left; 
	else 
		return 1 + h_right; 
}/*End of height()*/
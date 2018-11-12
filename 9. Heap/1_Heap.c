/*
File Name: Heap
Purpose  : To explain heap tree
Date     : 11th November 2018
Author   : Bipul Islam
 */
#include <stdio.h>
#define LARGE_VALUE 99999  ///All values in heap should be less than this value

void insert(int num, int arr[], int *p_hsize);
int deleteRoot(int arr[], int *p_hsize);
void restoreUp(int a[], int loc);
void restoreDown(int a[], int i, int hsize)
void display(int arr[],int hsize);

main( )
{
	int a[100]; ///array used to represent heap
	int n=0;  ////Number of nodes in the heap
	int choice, value;
	
	arr[0]= LARGE_VALUE;  ///Sentinel: All keys in heap should be less than this value

	while(1)
	{
		printf("1.Insert\n");
		printf("2.Delete root\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choice : ");
		scanf("%d",&choice);
		switch(choice)
		{
		 case 1:
			printf("Enter the number to be inserted : ");
			scanf("%d",&value);
			insert(value, a,&n);
			break;
		 case 2:
			if(n==0)
				printf("Heap is empty \n");
			else
			{
				value = deleteRoot(a, &n);
				printf("Maximum element is %d\n", value);
			}
			break;
		 case 3:
			display(a, n);
			break;
 		 case 4:
			printf("Enter size of the array ");
			scanf("%d",&hsize);
			printf("Enter array : "); 
			for(i=1;i<=hsize;i++)
				scanf("%d",&arr[i]);
			buildHeap(arr,hsize);
			break;
		 case 5:
			exit(1);
		 default:
			printf("Wrong choice\n");
		}
	}
}

void insert(int value, int a[], int *pn)
{
	(*pn)++;  ///Increase the heap size by 1
	a[*pn]=value;
	restoreUp(a, *pn);
}

void restoreUp(int a[], int i)
{
	int k = a[i];  
	int iparent = i/2;
	
	///while( iparent>=1 && arr[iparent] < num  ) if MAX_VAL not in a[0]
	while( a[iparent] < k  )
	{
		a[i]=arr[iparent];
		i = iparent;
		iparent = i/2;
	}
	a[i] = k; 
}

int deleteRoot(int a[], int *pn)
{
	int maxValue = a[1]; ///Save the element present at the root
	a[1] = a[*pn]; ///Place the last element in the root
	(*pn)--;   ///Decrease the heap size by 1
	restoreDown(a,1,*pn);
	return maxValue;
}

void restoreDown(int a[], int i, int hsize)
{
	int lchild=2*i, rchild=lchild+1;
	
	int num=a[i];
	
	while( rchild <= hsize)
	{
		if( num>=a[lchild] && num>=a[rchild] )  
		{
			a[i] = num;
			return;
		}
		else if(a[lchild] > a[rchild])
		{
			a[i] = a[lchild]; 
			i = lchild;
		}
		else
		{
			a[i] = a[rchild];
			i = rchild;
		}
		lchild = 2 * i;
		rchild = lchild + 1;
	}
	///If number of nodes is even	
	if(lchild == hsize && num < a[lchild] ) 
	{
		a[i]=a[lchild];
		i = lchild;
	}
	a[i]=num;
}

void display(int a[],int hsize)
{       
	int i;
	if(hsize==0)
	{
		printf("Heap is empty\n");
		return;
	}
	for(i=1;i<=hsize;i++)
		printf("%d ",a[i]);
	printf("\n");

	printf("Number of elements = %d\n",hsize);
}
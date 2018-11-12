/*
File Name: Build Heap
Purpose  : Building a heap from an array
Date     : 11th November 2018
Author   : Bipul Islam
 */
#include <stdio.h>
#define LARGE_VALUE 99999   ///All values in heap should be less than this value

void restoreUp(int a[], int loc);
void restoreDown(int a[], int i, int size);
void display(int arr[],int hsize);
void buildHeap_TopDown(int a[], int size);
void buildHeap_BottomUp(int a[], int size);

main( )
{
	int a1[] = {LARGE_VALUE, 20,33, 15, 6, 40, 60, 45, 16, 75, 10, 80, 12};
	int a2[] = {LARGE_VALUE, 20,33, 15, 6, 40, 60, 45, 16, 75, 10, 80, 12};

	int n = 12;

	buildHeap_TopDown(a1, n);
	buildHeap_BottomUp(a2, n);

	display(a1, n);
	display(a2, n);
}

void buildHeap_TopDown(int a[], int size)
{
	int i;
	for(i=2; i<=size; i++)
		restoreUp(a,i);
}

void buildHeap_BottomUp(int a[], int size)
{
	int i;
	for(i=size/2; i>=1; i--)
		restoreDown(a,i,size);
}

void restoreUp(int a[], int i)
{
	int k = a[i];  
	int iparent = i/2;
	
	///while( iparent>=1 && arr[iparent] < num  )  if MAX_VAL not in arr[0]
	while( a[iparent] < k  )
	{
		a[i]=a[iparent];
		i = iparent;
		iparent = i/2;
	}
	a[i] = k; 
}

void restoreDown(int a[], int i, int hsize )
{
	int lchild=2*i, rchild=lchild+1;
	
	int num=a[i];
	
	while( rchild <= hsize )
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
	///Ifnumber of nodes is even	
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


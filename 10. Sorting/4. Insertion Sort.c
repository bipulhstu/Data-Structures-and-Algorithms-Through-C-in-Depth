/*
File Name  : Insertion Sort.c
Purpose    : To explain Insertion Sort
Date       : 19 October 2018
Author     : Bipul Islam
*/
#include<stdio.h>
#define MAX 100
main()
{
	int a[MAX], i, j, n, temp;
	printf("Enter the number of elements:  ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter element %d:  ",i+1);
		scanf("%d", &a[i]);
	}

	for(i = 1; i<n; i++)
	{
		temp = a[i];

	    for(j = i-1; j>=0 && a[j]>temp; j--)
			a[j+1] = a[j];

		a[j+1] = temp;
	}

	printf("Sorted Array is : \n");
	for(i = 0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}




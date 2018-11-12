/*
File Name  : Bubble Sort.c
Purpose    : To explain Bubble Sort
Date       : 19 October 2018
Author     : Bipul Islam
*/
#include<stdio.h>
#define MAX 100
main()
{
	int a[MAX], i, j, n, temp, x;
	printf("Enter the number of elements:  ");
	scanf("%d", &n);

	for(i = 0; i < n; i++)
	{
		printf("Enter element %d:  ",i+1);
		scanf("%d", &a[i]);
	}

	for(x = n-2; x>=0; x--)
	{
		for(j=0; j<=n; j++)
		{
			if(a[j] > a[j+1])
				{
					temp = a[j];
					a[j] = a[j+1];
					a[j+1] = temp;
				}
		}
	}
	printf("Sorted Array is : \n");
	for(i = 0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}


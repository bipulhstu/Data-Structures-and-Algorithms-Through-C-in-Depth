/*Recursive Binary Search in an Array*/

#include<stdio.h>
#define SIZE 100
int search(int a[], int n, int searchValue);
int searchR(int a[], int first, int last, int searchValue);

main()
{
	int i, n, searchValue, a[SIZE], index;

	printf("Enter the number of elements : ");
	scanf("%d", &n);

	printf("Enter the elements (in sorted order): ");
	for(i = 0; i<n; i++)
		scanf("%d",&a[i]);

	printf("Enter the value to be searched: ");
	scanf("%d", &searchValue);

	index = search(a, n, searchValue);

	if(index == -1)
		printf("%d not found in the array\n", searchValue);
	else
		printf("%d found at index %d\n", searchValue, index);

}

int search(int a[], int n, int searchValue)
{
	return searchR(a, 0, n-1, searchValue);
}

int searchR(int a[], int first, int last, int searchValue)
{
	int mid;

	if(first > last)
		return -1;

	mid = (first+last)/2;

	if(searchValue > a[mid])
		return searchR(a, mid+1, last, searchValue);
	else if(searchValue < a[mid])
		return searchR(a, first, mid-1, searchValue);
	else
		return mid;
}



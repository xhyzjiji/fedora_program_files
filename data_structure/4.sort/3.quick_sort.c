/***********************************************************************************
@ File Name: 3.quick_sort.c
@ Author: pyf
@ Modified Time: 2014-10-08 Wednesday 00:28:59
@ File Performance: 
@ Relevant File: 
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int find_mid(int *d, int low, int high){
	int k;
	
	while(low<high){
		while(*(d+low)<*(d+high)&&low<high)
			high--;
		swap(d+low, d+high);
		while(*(d+low)<*(d+high)&&low<high)
			low++;
		swap(d+low, d+high);
	}
	return low;
}

void quicksort(int *d, int low, int high){
	int mid;

	if(low<high){
		mid = find_mid(d, low, high);
		quicksort(d, low, mid-1);
		quicksort(d, mid+1, high);
	}
}

int main(void){
	int data[] = {5,9,7,8,2,4,6,3,1};
	//int data[] = {5,4,3,2,1};
	int n = sizeof(data)/sizeof(int);
	int k;

	quicksort(data, 0, n-1);
	for(k=0; k<n; k++)
		printf("%d ", *(data+k));
	printf("\n");
	return 0;
}

/***********************************************************************************
@ File Name: 2.merge_sort.c
@ Author: pyf
@ Modified Time: 2014-10-07 Tuesday 16:47:37
@ File Performance: 
@ Relevant File: 
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void merge(int *a, int *ans, int s, int m, int t){
	int ak, bk, ansk;

	ak = s, bk = m+1, ansk = s;
	while(ak<=m&&bk<=t){
		*(ans+ansk++) = (*(a+ak)<*(a+bk))?*(a+ak++):*(a+bk++);
	}
	for(; ak<=m; ak++){
		*(ans+ansk++) = *(a+ak);
	}
	for(; bk<=t; bk++){
		*(ans+ansk++) = *(a+bk);
	}
}

void mergesort(int *a, int n, int low, int high, int *ans){
	int mid;
	int *temp;

	temp = (int*)malloc(sizeof(int)*n);

	if(low==high){
		*(ans+low) = *(a+low);
		return;
	}
	mid = (low+high)/2;
	//sort a[low...mid]
	mergesort(a, n, low, mid, temp);
	//sort a[mid+1, high]
	mergesort(a, n, mid+1, high, temp);
	//merge temp[low...mid] temp[mid+1, high] into ans[low...high]
	merge(temp, ans, low, mid, high);
	free(temp);
}

int main(void){
	int data[] = {2,4,8,5,1,6,3,10,9};
	int n = sizeof(data)/sizeof(int);
	int ansk;

	int *ans = (int*)malloc(sizeof(int)*n);
	int *temp = (int*)malloc(sizeof(int)*n);

	mergesort(data, n, 0, n-1, ans);
	for(ansk=0; ansk<n; ansk++){
		printf("%d ", *(ans+ansk));
	}
	printf("\n");

	return 0;
}

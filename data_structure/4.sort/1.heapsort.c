/***********************************************************************************
@ File Name: 1.heapsort.c
@ Author: pyf
@ Modified Time: 2014-10-06 Monday 18:39:33
@ File Performance: heapsort
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

void heapadjust(int *data, int n, int i){
	//downward adjustment
	int k;
	int max;

	for(k=i+1; k<=n/2; k++){
		//compare root,lchild,rchild
		max = (*(data+k-1)>*(data+2*k-1))?k-1:2*k-1;
		if(2*k<n)
			max = (*(data+max)>*(data+2*k))?max:2*k;
		if(max==k-1)
			continue;
		else{
			swap(data+k-1, data+max);
			heapadjust(data, n, max);
		}
	}
}
void heapsort(int n, int *data){
	int k;

	for(k=0; k<n; k++){
		swap(data, data+n-k-1);
		heapadjust(data, n-k-1, 0);
	}
}

int main(void){
	int data[]={2,4,8,5,11,9,6,7,0};
	int k;
	int n=sizeof(data)/sizeof(int);
	
	for(k=n/2; k>=0; k--){
		heapadjust(data, n, 0);  //initialize heap
	}
	heapsort(n, data);
	for(k=0; k<n; k++){
		printf("%d ", *(data+k));
	}
	printf("\n");
	return 0;
}

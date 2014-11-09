/***********************************************************************************
@ File Name: 1.multiple_array.c
@ Author: pyf
@ Modified Time: 2014-10-06 Monday 17:08:47
@ File Performance: use recursion to multiple n*n array
@ Relevant File: 
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void print_error(char *str){
	printf("%s\n", str);
	exit(0);
}

void add_array(int *d1, int *d2, int n, int* ans){
	int i,j;

	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			*(ans+i*n+j) = *(d1+i*n+j)+*(d2+i*n+j);
		}
	}
}
void multi_array(int *d1, int *d2, int n, int **result){
	int k;
	int *post_result[8];

	*result = (int*)calloc(n*n, sizeof(int));
	if(*result == NULL)
		print_error("malloc failed\n");
	if(n==1){
		**result = (*d1)*(*d2);
		return;
	}
	else{
		multi_array(d1, d2, n/2, &post_result[0]);
		multi_array(d1, d2+n/2, n/2, &post_result[1]);
		multi_array(d1+n/2, d2+n/2*n, n/2, &post_result[2]);
		multi_array(d1+n/2, d2+n/2*(n+1), n/2, &post_result[3]);
		multi_array(d1+n/2*n, d2, n/2, &post_result[4]);
		multi_array(d1+n/2*n, d2+n/2, n/2, &post_result[5]);
		multi_array(d1+n/2*(n+1), d2+n/2*n, n/2, &post_result[6]);
		multi_array(d1+n/2*(n+1), d2+n/2*(n+1), n/2, &post_result[7]);

		add_array(post_result[0], post_result[2], n/2, *result);
		add_array(post_result[1], post_result[3], n/2, *result+n/2);
		add_array(post_result[4], post_result[6], n/2, *result+n/2*n);
		add_array(post_result[5], post_result[7], n/2, *result+n/2*(n+1));

		for(k=0; k<8; k++){
			free(post_result[k]);
		}
	}
}
int main(void){
	int A[] = {1,2,3,4};
	int B[] = {1,2,1,2};
	int *C;
	int k;

	multi_array(A, B, 2, &C);
	for(k=0; k<4; k++){
		printf("%d ", C[k]);
	}
	printf("\n");
	return 0;
}

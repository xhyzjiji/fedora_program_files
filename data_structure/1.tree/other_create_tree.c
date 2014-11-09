/***********************************************************************************
@ File Name: other_create_tree.c
@ Author: pyf
@ Modified Time: Thu 28 Aug 2014 12:41:13 AM CST
@ File Performance: assumed that we already know about the result of preorder traversal, inorder traversal, postorder traversal, how we reconstruct the binary tree
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "visit_tree.h"
#include "tree_typedef.h"

//typedef struct node{
//	int id;
//	struct node* lc;
//	struct node* rc;
//}treenode;

//void preorder_traversal(treenode *T){
//	if(T==NULL)
//		return;
//	printf("%d ", T->id);
//	preorder_traversal(T->lc);
//	preorder_traversal(T->rc);
//}

void in_post_reconstruct(treenode **T, int *in, int *post, int node_num){
	int k;

	if(node_num==0){
		*T = NULL;
		return;
	}
	*T = (treenode*)malloc(sizeof(treenode));
	(*T)->id = *(post+node_num-1);
	for(k=0; k<node_num; k++){
		if(*(in+k)==*(post+node_num-1))
			break;
	}
	in_post_reconstruct(&(*T)->rc, in+k+1, post+k, node_num-k-1);
	in_post_reconstruct(&(*T)->lc, in, post, k);
}

int main(void){
	int node_num, k;
	int *in, *post;
	treenode *T;

	scanf("%d", &node_num);
	in = (int*)malloc(sizeof(int)*node_num);
	post = (int*)malloc(sizeof(int)*node_num);

	for(k=0; k<node_num; k++){
		if(k==0)
			scanf("%d", in);
		else
			scanf(" %d", in+k);
	}
	for(k=0; k<node_num; k++){
		if(k==0)
			scanf("%d", post);
		else
			scanf(" %d", post+k);
	}
	
	in_post_reconstruct(&T, in, post, node_num);
	//printf("result with preorder traversal: ");  preorder_traversal(T);  printf("\n");
	pre_visit(T);

	return 0;
}

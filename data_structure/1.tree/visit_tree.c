/***********************************************************************************
@ File Name: visit_tree.c
@ Author: pyf
@ Modified Time: Wed 27 Aug 2014 03:00:44 PM CST
@ File Performance: Implement a function in order to realize traversal of binary tree using preorder, inorder, postorder algorithm.
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "visit_tree.h"
#include "tree_typedef.h"

//typedef struct node{
//	int id;
//	struct node *lc;
//	struct node *rc;
//}treenode;

void preorder_traversal(treenode *T){
	if(T==NULL)
		return;
	printf("%d ", T->id);
	preorder_traversal(T->lc);
	preorder_traversal(T->rc);
}

void inorder_traversal(treenode *T){
	if(T==NULL)
		return;
	inorder_traversal(T->lc);
	printf("%d ", T->id);
	inorder_traversal(T->rc);
}

void postorder_traversal(treenode *T){
	if(T==NULL)
		return;
	postorder_traversal(T->lc);
	postorder_traversal(T->rc);
	printf("%d ", T->id);
}

void pre_visit(treenode *T){
	printf("result by using preorder traversal: ");
	preorder_traversal(T);
	printf("\n");
}

void in_visit(treenode *T){
	printf("result by using inorder traversal: ");
	inorder_traversal(T);
	printf("\n");
}

void post_visit(treenode *T){
	printf("result by using postorder traversal: ");
	postorder_traversal(T);
	printf("\n");
}

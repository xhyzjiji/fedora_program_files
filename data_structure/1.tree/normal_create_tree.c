/***********************************************************************************
@ File Name: nomal_create_tree.c
@ Author: pyf
@ Modified Time: Fri 29 Aug 2014 09:43:04 PM CST
@ File Performance: Creating a tree by serial in preorder, inorder or postorder
@ Relevant File: tree_typedef.h visit_tree.c
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "tree_typedef.h"
#include "visit_tree.h"

//@ Note: inorder cannot uniquely determine a binary tree!~ 
//@ Example:
//       a            a      
//      /           /   
//     b           c     
//    /          /   \        
//   c          d     b
//  /
// d 
//the inorder input of the binary trees above are the same - #d#c#b#a# 

void preorder_create_tree(treenode **T){
	char ch;
	int fuhao=1, datatemp;

	setbuf(stdin, NULL);
	ch = getchar();
	datatemp = 0;
	while(ch!='\n'&&ch!='#'){
		if(ch=='-')
			fuhao = -1;
		else
			datatemp = datatemp*10+ch-'0';
		//setbuf(stdin, NULL);
		ch = getchar();
	}
	datatemp = fuhao*datatemp;

	if(ch=='#'){
		*T = NULL;
		return;
	}
	else{
		*T = (treenode*)malloc(sizeof(treenode));
		(*T)->id = datatemp;
		//(*T)->lc = NULL;
		//(*T)->rc = NULL;
		preorder_create_tree(&(*T)->lc);
		preorder_create_tree(&(*T)->rc);
	}
}

typedef struct{
	int used;
	int max;
	treenode **top;
	treenode **head;
}treenode_stack;
#define init_stack_size 100
#define stack_size_increasement 50
void init_stack(treenode_stack **stk){
	*stk = (treenode_stack*)malloc(sizeof(treenode_stack));
	(*stk)->used = 0;
	(*stk)->max = init_stack_size;
	(*stk)->head = (treenode**)malloc(sizeof(treenode*)*init_stack_size);
	(*stk)->top = (*stk)->head;
}
void push_stack(treenode_stack *stk, treenode *node){
	stk->used ++;
	*(stk->top++) = node;
	if(stk->used==stk->max){
		stk->max += stack_size_increasement;
		stk->head = (treenode**)realloc(stk->head, sizeof(treenode*)*stk->max);
		stk->top = stk->head+stk->used;
	}
}
int pop_stack(treenode_stack *stk, treenode **node){
	if(stk->used==0){
		*node = NULL;
		return -1;
	}
	else{
		*node = *(--stk->top);
		return 0;
	}
}

void postorder_create_tree(treenode **T){
	char ch;
	int fuhao=1, datatemp;
	treenode *temp;
	treenode *lctemp, *rctemp;
	treenode_stack *mystack;

	init_stack(&mystack);
	setbuf(stdin, NULL);
	ch = getchar();
	datatemp = 0;
	while(ch!='\n'&&ch!='#'&&ch!='*'){
		if(ch=='-')
			fuhao = -1;
		else
			datatemp = datatemp*10+ch-'0';
		setbuf(stdin, NULL);
		ch = getchar();
	}
	datatemp = fuhao*datatemp;
	
	if(ch=='#')
		push_stack(mystack, NULL);
	else if(ch=='*'){
		if(pop_stack(mystack, &temp)==-1){
			printf("pop stack error\n");
			*T = NULL;
			//free(mystack->head);
			//free(mystack);
			return;
		}
		else{
			*T = temp;
			return;
		}
		free(mystack->head);
		free(mystack);
	}
	else{
		if(pop_stack(mystack, &rctemp)==-1||pop_stack(mystack, &lctemp)==-1){
			printf("pop stack error\n");
			*T = NULL;
			free(mystack->head);
			free(mystack);
			return;
		}
		else{
			temp = (treenode*)malloc(sizeof(treenode));
			temp->lc = lctemp;  temp->rc = rctemp;
			temp->id = datatemp;
			push_stack(mystack, temp);
		}
	}
}

int main(void){
	treenode *mytree1, *mytree2;

	printf("pre_create_tree:\n");
	preorder_create_tree(&mytree1);
	pre_visit(mytree1);
	printf("post_create_tree:\n");
	postorder_create_tree(&mytree2);
	post_visit(mytree2);

	return 0;
}

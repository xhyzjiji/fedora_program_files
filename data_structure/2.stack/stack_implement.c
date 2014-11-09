/***********************************************************************************
@ File Name: stack_implement.c
@ Author: pyf
@ Modified Time: Sat 30 Aug 2014 01:27:24 AM CST
@ File Performance: 
@ Relevant File: 
***********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stack_typedef.h>

//typedef int stack_datatype;
void init_stack(stack **mystk){
	*mystk = (stack*)malloc(sizeof(stack));
	(*mystk)->head = (stack_datatype*)malloc(sizeof(stack_datatype)*stack_init_size);
	(*mystk)->top = (*mystk)->head;
	(*mystk)->max = stack_init_size;
	(*mystk)->used = 0;
}

void push_stack(stack *mystk, stack_datatype d){
	*(mystk->top++) = d;
	mystk->used ++;
	if(mystk->used==mystk->max){
		mystk->max += stack_size_increasement;
		mystk->head = (stack_datatype*)realloc(sizeof(stack_datatype)*mystk->max);
		mystk->top = mystk->head+mystk->used;
	}
}

int pop_stack(stack *mystk, stack_datatype *rtn){
	if(mystk->used==0){
		return -1;
	else{
		*rtn = *(--mystk->top);
		mystk->used--;
		return 0;
	}
}

/***********************************************************************************
@ File Name: stack_implement.h
@ Author: pyf
@ Modified Time: Sat 30 Aug 2014 01:46:17 AM CST
@ File Performance: 
@ Relevant File: 
***********************************************************************************/

#ifndef _STACK_IMPLEMENT_H_
#define _STACK_IMPLEMENT_H_

#include "stack_typedef.h"

void init_stack(stack **);
void push_stack(stack *, stack_datatype);
int pop_stack(stack *, stack_datatype *);

#endif

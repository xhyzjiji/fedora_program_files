/***********************************************************************************
@ File Name: stack_typedef.h
@ Author: pyf
@ Modified Time: Sat 30 Aug 2014 01:19:04 AM CST
@ File Performance: Type definition of stack
@ Relevant File: 
***********************************************************************************/

#ifndef _STACK_TYPEDEF_H_
#define _STACK_TYPEDEF_H_

#include <stdio.h>

typedef int stack_datatype;
#define stack_size_increasement 20
#define stack_init_size 100
typedef struct stack{
	int used;
	int max;
//#if defined STACK_CHAR
//	char *top;
//	char *head;
//#elif defined STACK_LONG
//	long *top;
//	long *head;
//#else
//	int *top;
//	int *head;
//#endif
	stack_datatype *top;
	stack_datatype *head;
}stack;

#endif

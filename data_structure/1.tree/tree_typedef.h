/***********************************************************************************
@ File Name: tree_typedef.h
@ Author: pyf
@ Modified Time: Fri 29 Aug 2014 04:48:03 PM CST
@ File Performance: 
@ Relevant File: Define data type of tree
***********************************************************************************/

#ifndef _TREE_TYPEDEF_H_
#define _TREE_TYPEDEF_H_

typedef struct node{
	int id;
	struct node *lc;
	struct node *rc;
}treenode;

#endif

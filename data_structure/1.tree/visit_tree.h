/***********************************************************************************
@ File Name: visit_tree.h
@ Author: pyf
@ Modified Time: Thu 28 Aug 2014 10:19:28 PM CST
@ File Performance: 
@ Relevant File: visit_tree.c
***********************************************************************************/

#ifndef _VISIT_TREE_H_
#define _VISIT_TREE_H_

#include <stdio.h>
#include "tree_typedef.h"

void preorder_travesal(treenode *T);
void inorder_travesal(treenode *T);
void postorder_travesal(treenode *T);
void pre_visit(treenode *T);
void in_visit(treenode *T);
void post_visit(treenode *T);

#endif

#ifndef AVL_H
#define AVL_H
#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a)>(b))?(a):(b))
#define HEIGHT(node) (((node)==NULL)?0:((node)->height))
#define avl_delete(t, value) avl_del_node(t, value, NULL)
typedef enum direction{ LL, LR, RL, RR }direction;
typedef enum command{ add, search, del }command;
typedef struct avl{
	struct avl * left;
	struct avl * right;
	int value;
	int height;
}*avl;
avl avl_insert(avl t, int value);
avl avl_rotate(avl t, direction d);
avl avl_del_node(avl t, int value, avl target);
avl avl_find(avl t, int value);
#endif
#ifndef BST_H
#include <stdio.h>
#include <stdlib.h>
#define BST_H
typedef struct bst{
	int data;
	struct bst* left;
	struct bst* right;
}*bst;
typedef struct stack{
	bst tree;
	struct stack *next;
}*TreeStack;

//insert a node with the input data to the binary search tree, do nothing but return 0 if the data is  the data is already there
bst bst_insert(bst t, int data);

//creat a new empty tree node with next pointing to NULL
bst new_empty_tree();

//search the node with value data
bst bst_find(bst t, int data);

//delete a node in binary search tree, replace the node with the max node in left subtree (if exists)
bst bst_delete(bst t, int value);
#endif
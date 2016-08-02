#define _CRT_SECURE_NO_WARNINGS
#include "bst.h"
//insert a node with the input data to the binary search tree, do nothing but return 0 if the data is  the data is already there
bst bst_insert(bst t, int data){
	bst temp = t;
	if (!t){
		t = new_empty_tree();
		t->data = data;
		return t;
	}
	while (t){
		if (data == t->data)break;
		if (data < t->data)
			if (t->left)t = t->left;
			else{
				bst new_tree = new_empty_tree();
				while (!new_tree)new_tree = new_empty_tree();
				new_tree->data = data;
				t->left = new_tree;
			}
		else {
			if (t->right)t = t->right;
			else{
				bst new_tree = new_empty_tree();
				while (!new_tree)new_tree = new_empty_tree();
				new_tree->data = data;
				t->right = new_tree;
			}
		}
	}
	return temp ? temp : t;
}
//search a data in binary search tree t
//if the data exists, return a pointer to the node where the data is saved
//if the data cannot be found, return NULL
bst bst_find(bst t, int data){
	while (t){
		if (data == t->data)break;
		if (data < t->data)t = t->left;
		else t = t->right;
	}
	return t;
}
//creat a new empty tree node with next pointing to NULL
bst new_empty_tree(){
	bst new_tree = (bst)malloc(sizeof(struct bst));
	new_tree->left = NULL;
	new_tree->right = NULL;
	return new_tree;
}
//delete a node in binary search tree, replace the node with the max node in left subtree (if exists)
bst bst_delete(bst t, int value){
	bst temp;
	if (!t)return NULL;
	t = bst_find(t, value);
	//if the node has only one subtree, just remove the node and return its subtree
	if (!t->left){
		temp = t->right;
	}
	else if (!t->right){
		temp = t->left;
	}
	//merge subtrees
	else{
		bst p = NULL;
		temp = t->left;
		while (temp->right){
			p = temp;
			temp = temp->right;
		}
		if (p){
			temp->left = t->left;
			p->right = temp->left;
		}
		temp->right = t->right;
	}
	free(t);
	return temp;
}
typedef enum command{ add, search, del }command;
command trans(char op[]){
	if (op[0] == 'a' || op[0] == 'A'){
		return add;
	}
	else if (op[0] == 'd' || op[0] == 'D'){
		return del;
	}
	else{
		return search;
	}
}
//int main(){
//	command c;
//	int value;
//	char op[20];
//	bst t = NULL;
//	while (1){
//		scanf("%s %d", op, &value);
//		c = trans(op);
//		if (c == add){
//			t = bst_insert(t, value);
//		}
//		else if (c == del){
//			t = bst_delete(t, value);
//		}
//		else{
//			bst temp = bst_find(t, value);
//			printf("%p %d\n", temp, (temp==NULL)?0:temp->data);
//		}
//	}
//}
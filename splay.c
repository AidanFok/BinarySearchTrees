#define _CRT_SECURE_NO_WARNINGS
#include "splay.h"

//insert nodes by loop like normal binary search tree
//return the (new) root of the tree
splay splay_insert(splay t, int value){
	splay root = t, p = NULL;
	while (t){
		//do nothing whenthe value exists inthe tree
		if (value == t->value){
			break;
		}
		//insert the value in the left subtree
		else if (value < t->value){
			p = t;
			t = t->left;
		}
		//insert the value in the right subtree
		else{
			p = t;
			t = t->right;
		}
	}
	t = malloc(sizeof(struct splay));
	t->left = NULL;
	t->right = NULL;
	t->value = value;
	if (p){
		if (value < p->value){
			p->left = t;
		}
		else{
			p->right = t;
		}
		return root;
	}
	return t;
}

//zig-zig and zig-zag rotations
splay splay_rotate(splay t, direction d){
	splay x, p;
	//zig-zigs on left and right side
	if (d == LL){
		p = t->left;
		x = p->left;
		p->left = x->right;
		t->left = p->right;
		x->right = p;
		p->right = t;
	}
	else if (d == RR){
		p = t->right;
		x = p->right;
		p->right = x->left;
		t->right = p->left;
		x->left = p;
		p->left = t;
	}
	//zig-zags on RL and LR
	else if (d == LR){
		p = t->left;
		x = p->right;
		t->left = x->right;
		p->right = x->left;
		x->left = p;
		x->right = t;
	}
	else{
		p = t->right;
		x = p->left;
		t->right = x->left;
		p->left = x->right;
		x->left = t;
		x->right = p;
	}
	return x;
}

//a single rotation (with the root)
splay splay_single_rotate(splay t, direction d){
	splay temp;
	if (d == L){
		temp = t->left;
		t->left = temp->right;
		temp->right = t;
	}
	else{
		temp = t->right;
		t->right = temp->left;
		temp->left = t;
	}
	return temp;
}

//find operation recursively
//the searched node will be rotated to root finally
//a node with the searched value will be inserted if the node doesn't exist
//the new root will be returned
splay splay_find(splay t, int value, splay root){
	//insert the node if not exist
	splay *next;
	direction d, dl, dr;
	if (!t){
		t = splay_insert(t, value);
		return t;
	}
	if (value == t->value){
		return t;
	}
	if (value < t->value){
		next = &t->left;
		d = L;
		dl = LL;
		dr = LR;
	}
	else{
		next = &t->right;
		d = R;
		dl = RL;
		dr = RR;
	}
	*next = splay_find(*next, value, root);
	if (value = (*next)->value&&t == root){
		t = splay_single_rotate(t, d);
	}
	else if (value < (*next)->value){
		if (!(*next)->left){
			(*next)->left = splay_insert((*next)->left, value);
		}
		t = splay_rotate(t, dl);
	}
	else{
		if (!(*next)->right){
			(*next)->right = splay_insert((*next)->left, value);
		}
		t = splay_rotate(t, dr);
	}
	return t;
	/*
	if (value < t->value){
		t->left = splay_find(t->left, value, root);
		if (value == t->left->value&&t==root){
			t = splay_single_rotate(t, L);
		}
		else if (value < t->left->value){
			if (!t->left->left){
				t->left->left = splay_insert(t->left->left, value);
			}
			t = splay_rotate(t, LL);
		}
		else{
			if (!t->left->right){
				t->left->right = splay_insert(t->left->right, value);
			}
			t = splay_rotate(t, LR);
		}
		return t;
	}
	else{
		t->right = splay_find(t->right, value, root);
		if (value == t->right->value){
			t = splay_single_rotate(t, R);
		}
		else if (value < t->right->value){
			if (!t->right->left){
				t->right->left = splay_insert(t->right->left, value);
			}
			t = splay_rotate(t, RL);
		}
		else{
			if (!t->right->right){
				t->right->right = splay_insert(t->right->right, value);
			}
			t = splay_rotate(t, RR);
		}
		return t;
	}
	*/
}
//find the node and move it to the root, replace it with the min node in right subtree or max node in right subtree
splay splay_delete(splay t, int value){
	splay temp;
	if (!t)return NULL;
	t = splay_find(t, value, t);
	//if the node has only one subtree, just remove the node and return its subtree
	if (!t->left){
		temp = t->right;
	}
	else if (!t->right){
		temp = t->left;
	}
	//merge subtrees
	else{
		splay p = NULL;
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
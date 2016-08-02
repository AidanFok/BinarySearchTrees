#define _CRT_SECURE_NO_WARNINGS
#include "avl.h"

//insert new values recursively
//the root of the changed tree  will be returned
avl avl_insert(avl t, int value){
	//replace an empty node with a new one with the new value
	if (!t){
		t = malloc(sizeof(struct avl));
		if (!t)return NULL;
		t->height = 1;
		t->value = value;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	if (value < t->value){
		t->left = avl_insert(t->left, value);
		//deal with portencial LL and LR imbalance after insert a node on left side
		if (HEIGHT(t->right) - HEIGHT(t->left) == -2){
			if (value < t->left->value)
				t = avl_rotate(t, LL);
			else
				t = avl_rotate(t, LR);
		}
	}
	else if (value > t->value){
		t->right = avl_insert(t->right, value);
		//deal with portencial RL and RR imbalance after insert a node on right side
		if (HEIGHT(t->right) - HEIGHT(t->left) == 2){
			if (value < t->right->value)
				t = avl_rotate(t, RL);
			else
				t = avl_rotate(t, RR);
		}
	}
	//do NOTHING when the value to be inserted is the same with t's
	
	//updatethe height of tree t after insertion and portencial rotation
	//the height of NULL is 0
	t->height = MAX(HEIGHT(t->left), HEIGHT(t->right)) + 1;
	return t;
}

//deal with the imbalance by  for kinds of rotation and update the height of the nodes if any change is made
//the height of NULL is 0
//the root of the changed tree  will be returned
avl avl_rotate(avl t, direction d){
	avl temp;
	if (d == LL){
		temp = t->left;
		t->left = temp->right;
		temp->right = t;
		t->height = MAX(HEIGHT(t->left), HEIGHT(t->right)) + 1;
	}
	else if(d == RR){
		temp = t->right;
		t->right = temp->left;
		temp->left = t;
		t->height = MAX(HEIGHT(t->left), HEIGHT(t->right)) + 1;
	}
	else if (d == RL){
		avl r = t->right;
		temp = r->left;
		t->right = temp->left;
		r->left = temp->right;
		temp->left = t;
		temp->right = r;
		r->height = MAX(HEIGHT(r->left), HEIGHT(r->right)) + 1;
		t->height = MAX(HEIGHT(t->left), HEIGHT(t->right)) + 1;
	}
	else{
		avl l = t->left;
		temp = l->right;
		t->left = temp->right;
		l->right = temp->left;
		temp->left = l;
		temp->right = t;
		l->height = MAX(HEIGHT(l->left), HEIGHT(l->right)) + 1;
		t->height = MAX(HEIGHT(t->left), HEIGHT(t->right)) + 1;
	}
	return temp;
}

//return the address of the node with content value
//NULL will be returned if such node do not exist in the tree
avl avl_find(avl t, int value){
	while (t){
		if (value == t->value){
			return t;
		}
		else if (value < t->value){
			t = t->left;
		}
		else{
			t = t->right;
		}
	}
	return t;
}

//delete node recursively
//the root of the changed tree  will be returned
//replace the node with min node in right subtree or max node in right subtree
//and then adjust the subtree to an avl tree
//target will be NULL if not find and the address of the expecting node if found
avl avl_del_node(avl t, int value, avl target){
	//do nothing if not find
	if (!t)return NULL;
	//if the expecting node is found, set it as the target
	if (value == t->value){
		//if the target is a leaf node, just delete it
		if ((!t->left) && (!t->right)){
			free(t);
			return NULL;
		}
		//chose a node from the higher subtree to replace the target
		else if (HEIGHT(t->left) > HEIGHT(t->right)){
			t->left = avl_del_node(t->left, value, t);
		}
		else{
			t->right = avl_del_node(t->right, value, t);
		}
	}
	else if (value < t->value){
		//if there is no smaller node in this subtree
		if (!t->left){
			//if target is found, this is the min node in the right subtree
			//replace the target with it and then delete it
			if (target){
				avl temp = t->right;
				target->value = t->value;
				free(t);
				return temp;
			}
			//if the target haven'y been found, there is no such node, do nothing
			else{
				return t;
			}
		}
		t->left = avl_del_node(t->left, value, target);
	}
	else{
		//if there is no larger node in this subtree
		if (!t->right){
			//if target is found, this is the max node in the ledt subtree
			//replace the target with it and then delete it
			if (target){
				avl temp = t->left;
				target->value = t->value;
				free(t);
				return temp;
			}
			//if the target haven't been found, there is no such node, do nothing
			else{
				return t;
			}
		}
		t->right = avl_del_node(t->right, value, target);
	}
	//deal with portencial im balance recursively from downside to upside
	if (HEIGHT(t->right) - HEIGHT(t->left) == -2){
		if (HEIGHT(t->left->left) >= HEIGHT(t->left->right))
			t = avl_rotate(t, LL);
		else
			t = avl_rotate(t, LR);
	}
	else if (HEIGHT(t->right) - HEIGHT(t->left) == 2){
		if (HEIGHT(t->right->right) >= HEIGHT(t->right->left))
			t = avl_rotate(t, RR);
		else
			t = avl_rotate(t, RL);
	}
	t->height = MAX(HEIGHT(t->left), HEIGHT(t->right)) + 1;
	return t;
}
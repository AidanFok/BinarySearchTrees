#ifndef SPLAY_H
#define SPLAY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"

#define L LL
#define R RR
typedef struct splay{
	struct splay * left;
	struct splay * right;
	int value;
}*splay;
splay splay_insert(splay t, int value);
splay splay_find(splay t, int value, splay root);
splay splay_rotate(splay t, direction d);
splay splay_single_rotate(splay t, direction d);
splay splay_delete(splay t, int value);
#endif
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "avl.h"
#include "splay.h"
#include "bst.h"

void shuffle(int array[], int size);
void swap(int *a, int *b);
void bsttest_same(avl avl_tree, int N);
void bsttest_reverse(bst avl_tree, int N);
void bsttest_random(bst avl_tree, int N);
int random_1000_digits_ins[1000], random_1000_digits_del[1000];
int random_10000_digits_ins[10000], random_10000_digits_del[10000];
int random_5000_digits_ins[5000], random_5000_digits_del[5000];


int main(){
	long time_begin, time_end, time_cost;
	int i;
	avl avl_tree = NULL;
	splay splay_tree = NULL;
	//generate random digit lists
	for (i = 0; i < 10000; i++){
		random_10000_digits_ins[i] = i;
		random_10000_digits_del[i] = i;
	}
	shuffle(random_10000_digits_ins, 10000);
	shuffle(random_10000_digits_del, 10000);
	for (i = 0; i < 1000; i++){
		random_1000_digits_ins[i] = i;
		random_1000_digits_del[i] = i;
	}
	shuffle(random_1000_digits_ins, 1000);
	shuffle(random_1000_digits_del, 1000);
	time_begin = clock();
	for (i = 0; i < 1000; i++){
		avl_tree = avl_insert(avl_tree, i);
	}
	for (i = 0; i < 1000; i++){
		avl_tree = avl_delete(avl_tree, i);
	}
	//test on all kinds, avl tree first, then splay tree
	//from both in increase order to delete in reverse and all randomized
	//size in 1000 ones first and then size in 10000 ones
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("avl 1000 values inserted and deleted by increase in %lf seconds\n", ((double)(time_cost)) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 10000; i++){
		avl_tree = avl_insert(avl_tree, i);
	}
	for (i = 0; i < 10000; i++){
		avl_tree = avl_delete(avl_tree, i);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("avl 10000 values inserted and deleted by increase in %lf seconds\n", ((double)time_cost) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 1000; i++){
		avl_tree = avl_insert(avl_tree, i);
	}
	for (i = 999; i >= 0; i--){
		avl_tree = avl_delete(avl_tree, i);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("avl 1000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 10000; i++){
		avl_tree = avl_insert(avl_tree, i);
	}
	for (i = 9999; i  >= 0; i--){
		avl_tree = avl_delete(avl_tree, i);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("avl 10000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 1000; i++){
		avl_tree = avl_insert(avl_tree, random_1000_digits_ins[i]);
	}
	for (i = 999; i >= 0; i--){
		avl_tree = avl_delete(avl_tree, random_1000_digits_del[i]);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("avl 1000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
	
	time_begin = clock();
	for (i = 0; i < 10000; i++){
		avl_tree = avl_insert(avl_tree, random_10000_digits_ins[i]);
	}
	for (i = 9999; i >= 0; i--){
		avl_tree = avl_delete(avl_tree, random_10000_digits_del[i]);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("avl 10000 values inserted and deleted in randomized order in %lf seconds\n\n", ((double)time_cost) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 1000; i++){
		splay_tree = splay_insert(splay_tree, i);
	}
	for (i = 0; i < 1000; i++){
		splay_tree = splay_delete(splay_tree, i);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("splay 1000 values inserted and deleted by increase in %lf seconds\n", ((double)(time_cost)) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 10000; i++){
		splay_tree = splay_insert(splay_tree, i);
	}
	for (i = 0; i < 10000; i++){
		splay_tree = splay_delete(splay_tree, i);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("splay 10000 values inserted and deleted by increase in %lf seconds\n", ((double)time_cost) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 1000; i++){
		splay_tree = splay_insert(splay_tree, i);
	}
	for (i = 999; i >= 0; i--){
		splay_tree = splay_delete(splay_tree, i);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("splay 1000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 10000; i++){
		splay_tree = splay_insert(splay_tree, i);
	}
	for (i = 9999; i >= 0; i--){
		splay_tree = splay_delete(splay_tree, i);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("splay 10000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);

	time_begin = clock();
	for (i = 0; i < 1000; i++){
		splay_tree = splay_insert(splay_tree, random_1000_digits_ins[i]);
	}
	for (i = 999; i >= 0; i--){
		splay_tree = splay_delete(splay_tree, random_1000_digits_del[i]);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("splay 1000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
	time_begin = clock();
	for (i = 0; i < 10000; i++){
		splay_tree = splay_insert(splay_tree, random_10000_digits_ins[i]);
	}
	for (i = 9999; i >= 0; i--){
		splay_tree = splay_delete(splay_tree, random_10000_digits_del[i]);
	}
	time_end = clock();
	time_cost = time_end - time_begin;
	printf("splay 10000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
	system("pause");
}


//int main(){
//	long time_begin, time_end, time_cost;
//	int i;
//	avl avl_tree = NULL;
//	splay splay_tree = NULL;
//	//generate random digit lists
//	for (i = 0; i < 5000; i++){
//		random_5000_digits_ins[i] = i;
//		random_5000_digits_del[i] = i;
//	}
//	shuffle(random_5000_digits_ins, 5000);
//	shuffle(random_5000_digits_del, 5000);
//	for (i = 0; i < 1000; i++){
//		random_1000_digits_ins[i] = i;
//		random_1000_digits_del[i] = i;
//	}
//	shuffle(random_1000_digits_ins, 1000);
//	shuffle(random_1000_digits_del, 1000);
//	time_begin = clock();
//	for (i = 0; i < 1000; i++){
//		avl_tree = avl_insert(avl_tree, i);
//	}
//	for (i = 0; i < 1000; i++){
//		avl_tree = avl_delete(avl_tree, i);
//	}
//	//test on all kinds, avl tree first, then splay tree
//	//from both in increase order to delete in reverse and all randomized
//	//size in 1000 ones first and then size in 5000 ones
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("avl 1000 values inserted and deleted by increase in %lf seconds\n", ((double)(time_cost)) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 5000; i++){
//		avl_tree = avl_insert(avl_tree, i);
//	}
//	for (i = 0; i < 5000; i++){
//		avl_tree = avl_delete(avl_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("avl 5000 values inserted and deleted by increase in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 1000; i++){
//		avl_tree = avl_insert(avl_tree, i);
//	}
//	for (i = 999; i >= 0; i--){
//		avl_tree = avl_delete(avl_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("avl 1000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 5000; i++){
//		avl_tree = avl_insert(avl_tree, i);
//	}
//	for (i = 4999; i >= 0; i--){
//		avl_tree = avl_delete(avl_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("avl 5000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 1000; i++){
//		avl_tree = avl_insert(avl_tree, random_1000_digits_ins[i]);
//	}
//	for (i = 999; i >= 0; i--){
//		avl_tree = avl_delete(avl_tree, random_1000_digits_del[i]);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("avl 1000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 5000; i++){
//		avl_tree = avl_insert(avl_tree, random_5000_digits_ins[i]);
//	}
//	for (i = 4999; i >= 0; i--){
//		avl_tree = avl_delete(avl_tree, random_5000_digits_del[i]);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("avl 5000 values inserted and deleted in randomized order in %lf seconds\n\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 1000; i++){
//		splay_tree = splay_insert(splay_tree, i);
//	}
//	for (i = 0; i < 1000; i++){
//		splay_tree = splay_delete(splay_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("splay 1000 values inserted and deleted by increase in %lf seconds\n", ((double)(time_cost)) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 5000; i++){
//		splay_tree = splay_insert(splay_tree, i);
//	}
//	for (i = 0; i < 5000; i++){
//		splay_tree = splay_delete(splay_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("splay 5000 values inserted and deleted by increase in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 1000; i++){
//		splay_tree = splay_insert(splay_tree, i);
//	}
//	for (i = 999; i >= 0; i--){
//		splay_tree = splay_delete(splay_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("splay 1000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 5000; i++){
//		splay_tree = splay_insert(splay_tree, i);
//	}
//	for (i = 4999; i >= 0; i--){
//		splay_tree = splay_delete(splay_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("splay 5000 values inserted by increase and deleted in reverse in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 1000; i++){
//		splay_tree = splay_insert(splay_tree, random_1000_digits_ins[i]);
//	}
//	for (i = 999; i >= 0; i--){
//		splay_tree = splay_delete(splay_tree, random_1000_digits_del[i]);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("splay 1000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//	time_begin = clock();
//	for (i = 0; i < 5000; i++){
//		splay_tree = splay_insert(splay_tree, random_5000_digits_ins[i]);
//	}
//	for (i = 4999; i >= 0; i--){
//		splay_tree = splay_delete(splay_tree, random_5000_digits_del[i]);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("splay 5000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//	system("pause");
//}


void shuffle(int array[], int size){
	int i;
	srand(time(0));
	for (i = 0; i < size; i++){
		swap(&array[i], &array[rand() % size]);
	}
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;	
}


//int main()
//{
//	bst avltree=NULL;
//	long x;
//	//bsttest_same(avltree, 1000);
//	//bsttest_same(avltree, 5000);
//	//bsttest_same(avltree, 10000);
//	bsttest_reverse(avltree, 1000);
//	bsttest_reverse(avltree, 5000);
//	bsttest_reverse(avltree,  10000);
//	//bsttest_random(avltree, 0);
//	system("pause");
//}

//void bsttest_same(bst avl_tree, int N)
//{
//	avl_tree = NULL;
//	int i;
//	long time_begin, time_end, time_cost;
//	time_begin = clock();
//	for (i = 0; i < N; i++){
//		avl_tree = bst_insert(avl_tree, i);
//	}
//	for (i = 0; i < N; i++){
//		avl_tree = bst_delete(avl_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("bst %d values inserted and deleted by increase in %lf seconds\n", N, ((double)(time_cost)) / CLK_TCK);
//
//}

//void bsttest_reverse(bst avl_tree, int N)
//{
//	avl_tree = NULL;
//	int i;
//	long time_begin, time_end, time_cost;
//	time_begin = clock();
//	for (i = 0; i < N; i++){
//		avl_tree = bst_insert(avl_tree, i);
//	}
//	for (i = N - 1; i >= 0; i--){
//		avl_tree = bst_delete(avl_tree, i);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("bst %d values inserted and deleted by reverse in %lf seconds\n", N, ((double)(time_cost)) / CLK_TCK);
//
//}

//void bsttest_random(bst avl_tree, int N)
//{
//	avl_tree = NULL;
//	int i;
//	long time_begin, time_end, time_cost;
//
//
//	//generate random digit lists
//	for (i = 0; i < 10000; i++){
//		random_10000_digits_ins[i] = i;
//		random_10000_digits_del[i] = i;
//	}
//	shuffle(random_10000_digits_ins, 10000);
//	shuffle(random_10000_digits_del, 10000);
//	for (i = 0; i < 1000; i++){
//		random_1000_digits_ins[i] = i;
//		random_1000_digits_del[i] = i;
//	}
//	shuffle(random_1000_digits_ins, 1000);
//	shuffle(random_1000_digits_del, 1000);
//
//	for (i = 0; i < 5000; i++){
//		random_5000_digits_ins[i] = i;
//		random_5000_digits_del[i] = i;
//	}
//	shuffle(random_5000_digits_ins, 5000);
//	shuffle(random_5000_digits_del, 5000);
//
//	time_begin = clock();
//	for (i = 0; i < 1000; i++){
//		avl_tree = bst_insert(avl_tree, random_1000_digits_ins[i]);
//	}
//	for (i = 999; i >= 0; i--){
//		avl_tree = bst_delete(avl_tree, random_1000_digits_del[i]);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("bst 1000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 5000; i++){
//		avl_tree = bst_insert(avl_tree, random_5000_digits_ins[i]);
//	}
//	for (i = 4999; i >= 0; i--){
//		avl_tree = bst_delete(avl_tree, random_5000_digits_del[i]);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("bst 5000 values inserted and deleted in randomized order in %lf seconds\n", ((double)time_cost) / CLK_TCK);
//
//	time_begin = clock();
//	for (i = 0; i < 10000; i++){
//		avl_tree = bst_insert(avl_tree, random_10000_digits_ins[i]);
//	}
//	for (i = 9999; i >= 0; i--){
//		avl_tree = bst_delete(avl_tree, random_10000_digits_del[i]);
//	}
//	time_end = clock();
//	time_cost = time_end - time_begin;
//	printf("bst 10000 values inserted and deleted in randomized order in %lf seconds\n\n", ((double)time_cost) / CLK_TCK);
//
//
//
//}


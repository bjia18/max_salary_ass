#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}
#define LEN ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)+1

extern double h_max;
void naive(int *a,int n);
void stress_test(int n, int m);
void simple_test(int n, int m);
int is_better(const void *a, const void *b);
double combine_max(int *a, int n);
void print_array(int *arr, int size);
void heap_permutation(int a[], int size, int n) ;

#endif
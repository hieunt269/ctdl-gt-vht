#ifndef basic_sort_h
#define basic_sort_h

#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } bool;

void print_array(int a[], const int n, const int curr);
void swap(int a[], const int i, const int j);
void bubble_sort(int a[], const int n);
void bubble_sort_op(int a[], const int n);
void insertion_sort(int a[], const int n);
	void selection_sort(int a[], const int n);
#endif
//
//  heap.h
//  HeapSort
//
//  Created by TungDT on 7/24/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
void print_array(int *a, int n);
void heapify(int *arr, int n, int i);
void heap_sort(int *arr, int n);

#endif /* heap_h */

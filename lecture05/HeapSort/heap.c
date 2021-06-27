//
//  heap.c
//  HeapSort
//
//  Created by TungDT on 7/24/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "heap.h"


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Heapify a subtree at node i
void heapify(int *arr, int n, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int imax = i;
    
    if (left < n && arr[left] > arr[imax]) imax = left;
    if (right < n && arr[right] > arr[imax]) imax = right;
    
    if (imax != i)
    {
        swap(&arr[i], &arr[imax]);
        heapify(arr, n, imax);
    }
}
void heap_sort(int *arr, int n)
{
    // build a heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // heap sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

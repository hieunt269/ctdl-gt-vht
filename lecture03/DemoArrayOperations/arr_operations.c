//
//  arr_operations.c
//  DemoArrayOperations
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "arr_operations.h"
#include <stdio.h>

void delete_array(int a[],      // array
                  const int n,  // size of array
                  int *curr,    // current position
                  const int i)  // index to delete
{
    if (*curr >= n || *curr < 0) return;
    if (i > *curr || i < 0) return;
    
    for (int j = i; j < *curr; j++)
    {
        a[j] = a[j+1];
    }
    
    *curr = *curr - 1;
}

void print_array(int a[], const int n, const int curr)
{
    if (curr >= n) return;
    for (int i = 0; i <= curr; i++) printf("%d ", a[i]);
    printf("\n");
}

void swap(int a[], const int i, const int j)
{
    int temp = a[i]; a[i] = a[j]; a[j] = temp;
}

void reverse(int a[],       // array
             const int n)
{
    int m = n / 2;
    for (int i = 0; i < m; i++)
    {
        swap(a, i, n - i - 1);
    }
}

void re_arrange(int a[], const int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        // find 1st odd number
        while (a[i] % 2 == 1) i++;
        while (a[j] % 2 == 0) j--;
        
        if (i < j) swap(a, i, j);
    }
}

void rotate_left(int a[], const int n, const int k)
{
    int temp[k];
    // copy
    for (int i = 0; i < k; i++) temp[i] = a[i];
    // rotate
    for (int i = 0; i < n - k; i++) a[i] = a[i + k];
    // copy back
    for (int i = n - k; i < n; i++) a[i] = temp[i - (n-k)];
}

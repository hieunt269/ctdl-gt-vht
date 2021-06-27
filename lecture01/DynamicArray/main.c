//
//  main.c
//  L01-P02-DynamicArray
//
//  Created by TungDT on 7/2/20.
//  Copyright © 2020 macOne. All rights reserved.
//

void print(int *a, const int n);
void copy(int *a, int *b, const int source, const int destination, const int n);

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[5] = {1, 2, 3, 4, 5}; // a is fixed with always 5 elements
    print(a, 5);
    // allocate an array in heap with 5 elements
    int *b = (int*) malloc(5 * sizeof(int));
    // copy array a from stack to the array in heap
    copy(a, b, 0, 0, 5);
    print(b, 5);
    // reallocate the array in heap to 10 elements
    b = (int*) realloc(b, 10 * sizeof(int));
    // copy array a from stack to the new 5 elements
    copy(a, b, 0, 5, 5);
    print(b, 10);
    free(b);
    return 0;
}

void print(int *a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d", a[i]);
    }
    printf("\n");
}

void copy(int *a, int *b, const int source, const int destination, const int n)
{
    for (int i = source; i < source + n; i++)
    {
        b[destination + i] = a[source + i];
    }
}

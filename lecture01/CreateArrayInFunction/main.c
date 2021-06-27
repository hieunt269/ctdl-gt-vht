//
//  main.c
//  L01-P03-CreateArrayInFunction
//
//  Created by TungDT on 7/2/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* create_static_array(const int n);
int* create_dynamic_array(const int n);
void print(int *a, const int n);

int main()
{
    int *a = create_static_array(5);
    print(a, 5);
    
    a = create_dynamic_array(5);
    print(a, 5);
    
    free(a);
    return 0;
}

int* create_static_array(const int n)
{
    int a[n];
    for (int i = 0; i < n; i++) a[i] = i;
    return a;
}

int* create_dynamic_array(const int n)
{
    int *a = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) a[i] = i;
    return a;
}

void print(int *a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%3d", a[i]);
    }
    printf("\n");
}


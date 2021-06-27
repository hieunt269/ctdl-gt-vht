//
//  main.c
//  L01-P06-PassDynamicArray
//
//  Created by TungDT on 7/3/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void create_array(int **p, const int n);
//void create_array(int *p, const int n);
void print_array(int *a, const int n);
void double_array(int *a, const int n);

int main()
{
    //int *p = (int*) malloc(5 * sizeof(int));
    int *p;
    create_array(&p, 5);
    print_array(p, 5);
    double_array(p, 5);
    print_array(p, 10);
    free(p);
    return 0;
}

void create_array(int **p, const int n)
{
    printf("Enter array: ");
    *p = (int*) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &(*p)[i]);
}
//void create_array(int *p, const int n)
//{
//    printf("Enter array: ");
//    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
//}
void print_array(int *a, const int n)
{
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

void double_array(int *a, const int n)
{
    a = realloc(a, n * 2);
    for (int i = n; i < 2 * n; i++) a[i] = 0;
}

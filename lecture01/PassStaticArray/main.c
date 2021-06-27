//
//  main.c
//  L01-P05-PassStaticArray
//
//  Created by TungDT on 7/3/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
void print_array(int a[], const int n);
void enter_array(int a[], const int n);

int main(int argc, const char * argv[]) {
    int a[5];
    enter_array(a, 5);
    print_array(a, 5);
    return 0;
}
void print_array(int a[], const int n)
{
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
}

void enter_array(int a[], const int n)
{
    printf("Enter %d element: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
}


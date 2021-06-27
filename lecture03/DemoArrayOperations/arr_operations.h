//
//  arr_operations.h
//  DemoArrayOperations
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef arr_operations_h
#define arr_operations_h

void delete_array(int a[],      // array
                  const int n,  // size of array
                  int *curr,    // current position
                  const int i);  // index to delete

void insert_array(int a[],          // array
                  const int n,      // size of array
                  int *curr,        // current position
                  const int i,      // index to insert
                  const int value); // value to insert

void reverse(int a[],       // array
             const int n);  // size of array

void print_array(int a[], const int n, const int curr);

void swap(int a[], const int i, const int j);

void re_arrange(int a[], const int n);

void rotate_left(int a[], const int n, const int k);

#endif /* arr_operations_h */

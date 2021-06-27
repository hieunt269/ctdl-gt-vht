//
//  main.c
//  HeapSort
//
//  Created by TungDT on 7/24/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "heap.h"

int main(int argc, const char * argv[])
{
    int a[] = {5, 3, 6, 4, 1, 7, 9, 8, 10, 12, -2, -5, -3, 2, 11};
    heap_sort(a, 15);
    print_array(a, 15);
    return 0;
}

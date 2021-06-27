//
//  main.c
//  DemoArrayOperations
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "arr_operations.h"

int main(int argc, const char * argv[]) {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int curr = 5;
    
    printf("Delete item in array\n");
    delete_array(a, 10, &curr, 2);
    print_array(a, 10, curr);
    
    printf("Reverse array\n");
    int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverse(b, 10);
    print_array(b, 10, 9);
    
    printf("Re-arrange array\n");
    re_arrange(b, 10);
    print_array(b, 10, 9);
    
    printf("Rotate-left 2 elements\n");
    rotate_left(b, 10, 2);
    print_array(b, 10, 9);
    
    return 0;
}

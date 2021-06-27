//
//  main.c
//  BST
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>

#include "bst.h"

int main(int argc, const char * argv[])
{
    int a[7] = {4, 9, 12, 8, 3, 10, 7};
    node* bst = create_bst(a, 7);
    in_order(bst);
    
    printf("\n");
    
    int key;
    printf("Enter key to search: "); scanf("%d", &key);
    if (search_bst(bst, key)) printf(" ... found!\n");
    else printf(" ... not found\n");
    
    
    printf("Enter key to delete: "); scanf("%d", &key);
    delete_tree_node(bst, key);
    
    in_order(bst);
    
    printf("\n");
    clear_tree(&bst);
    
    return 0;
}

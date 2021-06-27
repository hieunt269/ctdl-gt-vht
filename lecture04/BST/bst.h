//
//  bst.h
//  BST
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef bst_h
#define bst_h

#include <stdlib.h>
#include <stdio.h>

typedef struct str_node node;

struct str_node
{
    int key;
    node *left;
    node *right;
};

node* create_node(const int key);
void insert_node(node **root, const int key);
void insert_child(node **child, node* n);
node* create_bst(int *a, const int n);
node* search_bst(node *root, const int key);
void pre_order(node *root);

#endif /* bst_h */

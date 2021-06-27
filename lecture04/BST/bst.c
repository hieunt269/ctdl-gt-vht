//
//  bst.c
//  BST
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "bst.h"

node* create_node(const int key)
{
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

void insert_child(node **child, node* n)
{
    if ((*child) == NULL) *child = n;
    else insert_node(child, n->key);
}
void insert_node(node **root, const int key)
{
    node *n = create_node(key);
    
    if (*root == NULL) *root = n;
    else
    {
        if ((*root)->key == key) return;
        if ((*root)->key <  key) insert_child(&(*root)->right, n);
        else                     insert_child(&(*root)->left,  n);
    }
        
}


node* create_bst(int *a, const int n)
{
    node *root = NULL;
    
    for (int i = 0; i < n; i++)
    {
        insert_node(&root, a[i]);
    }
    return root;
}
node* search_bst(node *root, const int key)
{
    // TODO
}
void pre_order(node *root)
{
    // TODO
}

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
void delete_node(node **n);
void clear_tree(node **root);
void insert_node(node **root, const int key);
void insert_child(node **child, node* n);
node* create_bst(int *a, const int n);
node* search_bst(node *root, const int key);
void in_order(node *root);

// delete a node with key, return the root
node* delete_tree_node(node* root, const int key);
node* find_min(node* root);
void move_to_child(node **root, node *child);
#endif /* bst_h */

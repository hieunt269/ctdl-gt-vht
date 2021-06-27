//
//  avl.h
//  AVL
//
//  Created by TungDT on 7/19/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef avl_h
#define avl_h

#include <stdlib.h>
#include <stdio.h>

typedef struct str_node node;
struct str_node
{
    int key;
    node* left;
    node* right;
    int height;
};

node* create_node(const int key);
void clear_avl(node** root);
void in_order(node *root);
int max(const int a, const int b);

int get_height(node* n);
int left_height(node* n);
int right_height(node* n);

node* l_rotation(node* n);
node* r_rotation(node* n);
node* lr_rotation(node* n);
node* rl_rotation(node* n);

int balance_factor(node* n);
node* rebalance_rightsubtree(node* n);
node* rebalance_leftsubtree(node* n);

node* find_min(node* root);

node* insert_node(node* root, const int key);
node* delete_node(node* root, const int key);
#endif /* avl_h */

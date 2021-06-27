//
//  tree.c
//  TreeTraversal
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "tree.h"

tree_node* create_node(const char data)
{
    tree_node* n = (tree_node*) malloc(sizeof(tree_node));
    n->data = data;
    
    for (int i = 0; i < MAX_CHILDREN; i++)
        n->children[i] = NULL;
    
    return n;
}

void clear_tree(tree_node **root)
{
    // TODO
}
void in_order(tree_node * const root)
{
    if (root == NULL) return;
    
    in_order(root->children[0]);
    printf("%c ", root->data);
    for (int i = 1; i < MAX_CHILDREN; i++)
        in_order(root->children[i]);
}

void pre_order(tree_node * const root)
{
    // TODO
}

void post_order(tree_node * const root)
{
    // TODO
}

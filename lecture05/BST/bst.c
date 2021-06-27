//
//  bst.c
//  BST
//
//  Created by TungDT on 7/17/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "bst.h"

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

node* create_node(const int key)
{
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->left = n->right = NULL;
    return n;
}

void delete_node(node **n)
{
    free(*n);
    *n = NULL;
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
    if (root == NULL) return NULL;
    else
    {
        if (root->key == key) return root;
        else if (root->key < key)
            return search_bst(root->right, key);
        else
            return search_bst(root->left, key);
    }
}
void in_order(node *root)
{
    if (root == NULL) return;
    in_order(root->left);
    printf("%d ", root->key);
    in_order(root->right);
}

node* delete_tree_node(node* root, const int key)
{
    if (root == NULL) return NULL;
    
    if (root->key < key)
        root->right = delete_tree_node(root->right, key);
    else if (root->key > key)
        root->left = delete_tree_node(root->left, key);
    else
    {
        if (root->left && root->right)
        {
            node *min_right = find_min(root->right);
            root->key = min_right->key;
            root->right = delete_tree_node(root->right, root->key);
        }
        else if (root->left) move_to_child(&root, root->left);
        else if (root->right) move_to_child(&root, root->right);
        else delete_node(&root);
    }
    return root;
}

node* find_min(node* root)
{
    if (root->left == NULL) return root;
    return find_min(root->left);
}

void move_to_child(node **root, node *child)
{
    node *temp = *root;
    *root = child;
    free(temp);
}
void clear_tree(node **root)
{
    if (*root == NULL) return;
    clear_tree(&(*root)->left);
    clear_tree(&(*root)->right);
    delete_node(root);
}

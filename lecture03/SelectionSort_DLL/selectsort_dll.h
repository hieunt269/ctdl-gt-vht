#ifndef selectsort_dll_h
#define selectsort_dll_h

#include <stdlib.h>
#include <stdio.h>

typedef struct str_node* link;

struct str_node
{
    int data;
    link prev;
    link next;
};

typedef struct str_node node;

node* create_node(const int data);
void add_head(node **head, node **tail, const int data);
void print_list(node *head);
void clear_list(node **head, node **tail);

void swap(node *head, node *i, node *j);
void selection_sort(node *head, node *tail);

#endif
//
//  dll.h
//  DemoDoubleLinkedList
//
//  Created by TungDT on 7/14/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef dll_h
#define dll_h

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
void add_tail(node **head, node **tail, const int data);
void print_list(node *head);
void clear_list(node **head, node **tail);

void remove_head(node **head, node **tail);
void remove_tail(node **head, node **tail);

#endif /* dll_h */

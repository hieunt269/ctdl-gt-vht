//
//  cll.h
//  DemoCircularLinkedList
//
//  Created by TungDT on 7/14/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#ifndef cll_h
#define cll_h

#include <stdlib.h>
#include <stdio.h>

typedef struct str_node * link;

struct str_node
{
    int data;
    link next;
};

typedef struct str_node node;

void add_head(node **head, const int data);
node* create_node(const int data);
void print_list(node *head);
void clear_list(node **head);


#endif /* cll_h */

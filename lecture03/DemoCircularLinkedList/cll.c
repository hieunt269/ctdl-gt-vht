//
//  cll.c
//  DemoCircularLinkedList
//
//  Created by TungDT on 7/14/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "cll.h"

node* create_node(const int data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    
    return n;
}
void add_head(node **head, const int data)
{
    node *n = create_node(data);
    if (*head == NULL)
    {
        *head = n;
        n->next = n;
    }
    else
    {
        node *tail = *head;
        while (tail->next != *head) tail = tail->next;
        n->next = *head;
        tail->next = n;
        *head = n;
    }
}
void print_list(node *head)
{
    printf("**->");
    node* n = head;
    if (head->next == head)
    {
        printf("[%d]->**\n", head->data);
        return;
    }
    while (n->next != head)
    {
        printf("[%d]->", n->data);
        n = n->next;
    }
    printf("[%d]->", n->data); // print tail
    
    printf("**\n");
}
void clear_list(node **head)
{
    if (*head == NULL) return;
    node *n = (*head)->next;
    while (n != *head)
    {
        node *p = n;
        n = n->next;
        free(p);
    }
    free(n);
    *head = NULL;
}

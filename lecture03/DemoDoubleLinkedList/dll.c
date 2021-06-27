//
//  dll.c
//  DemoDoubleLinkedList
//
//  Created by TungDT on 7/14/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "dll.h"

node* create_node(const int data)
{
    node *n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = n->prev = NULL;
    
    return n;
}
void add_head(node **head, node **tail, const int data)
{
    node *n = create_node(data);
    
    if (*head == NULL) *head = *tail = n;
    else
    {
        n->next = *head;
        (*head)->prev = n;
        *head = n;
    }
}
void add_tail(node **head, node **tail, const int data)
{
    node *n = create_node(data);
    
    if (*head == NULL) *head = *tail = n;
    else
    {
        (*tail)->next = n;
        n->prev = *tail;
        *tail = n;
    }
}
void print_list(node *head)
{
    node *p = head;
    if (head == NULL) printf("Empty list!\n");
    else
    {
        printf("[]<=");
        while (p != NULL)
        {
            printf("[%d]<=>", p->data);
            p = p->next;
        }
        printf("[]\n");
    }
}
void clear_list(node **head, node **tail)
{
    node *p = *head;
    while (p != NULL)
    {
        node *q = p;
        p = p->next;
        free(q);
    }
    *head = *tail = NULL;
}

void remove_head(node **head, node **tail)
{
    if (*head == NULL) printf("Empty list!\n");
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        node *p = *head;
        *head = p->next;
        (*head)->prev = NULL;
        free(p);
    }
        
}

void remove_tail(node **head, node **tail)
{
    if (*tail == NULL) printf("Empty list!\n");
    if ((*tail)->prev == NULL)
    {
        free(*tail);
        *tail = *head = NULL;
    }
    else
    {
        node *p = *tail;
        *tail = p->prev;
        (*tail)->next = NULL;
        free(p);
    }    
}

//
//  linked_list.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "linked_list.h"
#include <stdlib.h>
#include <stdio.h>

node* create_node(const int data)
{
    node* n = (node*) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    
    return n;
}
int is_empty(node* const head)
{
    return head == NULL;
}

void add_head(node **head, const int data)
{
    node* n = create_node(data);
    
    if (is_empty(*head))
    {
        *head = n;
    }
    else
    {
        n->next = *head;
        *head = n;
    }
}

void print_list(node* const head)
{
    if (is_empty(head)) printf("Empty list!\n");
    else
    {
        node *p = head;
        while (p != NULL)
        {
            printf("[%d]->", p->data);
            p = p->next;
        }
        printf("[]\n");
    }
}

void clear_list(node **head)
{
    if (is_empty(*head)) return;
    while (*head != NULL)
    {
        node *p = *head;
        *head = p->next;
        free(p);
    }
}

void clear_head(node **head)
{
    if (is_empty(*head)) return;
    else
    {
        node *p = *head;
        *head = p->next;
        free(p);
    }
}

void add_last(node **head, const int data)
{
    node *n = create_node(data);

    if (is_empty(*head))
    {
        *head = n;
    }
    else
    {
        node *p = *head;

        while(p->next != NULL) p = p->next;
        p->next = n;
    }
}

node* get_last(node* const head)
{
    node *p = head;

    while(p->next != NULL) p = p->next;
    return p;
}

node* find(node* const head, const int data)
{
    node *p = head;

    while(p != NULL)
    {
        if (p->data == data)
        {
            // p->next = NULL;
            return p;
        }
        p = p->next;
    }

    printf("No node have that data in list!\n");
    return 0;
}

void clear_last(node **head)
{
    if (is_empty(*head)) return;
    if ((*head)->next == NULL)
    {
        free(*head);
    }
    else
    {
        node *p = *head;
        while(p->next->next != NULL)
        {
            p = p->next;
        }
        free(p->next);
        p->next = NULL;
    }

}




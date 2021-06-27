#include "selectsort_dll.h"

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

void swap(node *head, node *i, node *j)
{
    int temp = i->data;
    i->data = j->data;
    j->data = temp;
}

void selection_sort(node *head, node *tail)
{
    node *i = head;

    for (; i != tail; i = i->next)
    {
        node *imin = i;
        node *j = i->next;

        for (; j != NULL; j = j->next)
        {
            if (j->data < imin->data) imin = j;
        }
        
        swap(head, i, imin);
    }
}
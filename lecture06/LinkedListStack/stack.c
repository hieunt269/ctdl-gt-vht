//
//  stack.c
//  LinkedListStack
//
//  Created by TungDT on 7/26/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "stack.h"

move* create_move(position pos)
{
    move* m = (move*) malloc(sizeof(move));
    m->pos = pos;
    m->next = NULL;
    return m;
}
int is_empty(move* stack)
{
    return stack == NULL;
}
void push(move** stack, position pos)
{
    move* m = create_move(pos);
    if (is_empty(*stack)) *stack = m;
    else
    {
        m->next = *stack;
        *stack = m;
    }
}
move* pop(move** stack)
{
    if (*stack == NULL) return NULL;
    move* m = *stack;
    *stack = m->next;
    m->next = NULL;
    return m;
}
void clear_stack(move** stack)
{
    while (*stack != NULL) free(pop(stack));
}

int get_size(move* stack)
{
    int size = 0;
    while (stack != NULL)
    {
        size++;
        stack = stack->next;
    }
    return size;
}

position* to_array(move* stack)
{
    int size = get_size(stack);
    if (size == 0) return NULL;
    position* arr_pos = (position*)malloc(size * sizeof(position));
    int i = 0;
    while (stack != NULL)
    {
        arr_pos[i++] = stack->pos;
        stack = stack->next;
    }
    return arr_pos;
}

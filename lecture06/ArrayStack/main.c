//
//  main.c
//  ArrayStack
//
//  Created by TungDT on 7/25/20.
//  Copyright © 2020 macOne. All rights reserved.
//
#include <string.h>
#include "stack.h"

#define TRUE  1
#define FALSE 0
int top = -1;
int stack[STACK_SIZE];


int validate_nesting(char * const expression);
int is_opened(const char c);
int is_closed(const char c);
int is_match(const char closed_char, const char opened_char);

int main(int argc, const char * argv[])
{
    printf("Enter an expression to check validate: ");
    char s[100];
    scanf("%[^\n]s", s);
    printf("%s:", s);
    if (validate_nesting(s)) printf("Validated\n");
    else printf("Not validated\n");
    
    return 0;
}


int validate_nesting(char * const expression)
{
    clear_stack();
    // TODO
}

int is_opened(const char c)
{
    switch (c)
    {
        case '(':
        case '[':
        case '{':
            return TRUE;
        default:
            return FALSE;
    }
}
int is_closed(const char c)
{
    switch (c)
    {
        case ')':
        case ']':
        case '}':
            return TRUE;
        default:
            return FALSE;
    }
}

int is_match(const char closed_char, const char opened_char)
{
    if (closed_char == ')' && opened_char == '(') return TRUE;
    if (closed_char == ']' && opened_char == '[') return TRUE;
    if (closed_char == '}' && opened_char == '{') return TRUE;
    return FALSE;
}

//
//  main.c
//  PostFix
//
//  Created by TungDT on 7/28/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#include "stack.h"

int* stack = NULL;
int top = -1;
int stack_size = 100;

int postfix_evaluate(char* expression);
int is_number(char* token);
int is_operator(char* token);
char* get_token(char** expression);
int evaluate(int a, int b, char op);
void stop_program(void);

int main(int argc, const char * argv[])
{
    printf("Enter a postfix expression: ");
    char expr[100];
    scanf("%[^\n]s", expr);
    
    printf("Value = %d\n", postfix_evaluate(expr));
    return 0;
}

int postfix_evaluate(char* expression)
{
    init_stack();
    int val = 0;
    
    // TODO
    clear_stack();
    
    return val;
}

char* get_token(char** expression)
{
    if (*expression == NULL) return NULL;
    char* token = *expression;
    char* end = *expression;
    while (*end != ' ' && *end != '\0') end++;
    if (*end == '\0') *expression = NULL;
    else
    {
        *end = '\0';
        *expression = end+1;
    }
    return token;
}

int is_number(char* token)
{
    for (int i = 0; i < strlen(token); i++)
        if (!isdigit(token[i])) return 0;
    return 1;
}

int is_operator(char* token)
{
    if (strlen(token) != 1) return 0;
    switch (token[0])
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int evaluate(int a, int b, char op)
{
    switch (op)
    {
        case '+': return b + a;
        case '-': return b - a;
        case '*': return b * a;
        case '/': return b / a;
        default:  return 0; // never get this
    }
}

void stop_program()
{
    clear_stack();
    printf("Invalid postfix!\n");
    exit(1);
}

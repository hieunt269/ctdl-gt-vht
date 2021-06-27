//
//  main.c
//  L01-P04-MemErrors
//
//  Created by TungDT on 7/2/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s = "hello";
    strcpy(s, "hello world");           // error: access memory that is out of range
    
    int *p;
    *p = 10;                            // error: access memory which is NULL
    int *q = NULL;
    *q = 10;                            // error: access memory which is NULL
    
    q = (int*) malloc(sizeof(int));
    p = (int*) malloc(sizeof(int));
    
    p = q;                              // leaked memory: now memory pointed by p has no ref
    free(p);
    free(q);                            // error: free memory block again
    
    return 0;
}

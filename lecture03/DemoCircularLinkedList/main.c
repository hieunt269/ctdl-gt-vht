//
//  main.c
//  DemoCircularLinkedList
//
//  Created by TungDT on 7/14/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "cll.h"

int main(int argc, const char * argv[]) {
    node *head = NULL;
    add_head(&head, 2);
    print_list(head);
    
    add_head(&head, 4);
    print_list(head);
    
    add_head(&head, 6);
    print_list(head);
    
    add_head(&head, 8);
    print_list(head);
    
    clear_list(&head);
    return 0;
}

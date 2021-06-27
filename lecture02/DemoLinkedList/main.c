//
//  main.c
//  DemoLinkedList
//
//  Created by TungDT on 7/10/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "linked_list.h"

int main(int argc, const char * argv[]) {
    node* list = NULL;

    node* last = NULL;

    node* node_found = NULL;

    add_head(&list, 1);
    add_head(&list, 2);
    add_head(&list, 3);
    add_head(&list, 4);
    
    print_list(list);

    clear_head(&list);
    print_list(list);

    add_last(&list, 5);
    print_list(list);

    last = get_last(list);
    print_list(last);

    node_found = find(list, 2);
    print_list(node_found);

    clear_last(&list);
    print_list(list);
    
    clear_list(&list);
    print_list(list);
    
    return 0;
}

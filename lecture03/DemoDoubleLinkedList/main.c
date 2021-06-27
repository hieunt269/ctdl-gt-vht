//
//  main.c
//  DemoDoubleLinkedList
//
//  Created by TungDT on 7/14/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include "dll.h"

int main(int argc, const char * argv[]) {
    // insert code here...

	node* head = NULL;
	node* tail = NULL;

	add_head(&head, &tail, 1);
	add_head(&head, &tail, 2);
	add_head(&head, &tail, 3);
	add_head(&head, &tail, 4);

	print_list(head);

	add_tail(&head, &tail, 5);

	print_list(head);

	remove_head(&head, &tail);

	print_list(head);

	remove_tail(&head, &tail);
	remove_tail(&head, &tail);
	remove_tail(&head, &tail);
	remove_tail(&head, &tail);

	print_list(head);

	clear_list(&head, &tail);

	print_list(head);

    return 0;
}

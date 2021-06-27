#include <stdio.h>
#include "selectsort_dll.h"

int main(int argc, char const *argv[])
{
	node* head = NULL;
	node* tail = NULL;

	add_head(&head, &tail, 2);
	add_head(&head, &tail, 3);
	add_head(&head, &tail, 5);
	add_head(&head, &tail, 1);
	add_head(&head, &tail, 4);

	print_list(head);

	selection_sort(head, tail);

	print_list(head);

	clear_list(&head, &tail);

	print_list(head);

	return 0;
}
#include <stdio.h>
#include "basic_sort.h"

int main(int argc, char const *argv[])
{
	int a[10] = {2, 4, 7, 3, 1, 9, 8, 5, 10, 6};
	int b[10] = {2, 4, 7, 3, 1, 9, 8, 5, 10, 6};
	int curr = 9;

	print_array(a, 10, 9);

	bubble_sort(a, 10);

	print_array(a, 10, 9);

	// bubble_sort_op(b, 10);
	// insertion_sort(b, 10);
	selection_sort(b, 10);

	print_array(b, 10, 9);

	return 0;
}
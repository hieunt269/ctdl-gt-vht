#include "basic_sort.h"

void print_array(int a[], const int n, const int curr)
{
    if (curr >= n) return;
    for (int i = 0; i <= curr; i++) printf("%d ", a[i]);
    printf("\n");
}

void swap(int a[], const int i, const int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void bubble_sort(int a[], const int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = n - 1; j > i; --j)
		{
			if (a[j] < a[j - 1])
			{
				swap(a, j, j - 1);
			}
		}
	}
}

void bubble_sort_op(int a[], const int n)
{
	bool need_swap;

	for (int i = 0; i < n - 1; ++i)
	{
		need_swap = FALSE;
		for (int j = n - 1; j > i; --j)
		{
			if (a[j] < a[j - 1])
			{
				swap(a, j, j - 1);
				need_swap = TRUE;
			}
		}
		if(!need_swap) break;
	}
}

void insertion_sort(int a[], const int n)
{
	for (int i = 1; i < n; ++i)
	{
		int temp = a[i];
		int j = i - 1;
		for (; j >= 0 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];
			printf("In j for: a[%d] = %d, a[%d] = %d\n", i, a[i], j + 1, a[j + 1]);

		}
		a[j + 1] = temp;
		printf("a[%d] = %d\n", j + 1, a[j + 1]);
	}
}

void selection_sort(int a[], const int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int imin = i;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[j] < a[imin])
			{
				imin = j;
			}
		}
		if (imin != i)
		{
			swap(a, i, imin);
		}
	}
}
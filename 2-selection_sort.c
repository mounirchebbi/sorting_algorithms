#include "sort.h"

/**
 * swaper - swap 2 integers
 * @n1: first
 * @n2: second
 */
void swaper(int *n1, int *n2)
{
	int tmp;

	tmp = *n1;
	*n1 = *n2;
	*n2 = tmp;
}

/**
 * selection_sort - sort by selection
 * @array: integers
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t i, j;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;
		if ((array + i) != min)
		{
			swaper(array + i, min);
			print_array(array, size);
		}
	}
}

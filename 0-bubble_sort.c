#include "sort.h"

/**
 * swaper - Swap 2 elements
 * @a: first int
 * @b: second int
 */
void swaper(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - effectuate a bubble sort on array
 * @array: pointer
 * @size: size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, lenght = size;
	bool check = false;

	if (array == NULL || size < 2)
		return;

	while (check == false)
	{
		check = true;
		for (i = 0; i < lenght - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swaper(array + i, array + i + 1);
				print_array(array, size);
				check = false;
			}
		}
		lenght--;
	}
}

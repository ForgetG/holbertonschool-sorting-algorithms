#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order,
 * Using the Selection sort algorithm.
 * @array: Given array of integers.
 * @size: Size of given array.
 */

void	selection_sort(int *array, size_t size)
{
	size_t	index1, index2, min_index;
	int	tmp;

	if (array == NULL || size < 2)
		return;
	for (index1 = 0; index1 < size - 1; index1++)
	{
		min_index = index1;
		for (index2 = index1 + 1; index2 < size; index2++)
		{
			if (array[index2] < array[min_index])
				min_index = index2;
		}
		if (min_index != index1)
		{
			tmp = array[index1];
			array[index1] = array[min_index];
			array[min_index] = tmp;
			print_array(array, size);
		}
	}
}

#include "sort.h"

/**
 * swap - Swaps two integers.
 * @a: First integer.
 * @b: Second integer
 */

void	swap(int *a, int *b)
{
	int	temp = 0;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Partitions the array using Lomuto partition scheme.
 * @array: Gien array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending inde of the partition.
 * @size: Size of the array.
 *
 * Return: Index of the pivot.
 */

int	lomuto_partition(int *array, int low, int high, size_t size)
{
	int	pivot = array[high];
	int	partition_index = low - 1;
	int	current_index;

	for (current_index = low; current_index < high; current_index++)
	{
		if (array[current_index] < pivot)
		{
			partition_index++;
			if (partition_index != current_index)
			{
				swap(&array[partition_index], &array[current_index]);
				print_array(array, size);
			}
		}
	}
	if (partition_index + 1 != high)
	{
		swap(&array[partition_index + 1], &array[high]);
		print_array(array, size);
	}
	return (partition_index + 1);
}

/**
 * quick_sort_recursive - Recusively sorts the given array,
 * Using Quick sort algorithm.
 * @array: Given array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Sze of the array.
 */

void	quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int	pivot_index = 0;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order,
 * Using the Quick sort algorithm.
 * @array: Given array to be sorted.
 * @size: Size of the given array.
 */

void	quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}

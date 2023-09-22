#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


/**
 * swap - swap two integers in an array
 *
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 *
 * Return: Void
 */

void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 *
 * @array: the array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 *
 * Return: the index of the pivot element
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}


/**
 * _quicksort - recursive function to perform quick sort
 *
 * @array: array to be sorted
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 *
 * Return: Void
 */

void _quicksort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, low, high, size);
		_quicksort(array, low, pivot - 1, size);
		_quicksort(array, pivot + 1, high, size);
	}
}



/**
 * quick_sort - sorts an array of integers in ascending order
 *
 * @array: array to be sorted
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;
	_quicksort(array, 0, size - 1, size);
}

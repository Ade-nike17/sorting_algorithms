#include "sort.h"

/**
  * selection_sort - Implements selection sort to sort an integer array
  * @array: Array to sort
  * @size: Size of the array
  *
  * Return: Void (Nothing)
  */
void selection_sort(int *array, size_t size)
{
	size_t pos, iter, replace;
	int temp_hold;

	for (pos = 0; pos < size - 1; pos++)
	{
		temp_hold = array[pos];
		for (iter = pos + 1; iter < size; iter++)
		{
			if (array[iter] < temp_hold)
			{
				temp_hold = array[iter];
				replace = iter;
			}
		}
		if (temp_hold != array[pos])
		{
			array[replace] = array[pos];
			array[pos] = temp_hold;
			print_array(array, size);
		}
	}
}

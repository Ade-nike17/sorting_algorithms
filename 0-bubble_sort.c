#include "sort.h"

/**
  * bubble_sort - Implements bubble sort to sort an integer array
  * @array: Array to sort
  * @size: Size of the array
  *
  * Return: Void (Nothing)
  */
void bubble_sort(int *array, size_t size)
{
	size_t iter, displace = 1;
	int temp_hold;

	while (displace)
	{
		displace = 0;
		for (iter = 0; iter < size - 1; iter++)
		{
			if (array[iter] > array[iter + 1])
			{
				temp_hold = array[iter];
				array[iter] = array[iter + 1];
				array[iter + 1] = temp_hold;
				displace = 1;
			}
		}
	}
}

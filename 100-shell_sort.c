#include "sort.h"

/**
  * shell_sort - Sorts array using shell sort algorithm
  * @array: Array to sort
  * @size: Size of array
  *
  * Return: Void (Nothing)
  */
void shell_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	knuth_seq_sort(array, size, 1);
}

/**
  * knuth_seq_sort - Shell sort using knuth sequence
  * @array: Array to sort
  * @size: Size of the array
  * @gap: Current gap
  *
  * Return: Void (Nothing)
  */
void knuth_seq_sort(int *array, size_t size, size_t gap)
{
	size_t iter, oter, new_gap = (3 * gap) + 1, rolld;
	int mid_val;

	if (new_gap < size)
		knuth_seq_sort(array, size, new_gap);
	for (oter = 0; oter < gap; oter++)
		for (iter = oter + gap; iter < size; iter += gap)
		{
			rolld = iter;
			while (rolld > oter)
			{
				if (array[rolld] < array[rolld - gap])
				{
					mid_val = array[rolld];
					array[rolld] = array[rolld - gap];
					array[rolld - gap] = mid_val;
				}
				rolld -= gap;
			}
		}
	print_array(array, size);
}

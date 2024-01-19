#include "sort.h"

/**
 * partition - divides the array at the pivot level
 * @array: array to divide.
 * @low: start of the array.
 * @high: end of the array.
 * @size: size of the array.
 *
 * Return: i.
*/

int partition(int array[], int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low;
	int j, tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;

			if (i != j)
				print_array(array, size);
			i++;
		}
	}
	tmp = array[i];
	array[i] = array[high];
	array[high] = tmp;

	if (i != j)
		print_array(array, size);

	return (i);
}


/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm.
 * @array: array to sorts.
 * @size: sizeof the array.
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	my_quick_sort(array, 0, size - 1, size);
}

/**
 * my_quick_sort - sorts a part of an array of integers.
 * @array: array to sorts.
 * @low: start of the array.
 * @high: end of the array.
 * @size: size of the array.
*/

void my_quick_sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		my_quick_sort(array, low, pivot - 1, size);
		my_quick_sort(array, pivot + 1, high, size);
	}

}

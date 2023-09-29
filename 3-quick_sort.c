#include "sort.h"

/**
 * swap - Function that swap two int
 * @a: input
 * @b: input
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Function that Partition an array and using pivot
 * @array: Array
 * @low: array value
 * @high: array value
 * @size: array size
 * Return: index
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int x = low - 1, y;

	for (y = low; y <= high; y++)
	{
		if (array[y] <= pivot)
		{
			x++;
			if (x != y)
			{
				swap(&array[x], &array[y]);
				print_array(array, size);
			}
		}
	}
	return (x);
}
/**
 * lomuto_qsort - Function Sorting Recursively an Array
 * @array: Array
 * @low: array size
 * @high: array value
 * @size: array size
 */
void lomuto_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		lomuto_qsort(array, low, i - 1, size);
		lomuto_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort - Function that Quick Sort Algorithme using lomuto partition
 * @array: array
 * @size: Array size
*/
void quick_sort(int *array, size_t size)
{
	lomuto_qsort(array, 0, size - 1, size);
}

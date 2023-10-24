#include "sort.h"

/**
 * swapInts -Function that swaps two integers in an array
 * @int1: First integer to swap
 * @int2: Second integer to swap
 */
void swapInts(int *int1, int *int2)
{
	int temp;

	temp = *int1;
	*int1 = *int2;
	*int2 = temp;
}

/**
 * selection_sort -Function that sorts array ints; ascending
 * @array: Array of integers
 * @size: Size of the array
 * Description: Prints the array after every swap
 */
void selection_sort(int *array, size_t size)
{
	int *minInt;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		minInt = array + i;
		for (j = i + 1; j < size; j++)
			minInt = (array[j] < *minInt) ? (array + j) : minInt;

		if ((array + i) != minInt)
		{
			swapInts(array + i, minInt);
			print_array(array, size);
		}
	}
}


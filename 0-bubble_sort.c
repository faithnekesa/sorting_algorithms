#include "sort.h"

/**
 * swapInts -Function that swaps 2 ints in an arrays
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
 * bubble_sort -Function that sorts array ints in ascending order
 * @array: Array integers to sort
 * @size: Array size
 * Description: Function prints the array after every swap
 */
void bubble_sort(int *array, size_t size)
{
	size_t counter, len = size;
	bool bubble = false;

	if (array == NULL || size < 2)
		return;

	while (bubble == false)
	{
		bubble = true;
		for (counter = 0; counter < len - 1; counter++)
		{
			if (array[counter] > array[counter + 1])
			{
				swapInts(array + counter, array + counter + 1);
				print_array(array, size);
				bubble = false;
			}
		}
		len--;
	}
}

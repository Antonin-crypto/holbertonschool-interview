#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Get the maximum number in the array
 * @array: The array
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_radix - Sorts array using counting sort based on digit
 * @array: The array
 * @size: Size of the array
 * @exp: Exponent (digit position)
 */
void counting_sort_radix(int *array, size_t size, int exp)
{
	int *output, count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i-- > 0;)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);
	free(output);
}

/**
 * radix_sort - Sorts array using LSD radix sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
		counting_sort_radix(array, size, exp);
}

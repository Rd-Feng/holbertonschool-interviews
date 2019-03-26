#include "search_algos.h"
void print_array_bs(int *array, int l, int r);
/**
 * binary_search - binary search
 * @array: array to search
 * @size: size of array
 * @value: value to search for
 *
 * Return: target index, -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int l = 0, r = size - 1, n;

	while (array && l <= r)
	{
		print_array_bs(array, l, r);
		n = (l + r) / 2;
		if (array[n] == value)
			return (n);
		if (array[n] < value)
			l = n + 1;
		else
			r = n;
	}
	return (-1);
}
/**
 * print_array_bs - print array for binary search
 * @array: array to print
 * @l: left bound
 * @r: right bound
 */
void print_array_bs(int *array, int l, int r)
{
	printf("Searching in array: ");
	while (l < r)
		printf("%d, ", array[l++]);
	printf("%d\n", array[r]);
}

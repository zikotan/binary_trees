#include "binary_trees.h"

/**
 * array_to_heap - func
 * @array: arg1
 * @size: arg2
 *
 * Return: Result
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	for (i = 0; i < size; i++)
		heap_insert(&root, array[i]);
	return (root);
}

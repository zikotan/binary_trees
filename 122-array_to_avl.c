#include "binary_trees.h"

/**
 * array_to_avl - func
 * @array: arg1
 * @size: arg2
 *
 * Return: Result
 */
avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int i;
	avl_t *myRoot = NULL;

	for (i = 0; i < size; i++)
		avl_insert(&myRoot, array[i]);
	return (myRoot);
}

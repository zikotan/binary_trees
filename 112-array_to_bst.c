#include "binary_trees.h"

/**
 * array_to_bst - func
 * @array: arg1
 * @size: arg2
 *
 * Return: Result
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *myRoot = NULL;
	unsigned int j;

	for (j = 0; j < size; j++)
		bst_insert(&myRoot, array[j]);
	return (myRoot);
}

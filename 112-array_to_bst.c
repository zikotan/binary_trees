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
	bst_t *root = NULL;
	unsigned int j;

	for (j = 0; j < size; j++)
		bst_insert(&root, array[j]);
	return (root);
}

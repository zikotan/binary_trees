#include "binary_trees.h"

/**
 * heap_to_sorted_array - func
 * @heap: arg1
 * @size: arg2
 *
 * Return: Result
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int j, *x = NULL;

	if (!heap || !size)
		return (NULL);
	*size = binary_tree_size(heap) + 1;
	x = malloc(sizeof(int) * (*size));
	if (!x)
		return (NULL);
	for (j = 0; heap; j++)
		x[j] = heap_extract(&heap);
	return (x);
}

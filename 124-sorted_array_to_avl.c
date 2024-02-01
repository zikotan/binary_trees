#include "binary_trees.h"

/**
 * sorted_array_to_avl - func
 * @array: arg1
 * @size: arg2
 *
 * Return: Result
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array)
		return (NULL);
	middle = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[middle]);

	assist5(&tree, array, -1, middle);
	assist5(&tree, array, middle, size);
	return (tree);
}

/**
 * assist5 - func
 * @root: arg1
 * @array: arg2
 * @low: arg3
 * @upp: arg4
 */
void assist5(avl_t **root, int *array, size_t low, size_t upp)
{
	avl_t *newNode = NULL;
	size_t center;

	if (upp - low > 1)
	{
		center = (upp - low) / 2 + low;
		newNode = binary_tree_node(*root, array[center]);
		if (array[center] > (*root)->n)
			(*root)->right = newNode;
		else if (array[center] < (*root)->n)
			(*root)->left = newNode;
		assist5(&newNode, array, low, center);
		assist5(&newNode, array, center, upp);
	}
}

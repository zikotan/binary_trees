#include "binary_trees.h"

/**
 * bst_search - func
 * @parent: arg1
 * @value: arg2
 *
 * Return: Result
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	if (!tree)
		return (NULL);
	while (node)
	{
		if (value < node->n)
			node = node->left;
		else if (value > node->n)
			node = node->right;
		else
			return (node);
	}
	return (NULL);
}

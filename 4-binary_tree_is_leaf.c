#include "binary_trees.h"

/**
 * binary_tree_is_leaf - func
 * @node: arg
 *
 * Return: Result
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	return ((node->left || node->right || !node) ? 0 : 1);
}

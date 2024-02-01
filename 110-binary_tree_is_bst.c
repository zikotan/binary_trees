#include "binary_trees.h"

/**
 * binary_tree_is_bst - func
 * @tree: arg
 *
 * Return: Result
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (assist3(tree, INT_MIN, INT_MAX));
}

/**
 * assist3 - func
 * @tree: arg1
 * @min: arg2
 * @max: arg3
 *
 * Return: Result
 */
int assist3(const binary_tree_t *tree, int min, int max)
{
	if (tree->n < min || tree->n > max)
		return (0);
	if (!tree)
		return (1);

	return (assist3(tree->left, min, tree->n - 1) &&
		assist3(tree->right, tree->n + 1, max));
}

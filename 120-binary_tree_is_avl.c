#include "binary_trees.h"

/**
 * binary_tree_is_avl - func
 * @tree: arg
 *
 * Return: Result
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (assist4(tree, INT_MIN, INT_MAX));
}

/**
 * binary_tree_height - func
 * @tree: arg
 *
 * Return: Result
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t heightLeft = 0, heightRight = 0;

	if (!tree)
		return (0);
	heightLeft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	heightRight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (heightLeft > heightRight ? heightLeft : heightRight);
}

/**
 * assist4 - func
 * @tree: arg1
 * @min: arg2
 * @max: arg3
 *
 * Return: Result
 */
int assist4(const binary_tree_t *tree, int min, int max)
{
	int pathLeft, pathRight;

	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	pathLeft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	pathRight = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	if (abs(pathLeft - pathRight) > 1)
		return (0);
	return (assist4(tree->left, min, tree->n - 1) &&
		assist4(tree->right, tree->n + 1, max));
}

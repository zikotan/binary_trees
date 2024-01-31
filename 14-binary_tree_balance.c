#include "binary_trees.h"

/**
 * binary_tree_balance - func
 * @tree: arg
 *
 * Return: Result
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int heightLeft, heightRight;

	if (!tree)
		return (0);

	heightLeft = tree->left ? (int)binary_tree_height(tree->left) : -1;
	heightRight = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (heightLeft - heightRight);
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

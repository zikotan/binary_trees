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



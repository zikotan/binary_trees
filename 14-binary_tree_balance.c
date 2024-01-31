#include "binary_trees.h"

/**
 * binary_tree_balance - func
 * @tree: arg
 *
 * Return: Result
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int bal = 0;
	int heightLeft = 0, heightRight = 0;

	if (!tree)
		return (0);

	heightLeft = tree->left ? (int)binary_tree_balance(tree->left) + 1 : 0;
	heightRight = tree->right ? (int)binary_tree_balance(tree->right) + 1 : 0;

	bal = heightLeft - heightRight;

	return (bal);
}

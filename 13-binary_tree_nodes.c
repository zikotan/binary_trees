#include "binary_trees.h"

/**
 * binary_tree_nodes - func
 * @tree: arg
 *
 * Return: Result
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t myNodes = 0;

	if (!tree)
		return (0);
	myNodes += binary_tree_nodes(tree->left);
	myNodes += binary_tree_nodes(tree->right);
	if (tree->left || tree->right)
		myNodes += 1;
	return (myNodes);
}

#include "binary_trees.h"

/**
 * binary_tree_levelorder - func
 * @tree: arg1
 * @func: arg2
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	size_t height = binary_tree_height(tree);

	for (size_t level = 1; level <= height + 1; level++)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			if (tree->left)
				func(tree->left->n);
			if (tree->right)
				func(tree->right->n);
		}
	}
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

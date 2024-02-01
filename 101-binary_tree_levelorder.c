#include "binary_trees.h"

/**
 * binary_tree_levelorder - func
 * @tree: arg1
 * @func: arg2
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t lev, max;

	if (!tree || !func)
		return;

	max = binary_tree_height(tree) + 1;

	for (lev = 1; lev <= max; lev++)
		assist(tree, func, lev);
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
 * assist - func
 * @tree: arg1
 * @func: arg2
 * @level: arg3
 */
void assist(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		assist(tree->left, func, level - 1);
		assist(tree->right, func, level - 1);
	}
}


#include "binary_trees.h"

/**
 * binary_tree_depth - func
 * @tree: arg
 *
 * Return: Result
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t deep = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		deep++;
		tree = tree->parent;
	}
	return (deep);
}

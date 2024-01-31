#include "binary_trees.h"

/**
 * binary_tree_insert_right - func
 * @first: arg1
 * @second: arg2
 *
 * Return: Result
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second)
{
	size_t firstDeep, secondDeep;

	if (!first || !second)
		return (NULL);

	firstDeep = binary_tree_depth(first);
	secondDeep = binary_tree_depth(second);

	while (firstDeep > secondDeep)
	{
		first = first->parent;
		firstDeep--;
	}
	while (secondDeep > firstDeep)
	{
		second = second->parent;
		secondDeep--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

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

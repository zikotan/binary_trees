#include "binary_trees.h"

/**
 * binary_tree_is_complete - func
 * @tree: arg
 *
 * Return: Result
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;
	
	if (!tree)
		return (0);
	size = binary_tree_size(tree);
	return (otherAssist(tree, 0, size));
}

/**
 * otherAssist - func
 * @tree: arg1
 * @index: arg2
 * @size: arg3
 *
 * Return: Result
 */
int otherAssist(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);
	if (index >= size)
		return (0);
	return (otherAssist(tree->left, 2 * index + 1, size) &&
		otherAssist(tree->right, 2 * index + 2, size));
}

#include "binary_trees.h"

/**
 * binary_tree_size - func
 * @tree: arg
 *
 * Return: Result
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}


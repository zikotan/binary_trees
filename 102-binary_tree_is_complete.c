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
	return (assist2(tree, 0, size));
}

/**
 * assist2 - func
 * @tree: arg1
 * @ind: arg2
 * @s: arg3
 *
 * Return: Result
 */
int assist2(const binary_tree_t *tree, size_t ind, size_t s)
{
	if (!tree)
		return (1);
	if (ind >= s)
		return (0);
	return (assist2(tree->left, 2 * ind + 1, s) &&
		assist2(tree->right, 2 * ind + 2, s));
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


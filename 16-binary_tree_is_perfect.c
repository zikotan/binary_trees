#include "binary_trees.h"

/**
 * binary_tree_is_perfect - func
 * @tree: arg
 *
 * Return: Result
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t myHeight = 0, myNodes = 0, pow = 0;

	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	myHeight = binary_tree_height(tree);
	myNodes = binary_tree_size(tree);

	pow = (size_t)powRec(2, myHeight + 1);
	return (pow - 1 == myNodes);
}

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
 * powRec - func
 * @a: arg1
 * @b: arg2
 * Return: Result
 */
int powRec(int a, int b)
{
	if (b < 0)
		return (-1);
	if (b == 0)
		return (1);
	else
		return (a * powRec(a, b - 1));
}

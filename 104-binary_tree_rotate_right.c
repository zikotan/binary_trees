#include "binary_trees.h"

/**
 * binary_tree_rotate_right - func
 * @tree: arg
 *
 * Return: Result
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *help = NULL, *father;

	if (!tree || !tree->left)
		return (NULL);
	help = tree;
	father = tree->parent;
	tree = tree->left;
	tree->parent = NULL;
	if (tree->right)
	{
		help->left = tree->right;
		tree->right->parent = help;
	}
	else
		help->left = NULL;
	help->parent = tree;
	tree->right = help;
	if (father)
		father->left = tree;
	tree->parent = father;
	return (tree);
}

#include "binary_trees.h"

/**
 * binary_tree_rotate_left - func
 * @tree: arg
 *
 * Return: Result
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *help = NULL, *father;

	if (!tree || !tree->right)
		return (NULL);
	help = tree;
	father = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		help->right = tree->left;
		tree->left->parent = help;
	}
	else
		help->right = NULL;
	help->parent = tree;
	tree->left = help;
	if (father)
		father->right = tree;
	tree->parent = father;
	return (tree);
}

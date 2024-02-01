#include "binary_trees.h"

/**
 * bst_remove - func
 * @root: arg1
 * @value: arg2
 *
 * Return: Result
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *help = NULL, *min = NULL;

	if (!root)
		return (NULL);
	if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else
	{
		if (!root->left)
		{
			help = root->right;
			free(root);
			return (help);
		}
		else if (!root->right)
		{
			help = root->left;
			free(root);
			return (help);
		}
		min = root->right;
		while (min->left)
			min = min->left;
		help = min;
		root->n = help->n;
		root->right = bst_remove(root->right, help->n);
	}
	return (root);
}

/**
 * bst_min_val - finds the smallest node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * Return: a pointer to the smallest node
 */
bst_t *bst_min_val(bst_t *root)
{
	bst_t *min = root;

	while (min->left)
		min = min->left;

	return (min);
}

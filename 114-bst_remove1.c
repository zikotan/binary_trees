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
	bst_t *help = NULL;

	if (!root)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
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
		help = myMin(root->right);
		root->n = help->n;
		root->right = bst_remove(root->right, help->n);
	}
	return (root);
}

/**
 * myMin - func
 * @myRoot: arg
 *
 * Return: Result
 */
bst_t *myMin(bst_t *myRoot)
{
	bst_t *m = myRoot;

	while (m->left)
		m = m->left;
	return (m);
}
#include "binary_trees.h"

/**
 * bst_insert - func
 * @tree: arg1
 * @value: arg2
 *
 * Return: Result
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *help = NULL, *two = NULL, *newNode = NULL;

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));
	if (!tree)
		return (NULL);
	help = *tree;
	while (help)
	{
		two = help;
		if (value == help->n)
			return (NULL);
		else if (value < help->n)
			help = help->left;
		else
			help = help->right;
	}
	newNode = binary_tree_node(NULL, value);
	if (two == NULL)
		two = newNode;
	else if (value < two->n)
	{
		two->left = newNode;
		newNode->parent = two;
	}
	else
	{
		two->right = newNode;
		newNode->parent = two;
	}
	return (newNode);
}

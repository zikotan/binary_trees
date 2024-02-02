#include "binary_trees.h"

/**
 * avl_insert - func
 * @tree: arg1
 * @value: arg2
 *
 * Return: Result
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *myNode = bst_insert(tree, value);
	int bal = 0;

	bal = binary_tree_balance(*tree);
	if (bal > 1 && value < myNode->left->n)
		return (binary_tree_rotate_right(myNode));
	if (bal < -1 && value > myNode->right->n)
		return (binary_tree_rotate_left(myNode));
	if (bal > 1 && value > myNode->left->n)
	{
		myNode->left = binary_tree_rotate_left(myNode->left);
		return (binary_tree_rotate_right(myNode));
	}
	if (bal < -1 && value < myNode->right->n)
	{
		myNode->right = binary_tree_rotate_right(myNode->right);
		return (binary_tree_rotate_left(myNode));
	}
	return (myNode);
}

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


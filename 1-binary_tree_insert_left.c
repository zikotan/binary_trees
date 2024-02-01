#include "binary_trees.h"

/**
 * binary_tree_insert_left - func
 * @parent: arg1
 * @value: arg2
 *
 * Return: Result
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *myNode;

	if (!parent)
		return (NULL);
	myNode = malloc(sizeof(binary_tree_t));
	if (!myNode)
		return (NULL);
	myNode->n = value;
	myNode->parent = parent;
	myNode->right = NULL;
	myNode->left = parent->left;
	parent->left = myNode;
	if (myNode->left)
		myNode->left->parent = myNode;
	return (myNode);
}

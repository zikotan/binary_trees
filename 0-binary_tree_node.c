#include "binary_trees.h"

/**
 * binary_tree_node - func
 * @parent: arg1
 * @value: arg2
 *
 * Return: Result
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *myNode;

	myNode = malloc(sizeof(binary_tree_t));
	if (!myNode)
		return (NULL);
	myNode->n = value;
	myNode->parent = parent;
	myNode->left = NULL;
	myNode->right = NULL;
	return (myNode);
}

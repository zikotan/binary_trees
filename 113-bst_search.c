#include "binary_trees.h"

/**
 * bst_search - func
 * @parent: arg1
 * @value: arg2
 *
 * Return: Result
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *myNode = (bst_t *)tree;

	if (!tree)
		return (NULL);
	while (myNode)
	{
		if (value < myNode->n)
			myNode = myNode->left;
		else if (value > myNode->n)
			myNode = myNode->right;
		else
			return (myNode);
	}
	return (NULL);
}

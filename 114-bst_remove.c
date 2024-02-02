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
	bst_t *myNode = NULL, *myLeaf;

	myLeaf = bst_search(root, value);
	if (myLeaf == NULL)
		return (root);
	if (myLeaf->left != NULL && myLeaf->right == NULL)
	{
		for (myNode = myLeaf->left; myNode->right != NULL; myNode = myNode->right)
			;
		if (myNode != myLeaf->left)
		{
			myNode->parent->right = myNode->left;
			myNode->left = myLeaf->left;
		}
		myNode->right = myLeaf->right, myNode->parent = myLeaf->parent;
	}
	else if (myLeaf->right != NULL)
	{
		for (myNode = myLeaf->right; myNode->left != NULL; myNode = myNode->left)
			;
		if (myNode != myLeaf->right)
		{
			myNode->parent->left = myNode->right;
			myNode->right = myLeaf->right;
		}
		myNode->left = myLeaf->left, myNode->parent = myLeaf->parent;
	}
	if (myLeaf->parent != NULL && myLeaf->parent->right == myLeaf)
		myLeaf->parent->right = myNode;
	if (myLeaf->parent != NULL && myLeaf->parent->left == myLeaf)
		myLeaf->parent->left = myNode;
	free(myLeaf);
	if (myNode->right != NULL && myNode != NULL)
		myNode->right->parent = myNode;
	if (myNode->left != NULL && myNode != NULL)
		myNode->left->parent = myNode;
	if (myNode->parent == NULL)
		return (myNode);
	return (root);
}

/**
 * bst_search - func
 * @tree: arg1
 * @value: arg2
 *
 * Return: Result
 */
bst_t *bst_search(bst_t const *tree, int value)
{
	bst_t const *myLeaf;

	myLeaf = tree;
	while (myLeaf != NULL && myLeaf->n != value)
	{
		if (value > myLeaf->n)
			myLeaf = myLeaf->right;

		else if (value < myLeaf->n)
			myLeaf = myLeaf->left;
	}
	return ((bst_t *)myLeaf);
}

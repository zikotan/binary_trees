#include "binary_trees.h"

/**
 * heap_extract - func
 * @root: arg
 *
 * Return: Result
 */
int heap_extract(heap_t **root)
{
	heap_t *heap_r, *node;
	int value;

	if (!root || !*root)
		return (0);
	heap_r = *root;
	value = heap_r->n;
	if (!heap_r->left && !heap_r->right)
	{
		*root = NULL;
		free(heap_r);
		return (value);
	}
	myPreorder(heap_r, &node, binary_tree_height(heap_r));
	heap_r->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	myHeap(heap_r);
	*root = heap_r;
	return (value);
}

/**
 * binary_tree_height - func
 * @tree: arg
 *
 * Return: Result
 */
size_t binary_tree_height(const heap_t *tree)
{
	size_t heightLeft = 0, heightRight = 0;

	if (!tree)
		return (0);
	if (tree->left)
		heightLeft = 1 + binary_tree_height(tree->left);
	if (tree->right)
		heightRight = 1 + binary_tree_height(tree->right);
	if (heightLeft > heightRight)
		return (heightLeft);
	return (heightRight);
}
/**
 * binary_tree_size - func
 * @tree: arg
 *
 * Return: Result
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t heightLeft = 0, heightRight = 0;

	if (!tree)
		return (0);
	if (tree->left)
		heightLeft = 1 + binary_tree_size(tree->left);
	if (tree->right)
		heightRight = 1 + binary_tree_size(tree->right);
	return (heightLeft + heightRight);
}

/**
 * myPreorder - func
 * @myTree: arg1
 * @myNode: arg2
 * @h: arg3
 *
 * Return: No Return
 */
void myPreorder(heap_t *myTree, heap_t **myNode, size_t h)
{
	if (!myTree)
		return;
	if (!h)
		*myNode = myTree;
	h--;
	myPreorder(myTree->left, myNode, h);
	myPreorder(myTree->right, myNode, h);
}

/**
 * myHeap - func
 * @myRoot: arg
 */
void myHeap(heap_t *myRoot)
{
	heap_t *help1, *help2;
	int val;

	if (!myRoot)
		return;
	help1 = myRoot;
	while (1)
	{
		if (!help1->left)
			break;
		if (!help1->right)
			help2 = help1->left;
		else
		{
			if (help1->left->n > help1->right->n)
				help2 = help1->left;
			else
				help2 = help1->right;
		}
		if (help1->n > help2->n)
			break;
		val = help1->n;
		help1->n = help2->n;
		help2->n = val;
		help1 = help2;
	}
}

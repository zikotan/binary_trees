#include "binary_trees.h"

/**
 * heap_insert - func
 * @root: arg1
 * @value: arg2
 *
 * Return: Result
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *myTree, *newNode, *Flip;
	int s, l, sub, myBit, lev, help;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	myTree = *root;
	s = binary_tree_size(myTree);
	l = s;
	for (lev = 0, sub = 1; l >= sub; sub *= 2, lev++)
		l -= sub;
	for (myBit = 1 << (lev - 1); myBit != 1; myBit >>= 1)
		myTree = l & myBit ? myTree->right : myTree->left;
	newNode = binary_tree_node(myTree, value);
	l & 1 ? (myTree->right = newNode) : (myTree->left = newNode);
	Flip = newNode;
	for (; Flip->parent && (Flip->n > Flip->parent->n); Flip = Flip->parent)
	{
		help = Flip->n;
		Flip->n = Flip->parent->n;
		Flip->parent->n = help;
		newNode = newNode->parent;
	}
	return (newNode);
}

/**
 * binary_tree_size - func
 * @tree: arg
 *
 * Return: Result
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

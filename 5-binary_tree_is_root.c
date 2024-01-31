#include "binary_trees.h"

/**
 * binary_tree_is_root - func
 * @node: node to check
 *
 * Return: Result
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}

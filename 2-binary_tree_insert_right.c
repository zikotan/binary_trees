#include "binary_trees.h"

/**
 * binary_tree_insert_right - func
 * @parent: arg1
 * @value: arg2
 *
 * Return: Result
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *my_node;

	if (!parent)
		return (NULL);

	my_node = malloc(sizeof(binary_tree_t));
	if (!my_node)
		return (NULL);

	my_node->n = value;
	my_node->parent = parent;
	my_node->left = NULL;
	my_node->right = parent->right;
	parent->right = my_node;
	if (my_node->right)
		my_node->right->parent = my_node;
	return (my_node);
}

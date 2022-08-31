#include "binary_trees.h"

/**
 * binary_tree_is_root - checks to see if node is root of binary tree
 * @node: pointer to node in binary tree
 * Return: 1 if true, 0 otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (!node->parent)
		return (1);

	return (0);
}

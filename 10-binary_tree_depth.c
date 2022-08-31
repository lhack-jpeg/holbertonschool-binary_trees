#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 * @tree: pointer to node on binary tree
 *Return: size_t of depth of node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}

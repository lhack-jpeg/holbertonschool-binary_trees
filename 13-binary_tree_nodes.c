#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the amount of nodes from a given node with
 * at least 1 child node
 * @tree: starting node
 *Return: count of nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		return (1 + binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->right));
	else
		return (0);
}

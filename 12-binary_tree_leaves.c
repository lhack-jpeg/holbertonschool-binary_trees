#include "binary_trees.h"

/**
 * binary_tree_leaves - count the amount of leaves from a given node in a binary
 * tree
 * @tree: starting root node in tree
 *Return: count of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	else
		return (binary_tree_leaves(tree->left) +
			binary_tree_leaves(tree->right));
}

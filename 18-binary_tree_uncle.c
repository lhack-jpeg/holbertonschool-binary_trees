#include "binary_trees.h"

/**
 * binary_tree_uncle - the uncle of a node in a binary tree
 * @node: pointer to node in tree
 *Return: pointer to uncle node, NULL otherwise
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	if (node->parent->parent->left == node)
		return (node->parent->right);

	return (node->parent->parent->left);
}

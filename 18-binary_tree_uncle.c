#include "binary_trees.h"

/**
 * binary_tree_uncle - the uncle of a node in a binary tree
 * @node: pointer to node in tree
 *Return: pointer to uncle node, NULL otherwise
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent_node;
	if (!node || !node->parent || !node->parent->parent)
		return (NULL);

	parent_node = node->parent;

	if (parent_node->parent->left = parent_node)
		return (parent_node->parent->right);

	return (parent_node->parent_left);
}

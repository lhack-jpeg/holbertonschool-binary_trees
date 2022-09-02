#include "binary_trees.h"

/**
 * binary_tree_size - work out the size of a binary tree
 * @tree: pointer to node in tree
 *Return: size of tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 +
		binary_tree_size(tree->right));
}

/**
 * is_complete - recursively checks if if binary tree is complete
 * @tree: pointer to node on tree
 * @index: index of node
 * @node_count: total count of node
 * Return: 1 if complete, 0 otherwise
 */

int is_complete(const binary_tree_t *tree, size_t index, size_t node_count)
{
	if (!tree)
		return (1);

	if (index >= node_count)
		return (0);

	return (is_complete(tree->left, index * 2 + 1, node_count) &&
		is_complete(tree->right, index * 2 + 2, node_count));
}

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to node
 *Return: 1 if complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int complete;
	size_t node_count, index = 0;

	if (!tree)
		return (0);

	node_count = binary_tree_size(tree);
	complete = is_complete(tree, index, node_count);

	return (complete);
}

#include "binary_trees.h"

/**
 * binary_tree_height - find the height of a node
 * @tree: pointer to node
 *Return: height of tree, 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	/* check to see if node is leaf */
	if (!tree->left && !tree->right)
		return (0);

	if (left > right)
		return (left + 1);
	else
		return (right + 1);
}

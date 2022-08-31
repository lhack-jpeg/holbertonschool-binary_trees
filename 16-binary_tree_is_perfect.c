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

/**
 * binary_tree_leaves - count the amount of
 * leaves from a given node in a binary tree
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

/**
 * binary_tree_is_perfect - checks to see if the binary tree is full
 * h_leaves is the hypothetical amount of leaves on the tree
 * a_leaves is the actual amount of leaves on the tree
 * @tree: pointer to root node to start checking
 *Return: 1 if true, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, h_leaves = 1, a_leaves, count;

	if (!tree)
		return (0);

	height = binary_tree_height(tree);

	/* raise h_leaves to the power of height */
	count = 0;
	while (count < height)
	{
		h_leaves *= 2;
		count++;
	}
	/* find actual amount of leaves from node */
	a_leaves = binary_tree_leaves(tree);

	if (h_leaves == a_leaves)
		return (1);

	return (0);
}

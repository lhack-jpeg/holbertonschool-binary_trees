#include "binary_trees.h"
#include <limits.h>

/**
 * is_bst - helper function for checking binnary tree
 * @tree: pointer to node
 * @min: min value
 * @max: max value
 * Return: 1 if tree is bst 0 othewise
*/

int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - function that checks if a binary tree is a
 * valid Binary Search Tree
 * @tree: pointer to node in tree
 *Return: 1 if tree is vald BST and 0 othwerise
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst(tree, INT_MIN, INT_MAX));
}

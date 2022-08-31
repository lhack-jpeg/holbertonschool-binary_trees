#include "binary_trees.h"

/**
 * binary_tree_is_full - checks to see if the binary tree is full
 * @tree: pointer to root node to start checking
 *Return: 1 if true, 0 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->right == NULL && tree->left == NULL)
		return (1);
	if (tree->right != NULL && tree->left != NULL)
		return (binary_tree_is_full(tree->right) &&
			binary_tree_is_full(tree->left));
	return (0);
}

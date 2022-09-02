#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function to rotate a binary tree to
 * the right
 * @tree: pointer to root node
 * Return: pointer to new root node
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root, *right;

	if (!tree || !tree->left)
		return (NULL);

	root = tree->left;
	right = tree;

	right->parent = root;
	right->left = NULL;
	root->parent = NULL;

	if (root->right)
	{
		right->left = root->right;
	}

	root->right = right;

	return (root);
}

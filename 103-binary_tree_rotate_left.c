#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function to rotate a binary tree to
 * the left
 * @tree: pointer to root node
 * Return: pointer to new root node
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root, *left;

	if (!tree || !tree->right)
		return (NULL);

	root = tree->right;
	left = tree;

	left->parent = root;
	left->right = NULL;
	root->parent = NULL;

	if (root->left)
	{
		left->right = root->left;
	}

	root->left = left;

	return (root);
}

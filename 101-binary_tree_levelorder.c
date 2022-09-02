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
 * print_current_level - recursively prints levels in order
 * @tree: pointer to node
 * @level: integer value of which level of the tree the node is on
 * @func: pointer to function
 * Return: void
 */

void print_current_level(const binary_tree_t *tree, size_t level,
			 void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);

	else if (level > 1)
	{
		print_current_level(tree->left, level - 1, func);
		print_current_level(tree->right, level - 1, func);
	}
}


/**
 * print_level_order - function to to send through to print_current_level
 * @tree: pointer to root node
 * @func: pointer to func
 * Return: void
 */

void print_level_order(const binary_tree_t *tree, void (*func)(int))
{
	size_t height, i;

	height = binary_tree_height(tree) + 1;

	for (i = 1; i <= height; i++)
		print_current_level(tree, i, func);
}

/**
 * binary_tree_levelorder - goes through binary tree using level-order
 * traversal
 * @tree: pointer to node
 * @func: pointer to function
 *Return: void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	print_level_order(tree, func);
}

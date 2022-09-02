#include "binary_trees.h"

/**
 * bst_insert - function that inserts a value in a Binary
 * Search Tree
 * @tree: pointer to pointer to root node binary tree
 * @value: value to be inserted.
 *Return: pointer to new node
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *node;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}

	node = *tree;

	if (value == node->n)
		return (NULL);

	if (value < node->n)
	{
		if (!node->left)
		{
			node->left = binary_tree_node(node, value);
			return (node->left);
		}

		return (bst_insert(&(node->left), value));
	}
	else
	{
		if (!node->right)
		{
			node->right = binary_tree_node((node), value);
			return (node->right);
		}

		return (bst_insert(&(node->right), value));
	}

	return (NULL);
}

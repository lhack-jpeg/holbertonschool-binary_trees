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
		return (binary_tree_node(*tree, value));

	node = *tree;

	if (node->n < value)
		return (bst_insert(&(node->left), value));
	else if (node->n > value)
		return (bst_insert(&(node->right), value));
	else
		return (NULL);
}

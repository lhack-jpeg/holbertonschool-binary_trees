#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a Binary tree node
 * @parent: pointer to parent node
 * @value: integer to store in node
 * Return: pointer to new node.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *node;

	node = malloc(sizeof(*node));

	if (node == NULL)
		return (NULL);

	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	node->n = value;

	return (node);
}

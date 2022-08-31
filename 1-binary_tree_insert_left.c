#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node in the left child of a parent node
 * @parent: pointer to parent node
 * @value: value to store in new node
 * Return: pointer to new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(*node));

	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->right = NULL;

	temp = parent->left;
	node->left = temp;
	parent->left = node;
	if (temp != NULL)
		temp->parent = node;

	return (node);
}

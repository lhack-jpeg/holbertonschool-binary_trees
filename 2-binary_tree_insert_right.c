#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert a node in the right child of a parent node
 * @parent: pointer to parent node
 * @value: value to store in new node
 * Return: pointer to new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node, *temp;

	if (parent == NULL)
		return (NULL);

	node = malloc(sizeof(*node));

	if (node == NULL)
		return (NULL);
	node->parent = parent;
	node->n = value;
	node->left = NULL;

	temp = parent->right;
	node->right = temp;
	parent->right = node;
	if (temp != NULL)
		temp->parent = node;

	return (node);
}

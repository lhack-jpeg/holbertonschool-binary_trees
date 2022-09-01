#include "binary_trees.h"

/**
 * binary_tree_depth - measure the depth of a node in a binary tree
 * @tree: pointer to node on binary tree
 *Return: size_t of depth of node
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL || !tree->parent)
		return (0);

	return (1 + binary_tree_depth(tree->parent));
}


binary_tree_t *binary_trees_ancestor_depth(const binary_tree_t *first, size_t first_depth, const binary_tree_t *second, size_t second_depth)
{
	if (first == second)
		return ((binary_tree_t *) first);

	if (first_depth == second_depth)
		return (binary_trees_ancestor_depth(first->parent,
						    first_depth - 1,
						    second->parent,
						    second_depth - 1));
	if (first_depth < second_depth)
		return (binary_trees_ancestor_depth(first,
						    first_depth,
						    second->parent,
						    second_depth - 1));
	else
		return (binary_trees_ancestor_depth(first->parent,
						    first_depth - 1,
						    second,
						    second_depth));
}


/**
 *  -
 *
 *Return:
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	if (!first || !second)
		return (NULL);

	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);
	return (binary_trees_ancestor_depth(first,
					    first_depth,
					    second,
					    second_depth));
}

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


/**
 * binary_trees_ancestor_depth - recursive way to work out lowest
 * common ancestor
 * @first: pointer to first node
 * @first_depth: depth of first node on tree
 * @second: pointer to second node
 * @second_depth: second node depth
 * Return: pointer to common ancestor.
 */
binary_tree_t *binary_trees_ancestor_depth(const binary_tree_t *first,
					   size_t first_depth,
					   const binary_tree_t *second,
					   size_t second_depth)
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
 * binary_trees_ancestor - function to check for loweest common ancestor
 * @first: pointer to first node
 * @second: pointer to second node
 *Return: pointer to node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
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

#include "binary_trees.h"
/**
 *  -
 *
 *Return:
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	if (!first || !second)
		return (NULL);

	if (first->n == second->parent->n)
		return (second->parent);

	if (first->parent->n == second->parent->n)
		return (first->parent);

	if (first->parent->n > second->parent->n)
		return (binary_trees_ancestor(first, second->parent));

	if (first->parent->n < second->parent->n)
		return (binary_trees_ancestor(first->parent, second));

	return (NULL);
}

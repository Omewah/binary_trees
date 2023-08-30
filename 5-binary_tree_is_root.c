#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if the given node is a root
 * @node: the nodee to be analyzed
 * Return: 1 (Success), Else 0 (Failure)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return (1);
}

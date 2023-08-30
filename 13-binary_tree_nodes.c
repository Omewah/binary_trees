#include "binary_trees.h"
/**
 * binary_tree_nodes - counts the nodes with at least 1 child in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of nodes
 * Return: node counted, Else 0 if NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{

	size_t  n_counter = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		n_counter += ((tree->left || tree->right) ? 1 : 0);
		n_counter += binary_tree_nodes(tree->left);
		n_counter += binary_tree_nodes(tree->right);
		return (n_counter);
	}
}

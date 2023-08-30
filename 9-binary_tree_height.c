#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree:  a pointer to the root node of the tree to measure the height
 * Return: the height, Else 0 if NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t a = 0;
	size_t b = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree)
		{
			a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			b = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((a > b) ? a : b);
	}
}

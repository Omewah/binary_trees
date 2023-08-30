#include "binary_trees.h"
/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the size
 * Return: the size, Else 0 if NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t tree_size = 0;
	size_t b = 0;
	size_t a = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		a = binary_tree_size(tree->left);
		b = binary_tree_size(tree->right);
		tree_size = b + a + 1;
	}
	return (tree_size);
}

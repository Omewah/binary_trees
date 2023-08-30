#include "binary_trees.h"
/**
 * binary_tree_leaves - a function that counts the leaves in a binary tree
 * @tree: a pointer to the root node of the tree to count the number of leaves
 * Return: the leave counts, Else 0 if NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t l_counter = 0;
	size_t a = 0;
	size_t b = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		a = binary_tree_leaves(tree->left);
		b = binary_tree_leaves(tree->right);
		l_counter = a + b;
		return ((!a && !b) ? l_counter + 1 : l_counter + 0);
	}
}

#include "binary_trees.h"

/**
 * tree_balance_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
 * Return: the height, Else 0 if NULL
 */
size_t tree_balance_height(const binary_tree_t *tree)
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
			a = tree->left ? 1 + tree_balance_height(tree->left) : 1;
			b = tree->right ? 1 + tree_balance_height(tree->right) : 1;
		}
		return ((a > b) ? a : b);
	}
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: points to the root node of the tree to measure the balance factor
 * Return: the measured balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int a = 0;
	int b = 0;
	int b_fact = 0;

	if (tree)
	{
		b = ((int)tree_balance_height(tree->left));
		a = ((int)tree_balance_height(tree->right));
		b_fact = b - a;
	}
	return (b_fact);
}

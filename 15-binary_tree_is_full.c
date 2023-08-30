#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: if full, Else 0 if NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int a = 0;
	int b = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left && tree->right)
		{
			a = binary_tree_is_full(tree->left);
			b = binary_tree_is_full(tree->right);
			if (a == 0 || b == 0)
			{
				return (0);
			}
			return (1);
		}
		else if (!tree->left && !tree->right)
		{
			return (1);
		}
		else
		{
			return (0);
		}
	}
}

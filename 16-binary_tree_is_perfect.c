#include "binary_trees.h"
/**
 * the_perfect_tree - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: the relative height level, ELse 0
 */
int the_perfect_tree(const binary_tree_t *tree)
{
	int a = 0;
	int b = 0;

	if (tree->left && tree->right)
	{
		a = 1 + the_perfect_tree(tree->left);
		b = 1 + the_perfect_tree(tree->right);
		if (b == a && b != 0 && a != 0)
			return (b);
		return (0);
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

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: checks if tree is perfect, Else 0 if NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int b_perfect = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		b_perfect = the_perfect_tree(tree);
		if (b_perfect != 0)
		{
			return (1);
		}
		return (0);
	}
}

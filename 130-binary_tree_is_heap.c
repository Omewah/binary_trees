#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree
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
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			a = tree->left ? 1 + binary_tree_height(tree->left) : 0;
			b = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		}
		return ((a > b) ? a : b);
		}
}

/**
 * binary_tree_balance - Measures balance factor of a binary tree
 * @tree: a pointer to the root node of the tree
 * Return: the measured balanced factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int a = 0;
	int b = 0;
	int b_fact = 0;

	if (tree)
	{
		b = ((int)binary_tree_height(tree->left));
		a = ((int)binary_tree_height(tree->right));
		b_fact = b - a;
	}
	return (b_fact);
}

/**
 * the_perfect_tree - checks if the binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: the relative height level, Else 0
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
 * binary_tree_is_perfect - checks if the binary tree is perfect
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

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 (Success), Else 0 if NULL
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int a;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
	{
		return (0);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (binary_tree_is_perfect(tree))
	{
		return (1);
	}
	a = binary_tree_balance(tree);
	if (a == 0)
	{
		return (binary_tree_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (a == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& binary_tree_is_perfect(tree->right));
	}
	else
	{
		return (0);
	}
}

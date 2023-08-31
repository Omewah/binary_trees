#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure
 * Return: the height of the binary tree
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
			a = tree->left ? 1 + binary_tree_height(tree->left) : 1;
			b = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		}
		return ((a > b) ? a : b);
		}
}

/**
 * compare_tree - compare the sub-trees.
 * @tree: node that point to the tree to check.
 * @head: a pointer to the head of the node
 * @tail: a pointer to the tail of the node.
 * Return: 1 if tree is AVL, Else 0.
 */
int compare_tree(const binary_tree_t *tree, int tail, int head)
{
	size_t a;
	size_t b;
	size_t z;

	if (tree != NULL)
	{
		if (tree->n > head || tree->n < tail)
		{
			return (0);
		}
		a = binary_tree_height(tree->left);
		b = binary_tree_height(tree->right);
		z = a > b ? a - b : b - a;
		if (z > 1)
		{
			return (0);
		}
		return (compare_tree(tree->left, tail, tree->n - 1) &&
			compare_tree(tree->right, tree->n + 1, head));
	}
	return (1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is AVL, Else 0.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (compare_tree(tree, INT_MIN, INT_MAX));
}

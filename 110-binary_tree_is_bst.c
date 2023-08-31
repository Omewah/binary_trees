#include "binary_trees.h"
/**
 * node_small - checks if nodes are smaller than root
 * @node: the nodes to be checked
 * @val: the value to coompare with
 * Return: 1 if small, Else 0
 */
int node_small(const binary_tree_t *node, int val)
{
	int a = 0;
	int b = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n >= val)
			return (0);
		a = node_small(node->left, val);
		b = node_small(node->right, val);
		if (a == b && a == 1)
			return (1);
		return (0);
	}
}
/**
 * node_big - checks if nodes are bigger than root
 * @node: the node to be checked
 * @val: the value to compare with
 * Return: 1 if big, Else 0
 */
int node_big(const binary_tree_t *node, int val)
{
	int a = 0;
	int b = 0;

	if (node == NULL)
	{
		return (1);
	}
	else
	{
		if (node->n <= val)
			return (0);
		a = node_big(node->left, val);
		b = node_big(node->right, val);
		if (a == b && a == 1)
			return (1);
		return (0);
	}
}
/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is valid, Else 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int var = 0, a = 2, b = 2;

	if (tree == NULL)
		return (0);
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n < tree->n)
		return (0);
	if (tree->left && tree->left->n < tree->n)
	{
		var = node_small(tree->left, tree->n);
		if (var == 0)
			return (0);
		a = binary_tree_is_bst(tree->left);
	}
	if (tree->right && tree->right->n > tree->n)
	{
		var = node_big(tree->right, tree->n);
		if (var == 0)
			return (0);
		b = binary_tree_is_bst(tree->right);
	}
	if (a != 2 || b != 2)
	{
		if (a == 0 || b == 0)
			return (0);
	}
	return (1);
}

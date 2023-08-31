#include "binary_trees.h"
/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height
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
/**
 * binary_tree_depth - depth of specified node from root
 * @tree: node to check the depth
 * Return: 0 is it is the root or number of depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	return ((tree && tree->parent) ? 1 + binary_tree_depth(tree->parent) : 0);
}
/**
 * node_list - creates a linked list containing node
 * @hd: pointer to head of the LL
 * @tree: the node contained in the LL
 * @depth: the depth of node in the LL
 */
void node_list(link_t **hd, const binary_tree_t *tree, size_t depth)
{
	link_t *a;
	link_t *b;

	a = malloc(sizeof(link_t));
	if (a == NULL)
	{
		return;
	}
	a->n = depth;
	a->nodeIN = tree;
	if (*hd == NULL)
	{
		a->nextIN = NULL;
		*hd = a;
	}
	else
	{
		b = *hd;
		while (b->nextIN != NULL)
		{
			b = b->nextIN;
		}
		a->nextIN = NULL;
		b->nextIN = a;
	}
}
/**
 * node_loop - a function that passes through the binary tree
 * @hd: a pointer to head of the LL
 * @tree: a pointer to the node of the tree
 */
void node_loop(link_t **hd, const binary_tree_t *tree)
{
	size_t depth = 0;

	if (tree != NULL)
	{
		depth = binary_tree_depth(tree);
		node_list(hd, tree, depth);
		node_loop(hd, tree->left);
		node_loop(hd, tree->right);
	}
}
/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * @tree: a pointer to the root node of the tree to traverse
 * @func: a pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	link_t *hd;
	link_t *b;
	size_t height = 0;
	size_t z = 0;

	if (!tree || !func)
	{
		return;
	}
	else
	{
		height = binary_tree_height(tree);
		hd = NULL;
		node_loop(&hd, tree);
		while (z <= height)
		{
			b = hd;
			while (b != NULL)
			{
				if (z == b->n)
				{
					func(b->nodeIN->n);
				}
				b = b->nextIN;
			}
			z++;
		}
		while (hd != NULL)
		{
			b = hd;
			hd = hd->nextIN;
			free(b);
		}
	}
}

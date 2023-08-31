#include "binary_trees.h"
/**
 * bst_search - searches for a value in a Binary Search Tree
 * @tree: a pointer to the root node of the BST to search
 * @value: the value to search in the tree
 * Return: a pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *val;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		val = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		val = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (val);
}

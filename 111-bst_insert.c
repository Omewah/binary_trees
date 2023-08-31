#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, Else NULL (failed)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *a;
	bst_t *b;
	binary_tree_t *c;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		c = binary_tree_node((binary_tree_t *)(*tree), value);
		a = (bst_t *)c;
		*tree = a;
	}
	else
	{
		b = *tree;
		if (value < b->n)
		{
			if (b->left)
				a = bst_insert(&b->left, value);
			else
			{
				c = binary_tree_node((binary_tree_t *)b, value);
				a = b->left = (bst_t *)c;
			}
		}
		else if (value > b->n)
		{
			if (b->right)
				a = bst_insert(&b->right, value);
			else
			{
				c = binary_tree_node((binary_tree_t *)b, value);
				a = b->right = c;
			}
		}
		else
			return (NULL);
	}
	return (a);
}

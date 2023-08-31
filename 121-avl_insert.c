#include "binary_trees.h"

/**
 * node_value - the value of node for instertion
 * @tree: double pointer to the root node of the AVL tree
 * @par: the parent node
 * @a: a pointer to either left or right node
 * @vin: the value to insert
 * Return: the node value
 */
avl_t *node_value(avl_t **tree, avl_t *par, avl_t **a, int vin)
{
	int v;

	if (*tree == NULL)
		return (*a = binary_tree_node(par, vin));
	if ((*tree)->n > vin)
	{
		(*tree)->left = node_value(&(*tree)->left, *tree, a, vin);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < vin)
	{
		(*tree)->right = node_value(&(*tree)->right, *tree, a, vin);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	v = binary_tree_balance(*tree);
	if (v > 1 && (*tree)->left->n > vin)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (v > 1 && (*tree)->left->n < vin)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (v < -1 && (*tree)->right->n < vin)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (v < -1 && (*tree)->right->n > vin)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}
/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * @value: the value to store in the node to be inserted
 * Return: a pointer to the created node, Else NULL (failed)
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *a = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	node_value(tree, *tree, &a, value);
	return (a);
}

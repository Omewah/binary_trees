#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right child
 * @parent: pointer to the node that inserts the right child
 * @value: the value to store the new node
 * Return: new node or NULL for failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *mint_node;

	if (parent == NULL)
	{
		return (NULL);
	}

	mint_node = binary_tree_node(parent, value);
	if (mint_node == NULL)
	{
		return (NULL);
	}
	if (parent->right != NULL)
	{
		mint_node->right = parent->right;
		parent->right->parent = mint_node;
	}
	parent->right = mint_node;
	return (mint_node);
}

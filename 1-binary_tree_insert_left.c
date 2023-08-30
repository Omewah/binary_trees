#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left child
 * @parent: pointer to the node thats inserts the child
 * @value: value to store the new node
 * Return: new node or NULL for failure
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if (parent->left != NULL)
	{
		mint_node->left = parent->left;
		parent->left->parent = mint_node;
	}
	parent->left = mint_node;
	return (mint_node);
}

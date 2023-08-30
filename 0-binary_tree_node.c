#include "binary_trees.h"

/**
 * binary_tree_node - a function that creates a binary node
 * @parent: the parent of the node
 * @value: the node value
 * Return: the new node created
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *mint_node;

	mint_node = malloc(sizeof(binary_tree_t));
	if (mint_node == NULL)
	{
		return (NULL);
	}
	mint_node->n = value;
	mint_node->parent = parent;
	mint_node->left = NULL;
	mint_node->right = NULL;
	return (mint_node);
}

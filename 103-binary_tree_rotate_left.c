#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *spin_l;

	if (tree == NULL || tree->right == NULL)
	{
		return (NULL);
	}
	spin_l = tree->right;
	tree->right = spin_l->left;
	if (spin_l->left != NULL)
	{
		spin_l->left->parent = tree;
	}
	spin_l->left = tree;
	spin_l->parent = tree->parent;
	tree->parent = spin_l;
	return (spin_l);
}

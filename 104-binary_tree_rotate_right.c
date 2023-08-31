#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *spin_r;

	if (tree == NULL || tree->left == NULL)
	{
		return (NULL);
	}
	spin_r = tree->left;
	tree->left = spin_r->right;
	if (spin_r->right != NULL)
	{
		spin_r->right->parent = tree;
	}
	spin_r->right = tree;
	spin_r->parent = tree->parent;
	tree->parent = spin_r;
	return (spin_r);
}

#include "binary_trees.h"
/**
 * current_node - gets the active node of the tree
 * @root: a pointer to the root node of the tree
 * Return: the value of the node
 */
int current_node(bst_t *root)
{
	int a = 0;

	if (root == NULL)
	{
		return (0);
	}
	else
	{
		a = current_node(root->left);
		if (a == 0)
		{
			return (root->n);
		}
		return (a);
	}

}
/**
 * next_node - gets the next active node of the tree
 * @root: a pointer to the root node of the tree 
 * Return: the value of the node
 */
int next_node(bst_t *root)
{
	int a = 0;

	a = successor(root->right);
	root->n = a;
	return (a);
}
/**
 *remove_node - frees a node
 *@root: a pointer to the root node of the tree 
 *Return: 0 if no child
 */
int remove_node(bst_t *root)
{
	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
		return (next_node(root));
}
/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int a = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		a = remove_node(root);
		if (a != 0)
			bst_remove(root->right, a);
	}
	else
		return (NULL);
	return (root);
}

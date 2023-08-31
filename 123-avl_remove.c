#include "binary_trees.h"

/**
 * tree_balance - checks if an AVL tree is balanced
 * @tree: a double pointer to the root node of the tree
 * Return: the balanced tree
 */
void tree_balance(avl_t **tree)
{
	int a;

	if (tree == NULL || *tree == NULL)
		return;
	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;
	tree_balance(&(*tree)->left);
	tree_balance(&(*tree)->right);
	a = binary_tree_balance((const binary_tree_t *)*tree);
	if (a > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (a < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
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
 * remove_node - frees a node
 * @root: a pointer to the root node of the tree
 * Return: 0 if no child
 */
int remove_node(bst_t *root)
{
	int a = 0;

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
	{
		a = current_node(root->right);
		root->n = a;
		return (a);
	}
}
/**
 * bst_remove - remove a node from a Binary Search Tree
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

/**
 * avl_remove - remove a node from a AVL tree
 * @root: a pointer to the root node of the tree for removing a node
 * @value: the value to remove in the tree
 * Return: a pointer to the new root node of the tree
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *a = (avl_t *) bst_remove((bst_t *) root, value);

	if (a == NULL)
		return (NULL);
	tree_balance(&a);
	return (a);
}

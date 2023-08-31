#include "binary_trees.h"
/**
 * create_node - creates a node in a LL
 * @node: pointer of a node to be created
 * Return: the new node created
 */
link_t *create_node(binary_tree_t *node)
{
	link_t *a;

	a =  malloc(sizeof(link_t));
	if (a == NULL)
	{
		return (NULL);
	}
	a->nodeIN = node;
	a->nextIN = NULL;

	return (a);
}
/**
 * free_node - frees a node
 * @hd: pointer to the head of the LL
 */
void free_node(link_t *hd)
{
	link_t *a;

	while (hd)
	{
		a = hd->nextIN;
		free(hd);
		hd = a;
	}
}
/**
 * add_node - adds a node to the stack
 * @node: pointer to the node to be added
 * @hd: pointer to the head of the LL
 * @tail: pointer to the tail of the LL
 */
void add_node(binary_tree_t *node, link_t *hd, link_t **tail)
{
	link_t *a;

	a = create_node(node);
	if (a == NULL)
	{
		free_node(hd);
		exit(1);
	}
	(*tail)->nextIN = a;
	*tail = a;
}
/**
 * pop_node - pops a node from the stack
 * @hd: pointer to the head of the LL
 */
void pop_node(link_t **hd)
{
	link_t *a;

	a = (*hd)->nextIN;
	free(*hd);
	*hd = a;
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * Return: tree is complete, Else 0 if NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	link_t *hd;
	link_t *tail;
	int z = 0;

	if (tree == NULL)
	{
		return (0);
	}
	hd = tail = create_node((binary_tree_t *)tree);
	if (hd == NULL)
	{
		exit(1);
	}
	while (hd != NULL)
	{
		if (hd->nodeIN->left != NULL)
		{
			if (z == 1)
			{
				free_node(hd);
				return (0);
			}
			add_node(hd->nodeIN->left, hd, &tail);
		}
		else
			z = 1;
		if (hd->nodeIN->right != NULL)
		{
			if (z == 1)
			{
				free_node(hd);
				return (0);
			}
			add_node(hd->nodeIN->right, hd, &tail);
		}
		else
			z = 1;
		pop_node(&hd);
	}
	return (1);
}

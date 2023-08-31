#include "binary_trees.h"
/**
 * partial_tree - creates a tree from a partial sorted array
 * @par: the parent array
 * @array: a pointer to the partial sorted array
 * @head: the head of the array
 * @tail: the tail of the array
 * Return: tree from the partial sorted array
 */
avl_t *partial_tree(avl_t *par, int *array, int head, int tail)
{
	avl_t *z;
	binary_tree_t *b;
	int a = 0;

	if (head <= tail)
	{
		a = (head + tail) / 2;
		b = binary_tree_node((binary_tree_t *)par, array[a]);
		if (b == NULL)
			return (NULL);
		z = (avl_t *)b;
		z->left = partial_tree(z, array, head, a - 1);
		z->right = partial_tree(z, array, a + 1, tail);
		return (z);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (partial_tree(NULL, array, 0, ((int)(size)) - 1));
}

#include "binary_trees.h"
/**
 * array_to_bst - builds a Binary Search Tree from an array
 * @array: a pointer to the first element of the array
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t a = 0;
	bst_t *z;

	z = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (; a < size; a++)
	{
		if (a == 0)
		{
			bst_insert(&z, array[a]);
		}
		else
		{
			bst_insert(&z, array[a]);
		}
	}
	return (z);
}

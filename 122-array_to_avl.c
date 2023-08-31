#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array
 * @size: the number of element in the array
 * Return: a pointer to the root node of the created AVL tree
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t a;
	size_t b = 0;
	avl_t *z;

	z = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (avl_insert(&z, array[a]) == NULL)
			{
				return (NULL);
			}
		}
	}
	return (z);
}

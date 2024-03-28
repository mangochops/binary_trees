#include "binary_trees.h"

/**
 * Turns an array into an AVL tree.
 * @array: Array to be turned into AVL tree.
 * @size: Size of the array.
 * Return: AVL tree created from the array.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i, j;
	avl_t *root = NULL;

	if (size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (array[j] == array[i])
				break;
		}

		if (j == i)
		{
			if (avl_insert(&root, array[i]) == NULL)
				return (NULL);
		}
	}
	return (root);
}

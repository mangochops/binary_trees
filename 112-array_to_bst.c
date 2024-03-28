#include "binary_trees.h"

/**
 * array_to_bst - Converts an array to a Binary Search Tree (BST)
 * @array: Array to convert to BST.
 * Return: Pointer to the root of the BST
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i = 0;
	bst_t *root;

	root = NULL;
	if (size == 0)
	{
		return (NULL);
	}
		for (; i < size; i++)
	{
		if (i == 0)
	{
		bst_insert(&root, array[i]);
	}
	else
	{
		bst_insert(&root, array[i]);
	}
	}
		return (root);
}

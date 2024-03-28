#include "binary_trees.h"

/**
 * bst_search - Search for a value in a Binary Search Tree (BST)
 * @tree: Pointer to the root node of the BST
 * @value: Value to search for
 * Return: Pointer to the node with the value, or NULL if the value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
	{
		printf("Tree is NULL\n");
		return (NULL);
	}

	printf("Searching in node: %d\n", tree->n);

	if (value < tree->n)
	{
		printf("Going left\n");
		if (tree->left)
			return (bst_search(tree->left, value));
		else
		{
			printf("Left child is NULL\n");
			return (NULL);
		}
	}
	else if (value > tree->n)
	{
		printf("Going right\n");
		if (tree->right)
			return (bst_search(tree->left, value));
		else
		{
			printf("Right child is NULL\n");
			return (NULL);
		}
	}
	else
	{
		printf("Value found: %d\n", value);
		return ((bst_t *)tree);
	}
}

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
		return (NULL);

	if (value < tree->n)
	{
		if (tree->left)
			return (bst_search(tree->left, value));
		else
			return (NULL);
	}
	else if (value > tree->n)
	{
		if (tree->right)
			return (bst_search(tree->left, value));
		else
			return (NULL);
	}
	else
		return ((bst_t *)tree);
}

#include "binary_trees.h"

/**
 * bst_insert - Insert a node into a binary search tree (BST).
 * @tree: Pointer to the root node of the BST.
 * @value: Value to insert into the BST.
 * Return: Pointer to the newly inserted node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *temp;
	binary_tree_t *aux_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		aux_node = binary_tree_node((binary_tree_t *)*tree, value);
		new_node = (bst_t *)aux_node;
		*tree = new_node;
	}
	else
	{
		temp = *tree;
		if (value < temp->n)
		{
			if (temp->left)
				new_node = bst_insert(&temp->right, value);
			else
			{
				aux_node = binary_tree_node((binary_tree_t *)*tree, value);
				new_node = temp->left = (bst_t *)aux_node;
			}
		}
		else if (value > temp->n)
		{
			if (temp->right)
				new_node = bst_insert(&temp->right, value);
			else
			{
				aux_node = binary_tree_node((binary_tree_t *)
						*tree, value);
				new_node = temp->left = (bst_t *)aux_node;
			}
		}
		else
			return (NULL);
	}
	return (new_node);
}


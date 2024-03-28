#include "binary_trees.h"

/**
 * r_insert_node - Inserts a node value in an AVL tree recursively
 * @tree: Pointer to the root node of the AVL tree
 * @parent: Parent node of the current node.
 * @new: Pointer to the new node being inserted.
 * @value: Value to insert into the AVL tree.
 * Return: Pointer to the new root after insertion, otherwise NULL.
 */
avl_t *r_insert_node(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int balance_factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));
	if ((*tree)->n > value)
	{
		(*tree)->left = r_insert_node(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = r_insert_node(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
	{
		return (*tree);
	}
	balance_factor = binary_tree_balance(*tree);
	if (balance_factor > 1 && (*tree)->left->n > value)
	{
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n < value)
	{
		*tree = binary_tree_rotate_left(*tree);
	}
	else if (balance_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: Pointer to the root node of the AVL tree to insert into.
 * @value: Value to store in the node to be inserted.
 * Return: Pointer to the inserted node, or NULL if insertion fails.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	r_insert_node(tree, *tree, &new, value);
	return (new);
}

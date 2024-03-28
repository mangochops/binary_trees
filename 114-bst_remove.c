#include "binary_trees.h"

/**
 * get_successor - Finds the minimum value in the right subtree.
 * @node: The node to start searching from.
 * Return: The minimum value found or 0 if node is NULL
 */
int get_successor(bst_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL)
		return (node->n);

	return (get_successor(node->left));
}

/**
 * replace_and_remove - Replaces a node's value successor and removes it.
 * @node: The node to remove.
 * Return: The value of the removed node.
 */
int replace_and_remove(bst_t *node)
{
	int new_value = get_successor(node->right);

	node->n = new_value;

	return (new_value);
}

/**
 * remove_type - Removes a node based on its children
 * @root: The node to remove.
 * Return: 0 if no children, 1 if one child,
 */
int remove_type(bst_t *root)
{
	if (root->left == NULL && root->right == NULL)
	{
		if (root->parent != NULL)
		{
			if (root->parent->left == root)
				root->parent->left = NULL;
			else
				root->parent->right = NULL;
		}
		free(root);
		return (0);
	}

	if (root->left == NULL || root->right == NULL)
	{
		bst_t *child = (root->left != NULL) ? root->left : root->right;

		if (root->parent != NULL)
		{
			if (root->parent->left == root)
				root->parent->left = child;
			else
				root->parent->right = child;
			child->parent = root->parent;
		}
		free(root);
		return (1);
	}
	return (2);
}

/**
 * bst_remove - Removes a node from a BST tree.
 * @root: The root of the tree.
 * @value: The value to remove.
 * Return: The updated tree after removal.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		int type = remove_type(root);

		if (type == 2)
			root->n = replace_and_remove(root->right);
	}

	return (root);
}

#include "binary_trees.h"

/**
 *  * binary_tree_rotate_left - Rotate a binary tree to the left.
 *   * @tree: Pointer to the root node of the tree to rotate.
 *    *
 *     * Return: Pointer to the new root node of the tree.
 *      */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	    binary_tree_t *pivot;
	    
	    /* Check if tree and its right child exist */
	    if (tree == NULL || tree->right == NULL)
	    {
		    /* Return NULL if rotation is not possible */
		    return (NULL);
	    }

	    /* Store the right child as pivot */
	    pivot = tree->right;
	    
	    /* Update tree's right child */
	    tree->right = pivot->left;

	    /* Update parent pointers */
	    if (pivot->left != NULL)
	    {
		    pivot->left->parent = tree;
	    }

	    /* Update pivot's left child and parent */
	    pivot->left = tree;
	    pivot->parent = tree->parent;
	    tree->parent = pivot;
	    
	    /* Return the new root node */
	    return (pivot);
}

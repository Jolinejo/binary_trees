#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate node to the left
 * Description: the movement of the node to down to the left
 * @tree: root node to move
 * Return: nothing
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent;

	if (tree == NULL)
		return (NULL);
	parent = tree->parent;

	/*check if the node was left or right child*/
	if (parent != NULL && parent->left == tree)
	{
		parent->left = tree->right;
		/*set the new parent of tree node right child*/
		tree->right->parent = parent;
		/*
		 * set the left child of tree node's right child
		 * as tree node's new right child
		 */
		tree->right = tree->right->left;
		/*set the old child of the tree as its parent*/
		tree->parent = parent->left;
		/*
		 * set the tree as the left child of the old right child
		 */
		parent->left->left =  tree;
	}
	else if (parent != NULL)
	{
		parent->right = tree->right;
		tree->right->parent = parent;
		tree->right = tree->right->left;
		tree->parent = parent->right;
		parent->right->left =  tree;
	}
	else
	{
		tree->parent = tree->right;
		tree->right->parent = parent;
		tree->right = tree->right->left;
		tree->parent->left = tree;
	}
	return (tree->parent);
}

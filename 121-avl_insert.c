#include "binary_trees.h"
/**
 * balance_tree - balances avl tree
 * @node: node to start balancing from
 */
void balance_tree(avl_t *node)
{
	avl_t *tmp;
	int balance;
	int value = node->n;

	while (node->parent)
	{
		balance = binary_tree_balance(node->parent);
		if (balance > 1)

			if (value > node->parent->left->n)
			{
				tmp = node->parent;
				binary_tree_rotate_left(node->parent->left);
				binary_tree_rotate_right(tmp);
				return;
			}
			else
			{
				binary_tree_rotate_right(node->parent);
				return;
			}
		else if (balance < -1)
		{
			if (value < node->parent->right->n)
			{
				tmp = node->parent;
				binary_tree_rotate_right(node->parent->right);
				binary_tree_rotate_left(tmp);
				return;
			}
			else
			{
				binary_tree_rotate_left(node->parent);
				return;
			}
		}
		node = node->parent;
	}
}
/**
 * avl_insert - inserts a value in a Balanced Binary Search Tree
 * @tree: a double pointer to the root node of the avl to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
avl_t *avl_insert(bst_t **tree, int value)
{
	avl_t *tmp = NULL, *second = NULL, *new = NULL;

	if (!tree)
		return (NULL);
	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	tmp = *tree;
	while (tmp)
	{
		second = tmp;
		if (value < tmp->n)
			tmp = tmp->left;
		else if (value > tmp->n)
			tmp = tmp->right;
		else if (value == tmp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (second == NULL)
		second = new;
	else if (value < second->n)
	{
		second->left = new;
		new->parent = second;
	}
	else
	{
		second->right = new;
		new->parent = second;
	}
	balance_tree(new);
	return (new);
}

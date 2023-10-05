#include "binary_trees.h"
/**
 * avl_insert - inserts a value in a Balanced Binary Search Tree
 * @tree: a double pointer to the root node of the avl to insert the value
 * @value: the value to store in the node to be inserted
 * Return: A pointer to the created node
 *         NULL on failure
 */
avl_t *_avl_insert(int *array, int start, int end, avl_t *parent)
{
	avl_t *root = NULL;
	int i = (start + end) / 2;

	if (start > end)
		return NULL;
	root = binary_tree_node(parent, array[i]);
	root->right = _avl_insert(array, i + 1, end, root);
	root->left = _avl_insert(array, start, i - 1, root);
	return (root);

}
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	
	root = _avl_insert(array, 0, (int)size - 1, NULL);
	return (root);

}

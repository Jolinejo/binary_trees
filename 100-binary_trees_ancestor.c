#include "binary_trees.h"

typedef struct ancestors_s
{
	const struct binary_tree_s *node;
	struct ancestors_s *next;
} ancestors_t;
void free_list(ancestors_t *head)
{
	ancestors_t *temp1 = head;
	ancestors_t *temp2;

	if (head == NULL)
		return;
	while (temp1)
	{
		temp2 = temp1;
		temp1 = temp1->next;
		free(temp2);
	}

}
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;
	size_t first_ancestors = 0, second_ancestors = 0;

	if (first == NULL || second == NULL)
		return (NULL);
	first_parent = first->parent;
	second_parent = second->parent;
	ancestors_t *f_head = malloc(sizeof(ancestors_t));
	f_head->node = first;
	f_head->next = NULL;
	ancestors_t *s_head = malloc(sizeof(ancestors_t));
	s_head->node = second;
        s_head->next = NULL;
	ancestors_t *temp = f_head;
	while (first_parent != NULL)
	{
		first_ancestors += 1;
		ancestors_t *new = malloc(sizeof(ancestors_t));
		new->node = first_parent;
		new->next = NULL;
		temp->next = new;
		temp = new;
		first_parent = first_parent->parent;
	}
	temp = s_head;
	while (second_parent != NULL)
        {
                second_ancestors += 1;
                ancestors_t *new = malloc(sizeof(ancestors_t));
                new->node = second_parent;
                new->next = NULL;
                temp->next = new;
                temp = new;
                second_parent = second_parent->parent;
        }
	ancestors_t *f_temp1 = f_head;
	ancestors_t *s_temp1 = s_head;
	while (first_ancestors > second_ancestors)
	{
		first_ancestors -= 1;
		f_head = f_head->next;
	}
	while (first_ancestors < second_ancestors)
        {
                second_ancestors -= 1;
                s_head = s_head->next;
        }
	while (s_head->node != f_head->node)
	{
		s_head = s_head->next;
		f_head = f_head->next;
	}
	binary_tree_t * return_node = (binary_tree_t *)s_head->node;
	free_list(f_temp1);
	free_list(s_temp1);
	return (return_node);

}

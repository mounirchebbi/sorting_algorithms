#include "sort.h"
/**
 * swaper - Swap nodes
 * @h: pointer
 * @n1: first node
 * @n2: second node
 */
void swaper(listint_t **h, listint_t **n1, listint_t *n2)
{
	(*n1)->next = n2->next;
	if (n2->next != NULL)
		n2->next->prev = *n1;
	n2->prev = (*n1)->prev;
	n2->next = *n1;
	if ((*n1)->prev != NULL)
		(*n1)->prev->next = n2;
	else
		*h = n2;
	(*n1)->prev = n2;
	*n1 = n2->prev;
}

/**
 * insertion_sort_list - sort by insertion
 * @list: pointer
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		insert = node->prev;
		while (insert != NULL && node->n < insert->n)
		{
			swaper(list, &insert, node);
			print_list((const listint_t *)*list);
		}
	}
}

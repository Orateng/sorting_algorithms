#include "sort.h"
/**
 *insertion_sort_list - Insert sort a doubly linked list
 *@list: List for insertion sort
 *Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sort = NULL, *temp = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	sort = *list;
	sort = sort->next;
	while (sort)
	{
		while (sort->prev && sort->n < (sort->prev)->n)
		{
			temp = sort;
			if (sort->next)
				(sort->next)->prev = temp->prev;
			(sort->prev)->next = temp->next;
			sort = sort->prev;
			temp->prev = sort->prev;
			temp->next = sort;
			if (sort->prev)
				(sort->prev)->next = temp;
			sort->prev = temp;
			if (temp->prev == NULL)
				*list = temp;
			print_list(*list);
			sort = sort->prev;
		}
		sort = sort->next;
	}

}

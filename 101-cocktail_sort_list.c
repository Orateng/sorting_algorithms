#include "sort.h"

/**
 *swap - Swap a node and a  node in the list
 *@list: Node list
 *@node: Node to swap
 *Return: Return void
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 *cocktail_sort_list - A function that implement the cocktail sorting
 *@list: The list for the doubly linked list
 */

void cocktail_sort_list(listint_t **list)
{
	char swapped = 1;
	listint_t *temp;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swapped != 0)
	{
		swapped = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap(list, temp);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (temp->prev != NULL)
		{
			if (temp->prev->n > temp->n)
			{
				swap(list, temp->prev);
				swapped = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}

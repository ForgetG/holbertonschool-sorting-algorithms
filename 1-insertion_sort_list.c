#include "sort.h"

/**
 * insertion_sort_list - that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp, *next;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		next = current->next;
		temp = current->prev;


		while (temp != NULL && temp->n > current->n)
		{
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;

			if (current->next != NULL)
				current->next->prev = temp;

			temp->next = current->next;
			current->prev = temp->prev;
			current->next = temp;
			temp->prev = current;

			temp = current->prev;

			print_list(*list);
		}
		current = next;
	}
}

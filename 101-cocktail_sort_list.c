#include "sort.h"
#include <stdio.h>
/**
 * swap_next_node - Swap a node in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr: A pointer to the current swapping node of the cocktail shaker algo.
 *
 * Return: Nothing.
 */
void swap_next_node(listint_t **head, listint_t **tail, listint_t **curr)
{
	listint_t *tmp = (*curr)->next;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = tmp;
	else
		*head = tmp;
	tmp->prev = (*curr)->prev;
	(*curr)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *curr;
	else
		*tail = *curr;
	(*curr)->prev = tmp;
	tmp->next = *curr;
	*curr = tmp;
}
/**
 * swap_prev_node - Swap a node in a listint_t doubly-linked
 *                  list of integers with the node before it.
 * @head: A pointer to the head of a doubly-linked list of integers.
 * @tail: A pointer to the tail of the doubly-linked list.
 * @curr: A pointer to the current swapping node of the cocktail shaker algo.
 *
 * Return: Nothing.
 */
void swap_prev_node(listint_t **head, listint_t **tail, listint_t **curr)
{
	listint_t *tmp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*curr)->next;
	(*curr)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *curr;
	else
		*head = *curr;
	(*curr)->next = tmp;
	tmp->prev = *curr;
	*curr = tmp;
}

/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 *                      ascending order using the cocktail shaker algorithm.
 * @list: A pointer to the head of a listint_t doubly-linked list.
 *
 * Return: Nothing.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool swapped = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (swapped == false)
	{
		swapped = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				swap_next_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				swap_prev_node(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				swapped = false;
			}
		}
	}
}


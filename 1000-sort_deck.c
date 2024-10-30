#include "deck.h"


/**
 * _strcmp - Compares two strings.
 * @str1: The first string to be compared.
 * @str2: The second string to be compared.
 *
 * Return: Positive byte difference if str1 > str2
 *         0 if str1 == str2
 *         Negative byte difference if str1 < str2
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	if (*str1 != *str2)
		return (*str1 - *str2);
	return (0);
}

/**
 * card_value - Retrieve the numeric index of a card.
 * @node: A pointer to a deck_node_t node.
 *
 * Return: The numeric index of the card.
 */
char card_value(deck_node_t *node)
{
	if (_strcmp(node->card->value, "Ace") == 0)
		return (0);
	if (_strcmp(node->card->value, "1") == 0)
		return (1);
	if (_strcmp(node->card->value, "2") == 0)
		return (2);
	if (_strcmp(node->card->value, "3") == 0)
		return (3);
	if (_strcmp(node->card->value, "4") == 0)
		return (4);
	if (_strcmp(node->card->value, "5") == 0)
		return (5);
	if (_strcmp(node->card->value, "6") == 0)
		return (6);
	if (_strcmp(node->card->value, "7") == 0)
		return (7);
	if (_strcmp(node->card->value, "8") == 0)
		return (8);
	if (_strcmp(node->card->value, "9") == 0)
		return (9);
	if (_strcmp(node->card->value, "10") == 0)
		return (10);
	if (_strcmp(node->card->value, "Jack") == 0)
		return (11);
	if (_strcmp(node->card->value, "Queen") == 0)
		return (12);
	return (13);
}

/**
 * insertion_sort_by_suit - Sort a deck of cards from spades to diamonds.
 * @head: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * Return: Nothing.
 */
void insertion_sort_by_suit(deck_node_t **head)
{
	deck_node_t *current, *previous, *tmp;

	for (current = (*head)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		previous = current->prev;
		while (previous != NULL && previous->card->kind > current->card->kind)
		{
			previous->next = current->next;
			if (current->next != NULL)
				current->next->prev = previous;
			current->prev = previous->prev;
			current->next = previous;
			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*head = current;
			previous->prev = current;
			previous = current->prev;
		}
	}
}

/**
 * insertion_sort_by_value - Sort a deck of cards sorted from
 *                           spades to diamonds from ace to king.
 * @head: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * Return: Nothing.
 */
void insertion_sort_by_value(deck_node_t **head)
{
	deck_node_t *current, *previous, *tmp;

	for (current = (*head)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		previous = current->prev;
		while (previous != NULL &&
		       previous->card->kind == current->card->kind &&
		       card_value(previous) > card_value(current))
		{
			previous->next = current->next;
			if (current->next != NULL)
				current->next->prev = previous;
			current->prev = previous->prev;
			current->next = previous;
			if (previous->prev != NULL)
				previous->prev->next = current;
			else
				*head = current;
			previous->prev = current;
			previous = current->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from ace to king and
 *             from spades to diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 *
 * Return: Nothing
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_by_suit(deck);
	insertion_sort_by_value(deck);
}

#include "sort.h"

/**
 * swapNodes -Function that swaps 2 nodes in a doubly-linked list
 * @headNode: Pointer to the head of the doubly-linked list
 * @node1: Pointer to the 1st node to swap
 * @node2: Pointer to the 2nd node to swap
 */
void swapNodes(listint_t **headNode, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*headNode = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of ints
 * @list: A pointer to the head of a doubly-linked list of ints
 * Description: Prints the list after every swap
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterateNode, *insert, *tempNode;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iterateNode = (*list)->next; iterateNode != NULL; iterateNode = tempNode)
	{
		tempNode = iterateNode->next;
		insert = iterateNode->prev;
		while (insert != NULL && iterateNode->n < insert->n)
		{
			swapNodes(list, &insert, iterateNode);
			print_list((const listint_t *)*list);
		}
	}
}


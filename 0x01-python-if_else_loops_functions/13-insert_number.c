#include "lists.h"

struct listint_t {
	int data;
	struct listint_t *next;
};
struct listint_t *insert_node(listint_t **head, int number) {
	struct listint_t *new_node = (struct listint_t *)malloc(sizeof(struct listint_t));
	if (new_node == NULL) {
	return NULL;
	}
	new_node->data = number;
	new_node->next = *head;
	*head = new_node;
	return new_node;
}

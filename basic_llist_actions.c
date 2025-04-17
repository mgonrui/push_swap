#include "push_swap.h"

void remove_beggining_node(Node **root)
{
    Node *new_root;
    new_root = (*root)->next;
    free(*root);
    *root = new_root;
}

void add_beginning_node(Node **root, int value)
{
    Node *new_node;
    new_node = malloc(sizeof (Node));
    if (new_node == NULL)
        exit (1);
    new_node->value = value;
    new_node->next = *root;
    *root = new_node;
    return ;
}

void add_end_node(Node **root, int value)
{
    Node *new_node;
    Node *current_node;
    int index;

    index = 1;
    if (*root == NULL)
    {
        (*root) = malloc (sizeof(Node));
        (*root)->value = value;
        (*root)->prev = NULL;
        (*root)->index = 0;
        (*root)->next = NULL;
        return ;
    }
    new_node = malloc(sizeof (Node));
    if (new_node == NULL)
        exit (1);
    new_node->value = value;
    new_node->next = NULL;
    current_node = *root;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
        index++;
    }
    new_node->index = index;
    new_node->prev = current_node;
    current_node->next = new_node;
}

int count_nodes(Node *root)
{
    Node *current_node;
    int i;
    i = 0;
    current_node = root;
    while(current_node != NULL)
    {
        current_node = current_node->next;
        i++;
    }
    return i;
}

void free_llist(Node *root)
{
	Node *current;
	Node *prev;
	current = root;
	while(current != NULL)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
}

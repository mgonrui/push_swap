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

// checked
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

/* void index_nodes(Node *root_a, Node *root_b) */
/* { */
/*     int i; */
/*     i = 0; */
/*     while(root_a != NULL) */
/*     { */
/*         root_a->index = i++; */
/*         root_a = root_a->next; */
/*     } */
/*     i = 0; */
/*     while(root_b != NULL) */
/*     { */
/*         root_b->index = i++; */
/*         root_b = root_b->next; */
/*     } */
/*     return ; */
/* } */

// checked
void index_nodes(Node *root_a, Node *root_b)
{
	int	i;
	int	centerline;

	i = 0;
	centerline = count_nodes(root_a) / 2;
	while (root_a)
	{
		root_a->index = i;
		if (i <= centerline)
			root_a->on_top_half = true;
		else
			root_a->on_top_half = false;
		root_a = root_a->next;
		++i;
	}
	i = 0;
	centerline = count_nodes(root_b) / 2;
	while (root_b)
	{
		root_b->index = i;
		if (i <= centerline)
			root_b->on_top_half = true;
		else
			root_b->on_top_half = false;
		root_b = root_b->next;
		++i;
	}

}

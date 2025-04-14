#include "push_swap.h"

void swap(Node **root)
{
    Node *first;
    Node *second;

    first = *root;
    second = (*root)->next;

    first->next = second->next;
    second->next = first;
    *root = second;
}

void rotate_reverse(Node **root)
{
   Node *current;
   Node *previous;

   current = *root;
   previous = NULL;
   while (current->next != NULL)
   {
       previous = current;
       current = current->next;
   }
   current->next = *root;
   *root = current;
   previous->next = NULL;
}

void rotate(Node **root)
{
   Node *current;
   Node *new_root;

   new_root = (*root)->next;
   current = *root;
   while (current->next != NULL)
   {
       current = current->next;
   }
   current->next = *root;
   (*root)->next = NULL;
   *root = new_root;
}

void push(Node **root_src, Node **root_dst)
{
    add_beginning_node(root_dst, (*root_src)->value);
    remove_beggining_node(root_src);
}

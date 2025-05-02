/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_llist_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:56:26 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:56:27 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_beggining_node(t_node **root)
{
	t_node	*new_root;

	new_root = (*root)->next;
	free(*root);
	*root = new_root;
}

void	add_beginning_node(t_node **root, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->value = value;
	new_node->next = *root;
	*root = new_node;
	return ;
}

void	add_end_node(t_node **root, int value)
{
	t_node	*new_node;
	t_node	*current_node;
	int		index;

	index = 1;
	if (*root == NULL)
	{
		init_root(root, value);
		return ;
	}
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
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

int	count_nodes(t_node *root)
{
	t_node	*current_node;
	int		i;

	i = 0;
	current_node = root;
	while (current_node != NULL)
	{
		current_node = current_node->next;
		i++;
	}
	return (i);
}

void	free_llist(t_node *root)
{
	t_node	*current;
	t_node	*prev;

	current = root;
	while (current != NULL)
	{
		prev = current;
		current = current->next;
		free(prev);
	}
}

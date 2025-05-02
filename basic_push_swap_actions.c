/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_push_swap_actions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:56:13 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:56:20 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **root)
{
	t_node	*first;
	t_node	*second;

	first = *root;
	second = (*root)->next;
	first->next = second->next;
	second->next = first;
	*root = second;
}

void	rotate_reverse(t_node **root)
{
	t_node	*current;
	t_node	*previous;

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

void	rotate(t_node **root)
{
	t_node	*current;
	t_node	*new_root;

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

void	push(t_node **root_src, t_node **root_dst)
{
	add_beginning_node(root_dst, (*root_src)->value);
	remove_beggining_node(root_src);
}

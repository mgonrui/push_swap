/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_costs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:56:09 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:56:10 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target_node(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;
	t_node	*target_node;
	int		best_target;

	while (stack_b != NULL)
	{
		best_target = MAX_INT;
		current = stack_a;
		while (current != NULL)
		{
			if (current->value > stack_b->value && current->value < best_target)
			{
				best_target = current->value;
				target_node = current;
			}
			current = current->next;
		}
		if (MAX_INT == best_target)
			stack_b->target_node = find_smallest(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

void	calculate_cost(t_node *stack_a, t_node *stack_b)
{
	t_node	*current;

	current = stack_b;
	while (current != NULL)
	{
		current->cost = current->index;
		if (current->on_top_half == false)
			current->cost = count_nodes(stack_b) - current->index;
		if (current->target_node->on_top_half == true)
			current->cost += current->target_node->index;
		else
			current->cost += count_nodes(stack_a) - current->target_node->index;
		current = current->next;
	}
	return ;
}

void	index_nodes(t_node *root_a, t_node *root_b)
{
	int	i;
	int	centerline;

	i = 0;
	centerline = count_nodes(root_a) / 2;
	while (root_a)
	{
		root_a->index = i;
		if (i++ <= centerline)
			root_a->on_top_half = true;
		else
			root_a->on_top_half = false;
		root_a = root_a->next;
	}
	i = 0;
	centerline = count_nodes(root_b) / 2;
	while (root_b)
	{
		root_b->index = i;
		if (i++ <= centerline)
			root_b->on_top_half = true;
		else
			root_b->on_top_half = false;
		root_b = root_b->next;
	}
}

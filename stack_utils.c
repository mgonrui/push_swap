/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:33 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:55:34 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*flag_cheapest(t_node *stack_b)
{
	t_node	*cheapest;

	cheapest = stack_b;
	while (stack_b != NULL)
	{
		stack_b->cheapest = false;
		if (cheapest->cost > stack_b->cost)
			cheapest = stack_b;
		stack_b = stack_b->next;
	}
	cheapest->cheapest = true;
	return (cheapest);
}

t_node	*find_largest(t_node *stack)
{
	t_node	*largest;
	t_node	*current;

	current = stack;
	largest = current;
	while (current != NULL)
	{
		if (largest->value < current->value)
			largest = current;
		current = current->next;
	}
	return (largest);
}

t_node	*find_smallest(t_node *stack)
{
	t_node	*current;
	t_node	*smallest_node;

	current = stack;
	smallest_node = stack;
	while (current != NULL)
	{
		if (current->value < smallest_node->value)
			smallest_node = current;
		current = current->next;
	}
	return (smallest_node);
}

bool	on_same_half_stack(t_node *tomove)
{
	if ((tomove->on_top_half == true
			&& tomove->target_node->on_top_half == true)
		|| (tomove->on_top_half == false
			&& tomove->target_node->on_top_half == false))
		return (true);
	else
		return (false);
}

void	restart_stacks(t_node *stack_a, t_node *stack_b)
{
	index_nodes(stack_a, stack_b);
	find_target_node(stack_a, stack_b);
	calculate_cost(stack_a, stack_b);
	flag_cheapest(stack_b);
}

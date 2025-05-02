/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:42 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:58:02 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_both(t_node *tomove, t_node **stack_a, t_node **stack_b)
{
	while (tomove->index != 0 && tomove->target_node->index != 0)
	{
		if (tomove->on_top_half == true
			&& tomove->target_node->on_top_half == true)
			rr(stack_a, stack_b);
		if (tomove->on_top_half == false
			&& tomove->target_node->on_top_half == false)
			rrr(stack_a, stack_b);
	}
}

void	move_nodes(t_node **stack_a, t_node **stack_b)
{
	t_node	*tomove;

	tomove = flag_cheapest(*stack_b);
	if (on_same_half_stack(tomove))
		move_both(tomove, stack_a, stack_b);
	while (tomove->index != 0)
	{
		if (tomove->on_top_half == true)
			rb(stack_a, stack_b, true);
		else
			rrb(stack_a, stack_b, true);
	}
	while (tomove->target_node->index != 0)
	{
		if (tomove->target_node->on_top_half == true)
			ra(stack_a, stack_b, true);
		else
			rra(stack_a, stack_b, true);
	}
	pa(stack_a, stack_b);
	return ;
}

void	sort_three(t_node **stack_a, t_node **stack_b)
{
	t_node	*largest;

	largest = find_largest(*stack_a);
	if (*stack_a == largest)
		ra(stack_a, stack_b, true);
	else if ((*stack_a)->next == largest)
		rra(stack_a, stack_b, true);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, stack_b, true);
	return ;
}

void	sort_all(t_node **stack_a, t_node **stack_b)
{
	t_node	*smallest_node;

	while (count_nodes(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	while (*stack_b != NULL)
	{
		restart_stacks(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	smallest_node = find_smallest(*stack_a);
	if (smallest_node->on_top_half == true)
		while (*stack_a != smallest_node)
			ra(stack_a, stack_b, true);
	else
		while (*stack_a != smallest_node)
			rra(stack_a, stack_b, true);
	return ;
}

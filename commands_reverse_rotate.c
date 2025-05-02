/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:56:01 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:56:02 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate_reverse(stack_a);
	index_nodes(*stack_a, *stack_b);
	if (print == true)
		ft_printf("rra\n");
	return ;
}

void	rrb(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate_reverse(stack_b);
	index_nodes(*stack_a, *stack_b);
	if (print == true)
		ft_printf("rrb\n");
	return ;
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rra(stack_a, stack_b, false);
	rrb(stack_a, stack_b, false);
	ft_printf("rrr\n");
	return ;
}

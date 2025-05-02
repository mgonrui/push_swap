/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:57 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:55:58 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate(stack_a);
	index_nodes(*stack_a, *stack_b);
	if (print == true)
		ft_printf("ra\n");
	return ;
}

void	rb(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate(stack_b);
	index_nodes(*stack_a, *stack_b);
	if (print == true)
		ft_printf("rb\n");
	return ;
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, stack_b, false);
	rb(stack_a, stack_b, false);
	ft_printf("rr\n");
	return ;
}

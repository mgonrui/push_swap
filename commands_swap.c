/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:53 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:55:54 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **stack_a, t_node **stack_b, bool print)
{
	swap(stack_a);
	index_nodes(*stack_a, *stack_b);
	if (print == true)
		ft_printf("sa\n");
	return ;
}

void	sb(t_node **stack_a, t_node **stack_b, bool print)
{
	swap(stack_b);
	index_nodes(*stack_a, *stack_b);
	if (print == true)
		ft_printf("sb\n");
	return ;
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	sa(stack_a, stack_b, false);
	sb(stack_a, stack_b, false);
	ft_printf("ss\n");
	return ;
}

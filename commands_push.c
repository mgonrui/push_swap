/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:56:05 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:56:06 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	index_nodes(*stack_a, *stack_b);
	ft_printf("pa\n");
	return ;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	index_nodes(*stack_a, *stack_b);
	ft_printf("pb\n");
	return ;
}

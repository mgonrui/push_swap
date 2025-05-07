/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:49 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 11:02:42 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_double_ptr(void **ptr)
{
	int	i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static bool	stack_in_order(t_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	clean(t_node **roots, char **argv, bool argv_modified, bool er)
{
	if (argv_modified == true)
		free_double_ptr((void **)argv);
	free_llist(roots[0]);
	free_llist(roots[1]);
	if (er == true)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	init_root(t_node **root, int value)
{
	(*root) = malloc(sizeof(t_node));
	if (*root == NULL)
		exit(1);
	(*root)->value = value;
	(*root)->prev = NULL;
	(*root)->index = 0;
	(*root)->next = NULL;
	return ;
}

int	main(int argc, char **argv)
{
	t_node	*roots[2];
	int		i;
	bool	argv_modified;

	argv_modified = false;
	roots[0] = NULL;
	roots[1] = NULL;
	i = 1;
	if (argc < 2)
		return (0);
	if (ft_strchr(argv[i], ' '))
	{
		argv = input_is_in_quotes(&argc, argv);
		argv_modified = true;
		i = 0;
	}
	if (input_is_wrong(&argv[i]) || argv[1][0] == '\0')
		return (clean(roots, argv, argv_modified, true), 0);
	while (i < argc)
		add_end_node(&roots[0], ft_atoi(argv[i++]));
	if (stack_in_order(roots[0]))
		return (clean(roots, argv, argv_modified, false), 0);
	sort_all(&roots[0], &roots[1]);
	return (clean(roots, argv, argv_modified, false), 0);
}

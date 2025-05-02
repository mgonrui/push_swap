/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 09:55:25 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 09:58:18 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**input_is_in_quotes(int *argc, char **argv)
{
	char	**ret_value;

	if (*argc > 2)
		ft_putstr_fd("Error\n", 2), exit(1);
	ret_value = ft_split(argv[1], ' ');
	if (ret_value == NULL)
		exit(1);
	*argc = 0;
	while (ret_value[*argc] != NULL)
		(*argc)++;
	return (ret_value);
}

bool	input_is_outside_int_values(char *str)
{
	int		sign;
	int		i;
	long	value;

	sign = 1;
	i = 0;
	value = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		value *= 10;
		value += str[i] - '0';
		i++;
	}
	value *= sign;
	if (value > MAX_INT || value < MIN_INT)
		return (true);
	return (false);
}

bool	duplicate_foud(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = i + 1;
		while (argv[j] != NULL)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[1] == '\0')
			return (false);
		else
			i++;
	}
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	input_is_wrong(char **argv)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		if (input_is_outside_int_values(argv[i]))
			return (true);
		if (!valid_number(argv[i]))
			return (true);
		i++;
	}
	if (duplicate_foud(argv))
		return (true);
	return (false);
}

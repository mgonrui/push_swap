/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariogo2 <mariogo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 10:48:59 by mariogo2          #+#    #+#             */
/*   Updated: 2025/04/28 11:02:29 by mariogo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# include "libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# define malloc(x) 0
typedef struct s_node
{
	int				value;
	int				index;
	int				cost;
	bool			on_top_half;
	bool			cheapest;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

// basic llist actions
void				remove_beggining_node(t_node **root);
void				add_beginning_node(t_node **root, int value);
void				add_end_node(t_node **root, int value);
int					count_nodes(t_node *root);
void				free_llist(t_node *root);
void				init_root(t_node **root, int value);

// basic push swap actions
void				swap(t_node **root);
void				push(t_node **root_src, t_node **root_dst);
void				rotate(t_node **root);
void				rotate_reverse(t_node **root);

// commands swap
void				sa(t_node **stack_a, t_node **stack_b, bool print);
void				sb(t_node **stack_a, t_node **stack_b, bool print);
void				ss(t_node **stack_a, t_node **stack_b);
// commands push
void				pa(t_node **stack_a, t_node **stack_b);
void				pb(t_node **stack_a, t_node **stack_b);
// commands rotate
void				ra(t_node **stack_a, t_node **stack_b, bool print);
void				rb(t_node **stack_a, t_node **stack_b, bool print);
void				rr(t_node **stack_a, t_node **stack_b);
// commands reverse rotate
void				rra(t_node **stack_a, t_node **stack_b, bool print);
void				rrb(t_node **stack_a, t_node **stack_b, bool print);
void				rrr(t_node **stack_a, t_node **stack_b);
// user input
char				**input_is_in_quotes(int *argc, char **argv);
bool				input_is_wrong(char **argv);
// move_nodes
void				sort_three(t_node **stack_a, t_node **stack_b);
void				sort_all(t_node **stack_a, t_node **stack_b);
void				move_nodes(t_node **stack_a, t_node **stack_b);
// algorythm
void				find_target_node(t_node *stack_a, t_node *stack_b);
void				calculate_cost(t_node *stack_a, t_node *stack_b);
void				restart_stacks(t_node *stack_a, t_node *stack_b);
void				index_nodes(t_node *root_a, t_node *root_b);
// stack utils
bool				on_same_half_stack(t_node *tomove);
t_node				*find_largest(t_node *list);
t_node				*find_smallest(t_node *list);
t_node				*flag_cheapest(t_node *stack_b);

#endif // PUSH_SWAP_H

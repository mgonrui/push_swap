#include "libft/libft.h"
#include "push_swap.h"

/* // checked */
/* Node *flag_cheapest(Node *stack_b) */
/* { */
/* 	long			best_match_value; */
/* 	Node	*best_match_node; */

/* 	if (NULL == stack_b) */
/* 		return NULL; */
/* 	best_match_value = MAX_INT; */
/* 	while (stack_b) */
/* 	{ */
/* 		if (stack_b->cost < best_match_value) */
/* 		{ */
/* 			best_match_value = stack_b->cost; */
/* 			best_match_node = stack_b; */
/* 		} */
/* 		stack_b = stack_b->next; */
/* 	} */
/* 	best_match_node->cheapest = true; */
/* 	return best_match_node; */
/* } */

void flag_cheapest(Node *stack_b)
{
	Node *cheapest;
	cheapest = stack_b;
	while(stack_b != NULL)
	{
		stack_b->cheapest = false;
		if (cheapest->cost > stack_b->cost)
			cheapest = stack_b;
		stack_b = stack_b->next;
	}
	cheapest->cheapest = true;
}

Node *find_largest(Node *stack)
{
	Node *largest;
	Node *current = stack;
	largest = current;
	while(current != NULL)
	{
		if (largest->value < current->value)
			largest = current;
		current = current->next;
	}
	return largest;
}

//checked
Node *find_smallest(Node *stack)
{
	Node *current;
	Node *smallest_node;
	current = stack;
	smallest_node = stack;
	while(current != NULL)
	{
		if (current->value < smallest_node->value)
			smallest_node = current;
		current = current->next;
	}

	return smallest_node;
}


// checked
void sort_three(Node **stack_a, Node **stack_b)
{
	Node *largest;
	largest = find_largest(*stack_a);
	if (*stack_a == largest)
		ra(stack_a, stack_b, true);
	else if ((*stack_a)->next == largest)
		rra(stack_a, stack_b, true);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, stack_b, true);
	return ;
}
// checked
void restart_stacks(Node *stack_a, Node *stack_b)
{
    index_nodes(stack_a, stack_b);
	find_target_node(stack_a, stack_b);
	/* half_top_or_bot(stack_a, stack_b); */
    calculate_cost(stack_a, stack_b);
    flag_cheapest(stack_b);
}

// checked
void sort_all(Node **stack_a, Node **stack_b)
{
	while(count_nodes(*stack_a) > 3)
	{
		pb(stack_a, stack_b);
	}
	sort_three(stack_a, stack_b);
	while(*stack_b != NULL)
	{
		restart_stacks(*stack_a, *stack_b);
		move_nodes(stack_a, stack_b);
	}
	Node *smallest_node;
	smallest_node = find_smallest(*stack_a);
	if (smallest_node->on_top_half == true)
		while(*stack_a != smallest_node)
			ra(stack_a, stack_b, true);
	else
		while(*stack_a != smallest_node)
			rra(stack_a, stack_b, true);
	return ;
}

// checked
void find_target_node(Node *stack_a, Node *stack_b)
{
	Node *current;
	Node *target_node;
	int best_target;

	while(stack_b != NULL)
	{
		best_target = MAX_INT;
		current = stack_a;
		while(current != NULL)
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

// checked
bool on_same_half_stack(Node *tomove)
{
	if ((tomove->on_top_half == true && tomove->target_node->on_top_half == true) || (tomove->on_top_half == false  && tomove->target_node->on_top_half == false))
		return true;
	else
		return false;
}

//checked
void calculate_cost(Node *stack_a, Node *stack_b)
{
	Node *current;
	current = stack_b;
	while(current != NULL)
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

void move_both(Node *tomove, Node **stack_a, Node **stack_b)
{
	while(tomove->index != 0 && tomove->target_node->index != 0)
	{
		if (tomove->on_top_half == true && tomove->target_node->on_top_half == true)
			rr(stack_a, stack_b);
		if (tomove->on_top_half == false && tomove->target_node->on_top_half == false)
			rrr(stack_a, stack_b);
	}
}

void move_nodes(Node **stack_a, Node **stack_b)
{
	Node *tomove;
	tomove = *stack_b;
	while(tomove->cheapest == false)
		tomove = tomove->next;
	if (on_same_half_stack(tomove))
		move_both(tomove, stack_a, stack_b);
	while(tomove->index != 0)
	{
		if (tomove->on_top_half == true)
			rb(stack_a, stack_b, true);
		else
			rrb(stack_a, stack_b, true);
	}
	while(tomove->target_node->index != 0)
	{
		if (tomove->target_node->on_top_half == true)
			ra(stack_a, stack_b, true);
		else
			rra(stack_a, stack_b, true);
	}
	pa(stack_a, stack_b);
	return ;
}

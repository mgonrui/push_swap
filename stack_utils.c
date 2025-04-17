#include "push_swap.h"

Node *flag_cheapest(Node *stack_b)
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
	return cheapest;
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

bool on_same_half_stack(Node *tomove)
{
	if ((tomove->on_top_half == true && tomove->target_node->on_top_half == true) || (tomove->on_top_half == false  && tomove->target_node->on_top_half == false))
		return true;
	else
		return false;
}

void restart_stacks(Node *stack_a, Node *stack_b)
{
    index_nodes(stack_a, stack_b);
	find_target_node(stack_a, stack_b);
    calculate_cost(stack_a, stack_b);
    flag_cheapest(stack_b);
}

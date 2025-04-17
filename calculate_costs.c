#include "push_swap.h"

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


#include "push_swap.h"

Node *find_largest(Node *list)
{
	Node *largest;
	Node *current = list;
	largest = current;
	while(current != NULL)
	{
		if (largest->value < current->value)
			largest = current;
		current = current->next;
	}
	return largest;
}

Node *find_smallest(Node *list)
{
	Node *current;
	Node *smallest_node;
	current = list;
	smallest_node = list;
	while(current != NULL)
	{
		if (current->value < smallest_node->value)
			smallest_node = current;
		current = current->next;
	}
	return smallest_node;
}

void sort_three(Node **root_a, Node **root_b)
{
	Node *largest;
	largest = find_largest(*root_a);
	if (*root_a == largest)
		ra(root_a, root_b);
	else if ((*root_a)->next == largest)
		rra(root_a, root_b);
	if ((*root_a)->value > (*root_a)->next->value)
		sa(root_a, root_b);
	return ;
}

void restart_stacks(Node *root_a, Node *root_b)
{
    index_nodes(root_a, root_b);
	find_target_node(root_a, root_b);
	half_top_or_bot(root_a, root_b);
    calculate_cost(root_a, root_b);
    flag_cheapest(root_b);

}

void sort_all(Node **root_a, Node **root_b)
{
	while(count_nodes(*root_a) > 3)
	{
		pb(root_a, root_b);
	}
	while(*root_b != NULL)
	{
		restart_stacks(*root_a, *root_b);
		move_nodes(root_a, root_b);
	}
	Node *smallest_node;
	smallest_node = find_smallest(*root_a);
	while(*root_a != smallest_node)
	{
		if (smallest_node->on_top_half == true)
			ra(root_a, root_b);
		else
			rra(root_a, root_b);
	}
	return ;
}

void find_target_node(Node *root_a, Node *root_b)
{
	Node *current;
	Node *target_node;
	int best_target;

	while(root_b != NULL)
	{
		best_target = MAX_INT;
		current = root_a;
		while(current != NULL)
		{
			if (current->value > root_b->value && current->value < best_target)
			{
				best_target = current->value;
				target_node = current;
			}
			current = current->next;
		}
		if (MAX_INT == best_target)
			root_b->target_node = find_smallest(root_a);
		else
			root_b->target_node = target_node;
		root_b = root_b->next;
	}
}

void half_top_or_bot(Node *root_a, Node *root_b)
{
	Node *current;
	current = root_a;
	while(current != NULL)
	{
		if (current->index > count_nodes(root_a) / 2)
			current->on_top_half = false;
		else
			current->on_top_half = true;
		current = current->next;
	}
	current = root_b;
	while(current != NULL)
	{
		if (current->index > count_nodes(root_b) / 2)
			current->on_top_half = false;
		else
			current->on_top_half = true;
		current = current->next;
	}
	return ;
}

void calculate_cost(Node *root_a, Node *root_b)
{
	Node *current;
	current = root_b;
	while(current != NULL)
	{
		current->cost = 0;
		if (current->on_top_half == false)
			current->cost += count_nodes(root_b) - current->index;
		else
			current->cost += current->index;
		if (current->target_node->on_top_half == false)
			current->cost += count_nodes(root_a) - current->target_node->index;
		else
			current->cost += current->target_node->index;
		if (can_move_both_in_same_action(current) == true)
			current->cost--;
		current = current->next;
	}
	return ;
}

void flag_cheapest(Node *root_b)
{
	Node *cheapest;
	cheapest = root_b;
	while(root_b != NULL)
	{
		root_b->cheapest = false;
		if (cheapest->cost > root_b->cost)
			cheapest = root_b;
		root_b = root_b->next;
	}
	cheapest->cheapest = true;
}

bool can_move_both_in_same_action(Node *current)
{
	if ((current->on_top_half == false && current->target_node->on_top_half == false)
		||(current->on_top_half == true && current->target_node->on_top_half == true)
		&& current->target_node->index != 0 && current->index != 0)
		return true;
	return false;

}

void move_nodes(Node **root_a, Node **root_b)
{
	Node *tomove;
	tomove = *root_b;
	while(tomove->cheapest == false)
		tomove = tomove->next;
	while (can_move_both_in_same_action(tomove) == true)
	{
		if (tomove->on_top_half == true)
		{
			rr(root_a, root_b);	
			index_nodes(*root_a, *root_b);
		}
		else
		{
			rrr(root_a, root_b);
			index_nodes(*root_a, *root_b);
		}

	}
	while(tomove->index != 0)
	{
		if (tomove->on_top_half == true)
		{
			rb(root_a, root_b);
			index_nodes(*root_a, *root_b);
		}
		else
		{
			rrb(root_a, root_b);
			index_nodes(*root_a, *root_b);
		}
	}
	while(tomove->target_node->index != 0)
	{
		if (tomove->on_top_half == true)
		{
			ra(root_a, root_b);
			index_nodes(*root_a, *root_b);
		}
		else
		{
			rra(root_a, root_b);
			index_nodes(*root_a, *root_b);
		}
	}
	pa(root_a, root_b);
	index_nodes(*root_a, *root_b);
	return ;
}

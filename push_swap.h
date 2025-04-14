#ifndef PUSH_SWAP_H_
#define PUSH_SWAP_H_

# define MAX_INT 2147483647
# define MIN_INT -2147483648

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct Node
{
    int value;
    int index;
    int cost;
    bool on_top_half;
    bool cheapest;
    struct Node *target_node;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct Stacks
{
    struct Node **a;
    struct Node **b;
} Stacks;

// basic llist actions
void remove_beggining_node(Node **root);
void add_beginning_node(Node **root, int value);
void add_end_node(Node **root, int value);
int count_nodes(Node *root);
void index_nodes(Node *root_a, Node *root_b);

// basic push swap actions
void swap(Node **root);
void push(Node **root_src, Node **root_dst);
void rotate(Node **root);
void rotate_reverse(Node **root);


// commands swap
void sa(Node **root_a, Node **root_b);
void sb(Node **root_a, Node **root_b);
void ss(Node **root_a, Node **root_b);
// commands push
void pa(Node **root_a, Node **root_b);
void pb(Node **root_a, Node **root_b);
// commands rotate
void ra(Node **stack_a, Node **stack_b);
void rb(Node **stack_a, Node **stack_b);
void rr(Node **stack_a, Node **stack_b);
//commands reverse rotate
void rra(Node **stack_a, Node **stack_b);
void rrb(Node **stack_a, Node **stack_b);
void rrr(Node **stack_a, Node **stack_b);
//user input
char **input_is_in_quotes(int *argc, char **argv);
int input_is_wrong(char **argv);


//algorythm
void sort_three(Node **root_a, Node **root_b);
Node *find_largest(Node *list);
void sort_all(Node **root_a, Node **root_b);
void find_target_node(Node *root_a, Node *root_b);
void calculate_cost(Node *root_a, Node *root_b);
void half_top_or_bot(Node *root_a, Node *root_b);
void flag_cheapest(Node *root_b);
bool can_move_both_in_same_action(Node *current);
void move_nodes(Node **root_a, Node **root_b);

#endif // PUSH_SWAP_H_

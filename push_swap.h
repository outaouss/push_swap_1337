# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
    struct s_node *previous;
} t_node;

void print_stack(t_node *head);
void rr(t_node **stack_a, t_node **stack_b);
void rb(t_node **stack_b);
void ra(t_node **stack_a);
static void rotate(t_node **stack);
t_node *find_last_node(t_node *lst);
static void reverse_rotate(t_node **stack);
void rrr(t_node **stack_a, t_node **stack_b);
void rrb(t_node **stack_b);
void rra(t_node **stack_a);
static void push(t_node **stack_a, t_node **stack_b);
void pa(t_node **stack_a, t_node **stack_b);
void pb(t_node **stack_a, t_node **stack_b);

#endif
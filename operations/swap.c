#include "../push_swap.h"

static void swap(t_node **stack)
{
    t_node *first;
    t_node *seconde;

    if (!*stack || !(*stack)->next)
        return ;

    first = *stack;
    seconde = (*stack)->next;

    first->next = seconde->next;
    first->previous = seconde;

    if (seconde->next)
        seconde->next->previous = first;

    seconde->next = *stack; 
    seconde->previous = NULL;
    
    *stack = seconde;
}

void sa(t_node **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void sb(t_node **stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void ss(t_node **stack_b, t_node **stack_a)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}

int main()
{
    t_node *node1 = malloc(sizeof(t_node));
    t_node *node2 = malloc(sizeof(t_node));
    t_node *node3 = malloc(sizeof(t_node));

    node1->value = 10;
    node2->value = 9;
    node3->value = 11;

    node1->previous = NULL;
    node2->previous = node1;
    node3->previous = node2;

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    printf("before swap\n");
    print_stack(node1);

    sa(&node1);

    printf("after swap\n");
    print_stack(node1);
}
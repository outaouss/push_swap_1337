#include "push_swap.h"

void assign_index(t_node *stack)
{
    int count;
    t_node *compare;
    t_node *current;

    if (!stack)
        return ;
    current = stack;
    while (current)
    {
        count = 0;
        compare = stack;
        while (compare)
        {
            if (compare->value < current->value)
                count++;
            compare = compare->next;
        }
        current->index = count;
        current = current->next;
    }
}

int is_sorted(t_node *stack)
{
    if (!stack || !stack->next)
        return 1;
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return 0;
        stack = stack->next;
    }
    return 1;
}

int stack_len(t_node *stack)
{
    int count = 0;

    if (!stack)
        return 0;
    while (stack)
    {
        count++;
        stack = stack->next;
    }
    return count;
}

// int main()
// {
//     t_node *node1 = malloc(sizeof(t_node));
//     t_node *node2 = malloc(sizeof(t_node));
//     t_node *node3 = malloc(sizeof(t_node));

//     node1->value = 1;
//     node2->value = 2;
//     node3->value = 3;

//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     node1->previous = NULL;
//     node2->previous = node1;
//     node3->previous = node2;

//     // int i = is_sorted(node1);
//     // printf("%d\n", i);
//     // node1->index = 0;
//     // node2->index = 0;
//     // node3->index = 0;

//     printf("%d\n", stack_len(node1));
//     // printf("node1 --> %d\n", node1->index);
//     // printf("node2 --> %d\n", node2->index);
//     // printf("node3 --> %d\n", node3->index);
    
//     // assign_index(node1);

//     // printf("after assigning \n");

//     // printf("node1 --> %d\n", node1->index);
//     // printf("node2 --> %d\n", node2->index);
//     // printf("node3 --> %d\n", node3->index);
// }
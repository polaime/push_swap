#include "push_swap.h"
// turc mecanique
int    *push_swap(t_stack *stack_a, int limit)
{
    int     i;

	i = 1;
    t_stack *stack_b = NULL;
    push_b(&stack_a, &stack_b);
    if (stack_b == NULL)
        return (NULL);
    while (!stack_a || !stack_b)
	{
        // if (stack_a -> value > stack_a -> next -> value)
        //     swap_a(&stack_a);
        if (stack_a -> value < stack_b -> value)
        {
            push_b(&stack_a, &stack_b);
            *stack_a = *stack_a -> next;
        }
        if (stack_a -> value > stack_b)
            push_a(&stack_a, &stack_b);
        if (stack_a == NULL)
        {
            while (stack_b == NULL)
                push_a(&stack_a, &stack_b);
        }
    }
    return (stack_a);
}


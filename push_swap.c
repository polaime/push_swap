#include "push_swap.h"
// turc mecanique
int calcul_min(t_stack *stack_a, int i)
{
	int min; 
	int j;

	j = 0;
	min = 0;
	t_stack *parcours = stack_a;
	if  (parcours == NULL)
		return (0);
	min = parcours -> value;
	while  (j <= i)
	{
		if  (parcours -> value < min)
			min = parcours -> value;
		parcours = parcours -> next;
		j++;
	}
	return (min);
}
int verif_tri(t_stack *stack_a)
{
	t_stack *current = stack_a;
    while (current && current -> next)
    {
        if (current -> value > current -> next -> value)
            return (0);
        current = current -> next;
    }
    return (1);
}

t_stack *remove_node(t_stack *stack, t_stack *node_to_remove) 
{
    if (stack == NULL || node_to_remove == NULL)
	    return stack; 
    if (stack == node_to_remove)
	{
        t_stack *new_head = stack->next;
        free(stack);
        return new_head;
    }
    t_stack *current = stack;
    while (current->next != NULL && current->next != node_to_remove)
		current = current->next;
    if (current->next == node_to_remove)
	{
        current->next = node_to_remove->next;
        free(node_to_remove);
    }
    return stack;
}

t_stack *utils_algo(t_stack *stack_a, int i)
{
	int min;
	int	k;

	t_stack *stack_b = NULL;
	t_stack *current;
	k = 0;
	current = stack_a;

    while (!verif_tri(stack_a))
	{
		current = stack_a;
		min = calcul_min(current, i);
		while (current != NULL)
		{
			if (current -> value == min)
			{
				stack_a = remove_node(stack_a, current);
			 	k += push_b(&stack_a, &stack_b);
				print_stack(stack_a);
				print_stack(stack_b);
				break;
			}
			current = current -> next;
		}
	}	
	while (stack_b != NULL)
        k =	k + push_a(&stack_a, &stack_b);
	print_stack(stack_a);
	printf("%i\n", k);
    return (stack_a);
}

t_stack *push_swap(t_stack **stack_a, int argc)
{
	// int	 i;
	// int	 min;
	// int	 max;

	// i = 0;
	// t_stack *parcours = *stack_a;
	// if  (parcours == NULL)
	// 	return (NULL);
	// min = parcours -> value;
	// max = parcours -> value;
	// while  (parcours != NULL)
	// {
	// 	if  (parcours -> value < min)
	// 		min = parcours -> value;
	// 	if (parcours -> value > max)
	// 	{
	// 		max = parcours -> value;
	// 	}
	// 	parcours = parcours -> next;
	// 	i++; 
	// }
	*stack_a = utils_algo(*stack_a, argc);
	return (*stack_a);
}


#include "push_swap.h"
// turc mecanique

int	calcul_min(t_stack *stack_a, int i)
{
	int min; 
	int j;

	j = 0;
	min = 0;
	t_stack *parcours = stack_a;
	if (parcours == NULL)
		return (0);
	min = parcours -> value;
	while (j <= i)
	{
		if (parcours -> value < min)
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

t_stack	*utils_algo(t_stack *stack_a, int i)
{
	int	k;
	int	mask;
	t_stack *stack_b = NULL;

	k = 0;
	mask = 1;
	while (!verif_tri(stack_a) && stack_a != NULL)
	{
		while (i + 1 > k && stack_a)
		{
			if ((stack_a -> value & mask) == 1)
			{
				rotate_a(&stack_a);
				k++;
			}
			else
			{
				push_b(&stack_a, &stack_b);
				k++;
			}
			stack_a = stack_a -> next;
		}
		k = 0;
		mask = mask << 1;
		while (stack_b != NULL && stack_a)
			push_a(&stack_a, &stack_b);
	}
	return (stack_a);
}

t_stack	*push_swap(t_stack **stack_a, int argc)
{
	*stack_a = utils_algo(*stack_a, argc);
	return (*stack_a);
}


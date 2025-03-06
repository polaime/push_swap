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
	if (stack_a == NULL)
	return (1);
	t_stack *current = stack_a;
    while (current -> next != NULL)
    {
        if (current -> value > current -> next -> value)
            return (0);
        current = current -> next;
    }
    return (1);
}

t_stack	*utils_algo(t_stack *stack_a, int size)
{
	int	k;
	int z;
	int	mask;
	t_stack *stack_b = NULL;
	
	z = 0;
	mask = 1;
	while (!verif_tri(stack_a))
	{
		k = 0;
		while (k < size)
		{
			if ((stack_a -> value & mask) == 0)
				z = z + push_b(&stack_a, &stack_b);
			else
				z = z + rotate_a(&stack_a);
			k++;
		}
		while (stack_b != NULL)
			push_a(&stack_a, &stack_b);
		mask = mask << 1;
		if (mask == 0)
			break;
	}
	printf("%i\n", z);
	return (stack_a);
}

t_stack	*push_swap(t_stack **stack_a, int size)
{
	*stack_a = utils_algo(*stack_a, size);
	return (*stack_a);
}


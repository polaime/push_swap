#include "push_swap.h"

int	find_min(t_stack *stack_a, int size)
{
	int		min;
	int		j;
	t_stack	*parcours;

	j = 0;
	min = 0;
	parcours = stack_a;
	if (parcours == NULL)
		return (0);
	min = parcours -> value;
	while (j < size)
	{
		if (parcours -> value < min)
			min = parcours -> value;
		parcours = parcours -> next;
		j++;
	}
	if (j < size / 2)
		return (1);
	return (0);
}

int	calcul_min(t_stack *stack_a, int size)
{
	int		min;
	int		j;
	t_stack	*parcours;

	j = 0;
	min = 0;
	parcours = stack_a;
	if (parcours == NULL)
		return (0);
	min = parcours -> value;
	while (j < size)
	{
		if (parcours -> value < min)
			min = parcours -> value;
		parcours = parcours -> next;
		j++;
	}
	return (min);
}

int	verif_tri(t_stack *stack_a)
{
	t_stack	*current;

	current = stack_a;
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
	int			k;
	int			mask;
	t_stack		*stack_b;

	stack_b = NULL;
	mask = 1;
	while (!verif_tri(stack_a))
	{
		k = 0;
		while (k < size)
		{
			if ((stack_a -> value & mask) == 0)
				push_b(&stack_a, &stack_b);
			else
				rotate_a(&stack_a);
			k++;
		}
		while (stack_b != NULL)
			push_a(&stack_a, &stack_b);
		mask = mask << 1;
		if (mask == 0)
			break ;
	}
	return (stack_a);
}

t_stack	*push_swap(t_stack **stack_a, int size)
{
	if (size == 3 || size == 2)
		*stack_a = sort_for_3(*stack_a, size);
	if (size > 10)
		*stack_a = utils_algo(*stack_a, size);
	else
		*stack_a = sort_for_10(*stack_a, size);
	return (*stack_a);
}


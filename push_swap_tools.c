#include "push_swap.h"

int	calcul_max(t_stack *stack_a)
{
	int			max;
	t_stack		*parcours;

	parcours = stack_a;
	if (parcours == NULL)
		return (0);
	max = parcours -> value;
	while (parcours != NULL)
	{
		if (parcours -> value > max)
			max = parcours -> value;
		parcours = parcours -> next;
	}
	return (max);
}

t_stack	*sort_for_3(t_stack *stack_a, int size)
{
	int	max;

	max = calcul_max (stack_a);

	while (!verif_tri(stack_a) && size)
	{
		if (stack_a -> value != max && stack_a -> next -> value != max)
			swap_a(&stack_a);
		else if (stack_a -> value == max)
		{
			rotate_a(&stack_a);
			if (!verif_tri(stack_a) && size)
				swap_a(&stack_a);
		}
		else
		{
			reverse_rotate_a(&stack_a);
			if (!verif_tri(stack_a) && size)
				swap_a(&stack_a);
		}
	}
	return (stack_a);
}

t_stack	*sort_for_10(t_stack *stack_a, int size)
{
	t_stack		*stack_b;
	int			i;
	int			min_value;
	int			min_index;

	stack_b = NULL;
	i = size;
	while (!verif_tri(stack_a))
	{
		while (i > 3)
		{
			min_value = calcul_min(stack_a, i);
			min_index = find_min(stack_a, i);
			if (!min_index)
			{
				while (stack_a -> value != min_value)
					reverse_rotate_a(&stack_a);
			}
			else if (min_index == 1)
			{
				while (stack_a -> value != min_value)
					rotate_a(&stack_a);
			}
			push_b(&stack_a, &stack_b);
			i--;
		}
		stack_a = sort_for_3(stack_a, 3);
		while (stack_b != NULL)
			push_a(&stack_a, &stack_b);
		i = size;
	}
	return (stack_a);
}

int	find_median(t_stack *stack_a, int size)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stack_a;
	while (i < size / 2)
	{
		tmp = tmp -> next;
		i++;
	}
	printf("%i\n", tmp -> value);
	return (tmp -> value);
}

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}
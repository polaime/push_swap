#include "push_swap.h"
// turc mecanique
int verif_tri(t_stack *stack_a)
{
    while (stack_a && stack_a -> next)
    {
        if (stack_a -> value > stack_a -> next -> value)
            return (0);
        stack_a = stack_a -> next;
    }
    return (1);
}
int calcul_mediane (t_stack *stack_a, int i)
{
	int	 mediane;
	int	 j;

	j = 0;	
	mediane = 0;
	t_stack *mid = stack_a;
	while (j < i / 2)
	{
		mid = mid -> next;
		j++;
	}
	mediane = mid -> value;
	printf("%i\n", mediane);
	return (mediane);
}
t_stack *utils_algo(t_stack *stack_a, int i)
{
	int		j;
	int		mediane;
	t_stack *stack_b;
	
	stack_b = NULL;
	j = 0;
	while (!verif_tri(stack_a))
	{
			mediane = calcul_mediane(stack_a, i);
			j = 0;
			while (stack_a != NULL && j != i)
			{
				if (stack_a -> value < mediane)
					push_b(&stack_a, &stack_b);
				else
					rotate_a(&stack_a);
				j++;
			}
		while (stack_b != NULL)
			push_a(&stack_a, &stack_b);
		print_stack(stack_a);
	}
	return (stack_a);
}
t_stack *push_swap(t_stack **stack_a, int argc)
{
	int	 i;
	int	 min;
	int	 max;

	i = 0;
	t_stack *parcours = *stack_a;
	if  (parcours == NULL)
		return (NULL);
	min = parcours -> value;
	max = parcours -> value;
	while  (parcours != NULL)
	{
		if  (parcours -> value < min)
			min = parcours -> value;
		if (parcours -> value > max)
		{
			max = parcours -> value;
		}
		parcours = parcours -> next;
		i++; 
	}
	*stack_a = utils_algo(*stack_a, argc);
	return (*stack_a);
}


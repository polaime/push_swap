#include "push_swap.h"
int  calcul_max(t_stack *stack_a)
{
 	int max;

 	max = stack_a -> value;
 	t_stack *parcours = stack_a;
	if  (parcours == NULL)
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

t_stack *sort_for_3(t_stack *stack_a, int size)
{
   	while (!verif_tri(stack_a) && size)
	{
		if (stack_a -> value < stack_a -> next -> value)
			swap_a(&stack_a);
		else
			rotate_a(&stack_a);
	}
	return (stack_a);
}
t_stack *sort_for_10(t_stack *stack_a, int size)
{
	t_stack *stack_b;
	int median;
	int j;

	j = 0;
	stack_b = NULL;
	while (!verif_tri(stack_a) && size)
	{
		median = find_median(stack_a, size);
		while (j < size)
		{
			if (stack_a -> value < median)
				rotate_a(&stack_a);
			else 
				push_b(&stack_a, &stack_b);
			j++;
		}
		while (stack_b != NULL)
			push_a(&stack_a, &stack_b);
		j = 0;
	}
	return (stack_a);
}
int find_median(t_stack *stack_a, int size)
{
	int		i;
	t_stack *tmp;
	
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
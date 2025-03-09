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

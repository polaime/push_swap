#include "push_swap.h"

int calcul_max(t_stack *stack_a)
{
 	int max;

 	max = stack_a -> value;
 	t_stack *parcours = *stack_a;
	if  (parcours == NULL)
		return (NULL);
	max = parcours -> value;
	while (parcours != NULL)
	{
		if (parcours -> value > max)
			max = parcours -> value;
		parcours = parcours -> next; 
	}
}

void sort_for_3(t_stack *stack_a)
{
    int	k;
	int z;
    int max;
    int min;
	t_stack *stack_b = NULL;
    
    max = calcul_max(&stack_a);
    min = calcul_min(&stack_a);
	z = 0;
   	while (!verif_tri(stack_a))
	{
		k = 0;
		while (k < 3)
		{
			if ((min != stack_a -> value && min != stack_a -> next -> value)
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
}
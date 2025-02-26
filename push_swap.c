#include "push_swap.h"
// turc mecanique
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
// int calcul_mediane (t_stack *stack_a, int i)
// {
// 	int	 mediane;
// 	int	 j;

// 	j = 0;	
// 	mediane = 0;
// 	t_stack *mid = stack_a;
// 	while (j < i / 2)
// 	{
// 		mid = mid -> next;
// 		j++;
// 	}
// 	mediane = mid -> value;
// 	printf("%i\n", mediane);
// 	return (mediane);
// }
t_stack *utils_algo(t_stack *stack_a, int i)
{    
	int j;
    t_stack *stack_b;
	int	k;

	k = 0;
	stack_b = NULL;
    while (!verif_tri(stack_a))
	{
		t_stack *current = stack_a;
        t_stack *noeud_suivant;

        while (current != NULL && j < i) {
            noeud_suivant = current->next;

            if (noeud_suivant != NULL) 
			{
                if (current->value < noeud_suivant->value)
                    k = k + push_b(&stack_a, &stack_b);
                else 
                    k = k + swap_a(&stack_a);
            }
            current = noeud_suivant;
            j++;
        }
        while (stack_b != NULL)
            push_a(&stack_a, &stack_b);
        print_stack(stack_a);
    }
	printf("%i\n", k);
    return stack_a;
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


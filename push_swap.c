#include "push_swap.h"
// turc mecanique
// void print_stack(t_stack *stack) {
//     while (stack != NULL) {
//         printf("%d -> ", stack->value);
//         stack = stack->next;
//     }
//     printf("NULL\n");
// }
t_stack *utils_algo(t_stack *stack_a, int i)
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
	j = 0;
	t_stack *stack_b = NULL;
	while (j != i)
	{
		if (stack_a -> value < mediane)
			push_b(&stack_a, &stack_b);
		else
			rotate_a(&stack_a);
		j++;
		// print_stack (stack_a);
	}
	while (stack_b != NULL)
	{
		push_a(&stack_a, &stack_b);
	}
	return (stack_a);
}
t_stack *push_swap(t_stack **stack_a)
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
	*stack_a = utils_algo(*stack_a, i);
	return (*stack_a);
}


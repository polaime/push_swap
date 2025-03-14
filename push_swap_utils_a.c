#include "push_swap.h"

int push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (*stack_b == NULL)
		return (0); 
	temp = *stack_b;
	*stack_b = (*stack_b)-> next;
	temp -> next = *stack_a;
	*stack_a = temp;
	ft_putstr("pa\n");
	return (1);
}
int swap_a(t_stack **stack_a)
{
	if (*stack_a == NULL || (*stack_a) -> next == NULL)
		return (0); 
	t_stack *tete = (*stack_a);
	t_stack *cou = tete -> next;
	tete -> next = cou -> next;
	cou -> next = tete;
	*stack_a = cou;
	ft_putstr("sa\n");
	return (1);
}

int  rotate_a(t_stack **stack_a)
{
	t_stack *queue;
	t_stack *tete;
	if (*stack_a == NULL || (*stack_a) -> next == NULL)
		return (0);
	queue = *stack_a;
	tete  = *stack_a;
	while (queue -> next != NULL)
		queue = queue -> next;
	*stack_a = tete -> next;
	queue -> next = tete;
	tete -> next = NULL;
	ft_putstr("ra\n");
	return (1);
}

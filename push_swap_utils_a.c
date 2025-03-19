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
	t_stack *cou;
	t_stack *tete;

	if (*stack_a == NULL || (*stack_a) -> next == NULL)
		return (0); 
	tete = (*stack_a);
	cou = tete -> next;
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

int	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*tete;
	t_stack	*nouvelle_tete;
	t_stack	*tmp;

	if (*stack_a == NULL || (*stack_a)-> next == NULL)
		return (0);
	tmp = *stack_a;
	tete = *stack_a;
	nouvelle_tete = *stack_a;
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	while (nouvelle_tete -> next != NULL)
		nouvelle_tete = nouvelle_tete -> next;
	*stack_a = nouvelle_tete;
	(*stack_a)-> next = tete;
	tmp -> next = NULL;
	ft_putstr ("rra\n");
	return (1);
}

#include "push_swap.h"

int push (t_stack **src, t_stack ** dest)
{
	t_stack *nodes;

	if (!*src)
		return (0);
	nodes = *src;
	*src = (*src) -> next;
	if (!*dest)
	{
		*dest = nodes;
		nodes -> next = NULL;
	}
	else
	{
		nodes->next = *dest;
		*dest = nodes;
	}
	ft_putstr("push");
	return (1);
}
int push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (*stack_a == NULL)
		return (0); 
	temp = *stack_a;
	*stack_a = (*stack_a)-> next;
	temp -> next = *stack_b;
	*stack_b = temp;
	ft_putstr("pb\n");
	return (1);
}
int push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return (0); 
	t_stack *temp = *stack_b;
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
void swap_b(t_stack **stack_b)
{
	if (*stack_b == NULL || (*stack_b) -> next == NULL)
		return; 
	t_stack *tete = (*stack_b);
	t_stack *cou = tete -> next;
	tete -> next = cou -> next;
	cou -> next = tete;
	*stack_b = cou;
	ft_putstr("sb\n"); 
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
	*stack_a = (*stack_a)->next;
	queue -> next = tete;
	tete -> next = NULL;
	ft_putstr("ra\n");
	return (1);
}
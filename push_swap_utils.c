#include "push_swap.h"

void push_b(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a == NULL)
		return; 
	t_stack *temp = *stack_a;
	*stack_a = (*stack_a)-> next;
	temp -> next = *stack_b;
	*stack_b = temp;
	ft_putstr("pb\n");
}
void push_a(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_b == NULL)
		return; 
	t_stack *temp = *stack_b;
	*stack_b = (*stack_b)-> next;
	temp -> next = *stack_a;
	*stack_a = temp;
	ft_putstr("pa\n"); 
}
void swap_a(t_stack **stack_a)
{
	if (*stack_a == NULL || (*stack_a) -> next == NULL)
		return; 
	t_stack *tete = (*stack_a);
	t_stack *cou = tete -> next;
	tete -> next = cou -> next;
	cou -> next = tete;
	*stack_a = cou;
	ft_putstr("sa\n"); 
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
void  rotate_a(t_stack **stack_a)
{
	if (*stack_a == NULL || (*stack_a) -> next == NULL)
		return;
	t_stack *queue = *stack_a;
	t_stack *tete  = *stack_a;
	while(queue -> next != NULL)
		queue = queue -> next;
	*stack_a = (*stack_a)->next;
	queue -> next = tete;
	tete -> next = NULL;
	ft_putstr("ra\n");
	tete -> next = NULL;
}
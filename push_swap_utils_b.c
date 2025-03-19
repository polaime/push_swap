#include "push_swap.h"

int	rotate_b(t_stack **stack_b)
{
	t_stack	*queue;
	t_stack	*tete;

	if (*stack_b == NULL || (*stack_b) -> next == NULL)
		return (0);
	queue = *stack_b;
	tete = *stack_b;
	while (queue -> next != NULL)
		queue = queue -> next;
	*stack_b = tete -> next;
	queue -> next = tete;
	tete -> next = NULL;
	ft_putstr("rb\n");
	return (1);
}
void	swap_b(t_stack **stack_b)
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
int	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return (0); 
	temp = *stack_a;
	*stack_a = (*stack_a)-> next;
	temp -> next = *stack_b;
	*stack_b = temp;
	ft_putstr("pb\n");
	return (1);
}

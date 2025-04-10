/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:38:44 by pthibaud          #+#    #+#             */
/*   Updated: 2025/03/21 14:39:13 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calcul_max(t_stack *stack_a)
{
	int			max;
	t_stack		*parcours;

	parcours = stack_a;
	if (parcours == NULL)
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

t_stack	*sort_for_3(t_stack *stack_a, int size)
{
	int	max;

	max = calcul_max (stack_a);
	while (!verif_tri(stack_a) && size)
	{
		if (stack_a -> value != max && stack_a -> next -> value != max)
			swap_a(&stack_a);
		else if (stack_a -> value == max)
		{
			rotate_a(&stack_a);
			if (!verif_tri(stack_a) && size)
				swap_a(&stack_a);
		}
		else
		{
			reverse_rotate_a(&stack_a);
			if (!verif_tri(stack_a) && size)
				swap_a(&stack_a);
		}
	}
	return (stack_a);
}

t_stack	*sort_for_10(t_stack *stack_a, int size)
{
	t_stack		*stack_b;
	int			i;

	stack_b = NULL;
	i = size;
	while (!verif_tri(stack_a))
	{
		stack_a = help_for_sort(stack_a, stack_b, i);
		i = size;
	}
	return (stack_a);
}


t_stack	*help_for_sort(t_stack *stack_a, t_stack *stack_b, int i)
{
	int			min_value;
	int			min_index;

	while (i > 3)
	{
		min_value = calcul_min(stack_a, i);
		min_index = find_min(stack_a, i);
		if (!min_index)
		{
			while (stack_a -> value != min_value)
				reverse_rotate_a(&stack_a);
		}
		else if (min_index == 1)
		{
			while (stack_a -> value != min_value)
				rotate_a(&stack_a);
		}
		push_b(&stack_a, &stack_b);
		i--;
	}
	stack_a = sort_for_3(stack_a, i);
	while (stack_b)
		push_a(&stack_a, &stack_b);
	return (stack_a);
}

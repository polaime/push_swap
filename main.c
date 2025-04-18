/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:45:55 by pthibaud          #+#    #+#             */
/*   Updated: 2025/03/25 15:45:59 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	utilitaire_du_main(char **argv, int *list, int argc, t_stack **stack_a)
{
	int		i;
	int		j;
	t_stack	*dernier;
	t_stack	*nouveau_noeud;

	i = 1;
	j = 0;
	while (argc > i)
	{
		if (!help_for_main(argv, i, list, j))
			return (ft_putstr("Error\n"), 0);
		nouveau_noeud = malloc(sizeof(t_stack));
		if (!nouveau_noeud)
			return (free (list), 0);
		nouveau_noeud -> value = list[j];
		nouveau_noeud -> next = NULL;
		if (*stack_a == NULL)
			*stack_a = nouveau_noeud;
		else
			dernier -> next = nouveau_noeud;
		dernier = nouveau_noeud;
		i++;
		j++;
	}
	return (1);
}

int	help_for_main(char **argv, int i, int *list, int j)
{
	list[j] = ft_atoi((char *)argv[i]);
	if (ft_isdigit(*argv[i]) == 0)
		return (0);
	return (1);
}

void	free_stack(t_stack *stack)
{
	t_stack		*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	verif_nbr(t_stack **stack_a, int size)
{
	t_stack	*verif;
	t_stack	*tmp;
	int		i;
	int		nbr;
	int		j;

	j = 0;
	tmp = *stack_a;
	while (j < size)
	{
		i = 0;
		nbr = tmp -> value;
		verif = *stack_a;
		while (verif != NULL)
		{
			if (verif -> value == nbr)
				i++;
			if (i >= 2)
				return (ft_putstr("Error\n"), 0);
			verif = verif -> next;
		}
		j++;
		tmp = tmp -> next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		*list;
	t_stack	*stack_a;

	if (argc < 2)
		return (0);
	stack_a = NULL;
	list = malloc((argc - 1) * sizeof(int));
	if (!list)
		return (1);
	if (!utilitaire_du_main(argv, list, argc, &stack_a))
		return (free (list), 1);
	if (!verif_nbr(&stack_a, argc - 1))
		return (free_stack(stack_a), 1);
	stack_a = push_swap(&stack_a, argc - 1);
	while (stack_a -> next != NULL)
	{
		printf("%i ", stack_a -> value);
		stack_a = stack_a -> next;
	}
	printf("%i ", stack_a -> value);
	printf("\n");
	free (list);
	free_stack(stack_a);
	return (0);
}

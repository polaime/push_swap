/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthibaud <pthibaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:42:43 by pthibaud          #+#    #+#             */
/*   Updated: 2025/02/08 20:34:25 by pthibaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	r;

	nb = 0;
	i = 0;
	r = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ' )
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			r++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10);
		nb = nb + str[i] - '0';
		i++;
	}
	if (r % 2 == 1)
		nb = -nb;
	return (nb);
}
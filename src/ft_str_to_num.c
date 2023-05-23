/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:40 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/19 12:55:56 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_number(char xar)
{
	if (xar >= '0' && xar <= '9')
		return (1);
	return (0);
}

int	is_positive_negative(char xar)
{
	if (xar == '-' || xar == '+')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int		number;
	int		sign;
	int		i;

	i = 0;
	number = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
				sign *= -1;
		i++;
	}
	while (str[i] && is_number(str[i]))
	{
	number *= 10;
	number += str[i] - '0';
	i++;
	}
	return (number * sign);
}

long	ft_atol(char *str)
{
	long	number;
	int		sign;
	int		i;

	i = 0;
	number = 0;
	sign = 1;

	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
				sign *= -1;
		i++;
	}
	while (str[i] && is_number(str[i]))
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:35:00 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/19 13:06:58 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_abs(int x, int y)
{
	if (y > x)
		return ((x - y) * -1);
	else
		return (x - y);
}

int	ft_avarege(int *list, int size)
{
	int	i;
	int	sum;

	if (!size)
		return (0);
	i = 0;
	sum = 0;
	while (i < size)
	{
		sum += list[i];
		i++;
	}
	return (sum / size);
}

void	print_t_stacks(t_stack a, t_stack b)
{
	int	i;
	int	size;

	size = a.size;
	if (b.size > a.size)
		size = b.size;
	i = 0;
	while (i < size)
	{
		if (a.size > i && b.size > i)
			ft_printf("   %d	%d   \n", a.list[i], b.list[i]);
		else if (a.size > i && b.size <= i)
			ft_printf("   %d	x   \n", a.list[i]);
		else if (a.size <= i && b.size > i)
			ft_printf("   %d	x   \n", b.list[i]);
		i++;
	}
	ft_printf("t_stackA	t_stackB\n\n");
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	check_is_space(char *str)
{
	if (str[0] == ' ' && str[1] == '\0')
	{
		write (2, "Error\n", 6);
		exit (0);
	}
	if ((str[0] == '+' || str[0] == '-') && str[1] == '\0')
	{
		write (2, "Error\n", 6);
		exit (0);
	}
}

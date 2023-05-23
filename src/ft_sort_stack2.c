/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:34 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/15 14:04:05 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// This takes a stack, value and step as input and compares the
// First value in the stack to a value calculate using the input
// value and step, an if it's lss that the value, it shifts down
void	betterb(t_stack *s, long val, int step)
{
	int	i;

	i = 0;
	if (s->size < 2)
		return ;
	if (s->list[i] < ((val + (val - step)) / 2))
		ft_shiftup(s);
}

void	bettera(t_stack *s, long val, int step)
{
	int	i;

	i = 0;
	if (s->size < 2)
		return ;
	if (s->list[i] < (val + (step / 2)))
		ft_shiftup(s);
}

void	ft_finish(t_stack *from, t_stack *to)
{
	while (from->size > 0)
	{
		maxontop(from);
		ft_push(from, to);
	}
}

int	is_sorted(t_stack *s)
{
	int	i;
	int	num;

	if (!s->size)
		return (1);
	i = 0;
	num = s->list[i];
	while (i < (s->size - 1))
	{
		if (num > s->list[i + 1])
			return (0);
		num = s->list[i + 1];
		i++;
	}
	return (1);
}

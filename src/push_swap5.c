/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:50 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/17 12:22:59 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push5_utils(t_stack *a, t_stack *b)
{
	push_swap3(a);
	if (is_sorted(b))
	{
		ft_shiftup(b);
		ft_push(b, a);
		ft_shiftup(a);
		ft_push(b, a);
	}
	else
	{
		ft_push(b, a);
		ft_shiftup(a);
		ft_push(b, a);
	}
}

void	push_swap5(t_stack *a, t_stack *b)
{
	long	vmin;
	long	vmax;
	long	*l;

	if (is_sorted(a))
		return ;
	l = a->list;
	vmin = l[min_index(a->list, a->size)];
	vmax = l[max_index(a->list, a->size)];
	while (a->size > 3)
	{
		if (l[0] == vmin || l[0] == vmax)
			ft_push(a, b);
		else
		{
			if ((l[1] == vmin || l[1] == vmax)
				|| (l[2] == vmin || l[2] == vmax))
				ft_shiftup(a);
			else
				ft_shiftdown(a);
			l = a->list;
		}
	}
	push5_utils (a, b);
}

void	push_swap4(t_stack *a, t_stack *b)
{
	long	vmin;
	long	*l;

	if (is_sorted(a))
		return ;
	l = a->list;
	vmin = l[min_index(a->list, a->size)];
	while (a->size > 3)
	{
		l = a->list;
		if (l[0] == vmin)
			ft_push(a, b);
		else
		{
			if (l[1] == vmin)
				ft_shiftup(a);
			else
				ft_shiftdown(a);
		}
	}
	push_swap3(a);
	ft_push(b, a);
}

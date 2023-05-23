/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:48 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/10 13:57:47 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap3(t_stack *s)
{
	long	imax;
	long	imin;

	if (!s->size)
		return ;
	imax = max_index(s->list, s->size);
	imin = min_index(s->list, s->size);
	while (!is_sorted(s))
	{
		if (imin == (s->size - 1) && imax == (imin - 1))
			ft_shiftdown(s);
		else if (imax == 0 && imin == (imax + 1))
			ft_shiftup(s);
		else
			ft_swap(s);
		imax = max_index(s->list, s->size);
		imin = min_index(s->list, s->size);
	}
}

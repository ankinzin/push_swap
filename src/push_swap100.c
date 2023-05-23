/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap100.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:53 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/10 10:50:04 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/**
 * This program is part of the sorting algorithm of pushwap
 * This one specifically is used to sorting stacks of ints
 * up to 100 elements in size. Dividing stucks into "chunks"
 * and uses a median value to determine which elements to
 * push onto a second stack, repeats it until the OG stack is sorted.
*/

void	push_swap100(t_stack *a, t_stack *b, int part)
{
	pushswap_100logic(a, b, part);
	ft_finish(b, a);
}

void	pushswap_100logic(t_stack *a, t_stack *b, int part)
{
	t_func_var	var;

	var.ntil = 1;
	var.lst.list = ascending_list(a->list, a->size);
	var.lst.size = a->size;
	var.total = a->size;
	var.step = var.total / part;
	var.sent = 0;
	if (is_sorted(a))
		return ;
	while (var.sent < var.total)
	{
		var.val = ft_median(var.lst.list, var.lst.size, var.ntil, part);
		while (var.sent < ((var.total / part) * var.ntil))
		{
			index_in_chunk(a, var.val);
			ft_push(a, b);
			var.sent++;
			betterb(b, var.val, var.step);
		}
		var.ntil++;
	}
	free (var.lst.list);
}

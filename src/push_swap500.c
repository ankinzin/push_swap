/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:57 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/15 13:56:27 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap500(t_stack *a, t_stack *b, int part)
{
	pushswap_100logic(a, b, part);
	pushswap_500logic(b, a, (5 * part));
	pushswap_100logic(a, b, (25 * part));
	ft_finish(b, a);
}

void	index_in_chunk2(t_stack *s, long val)
{
	int	i;
	int	j;

	i = 0;
	j = (s->size - 1);
	while ((i + 1) < s->size)
	{
		if (s->list[i] >= val)
			break ;
		i++;
	}
	while (j > (i + 1))
	{
		if (s->list[j] >= val)
			break ;
		j--;
	}
	best_rotate(s, i, j);
}

void	pushswap_500logic(t_stack *b, t_stack *a, int part)
{
	t_func_var		var;

	var.ntil = part - 1;
	var.lst.list = ascending_list(b->list, b->size);
	var.lst.size = b->size;
	var.total = b->size;
	var.step = var.total / part;
	var.sent = 0;
	if (is_sorted(b))
		return ;
	while (var.sent < var.total)
	{
		var.val = ft_median(var.lst.list, var.lst.size, var.ntil, part);
		while (var.sent <= (var.total - ((var.total / part) * var.ntil)))
		{
			index_in_chunk2(b, var.val);
			ft_push(b, a);
			var.sent++;
			bettera(a, var.val, var.step);
		}
		var.ntil--;
	}
	free (var.lst.list);
}

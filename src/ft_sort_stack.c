/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:28 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/22 11:29:04 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** This sort stack defines my helper functions for sorting a stack of
 * integers using push_swap algorithm.
 * The minontop function moves the smallest value in the stack to the top.
 * The maxontop function moves the largest value in the stack to the top.
 * The index_in_chunk function takes a stack and a value, and finds the
 * 1st and lst indices of elements in the stack that are greater than the value
 * it then calls best_rotate to rotate the stack to place these elements in the
 * center.
 * The best rotate function takes a stack and 2 indices, and rotates the stack
 * to move the element at 1 index closer to the center of the stack than the
 * element at other index. it uses do_best_rotate as a helper function.
**/

void	minontop(t_stack *s)
{
	int	imin;

	if (s->size < 2)
		return ;
	imin = min_index(s->list, s->size);
	while (imin != 0)
	{
		if (imin <= (s->size / 2))
			ft_shiftup(s);
		else
			ft_shiftdown(s);
		imin = min_index(s->list, s->size);
	}
}

void	maxontop(t_stack *s)
{
	int	imax;

	if (s->size < 2)
		return ;
	imax = max_index(s->list, s->size);
	while (imax != 0)
	{
		if (imax <= (s->size / 2))
			ft_shiftup(s);
		else
			ft_shiftdown(s);
		imax = max_index(s->list, s->size);
	}
}

void	index_in_chunk(t_stack *s, int val)
{
	int	i;
	int	j;

	i = 0;
	j = (s->size - 1);
	while ((i + 1) < s->size)
	{
		if (s->list[i] <= val)
			break ;
		i++;
	}
	while (j > (i + 1))
	{
		if (s->list[j] <= val)
			break ;
		j--;
	}
	best_rotate(s, i, j);
}

void	do_best_rotate(t_stack *s, int posi, int posj, int center)
{
	if (ft_abs(posi, center) >= ft_abs(posj, center))
	{
		while (posi > 0)
		{
			ft_shiftup(s);
			posi--;
		}
	}
	else
	{
		if (posj == (posi + 1))
			ft_shiftdown(s);
		while ((posj + 1) <= s->size)
		{
			ft_shiftdown(s);
			posj++;
		}
	}
}

void	best_rotate(t_stack *s, int i, int j)
{
	int	center;

	if (s->size < 3)
		return ;
	center = (s->size / 2);
	if (i == (s->size - 1))
	{
		ft_shiftdown(s);
		i = 0;
	}
	do_best_rotate (s, i, j, center);
}

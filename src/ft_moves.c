/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:12 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/17 20:40:32 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_remove_first_elem(t_stack *s)
{
	long	*list;
	int		i;

	list = (long *)malloc(sizeof(long) * (s->size - 1));
	i = 0;
	while ((i + 1) < s->size)
	{
		list[i] = s->list[i + 1];
		i++;
	}
	free (s->list);
	s->list = list;
}

void	ft_swap(t_stack *s)
{
	long	swap;

	ft_printf("s%c\n", s->c);
	if (s->size < 2)
		return ;
	swap = s->list[0];
	s->list[0] = s->list[1];
	s->list[1] = swap;
}

void	ft_shiftup(t_stack *s)
{
	long	*list;
	int		i;

	ft_printf("r%c\n", s->c);
	if (s->size < 2)
		return ;
	i = 0;
	list = (long *)malloc(sizeof(long) * s->size);
	while (i <= (s->size - 2))
	{
		list[i] = s->list[i + 1];
		i++;
	}
	list[i] = s->list[0];
	free(s->list);
	s->list = ft_cpy_list(list, s->size);
	free(list);
}

void	ft_shiftdown(t_stack *s)
{
	long	*list;
	int		i;

	ft_printf("rr%c\n", s->c);
	if (s->size < 2)
		return ;
	i = 0;
	list = (long *)malloc(sizeof(long) * s->size);
	while (i <= (s->size - 2))
	{
		list[i + 1] = s->list[i];
		i++;
	}
	list[0] = s->list[i];
	free(s->list);
	s->list = ft_cpy_list(list, s->size);
	free(list);
}

void	ft_push(t_stack *from, t_stack *to)
{
	long	*list;
	int		i;

	ft_printf("p%c\n", to->c);
	if (from->size < 1)
		return ;
	list = (long *)malloc(sizeof(long) * (to->size + 1));
	i = 0;
	list[0] = from->list[0];
	while (i < to->size)
	{
		list[i + 1] = to->list[i];
		i++;
	}
	free (to->list);
	to->size++;
	to->list = list;
	ft_remove_first_elem(from);
	from->size--;
}

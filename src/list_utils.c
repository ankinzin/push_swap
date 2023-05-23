/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:43 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/17 12:53:05 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_index(long *list, int size)
{
	long	min;
	int		i;
	int		imin;

	min = list[0];
	i = 1;
	imin = 0;
	while (i < size)
	{
		if (min > list[i])
		{
			imin = i;
			min = list[i];
		}
		i++;
	}
	return (imin);
}

int	max_index(long *list, int size)
{
	long	max;
	int		i;
	int		imax;

	max = list[0];
	i = 1;
	imax = 0;
	while (i < size)
	{
		if (max < list[i])
		{
			imax = i;
			max = list[i];
		}
		i++;
	}
	return (imax);
}

long	ft_median(long *list, int size, int ntil, int part)
{
	long	valor;
	int		pos;

	if (!size)
		return (0);
	if (size == 1)
		return (list[0]);
	pos = ((size - 1) * ntil) / part;
	valor = list[pos];
	return (valor);
}

long	*ascending_list(long *lst, int size)
{
	long	*cp;
	long	swap;
	int		i;

	cp = (long *)malloc(sizeof(long) * size);
	i = -1;
	while (++i < size)
		cp[i] = lst[i];
	i = 0;
	while (i < (size - 1))
	{
		if (cp[i] > cp[i + 1])
		{
			swap = cp[i];
			cp[i] = cp[i + 1];
			cp[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	return (cp);
}

long	*ft_cpy_list(long *list, int size)
{
	int		i;
	long	*cpy;

	i = 0;
	cpy = (long *)malloc(sizeof(long) * size);
	while (i < size)
	{
		cpy[i] = list[i];
		i++;
	}
	return (cpy);
}

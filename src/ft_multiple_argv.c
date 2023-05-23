/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_argv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:16 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/10 11:39:07 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_b(t_stack *b)
{
	b->list = NULL;
	b->size = 0;
	b->c = 'b';
}

static void	init_a_mult_argv(t_stack *a, int argc, char **argv)
{
	int		i;
	int		s;

	s = 1;
	a->c = 'a';
	a->size = argc - 1;
	a->list = (long *)malloc(sizeof(long) * a->size);
	i = 0;
	while (i < a->size)
	{
		a->list[i] = ft_atol(argv[s]);
		i++;
		s++;
	}
}

void	ft_multiple_argv(t_stack *a, t_stack *b, int argc, char **argv)
{
	init_b(b);
	init_a_mult_argv(a, argc, argv);
}

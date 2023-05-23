/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:20 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/20 19:17:25 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_a_sigle_argv(t_stack *a, char *str)
{
	char	**split;
	int		i;

	a->c = 'a';
	a->size = word_counter(str);
	a->list = (long *)malloc(sizeof(long) * a->size);
	split = ft_split(str);
	i = 0;
	while (split[i])
	{
		if (!ft_strcmp(split[i], "-") || !ft_strcmp(split[i], "+"))
		{
			a->error_code = 1;
			break ;
		}
		a->list[i] = ft_atol(split[i]);
		i++;
	}
	free_split(split);
}

void	ft_single_argv(t_stack *a, t_stack *b, char *str)
{
	init_b(b);
	init_a_sigle_argv(a, str);
}

void	str_null(char *str)
{
	if (str[0] == '\0')
	{
		write (2, "Error\n", 6);
		exit (0);
	}
}

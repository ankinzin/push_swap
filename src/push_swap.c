/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:45 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/16 13:45:42 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
	{
		return (0);
	}
	checkarguments(&a, &b, argv, argc);
	if (a.size <= 3)
		push_swap3(&a);
	else if (a.size == 4)
		push_swap4(&a, &b);
	else if (a.size == 5)
		push_swap5(&a, &b);
	else if (a.size <= 100)
		push_swap100(&a, &b, 5);
	else if (a.size >= 500)
		push_swap500(&a, &b, 2);
	free (a.list);
	free (b.list);
	return (0);
}

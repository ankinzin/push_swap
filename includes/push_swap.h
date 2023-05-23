/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:33:58 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/20 18:35:39 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

// t_stack structure
typedef struct s_pushswap
{
	long		*list;
	int			size;
	char		c;
	int			error_code;
}	t_stack;

//
typedef struct s_pushplus
{
	long	val;
	int		sent;
	int		total;
	int		ntil;
	int		step;
	t_stack	lst;
}	t_func_var;

// ft_check_args.c
void	checkarguments(t_stack *a, t_stack *b, char **argv, int argc);
void	check_int_limits(t_stack *a);
void	check_reps(t_stack *a);
void	check_invalid_single_argv(char *str);
void	check_invalid_mult_argv(int argc, char **argv);
// ft_split.c
char	**ft_split(char *str);
int		word_counter(char *str);
void	free_split(char **str);
// list_utils.c
int		min_index(long *list, int size);
int		max_index(long *list, int size);
long	ft_median(long *list, int size, int ntil, int part);
long	*ascending_list(long *lst, int size);
// ft_moves.c
void	ft_remove_first_elem(t_stack *s);
void	ft_swap(t_stack *s);
void	ft_shiftup(t_stack *s);
void	ft_shiftdown(t_stack *s);
void	ft_push(t_stack *from, t_stack *to);
// ft_multiples_args.c
void	init_b(t_stack *b);
void	ft_multiple_argv(t_stack *a, t_stack *b, int argc, char **argv);
// pushswap3.c
void	push_swap3(t_stack *s);
// pushswap5.c
void	push_swap5(t_stack *a, t_stack *b);
void	push5_utils(t_stack *a, t_stack *b);
void	push_swap4(t_stack *a, t_stack *b);
// pushswap100.c
void	push_swap100(t_stack *a, t_stack *b, int part);
void	pushswap_100logic(t_stack *a, t_stack *b, int part);
// pushswap500.c
void	push_swap500(t_stack *a, t_stack *b, int part);
void	index_in_chunk2(t_stack *s, long val);
void	pushswap_500logic(t_stack *b, t_stack *a, int part);
// ft_single_argv.c
void	ft_single_argv(t_stack *a, t_stack *b, char *str);
void	init_a_sigle_argv(t_stack *a, char *str);
void	str_null(char *str);
// ft_sort_t_stack.c
void	minontop(t_stack *s);
void	maxontop(t_stack *s);
void	index_in_chunk(t_stack *s, int val);
void	do_best_rotate(t_stack *s, int posi, int posj, int center);
void	best_rotate(t_stack *s, int i, int j);
// ft_sort_t_stack2.c
void	betterb(t_stack *s, long val, int step);
void	bettera(t_stack *s, long val, int step);
void	ft_finish(t_stack *from, t_stack *to);
int		is_sorted(t_stack *s);
// ft_str_to_number.c
int		is_number(char xar);
int		is_positive_negative(char xar);
int		ft_atoi(char *str);
long	ft_atol(char *str);
// utils.c
int		ft_abs(int x, int y);
int		ft_avarege(int *list, int size);
void	print_t_stacks(t_stack a, t_stack b);
int		ft_strcmp(char *s1, char *s2);
void	check_is_space(char *str);
long	*ft_cpy_list(long *list, int size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:34:37 by ankinzin          #+#    #+#             */
/*   Updated: 2023/05/17 12:02:33 by ankinzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	word_counter(char *str)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

static int	word_len(char *str, int pos)
{
	int	len;
	int	i;

	i = pos;
	len = 0;
	while (str[i] && str[i] != ' ')
	{
		len++;
		i++;
	}
	return (len);
}

static char	*get_word(char *str, int pos)
{
	char	*arg;
	int		i;
	int		j;

	i = pos;
	j = 0;
	arg = (char *)malloc(sizeof(char) * (word_len(str, pos) + 1));
	while (str[i] && str[i] != ' ')
		arg[j++] = str[i++];
	arg[j] = '\0';
	return (arg);
}

char	**ft_split(char *str)
{
	char	**args;
	int		i;
	int		s;

	if (!str)
		return (NULL);
	i = 0;
	s = 0;
	args = (char **)malloc((sizeof(char *)) * (word_counter(str) + 1));
	while (str[i])
	{
		while (str[i] && str[i] == ' ')
			i++;
		if (str[i])
			args[s++] = get_word(str, i++);
		while (str[i] && str[i] != ' ')
			i++;
	}
	args[s] = NULL;
	return (args);
}

void	free_split(char **str)
{
	int	string;

	string = 0;
	while (str[string])
		free (str[string++]);
	free (str[string]);
	free (str);
}

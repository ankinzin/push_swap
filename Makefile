# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ankinzin <ankinzin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:33:44 by ankinzin          #+#    #+#              #
#    Updated: 2023/05/15 15:30:08 by ankinzin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Mandatory --- #
# Executable file
NAME	= push_swap

# My ft_printf
PRINTFDIR	= ./includes/ft_printf/
PRINTFLIB	= ./includes/ft_printf/libftprintf.a

# Compiler and shell scripts
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g
RM		= rm -f

# Source files
SRCDIR	= ./src/
SRC		= ./src/ft_check_args.c ./src/ft_split.c ./src/list_utils.c \
			./src/ft_moves.c ./src/ft_multiple_argv.c ./src/push_swap.c \
			./src/push_swap3.c ./src/push_swap5.c ./src/push_swap100.c \
			./src/push_swap500.c ./src/ft_single_argv.c \
			./src/ft_sort_stack.c ./src/ft_sort_stack2.c ./src/ft_str_to_num.c ./src/utils.c

# Target and rules
all: $(NAME)

$(NAME): $(PRINTFLIB) $(SRC)
		$(CC) $(CFLAGS) $(PRINTFLIB) $(SRC) -o $(NAME)

$(PRINTFLIB):
		make -C $(PRINTFDIR)

clean:
		make clean -C $(PRINTFDIR)

fclean: clean
		make fclean -C $(PRINTFDIR)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

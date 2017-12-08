# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsikora <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/23 16:56:40 by nsikora           #+#    #+#              #
#    Updated: 2017/12/07 16:01:52 by nsikora          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fillit

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

INCLUDE	=	fillit.h

SRCS	=	main.c 				\
			ft_read.c			\
			ft_algo.c			\
			ft_print_tetri.c	\
			ft_check_error.c

all: 		$(NAME)
			make -C libft
			$(CC) -o $(NAME) $(OBJS) -I ./$(INCLUDE) -L./libft -lft

$(NAME): $(OBJS)

%.o: %.c
	$(CC) -o $@ -c $< -I $(INCLUDE) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)
	make re -C libft/

.PHONY: all re clean fclean

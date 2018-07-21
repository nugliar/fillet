# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsharipo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 09:51:19 by rsharipo          #+#    #+#              #
#    Updated: 2018/07/19 19:25:36 by rsharipo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c ft_solver.c ft_sq_rt.c ft_filler.c ft_stack.c ft_isvalid.c

OBJ = $(SRC:.c=.o)

LIB = libft.a

CFLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

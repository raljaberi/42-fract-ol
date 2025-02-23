# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: raljaber <raljaber@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 18:54:28 by raljaber          #+#    #+#              #
#    Updated: 2024/07/18 15:05:29 by raljaber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = main.c \
	events.c \
	init.c \
	math.c \
	render.c \
	helper.c \
	parsing.c
		
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L minilibx -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)
PRINTS = ./ft_printf/libftprintf.a 

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx
	make -C ft_printf
	cc $(CFLAGS) $(OBJ) $(PRINTS) $(LDFLAGS) -o $(NAME)

clean:
	make -C minilibx clean
	make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	rm -f ft_printf/libftprintf.a
	rm -f $(NAME)

re: fclean all

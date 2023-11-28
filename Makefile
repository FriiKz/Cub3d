# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbusi <lbusi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 18:54:27 by aliburdi          #+#    #+#              #
#    Updated: 2023/11/28 11:55:15 by lbusi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3d		

CC = gcc

CFLAGS = -g -Wall -Werror -Wextra -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm

SRC = PROVA.c matrix.c utils.c angles.c input.c draw.c map.c libft_utils.c\
	./get_next_line/get_next_line_utils.c \
   ./get_next_line/get_next_line.c \

OBJ = $(SRC:.c=.o)

.%o: %.c
	$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./minilibX
	$(CC) $(OBJ) minilibX/libmlx.a $(CFLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
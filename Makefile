# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 03:03:23 by tclarita          #+#    #+#              #
#    Updated: 2019/11/08 03:33:27 by tclarita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = draw_line.c main.c read_file.c change.c keybord_change.c

OFILES = $(SRC:.c-.o)

HEADER = fdf.h

FLAGS = -Wall -Werror -Wextra

LIBFT = libft

MLX = minilibx_macos

.PHONY: clean fclean all re

all: $(NAME)

$(NAME):
	@make -C $(LIBFT)
	@make -C $(MLX)
	@clang -o fdf -Wall -Werror -Wextra *.c libft/libft.a \
	minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

clean:
	rm -f $(OFILES)
	make clean -C $(LIBFT)
	make clean -C $(MLX)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

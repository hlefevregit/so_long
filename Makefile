# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hulefevr <hulefevr@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:44:56 by hulefevr          #+#    #+#              #
#    Updated: 2024/05/07 17:44:56 by hulefevr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_GNL = ./src/gnl/
PATH_MAP = ./src/treat_map/
PATH_ER = ./src/error/
PATH_UT = ./src/utils/
PATH_GAME = ./src/game/
PATH_OBJ = ./obj/

NAME = so_long

SRCS =	./src/so_long.c \
		$(PATH_MAP)init_sprites.c \
		$(PATH_GAME)utils.c \
		$(PATH_MAP)maps.c \
		$(PATH_MAP)read_map.c \
		$(PATH_ER)error.c \
		$(PATH_MAP)check.c \
		$(PATH_GAME)deplacements.c \
		$(PATH_GAME)init_game.c \
		$(PATH_GNL)get_next_line.c \
		$(PATH_GNL)get_next_line_utils.c \
		$(PATH_UT)check_ext.c \
		$(PATH_UT)ft_itoa.c \
		$(PATH_UT)ft_strdup.c \
		$(PATH_MAP)printmap.c \
		$(PATH_UT)ft_putstr.c \
		$(PATH_UT)ft_calloc.c \
		$(PATH_UT)ft_memset.c \
		$(PATH_MAP)path_finding.c \

		

CFLAGS = -Wall -Wextra -Werror -Iminilibx-linux -fsanitize=address -g

CC = gcc

LIBFT_DIR = libft

LIBFT_LIB = $(LIBFT_DIR)/libftprintf.a

LIBFT_FLAGS = -L$(LIBFT_DIR)

MINILIBX_DIR = minilibx-linux

MINILIBX_LIB = $(MINILIBX_DIR)/libmlx_Linux.a

RM = rm -f

OBJS = $(SRCS:%.c=%.o)

all: $(LIBFT_LIB) $(MINILIBX_LIB) $(NAME)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(MINILIBX_LIB):
	make -C $(MINILIBX_DIR)

$(NAME): $(OBJS) $(LIBFT_LIB)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT_FLAGS) -Lmlx_linux -lmlx_Linux -L$(MINILIBX_DIR) -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I -Imlx_linux -O3 -c $< -o $@

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make clean -C $(MINILIBX_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
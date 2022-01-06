PATH_GNL = ./src/gnl/
PATH_MAP = ./src/treat_map/
PATH_ER = ./src/error/
PATH_UT = ./src/utils/
PATH_GAME = ./src/game/
PATH_MLX = ./src
PATH_OBJ = ./obj

MLX = $(PATH_MLX)libmlx.a
NAME = so_long

FILES =	$(PATH_MAP)check.c \
		$(PATH_MAP)init_sprites.c \
		$(PATH_MAP)maps.c \
		$(PATH_MAP)printmap.c \
		$(PATH_MAP)read_map.c \
		$(PATH_ER)error.c \
		$(PATH_GAME)deplacements.c \
		$(PATH_GAME)init_game.c \
		$(PATH_GAME)utils.c \
		$(PATH_GNL)get_next_line.c \
		$(PATH_GNL)get_next_line_utils.c \
		$(PATH_UT)check_ext.c \
		$(PATH_UT)ft_itoa.c \
		$(PATH_UT)ft_strlen.c \

OBJ = $(patsubst ./src/%.c, $(PATH_OBJ)%.o, $(FILES))

CC = gcc
FLAGS = -Wextra -Wall -Werror

all:	$(NAME)

$(NAME): $(OBJ)
		@make -C $(PATH_MLX)
		@gcc $(FLAGS) ./src/so_long.c $(OBJ) $(MLX) -o so_long

$(PATH_OBJ)%.o:	./src/%.c
	@mkdir %(PATH_OBJ)
	gcc $(FLAGS) -I. -c $< -o $@

clean:
	rm -rf $(PATH_OBJ)

fclean: clean
	@make clean -C $(PATH_MLX)
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean
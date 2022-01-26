PATH_GNL = ./src/gnl/
PATH_MAP = ./src/treat_map/
PATH_ER = ./src/error/
PATH_UT = ./src/utils/
PATH_GAME = ./src/game/
PATH_OBJ = ./obj/

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
		$(PATH_UT)ft_strdup.c \
		./src/so_long.c

OBJ = ${FILES:.c=.o}

FLAGS = -Wextra -Wall -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -lz

all:	${NAME}

${NAME}: ${OBJ}
		gcc $(OBJ) $(MLXFLAGS) $(FLAGS) -o $(NAME)

%o:	%.c
	gcc $(FLAGS) -lmlx -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.out

re: fclean all

.PHONY: all clean fclean re
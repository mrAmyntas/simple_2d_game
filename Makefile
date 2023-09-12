NAME = so_long

MLX_NAME = libmlx.dylib

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

OBJ_DIR = obj/

SRC_DIR = src/

SRC =	src/build_map.c\
		src/so_long.c\
		src/readmap.c\
		src/readimages.c\
		src/keypresses.c\
		src/sprites_to_win.c\
		src/utils.c\
		src/errors.c\
		src/get_next_line.c\
		src/ft_split.c

OBJ = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

HEADER_FILES = include/solong.h

all: $(MLX_NAME) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L. -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(MLX_NAME):
	make -C ./mlx
	cp ./mlx/libmlx.dylib libmlx.dylib

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER_FILES)
	$(CC) -c $(FLAGS) -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

clean:
	rm -f obj/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(MLX_NAME)
	make clean -C ./mlx

re: fclean all

.PHONY: all clean fclean re
NAME = so_long

SRCS = mapcontrol.c main.c flood_fill.c cpymapcontrol.c free.c info.c mlx.c movement.c

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft/libft.a
MLX_LIB = minilibx-linux/libmlx_Linux.a
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(GET_NEXT_LINE) $(MLX_LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(GET_NEXT_LINE) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

$(MLX_LIB):
	make -C minilibx-linux

clean:
	make clean -C libft
	make clean -C minilibx-linux
	rm -rf *.o

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = so_long

SRCS = mapcontrol.c main.c flood_fill.c

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

LIBFT = libft/libft.a
MLX_LIB = minilibx-linux/libmlx_Linux.a
FT_PRINTF = printf/libftprintf.a
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MLX_FLAGS = -Lminilibx-linux -lmlx_Linux -L/usr/X11R6/lib -lXext -lX11 -lm -lbsd

all: $(NAME)

$(NAME): $(SRCS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MLX_LIB)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C libft

$(FT_PRINTF):
	make -C printf

$(MLX_LIB):
	make -C minilibx-linux

clean:
	make clean -C libft
	make clean -C printf
	make clean -C minilibx-linux
	rm -rf *.o

fclean: clean
	make fclean -C libft
	make fclean -C printf
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

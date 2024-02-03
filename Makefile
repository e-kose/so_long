NAME = so_long

COLOUR_BLUE=\033[0;34m
SRCS = main.c error.c checker.c so_long_utils.c \
		init.c hook.c checker2.c free.c GNL/get_next_line.c \
		GNL/get_next_line_utils.c
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Lmlx -lmlx -Llibft -lft -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\033[0;34m"
	@make -C ./libft
	@make -C ./mlx
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "\033[33m┏┓   ┓"
	@echo "┗┓┏┓ ┃┏┓┏┓┏┓"
	@echo "┗┛┗┛━┗┗┛┛┗┗┫"
	@echo "           ┛\033[0m"

clean:
	@echo "\033[0;34m"
	@make clean -C ./libft
	@rm -rf $(OBJS)

fclean: clean
	@echo "\033[33m"
	@make fclean -C ./libft
	@make clean -C ./mlx
	@rm -f $(NAME)
	@echo "\n\033[31mDeleting EVERYTHING!\n"

re: fclean all

.PHONY: all clean fclean re

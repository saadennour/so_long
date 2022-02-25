NAME=so_long

CC=gcc

SRCS= movement.c draw.c get_next_line.c get_next_line_utils.c so_long.c tools.c more_tools.c map_helpers.c move_helpers.c

FLAGS=-Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

OBJS= ${SRCS:.c=.o}

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
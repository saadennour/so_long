NAME=so_long

BONUS = so_long_bonus

CC=gcc

MOVES= movement.c move_helpers.c \

BMOVES = movement_bonus.c move_helpers_bonus.c \

MAP =  map_helpers.c draw.c \

BMAP = map_helpers_bonus.c draw_bonus.c \

GNL = get_next_line.c get_next_line_utils.c \

TOOLS = tools.c more_tools.c \

BTOOLS = tools_bonus.c more_tools_bonus.c \

MAIN = so_long.c \

BMAIN = so_long_bonus.c \

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

OBJS = $(MAIN:.c=.o) $(GNL:.c=.o) $(TOOLS:.c=.o) $(MAP:.c=.o) $(MOVES:.c=.o)

BOBJS= $(BMAIN:.c=.o) $(GNL:.c=.o) $(BTOOLS:.c=.o) $(BMAP:.c=.o) $(BMOVES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(MAIN) $(GNL) $(TOOLS) $(MAP) $(MOVES) -o $(NAME)

bonus : $(BOBJS)
	$(CC) $(FLAGS) $(BMAIN) $(GNL) $(BTOOLS) $(BMAP) $(BMOVES) -o $(BONUS)

clean:
	rm -rf $(OBJS) $(BOBJS)

fclean: clean
	rm -rf $(NAME) $(BONUS)


re: fclean all

.PHONY:all clean fclean re bonus
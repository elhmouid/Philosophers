CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.
NAME    = philosophers

SRC     = philosophers.c parsing.c
OBJ     = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lpthread -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = printf

CC = cc
FLAGS = -Wall -Werror -Wextra

SRC = $(wildcard *.c)
HEADER = $(wildcard *.h)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o:%.c
	$(CC) $(FLAGS) $^ -c $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

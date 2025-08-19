NAME = printf

CC = cc
FLAGS = -g -Wall -Werror -Wextra

SRC = $(wildcard *.c)
OBJ_F = objs
OBJ = $(addprefix $(OBJ_F)/,$(SRC:.c=.o))

all: $(OBJ_F) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ libft.a -o $@

$(OBJ_F)/%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_F):
	mkdir $@

clean:
	rm -rf $(OBJ_F)

fclean: clean
	rm -f $(NAME)

re: fclean all

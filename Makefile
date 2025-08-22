NAME = libftprintf.a

NAME_TEST = printf

CC = cc
FLAGS = -g -Wall -Werror -Wextra

SRC = ft_printf.c ft_printpointer.c ft_printchar.c ft_printdecimal.c \
	  ft_printstr.c ft_printunsigned.c

OBJ_F = objs
OBJ = $(addprefix $(OBJ_F)/,$(SRC:.c=.o))

LIBFT = libft/libft.a

all: $(OBJ_F) $(NAME)

$(NAME_TEST): $(OBJ) $(LIBFT) objs/main.o
	$(CC) $(FLAGS) $^ -o $@

$(NAME): $(OBJ) $(LIBFT)
	cp $(LIBFT) $@
	ar rcs $@ $^ $(LIBFT)

$(OBJ_F)/%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_F):
	mkdir $@

objs/main.o: main.c
	$(CC) $(FLAGS) -c $^ -o $@

$(LIBFT):
	make bonus -C libft

clean:
	rm -rf $(OBJ_F)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(NAME_TEST)
	make -C libft fclean

test: fclean $(OBJ_F) $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean re

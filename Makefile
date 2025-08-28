NAME = libftprintf.a

CC = cc
FLAGS = -g -Wall -Werror -Wextra

SRC = ft_printf.c ft_printpointer.c ft_printchar.c ft_printdecimal.c \
	  ft_printstr.c ft_printunsigned.c ft_printhexa.c

OBJ_F = objs
OBJ = $(addprefix $(OBJ_F)/,$(SRC:.c=.o))

LIBFT = libft/libft.a

all: $(OBJ_F) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	cd $(OBJ_F) && ar -x ../$(LIBFT)
	ar rcs $@ $(OBJ) $(OBJ_F)/*.o

$(OBJ_F)/%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_F):
	mkdir $@

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

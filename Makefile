NAME = libftprintf.a

CC = cc
FLAGS = -g -Wall -Werror -Wextra

SRC = ft_printf.c ft_printpointer.c ft_printchar.c ft_printdecimal.c \
	  ft_printstr.c ft_printunsigned.c ft_printhexa.c

OBJ_F = objs
OBJ = $(addprefix $(OBJ_F)/,$(SRC:.c=.o))

LIBFT = libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
RESET = \033[0m

all: $(OBJ_F) $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "\n$(GREEN)> Compilating libftprintf.a...$(RESET)\n"
	cd $(OBJ_F) && ar -x ../$(LIBFT)
	ar rcs $@ $(OBJ) $(OBJ_F)/*.o

$(OBJ_F)/%.o:%.c
	$(CC) $(FLAGS) -c $^ -o $@

$(OBJ_F):
	@echo "\n$(GREEN)> Compilating printf...$(RESET)\n"
	mkdir $@

clean:
	@echo "\n$(RED)> Cleaning objs...$(RESET)\n"
	rm -rf $(OBJ_F)

fclean: clean
	@echo "\n$(RED)> Cleaning binaries and objs...$(RESET)\n"
	rm -f $(NAME) $(NAME_TEST)

re: fclean all

.PHONY: all clean fclean re

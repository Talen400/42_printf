NAME = libftprintf.a

CC = cc
FLAGS = -g -Wall -Werror -Wextra

SRC = ft_printf.c ft_printpointer.c ft_printchar.c ft_printdecimal.c \
	  ft_printstr.c ft_printunsigned.c ft_printhexa.c

OBJ_DIR = objs
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
LIBFT_DIR = libft
LIBFT = libft/libft.a

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "\n$(GREEN)> Compilating libftprintf.a...$(RESET)\n"
	cp $(LIBFT) $@
	ar rcs $@ $(OBJ)

$(OBJ_DIR)/%.o:%.c
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	@echo "\n$(YELLOW)> Compilation libft...$(YELLOW)"
	make -C $(LIBFT_DIR)

clean:
	@echo "\n$(RED)> Cleaning objs...$(RESET)\n"
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "\n$(RED)> Cleaning binaries and objs...$(RESET)\n"
	rm -f $(NAME) $(NAME_TEST)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

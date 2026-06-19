NAME := libftprintf.a
CC := cc
CFLAGS := -Wall -Werror -Wextra

LIBFT_DIR = libft/
LIBFT := $(LIBFT_DIR)/libft.a

SRCS_DIR := srcs
SRCS := $(SRCS_DIR)/ft_printf.c # \
		other

OBJS_DIR := objs
OBJS := $(patsubst $(SRCS_DIR)/%.c,$(OBJS_DIR)/%.o,$(SRCS))

HEADERS := includes/ft_printf.h

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $@
	ar rcs $@ $(OBJS)

$(OBJS):$(SRCS)
	mkdir -p $(OBJS_DIR)
	$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

TEST_OUT = test_out

clean:
	rm -rf $(OBJS_DIR) $(TEST_OUT)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

FILE_TEST = test.c

test: re
	cc $(FILE_TEST) libftprintf.a -o test_out
	./$(TEST_OUT) || true

val: test
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		./$(TEST_OUT)

.PHONY= all clean fclean re test
.DEFAULT_GOAL := all

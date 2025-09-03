NAME = libft.a
NAME_TEST = test

CC = cc
FLAGS = -Wall -Wextra -Werror

C_SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
        ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
        ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
        ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
        ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
        ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
        ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		

BONUS_SRC = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJ = $(C_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

H_SRC = libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

$(NAME_TEST) : $(OBJ) $(BONUS_OBJ)
	$(CC) $(FLAGS) $^ -o $@

%.o: %.c $(H_SRC)
	$(CC) $(FLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME_TEST) test_gdb

re: fclean all

re$(NAME_TEST): fclean $(NAME_TEST)

gdb: $(OBJ) $(BONUS_OBJ)
	$(CC) -g $^ -o test_gdb

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $^

.PHONY: all clean fclean re bonus

CC = gcc
NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
SRC = main.c push_swap.c
UTILS = utils/error_handling.c utils/init_stack.c utils/split_argv.c\
		utils/utils_a_to_b.c utils/utils_algorithm.c utils/utils_b_to_a.c \
		utils/utils_list.c
ACTIONS = actions/push.c actions/reverse_rotate.c actions/rotate.c\
		actions/swap.c actions/algorithm.c
SRCS = $(SRC) $(UTILS) $(ACTIONS)
OBJ = $(SRCS:.c=.o)
LIBFTPRINTF = ./ft_printf/libftprintf.a
DEPS = $(wildcard *.h)

all : $(NAME)

$(NAME) : $(LIBFTPRINTF) $(OBJ)
	cp $(LIBFTPRINTF) $(NAME)
	ar -rcs $@ $^

$(LIBFTPRINTF):
	make -C ./ft_printf all
%.o: %.c $(DEPS)
	$(CC) -c $(CFLAGS) $< -o $@

clean :
	make -C ./ft_printf clean
	rm -f $(OBJ)

fclean: clean
	make -C ./ft_printf fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

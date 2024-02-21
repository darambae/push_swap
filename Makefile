CC = gcc -g
NAME = push_swap
BONUS_NAME = checker
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
OBJ_DIR = obj/
SRC_DIR = srcs/
CHECKER_DIR = checker/
SRC = main.c push_swap.c
UTILS = utils/error_handling.c utils/init_stack.c utils/split_argv.c\
		utils/utils_a_to_b.c utils/utils_algorithm.c utils/utils_b_to_a.c \
		utils/utils_list.c
ACTIONS = actions/push.c actions/reverse_rotate.c actions/rotate.c\
		actions/swap.c actions/algorithm.c
BONUS = checker/checker.c checker/checker_utils.c checker/get_next_line/get_next_line_utils.c checker/get_next_line/get_next_line.c
SRCS = $(addprefix $(SRC_DIR), $(SRC) $(UTILS) $(ACTIONS) $(BONUS))
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o) $(UTILS:.c=.o) $(ACTIONS:.c=.o) $(BONUS:.c=.o))
DEPS = $(wildcard *.h)
BONUS_OBJ = $(BONUS:.c=.o)

all : $(NAME)

bonus: $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $^

$(LIBFT):
		$(MAKE) -C ./libft

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(DEPS)
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_DIR)%.o: $(CHECKER_DIR)%.c $(DEPS)
	@mkdir -p $(@D)
	@$(CC) -c $(CFLAGS) $< -o $@	

clean:
	$(MAKE) clean -C ./libft
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C ./libft 
	@$(RM) -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re

NAME = push_swap

CHECK = checker

LIBFT = libft/

LIBFT_A =	$(LIBFT)libft.a

SRC_PUSH_SWAP = push_swap.c \
	src/stack/stack_utils.c \
	src/stack/stack_functions.c \
	src/arguments/check_arguments.c \
	src/algorithm/radix_sort.c \
	src/algorithm/sort_three.c \
	src/operations/ft_push_operations.c \
	src/operations/ft_rotate_operations.c \
	src/operations/ft_swap_operations.c \
	src/operations/ft_reverse_rotate_operations.c \
	src/free/free.c 

SRC_CHECKER = checker_bonus.c \
	src_bonus/arguments_bonus/check_arguments_bonus.c \
	src_bonus/free_bonus/free_bonus.c \
	src_bonus/stack_bonus/stack_functions_bonus.c \
	src_bonus/stack_bonus/stack_utils_bonus.c \
	src_bonus/operations_bonus/ft_push_operations_bonus.c \
	src_bonus/operations_bonus/ft_rotate_operations_bonus.c \
	src_bonus/operations_bonus/ft_swap_operations_bonus.c \
	src_bonus/operations_bonus/ft_reverse_rotate_operations_bonus.c

CC = cc

CC_FLAGS = -g -Wall -Wextra -Werror 

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)

OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJ_PUSH_SWAP)
	@$(CC) $(CC_FLAGS) $(OBJ_PUSH_SWAP) $(LIBFT_A) -o $(NAME)

bonus: $(LIBFT_A) $(CHECK)

$(CHECK): $(OBJ_CHECKER)
	@$(CC) $(CC_FLAGS) $(OBJ_CHECKER) $(LIBFT_A) -o $(CHECK)

.c.o:
	@$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT_A):
	@make -C $(LIBFT)

clean:
	@rm -f $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME) $(CHECK)
	@make fclean -C $(LIBFT)

re: fclean all

r:$(NAME)
	clear
	@echo "Input: ${var}"
	@./$(NAME) ${var}

v: $(NAME)
	clear
	@echo "input: ${var}\n"
	@valgrind -s --track-origins=yes  --leak-check=full --show-leak-kinds=all ./$(NAME) ${var}

c:
	@find . -type f -iname "*.c" -exec grep "//" {} +

t:$(NAME) $(CHECK)
	clear
	@echo "Input: ${ARG}"
	@valgrind ./$(NAME) ${ARG} | valgrind ./$(CHECK) ${ARG}

.PHONY: all clean fclean re v c bonus

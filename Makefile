NAME = push_swap

CHECK = checker

LIBFT = libft/

LIBFT_A =	$(LIBFT)libft.a

SRC_PUSH_SWAP = push_swap.c \
	src/stack/stack_utils.c \
	src/stack/stack_functions.c \
	src/arguments/check_arguments.c \
	src/algorithm/radix_sort.c \
	src/algorithm/sort_values.c \
	src/operations/ft_push_operations.c \
	src/operations/ft_rotate_operations.c \
	src/operations/ft_swap_operations.c \
	src/operations/ft_reverse_rotate_operations.c \
	src/free/free.c 

SRC_CHECKER = checker_bonus.c \
	src_bonus/arguments_bonus/check_arguments_bonus.c \
	src_bonus/arguments_bonus/validation_bonus.c \
	src_bonus/free_bonus/free_bonus.c \
	src_bonus/stack_bonus/stack_functions_bonus.c \
	src_bonus/stack_bonus/stack_utils_bonus.c \
	src_bonus/commands_bonus/read_operations_bonus.c \
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

chat:
	./$(NAME) 0 1 2 4 3 | wc -l
	./$(NAME) 0 1 3 2 4 | wc -l
	./$(NAME) 0 1 3 4 2 | wc -l
	./$(NAME) 0 1 4 2 3 | wc -l
	./$(NAME) 0 1 4 3 2 | wc -l
	./$(NAME) 0 2 1 3 4 | wc -l
	./$(NAME) 0 2 1 4 3 | wc -l
	./$(NAME) 0 2 3 1 4 | wc -l
	./$(NAME) 0 2 3 4 1 | wc -l
	./$(NAME) 0 2 4 1 3 | wc -l
	./$(NAME) 0 2 4 3 1 | wc -l
	./$(NAME) 0 3 1 2 4 | wc -l
	./$(NAME) 0 3 1 4 2 | wc -l
	./$(NAME) 0 3 2 1 4 | wc -l
	./$(NAME) 0 3 2 4 1 | wc -l
	./$(NAME) 0 3 4 1 2 | wc -l
	./$(NAME) 0 3 4 2 1 | wc -l
	./$(NAME) 0 4 1 2 3 | wc -l
	./$(NAME) 0 4 1 3 2 | wc -l
	./$(NAME) 0 4 2 1 3 | wc -l
	./$(NAME) 0 4 2 3 1 | wc -l
	./$(NAME) 0 4 3 1 2 | wc -l
	./$(NAME) 0 4 3 2 1 | wc -l
	./$(NAME) 1 0 2 3 4 | wc -l
	./$(NAME) 1 0 2 4 3 | wc -l
	./$(NAME) 1 0 3 2 4 | wc -l
	./$(NAME) 1 0 3 4 2 | wc -l
	./$(NAME) 1 0 4 2 3 | wc -l
	./$(NAME) 1 0 4 3 2 | wc -l
	./$(NAME) 1 2 0 3 4 | wc -l
	./$(NAME) 1 2 0 4 3 | wc -l
	./$(NAME) 1 2 3 0 4 | wc -l
	./$(NAME) 1 2 3 4 0 | wc -l
	./$(NAME) 1 2 4 0 3 | wc -l
	./$(NAME) 1 2 4 3 0 | wc -l
	./$(NAME) 1 3 0 2 4 | wc -l
	./$(NAME) 1 3 0 4 2 | wc -l
	./$(NAME) 1 3 2 0 4 | wc -l
	./$(NAME) 1 3 2 4 0 | wc -l
	./$(NAME) 1 3 4 0 2 | wc -l
	./$(NAME) 1 3 4 2 0 | wc -l
	./$(NAME) 1 4 0 2 3 | wc -l
	./$(NAME) 1 4 0 3 2 | wc -l
	./$(NAME) 1 4 2 0 3 | wc -l
	./$(NAME) 1 4 2 3 0 | wc -l
	./$(NAME) 1 4 3 0 2 | wc -l
	./$(NAME) 1 4 3 2 0 | wc -l
	./$(NAME) 2 0 1 3 4 | wc -l
	./$(NAME) 2 0 1 4 3 | wc -l
	./$(NAME) 2 0 3 1 4 | wc -l
	./$(NAME) 2 0 3 4 1 | wc -l
	./$(NAME) 2 0 4 1 3 | wc -l
	./$(NAME) 2 0 4 3 1 | wc -l
	./$(NAME) 2 1 0 3 4 | wc -l
	./$(NAME) 2 1 0 4 3 | wc -l
	./$(NAME) 2 1 3 0 4 | wc -l
	./$(NAME) 2 1 3 4 0 | wc -l
	./$(NAME) 2 1 4 0 3 | wc -l
	./$(NAME) 2 1 4 3 0 | wc -l
	./$(NAME) 2 3 0 1 4 | wc -l
	./$(NAME) 2 3 0 4 1 | wc -l
	./$(NAME) 2 3 1 0 4 | wc -l
	./$(NAME) 2 3 1 4 0 | wc -l
	./$(NAME) 2 3 4 0 1 | wc -l
	./$(NAME) 2 3 4 1 0 | wc -l
	./$(NAME) 2 4 0 1 3 | wc -l
	./$(NAME) 2 4 0 3 1 | wc -l 	
	./$(NAME) 2 4 1 0 3 | wc -l
	./$(NAME) 2 4 1 3 0 | wc -l
	./$(NAME) 2 4 3 0 1 | wc -l
	./$(NAME) 2 4 3 1 0 | wc -l
	./$(NAME) 3 0 1 2 4 | wc -l
	./$(NAME) 3 0 1 4 2 | wc -l
	./$(NAME) 3 0 2 1 4 | wc -l
	./$(NAME) 3 0 2 4 1 | wc -l
	./$(NAME) 3 0 4 1 2 | wc -l
	./$(NAME) 3 0 4 2 1 | wc -l
	./$(NAME) 3 1 0 2 4 | wc -l
	./$(NAME) 3 1 0 4 2 | wc -l
	./$(NAME) 3 1 2 0 4 | wc -l
	./$(NAME) 3 1 2 4 0 | wc -l
	./$(NAME) 3 1 4 0 2 | wc -l
	./$(NAME) 3 1 4 2 0 | wc -l
	./$(NAME) 3 2 0 1 4 | wc -l
	./$(NAME) 3 2 0 4 1 | wc -l
	./$(NAME) 3 2 1 0 4 | wc -l
	./$(NAME) 3 2 1 4 0 | wc -l
	./$(NAME) 3 2 4 0 1 | wc -l
	./$(NAME) 3 2 4 1 0 | wc -l
	./$(NAME) 3 4 0 1 2 | wc -l
	./$(NAME) 3 4 0 2 1 | wc -l
	./$(NAME) 3 4 1 0 2 | wc -l
	./$(NAME) 3 4 1 2 0 | wc -l
	./$(NAME) 3 4 2 0 1 | wc -l
	./$(NAME) 3 4 2 1 0 | wc -l
	./$(NAME) 4 0 1 2 3 | wc -l
	./$(NAME) 4 0 1 3 2 | wc -l
	./$(NAME) 4 0 2 1 3 | wc -l
	./$(NAME) 4 0 2 3 1 | wc -l
	./$(NAME) 4 0 3 1 2 | wc -l
	./$(NAME) 4 0 3 2 1 | wc -l
	./$(NAME) 4 1 0 2 3 | wc -l
	./$(NAME) 4 1 0 3 2 | wc -l
	./$(NAME) 4 1 2 0 3 | wc -l
	./$(NAME) 4 1 2 3 0 | wc -l
	./$(NAME) 4 1 3 0 2 | wc -l
	./$(NAME) 4 1 3 2 0 | wc -l
	./$(NAME) 4 2 0 1 3 | wc -l
	./$(NAME) 4 2 0 3 1 | wc -l
	./$(NAME) 4 2 1 0 3 | wc -l
	./$(NAME) 4 2 1 3 0 | wc -l
	./$(NAME) 4 2 3 0 1 | wc -l
	./$(NAME) 4 2 3 1 0 | wc -l
	./$(NAME) 4 3 0 1 2 | wc -l
	./$(NAME) 4 3 0 2 1 | wc -l
	./$(NAME) 4 3 1 0 2 | wc -l
	./$(NAME) 4 3 1 2 0 | wc -l
	./$(NAME) 4 3 2 0 1 | wc -l
	./$(NAME) 4 3 2 1 0 | wc -l

t:$(NAME) $(CHECK)
	clear
	@echo "Input: ${ARG}"
	@valgrind ./$(NAME) ${ARG} | valgrind ./$(CHECK) ${ARG}

.PHONY: all clean fclean re v c bonus t

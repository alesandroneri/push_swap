NAME = push_swap

CHECK = checker

LIBFT = libft/

LIBFT_A=	$(LIBFT)libft.a

SRC =	push_swap.c \
		src/checker/checker.c \
		src/algorithm/find_values.c \
		src/algorithm/radix_sort.c \
		src/algorithm/sort_three.c \
		src/stack_functions/stack_utils.c \
		src/arguments/check_arguments.c \
		src/operations/ft_push_operations.c \
		src/operations/ft_rotate_operations.c \
		src/operations/ft_swap_operations.c \
		src/free/free.c \
		src/operations/ft_reverse_rotate_operations.c

CHECKER =	checker.c \
			src/free/free.c \
			src/stack_functions/stack_utils.c \
			src/operations/ft_push_operations.c \
			src/operations/ft_rotate_operations.c \
			src/operations/ft_swap_operations.c \
			src/operations/ft_reverse_rotate_operations.c

CC = cc

INCLUDE= includes

CC_FLAGS = -g -Wall -Wextra -Werror -I$(INCLUDE)

OBJS = $(SRC:.c=.o)

CHECK_OBJS = ${CHECK_SRCS:.c=.o}

all: $(LIBFT_A) $(NAME) $(CHECK)

$(NAME): $(OBJS)
	@$(CC) $(CC_FLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)

$(CHECK): $(CHECK_OBJS)
	@$(CC) $(CC_FLAGS) $(OBJS) $(LIBFT_A) -o $(CHECK)

.c.o:
	@$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT_A):
	@make -C $(LIBFT)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean $(NAME)

v:	$(NAME)
	clear
	@echo "input: ${var}\n"
	@./$(NAME) ${var}

c:
	@find . -type f -iname "*.c" -exec grep "//" {} +

.PHONY: all clean fclean re v c
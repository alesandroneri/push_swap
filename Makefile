NAME = push_swap

LIBFT = libft/

GNL = get_next_line/

LIBFT_A=	$(LIBFT)libft.a

SRC =	push_swap.c \
		src/check_arguments.c \
		src/ft_operations.c \
		src/push_swap_utils.c
		

CC = cc

CC_FLAGS = -g -Wall -Wextra -Werror 

OBJS = $(SRC:.c=.o)

all: $(LIBFT_A) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(OBJS) $(LIBFT) -O $(NAME)

.c.o:
	$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)

$(LIBFT_A):
	@make -C $(LIBFT)

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIBFT)

re: fclean $(NAME)

run: re
	@clear
	@$(CC) $(CC_FLAGS) main.c $(NAME)
	@./a.out

.PHONY: all clean fclean re run 

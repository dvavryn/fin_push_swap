NAME	:=	push_swap

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

SRCS	:=	src/error.c \
			src/ex_op.c \
			src/free.c \
			src/get_stack.c \
			src/main.c \
			src/operations.c \
			src/sort_utils.c \
			src/sort.c \
			libft/libft.a


$(NAME):
	@make -s -C libft
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME) -g

all: $(NAME)
	@echo "Make all"

clean:
	@echo "Make clean"
	@make clean -s -C libft

fclean: clean
	@echo "Make fclean"
	@rm -f $(NAME)
	@make fclean -s -C libft

re:	fclean all

.PHONY: all clean fclean re
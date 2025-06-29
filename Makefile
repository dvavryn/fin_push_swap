NAME	:= push_swap

CC		:= cc

CFLAGS	:= -Wall -Wextra -Werror

SRCS	:=	\
		./src/error.c \
		./src/ex_op.c \
		./src/free.c \
		./src/get_stack.c \
		./src/isempty.c \
		./src/main.c \
		./src/operations.c \
		./src/sort_utils.c \
		./src/sort.c \

OBJS	:= $(SRCS:.c=.o)

$(NAME)	: $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -o $(NAME) -g

all		: $(NAME)

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ -g

clean	:
	@make clean -C libft
	@rm -f $(OBJS)

fclean	: clean
	@make fclean -C libft
	@rm -f $(NAME)

re		: fclean all

.PHONY: all clean fclean re
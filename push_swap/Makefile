NAME		=			push_swap
CC			=			gcc
CFLAGS		=			-Wall -Werror -Wextra
DEPS		=			push_swap.h

SRCS		=									\
						main.c					\
						checking.c				\
						stack.c					\
						stack_commands.c		\
						stack_commands2.c		\
						stack_commands3.c		\
						stack_commands4.c		\
						allowed_commands.c		\
						allowed_commands2.c		\
						allowed_commands3.c		\

OBJS		=			$(SRCS:.c=.o)

%.o:		%.c $(DEPS)
			@$(CC) -c $< $(CFLAGS)

$(NAME):	$(OBJS)
			@make bonus -C libft
			@cp libft/libft.a libft.a
			@$(CC) libft.a $(OBJS) -o $(NAME) $(CFLAGS)

all:		$(NAME)

clean:
			@rm -f libft/*.o
			@rm -f libft/libft.a
			@rm -f *.o

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

test:		$(NAME)
			./$(NAME) 1 2 3 4 5 6

.SILENT: clean fclean
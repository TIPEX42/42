NAME		=			push_swap
CC			=			gcc
CFLAGS		=			-Wall -Werror -Wextra
DEPS		=			push_swap.h

SRCS		=						\
						main.c		\
						checking.c	\

OBJS		=			$(SRCS:.c=.o)

%.o:		%.c $(DEPS)
			@$(CC) -c $< $(CFLAGS)

$(NAME):	$(OBJS)
			@make libft/Makefile
			@$(CC) libft/libft.a $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			@rm -f *.o

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.SILENT: clean fclean
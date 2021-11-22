NAME		=		libftprintf.a
CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra
DEPS		=		libft.h libft.a
SRCS		=		$(wildcard *.c)
OBJS		=		$(SRCS:.c=.o)

%.o:		%.c $(DEPS)
			$(CC) -c $< $(CFLAGS)

$(NAME):	$(OBJS)
			rm -f $(NAME)
			ar -rcs $(NAME) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			rm -f *.o

fclean: clean
			rm -f $(NAME)

re: fclean all
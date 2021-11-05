NAME		=		libft.a
CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra
DEPS		=		libft.h
SRCS		=		$(wildcard *.c)
SRCSB		=		$(wildcard *lst*.c)
OBJS		=		$(SRCS:.c=.o)

%.o:		%.c $(DEPS)
			$(CC) -c $< $(CFLAGS)

$(NAME):	$(OBJS)
			ar -rcs libft.a *.o
			ranlib $(NAME)

all:		$(NAME)

bonus:		$(NAME)

clean:
			rm -f $(OBJS)

fclean: clean
			rm -f $(NAME)

re: fclean all
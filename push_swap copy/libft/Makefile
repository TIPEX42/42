NAME		=		libft.a
CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra
DEPS		=		libft.h
SRCS		=		$(wildcard *.c)
SRCSB		=		$(wildcard *lst*.c)
SRCSA 		=		$(filter-out $(SRCSB), $(SRCS))
OBJSA		=		$(SRCSA:.c=.o)
OBJSB		=		$(SRCSB:.c=.o)

%.o:		%.c $(DEPS)
			@$(CC) -c $< $(CFLAGS)

$(NAME):	$(OBJSA)
			@ar -rcs libft.a $(OBJSA)
			@ranlib $(NAME)

all:		$(NAME)

bonus:		$(OBJSA) $(OBJSB)
			@ar -rcs libft.a *.o
			@ranlib $(NAME)

clean:
			@rm -f *.o

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

.SILENT:	clean fclean
.PHONY:		all
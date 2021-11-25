NAME		=		libftprintf.a
CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra
DEPS		=		ft_printf.h Makefile
SRCS		=							\
					ft_printf.c			\
					ft_print_char.c		\
					ft_print_hex.c		\
					ft_print_hex_big.c	\
					ft_print_integer.c	\
					ft_print_uinteger.c	\
					ft_putnbr_base.c	\
					ft_print_ptr.c		\
					ft_print_str.c		\
					ft_strlen.c			\
					ft_putnbr_fd.c		\

OBJS		=		$(SRCS:.c=.o)

%.o:		%.c $(DEPS)
			$(CC) -c $< $(CFLAGS)

$(NAME):	$(OBJS)
			rm -f $(NAME)
			ar -rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f *.o

fclean: clean
			rm -f $(NAME)

re: fclean all
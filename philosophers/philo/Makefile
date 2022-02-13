NAME		=		philo
CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -O2 -MD
LD_FLAGS	=

SRCS		=							\
					ft_printf.c			\
					ft_print_char.c		\
					ft_print_hex.c		\
					ft_print_hex_big.c	\
					ft_print_integer.c	\
					ft_print_uinteger.c	\
					ft_putnbr_base_fd.c	\
					ft_print_ptr.c		\
					ft_print_str.c		\
					ft_putnbr_fd.c		\
					main.c				\
					ft_calloc.c			\
					ft_strlen.c			\
					ft_atoi.c			\
					ft_isspace.c		\
					ft_isdigit.c		\
					init.c				\
					timestamp.c			\
					philo.c				\

OBJDIR		=		objs/
OBJS		=		$(addprefix $(OBJDIR), $(SRCS:.c=.o))
DEPENDS		=		$(addprefix $(OBJDIR), $(SRCS:.c=.d))

$(OBJDIR)%.o:		%.c
					@echo "[Philo] Compiling $<"
					@mkdir -p $(OBJDIR)
					@$(CC) -c $< $(CFLAGS) -o $@

$(NAME):			$(OBJS)
					@echo "Linking $(NAME)..."
					@$(CC) $(OBJS) $(LD_FLAGS) -o $(NAME)

.PHONY: all
all:				$(NAME)

.PHONY: clean
clean:
					rm -f $(OBJS)
					rm -f $(DEPENDS)

.PHONY: fclean
fclean: clean
					rm -f $(NAME)

.PHONY: re
re: fclean all

-include $(DEPENDS)
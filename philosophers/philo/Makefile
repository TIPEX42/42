NAME		=		philo
CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -O2 -MD
LDFLAGS		=

SRCS		=							\
					main.c				\
					ft_calloc.c			\
					ft_strlen.c			\
					ft_atoi.c			\
					ft_isspace.c		\
					ft_isdigit.c		\
					init.c				\
					time.c				\
					philo.c				\
					philo_utils.c		\
					philo_mutex.c		\
					helper.c			\
					init_helper.c

OBJDIR		=		objs/
OBJS		=		$(addprefix $(OBJDIR), $(SRCS:.c=.o))
DEPENDS		=		$(addprefix $(OBJDIR), $(SRCS:.c=.d))

$(OBJDIR)%.o:		%.c
					@echo "[Philo] Compiling $<"
					@mkdir -p $(OBJDIR)
					@$(CC) -c $< $(CFLAGS) -o $@

$(NAME):			$(OBJS) Makefile
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
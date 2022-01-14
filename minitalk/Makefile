CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -fsanitize=address
LDFLAGS		=		-fsanitize=address

SERVER		=		server
CLIENT		=		client
NAME		=		$(SERVER)

SRCDIR		=		srcs/
SERVERSRC	=		main.c Printf/ft_print_char.c Printf/ft_print_hex.c Printf/ft_print_hex_big.c						\
					Printf/ft_print_integer.c Printf/ft_print_ptr.c Printf/ft_print_str.c Printf/ft_print_uinteger.c	\
					Printf/ft_printf.c Printf/ft_putnbr_base.c Printf/ft_putnbr_fd.c Printf/ft_strlen.c

CLIENTSRC	=		main.c ft_atoi.c ft_isdigit.c

SERVERSRCS	=		$(addprefix $(SRCDIR)$(SERVER)/, $(SERVERSRC))
CLIENTSRCS	=		$(addprefix $(SRCDIR)$(CLIENT)/, $(CLIENTSRC))

OBJDIR		=		objs/
SERVEROBJS	=		$(addprefix $(OBJDIR)$(SERVER)/, $(notdir $(SERVERSRCS:.c=.o)))
CLIENTOBJS	=		$(addprefix $(OBJDIR)$(CLIENT)/, $(notdir $(CLIENTSRCS:.c=.o)))

all:				$(CLIENT) $(SERVER)

$(NAME):			$(SERVEROBJS)
					@echo "compiling server ..."
					@$(CC) $(SERVEROBJS) $(LDFLAGS) -o $(NAME)

$(CLIENT):			$(CLIENTOBJS)
					@echo "compiling client"
					@$(CC) $(CLIENTOBJS) $(LDFLAGS) -o $(CLIENT)

$(OBJDIR)$(SERVER)/%.o:		$(SRCDIR)$(SERVER)/%.c $(SERVER).h
							@echo "Compiling $<"
							@mkdir -p objs
							@$(CC) -c $< $(CFLAGS) -o $@

$(OBJDIR)$(SERVER)/%.o:		$(SRCDIR)$(SERVER)/Printf/%.c $(SERVER).h
							@echo "Compiling $<"
							@mkdir -p objs
							@$(CC) -c $< $(CFLAGS) -o $@

$(OBJDIR)$(CLIENT)/%.o:		$(SRCDIR)$(CLIENT)/%.c $(CLIENT).h
							@echo "Compiling $<"
							@mkdir -p objs
							@$(CC) -c $< $(CFLAGS) -o $@

clean:
					rm -f $(CLIENTOBJS) $(SERVEROBJS)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY: all clean fclean re
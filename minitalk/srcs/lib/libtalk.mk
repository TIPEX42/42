LIB_SRCS	=		ft_atoi.c ft_isdigit.c ft_strlen.c ft_print_char.c ft_print_hex.c ft_print_hex_big.c				\
					ft_print_integer.c ft_print_ptr.c ft_print_str.c ft_print_uinteger.c ft_printf.c ft_putnbr_base.c	\
					ft_putnbr_fd.c

OBJDIR		=		objs/
OBJS		=		$(addprefix $(OBJDIR), $(LIB_SRCS:.c=.o))

DEPENDS		=		$(addprefix $(OBJDIR), $(LIB_SRCS:.c=.d))

.PHONY: all
all:				$(LIBTALK_LIB)

$(LIBTALK_LIB):		$(OBJS) $(MASTER_MAKE)
					@echo "Linking $(notdir $(LIBTALK_LIB))..."
					@ar -rcs $(LIBTALK_LIB) $(OBJS)

$(OBJDIR)%.o:		%.c
					@echo "Compiling $<"
					@mkdir -p $(OBJDIR)
					@$(BIN_CC) -c $< $(BIN_CFLAGS) -o $@

.PHONY: clean
clean:
					rm -f $(DEPENDS)
					rm -f $(OBJS)

.PHONY: re
re:					fclean $(LIBTALK_LIB)

-include $(DEPENDS)
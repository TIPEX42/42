SRCDIR		=		srcs/
ROOTSRCS	=		main.c mlx_draw.c mlx_colors.c parsing.c map_init.c \
					map_draw.c map_scale.c app_init.c mlx_keys.c

SRCSMAND	=		$(addprefix $(SRCDIR)mandatory/, $(ROOTSRCS))

OBJDIR		=		objs/
OBJSMAND	=		$(addprefix $(OBJDIR)mandatory/, $(notdir $(SRCSMAND:.c=.o)))

DEPENDSMAND	=		$(addprefix $(OBJDIR)mandatory/, $(notdir $(SRCSMAND:.c=.d)))

.PHONY: all
all:				$(BIN)

$(BIN):				$(OBJSMAND) ../Libft/libft.a root.mk ../Makefile
					@echo "Linking $(notdir $(BIN))..."
					$(BIN_CC) $(LIB_PATH) $(LIBS) $(OBJSMAND) $(BIN_LDFLAGS) -o $(BIN)
					@sleep 1.1
					@touch bonus.mk

$(OBJDIR)%.o:		$(SRCDIR)%.c
					@echo "Compiling $<"
					@mkdir -p $(OBJDIR)mandatory
					@$(BIN_CC) -c $< $(BIN_CFLAGS) $(INC_PATH) -o $@

.PHONY: clean
clean:
					rm -f $(DEPENDSMAND)
					rm -f $(OBJSMAND)

.PHONY: re
re:					fclean $(BIN)

-include $(DEPENDSMAND)

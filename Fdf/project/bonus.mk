SRCDIR		=		srcs/
ROOTSRCS	=		main.c mlx_draw.c mlx_colors.c parsing.c map_init.c \
					map_draw.c map_scale.c app_init.c mlx_keys.c

SRCSBONUS	=		$(subst .c,_bonus.c, $(addprefix $(SRCDIR)bonus/, $(ROOTSRCS)))

OBJDIR		=		objs/
OBJSBONUS	=		$(addprefix $(OBJDIR)bonus/, $(notdir $(SRCSBONUS:.c=.o)))

DEPENDSBONUS=		$(addprefix $(OBJDIR)bonus/, $(notdir $(SRCSBONUS:.c=.d)))

.PHONY: all
all:				$(BIN)

$(BIN):				$(OBJSBONUS) ../Libft/libft.a bonus.mk ../Makefile
					@echo "Linking $(notdir $(BIN))..."
					$(BIN_CC) $(LIB_PATH) $(LIBS) $(OBJSBONUS) $(BIN_LDFLAGS) -o $(BIN)
					@sleep 1.1
					@touch root.mk

$(OBJDIR)%.o:		$(SRCDIR)%.c
					@echo "Compiling $<"
					@mkdir -p $(OBJDIR)bonus
					@$(BIN_CC) -c $< $(BIN_CFLAGS) $(INC_PATH) -o $@

.PHONY: clean
clean:
					rm -f $(DEPENDSBONUS)
					rm -f $(OBJSBONUS)

.PHONY: re
re:					fclean $(BIN)

-include $(DEPENDSBONUS)

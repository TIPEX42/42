NAME		=	cube

MAIN_DIR	=	main
MAIN		=	main.c

RENDER_DIR	=	renderer
RENDERER	=	renderer.c colors_helper.c

SRC_MAIN	=	$(addprefix $(MAIN_DIR)/, $(MAIN))
SRC_RENDER	=	$(addprefix $(MAIN_DIR)/, $(RENDERER))

OBJS		=	$(addprefix $(OBJS_DIR)/, $(MAIN:.c=.o))	\
				$(addprefix $(OBJS_DIR)/, $(RENDERER:.c=.o))

DEPENDS		=	$(addprefix $(OBJS_DIR)/, $(OBJS:.o=.d))

# Recipe
# ****************************************************************************

.PHONY: all
all:	../$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/$(MAIN_DIR)/%.c | $(OBJS_DIR)
	@$(BIN_CC) $(BIN_CFLAGS) -c $< -o $@
	@printf "$(_YELLOW)█$(_END)"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/$(RENDER_DIR)/%.c | $(OBJS_DIR)
	@$(BIN_CC) $(BIN_CFLAGS) -c $< -o $@
	@printf "$(_YELLOW)█$(_END)"

../$(NAME):	$(OBJS) $(MASTER_MAKE) $(LIBFT_LIB) $(MLX_LIB)
	@printf "$(_BLUE)\nCompiled source files\n$(_END)"
	@$(BIN_CC) $(BIN_LDFLAGS) $(OBJS) -o ../$(NAME) $(LIBS)
	@printf "$(_YELLOW)Finish compiling $(NAME)!$(_END)\n"

.PHONY: bonus
bonus: all

.PHONY: clean
clean:
	@printf "$(_YELLOW)Removing object files ...$(_END)\n"
	@rm -rf $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	@printf "$(_RED)Removing Executable ...$(_END)\n"
	@rm -f ../$(NAME)

re: fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

-include $(DEPENDS)

NAME		=	parsing

SRCS		=	main.c parsing.c command_split.c minishell_error.c get_redirections.c get_redirections_helper.c			\
				parsing_helper.c get_next_word.c get_single_quotes.c get_double_quotes.c get_env_var_first_word.c		\
				get_env_var_raw.c env_var_helper.c parsing_error.c file_and_directories.c strip_out_operators.c			\
				tokenize.c lexer.c token_type.c command_batch.c

OBJS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

HEADERS		=	$(MAKE_DIR)/includes/minishell.h

DEPENDS		=	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.d))

# Recipe
# ****************************************************************************

.PHONY: all
all:	$(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(BIN_CC) $(BIN_CFLAGS) -c $< -o $@
	@printf "$(_GREEN)█$(_END)"

$(NAME):	$(OBJS) $(MASTER_MAKE) $(LIBFT_LIB)
	@printf "$(_BLUE)\nCompiled source files\n$(_END)"
	@$(BIN_CC) $(BIN_LDFLAGS) $(OBJS) -o ../$@ $(LIBS)
	@printf "$(_GREEN)Finish compiling $(NAME)!$(_END)\n"

.PHONY: bonus
bonus: all

.PHONY: clean
clean:
	rm -rf $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	rm -f ../$(NAME)

re: fclean all

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

-include $(DEPENDS)

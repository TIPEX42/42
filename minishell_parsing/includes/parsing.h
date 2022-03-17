/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cybattis <cybattis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 21:46:20 by njennes           #+#    #+#             */
/*   Updated: 2022/03/07 11:37:17 by cybattis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stddef.h>
# include "libft.h"

# define TOKEN_UNKNOWN -2
# define TOKEN_EMPTY -1
# define TOKEN_END 0
# define TOKEN_COMMAND 1
# define TOKEN_ARG 2
# define TOKEN_PIPE 3
# define TOKEN_REDIR_OUT 4
# define TOKEN_REDIR_IN 5
# define TOKEN_REDIR_OUT_APPEND 6
# define TOKEN_REDIR_HEREDOC 7
# define TOKEN_FILE 8

# define PATH_FILE 1
# define PATH_DIRECTORY 2

typedef struct s_redir
{
	int			type;
	char		*file;
}				t_redir;

typedef struct s_command
{
	int			is_piping;
	int			is_redirecting;
	int			is_builtin;
	char		*name;
	char		**args;
	char		*str;
	t_redir		*redirections;
}				t_command;

typedef struct s_command_batch
{
	t_command	*commands;
	size_t		count;
}				t_command_batch;

typedef struct s_parser
{
	size_t		i;
	char		*str;
}				t_parser;

typedef struct s_token
{
	int			type;
	char		*str;
}				t_token;

typedef struct s_lexer
{
	t_token		*tokens;
	size_t		count;
}				t_lexer;

typedef struct s_err_or_charptr
{
	char		*error;
	char		*result;
}				t_err_or_charptr;

t_gc			*get_gc();

//NEW
int					error_return(char *msg, int code);
int					split_input_into_commands(char *input, t_command_batch *batch);
int					get_redirections(char *input, t_command_batch *batch);

int					is_operator_char(char c);
int					is_envchar(char c);
int					is_redirection_char(char c);
char				*skip_spaces(char *str);
size_t				skip_quotes(char *str);
int					contains_open_spaces(char *str);

t_err_or_charptr	get_next_word(char *str, int expand_vars);

t_err_or_charptr	get_double_quotes(t_parser *parser);
t_err_or_charptr	get_single_quotes(t_parser *parser);

char				*get_env_var_first_word(t_parser *parser);
char				*get_env_var_raw(t_parser *parser);
char				*get_env_var_name(t_parser *parser);

char				*error_ambiguous_redirection(char *str);
char				*parsing_error(char *str);
char				*file_error(char *str, char *file);

int					is_valid_path(char *str);
int					contains_file(char *str);
int					is_absolute_path(char *str);
void				make_absolute_path(char **str);

t_parser			*strip_out_operators(char *input, t_command_batch *batch);

//parsing.c
t_command_batch	parse_input(char *input);

//get_token.c
t_token			consume_single_quotes(t_parser *parser, t_lexer *lexer);
t_token			consume_double_quotes(t_parser *parser, t_lexer *lexer);
t_token			consume_word(t_parser *parser, t_lexer *lexer);

//token_type.c
int				is_operator(char c);
int				is_redir_token(int token);
int				get_token_type(char *token, t_lexer *lexer, int handle_op);

//tokenizer.c
t_lexer			tokenize_input(char *input);

//lexer.c
int				get_last_token_type(t_lexer *lexer);
void			lexer_add_token(t_token token, t_lexer *lexer);
void			lexer_add_end(t_lexer *lexer);
void			lexer_destroy(t_lexer *lexer);

//handle_env.c
int				is_envchar(char c);
void			handle_dollar_sign(t_parser *parser, t_lexer *lexer,
					int chop_tokens, t_token *current);

//parsing_error.c
int				check_parsing_errors(t_lexer lexer);

//command_batch.c
void			create_command_batch(t_lexer lexer, t_command_batch *batch);

//command_batch_helper.c
size_t			get_redirs_count(t_token *tokens);
size_t			get_arg_count(t_token *tokens);
int				is_builtin_command(char *str);

//Debug
void			lexer_print(t_lexer *lexer);
char			*token_type_to_str(int token_type);

#endif

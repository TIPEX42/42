NAME		=			push_swap
CC			=			gcc
CFLAGS		=			-Wall -Werror -Wextra -fsanitize=address
DEPS		=			push_swap.h Makefile

SRCS		=									\
						main.c					\
						checking.c				\
						stack.c					\
						stack_commands.c		\
						stack_commands2.c		\
						stack_commands3.c		\
						stack_commands4.c		\
						allowed_commands.c		\
						allowed_commands2.c		\
						allowed_commands3.c		\

PATH_OBJS	=			objs/

OBJS		=			$(addprefix $(PATH_OBJS), $(SRCS:.c=.o))

objs/%.o:				%.c $(DEPS)
						@mkdir -p $(PATH_OBJS)
						@printf "\x1B[34m Compiling $<\n"
						@$(CC) -c $< $(CFLAGS) -o $@

$(NAME):				$(OBJS)
						@make bonus -C libft
						@cp libft/libft.a libft.a
						@printf "\x1B[36m Linking $(NAME)...\n"
						@$(CC) libft.a $(OBJS) -o $(NAME) $(CFLAGS)

all:					header $(NAME)

info:					header

clean:	
						@rm -f libft/*.o
						@rm -f libft/libft.a
						@rm -f $(PATH_OBJS)*.o

fclean:					clean
						@rm -f $(NAME)

re:						fclean all

header:			
						@printf "\x1B[32m ________              ______       ________                          \n"
						@printf "\x1B[32m ___  __ \___  ___________  /_      ___/ __/__      _______ ________  \n"
						@printf "\x1B[32m __  /_/ /  / / /_  ___/_  __ \     __/__  __ | /| / /  __ '/__  __ \ \n"
						@printf "\x1B[32m _  ____// /_/ /_(__  )_  / / /     ____/ /__ |/ |/ // /_/ /__  /_/ / \n"
						@printf "\x1B[32m /_/     \__,_/ /____/ /_/ /_/      /____/ ____/|__/ \__,_/ _  .___/  \n"
						@printf "\x1B[32m                                                            /_/       \n"
						@printf "\n"

						@printf "\x1B[33m Compiler : $(CC)\n"
						@printf "\x1B[33m Flags : $(CFLAGS)\n"
						@printf "\x1B[33m Executable : $(NAME)\n"
						@printf "\n"

.SILENT: clean fclean
.PHONY: fclean all re clean
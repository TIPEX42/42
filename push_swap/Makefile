NAME		=			push_swap
CC			=			gcc
CFLAGS		=			-Wall -Werror -Wextra
DEPS		=			push_swap.h

SRCS		=														\
						$(PATH_SRCS)main.c							\
						$(PATH_SRCS)checking.c						\
						$(PATH_SRCS)checking2.c						\
						$(PATH_SRCS)splitting.c						\
						$(PATH_SRCS)splitting_optimizations.c		\
						$(PATH_SRCS)splitting_optimizations2.c		\
						$(PATH_SRCS)rotate_optimizations.c			\
						$(PATH_SRCS)stack.c							\
						$(PATH_SRCS)stack_basics.c					\
						$(PATH_SRCS)stack_get.c						\
						$(PATH_SRCS)stack_size.c					\
						$(PATH_SRCS)stack_sorted.c					\
						$(PATH_SRCS)stack_sorting.c					\
						$(PATH_SRCS)allowed_commands.c				\
						$(PATH_SRCS)allowed_commands2.c				\
						$(PATH_SRCS)allowed_commands3.c				\

OBJS		=														\
						$(PATH_OBJS)main.o							\
						$(PATH_OBJS)checking.o						\
						$(PATH_OBJS)checking2.o						\
						$(PATH_OBJS)splitting.o						\
						$(PATH_OBJS)splitting_optimizations.o		\
						$(PATH_OBJS)splitting_optimizations2.o		\
						$(PATH_OBJS)rotate_optimizations.o			\
						$(PATH_OBJS)stack.o							\
						$(PATH_OBJS)stack_basics.o					\
						$(PATH_OBJS)stack_get.o						\
						$(PATH_OBJS)stack_size.o					\
						$(PATH_OBJS)stack_sorted.o					\
						$(PATH_OBJS)stack_sorting.o					\
						$(PATH_OBJS)allowed_commands.o				\
						$(PATH_OBJS)allowed_commands2.o				\
						$(PATH_OBJS)allowed_commands3.o				\


PATH_OBJS	=			objs/
PATH_SRCS	=			srcs/

$(PATH_OBJS)%.o:		$(PATH_SRCS)%.c $(DEPS)
						@mkdir -p $(PATH_OBJS)
						@printf "\x1B[34m Compiling $<\n"
						@$(CC) -c $< $(CFLAGS) -o $@

$(NAME):				$(OBJS) Makefile
						@make bonus -C libft
						@printf "\x1B[36m Linking $(NAME)...\n"
						@printf "\x1B[33m Release compilation\n"
						@$(CC) -Llibft/ -lft $(OBJS) -o $(NAME) $(CFLAGS)

all:					header $(NAME)

info:					header

clean:
						@rm -f libft.a
						@make clean -C libft
						@rm -f $(PATH_OBJS)*.o

fclean:					clean
						@make fclean -C libft
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
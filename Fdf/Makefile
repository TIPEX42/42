CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -o2 -std=c11
LDFLAGS		=		-Wall -Werror -Wextra -o2 -framework OpenGL -framework AppKit -std=c11
NAME		=		fdf

LIBFT		=		Libft
MINILIBX	=		minilibx_macos

DEPS		=		fdf.h

SRCDIR		=		srcs/
SRC			=		main.c mlx_draw.c mlx_colors.c mlx_keys.c

SRCS		=		$(addprefix $(SRCDIR), $(SRC))

OBJDIR		=		objs/
OBJ			=		$(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

all:				$(NAME)

run:				all
					./$(NAME)

libs:
					@echo "Generating libft..."
					@make -C $(LIBFT)
					@echo "Generating minilibx..."
					@make -C $(MINILIBX)

$(NAME):			libs $(OBJ) Makefile
					@$(CC) -Llibft -Lminilibx_macos -lft -lmlx $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJDIR)%.o:		$(SRCDIR)%.c $(DEPS)
					@echo "Compiling $<"
					@mkdir -p objs
					@$(CC) -c $< $(CFLAGS) -o $@

clean:
					@make clean -C $(MINILIBX)
					@make clean -C $(LIBFT)
					rm -f $(OBJ)

fclean:
					@make clean -C $(MINILIBX)
					@make fclean -C $(LIBFT)
					rm -f $(OBJ)
					rm -f $(NAME)

re:					fclean $(NAME)
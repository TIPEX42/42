CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -o2
LDFLAGS		=		-Wall -Werror -Wextra -o2 -framework OpenGL -framework AppKit
NAME		=		fdf

LIBFT		=		libft
MINILIBX	=		minilibx_macos

DEPS		=		fdf.h

SRCDIR		=		srcs/
SRC			=		main.c mlx_draw.c

SRCS		=		$(addprefix $(SRCDIR), $(SRC))

OBJDIR		=		objs/
OBJ			=		$(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

all:				$(NAME)

libs:
					@echo "Generating libft..."
					@make -C $(LIBFT)
					@echo "Generating minilibx..."
					@make -C $(MINILIBX)

$(NAME):			libs $(OBJ) Makefile
					@$(CC) -Llibft -Lminilibx_macos -lft -lmlx $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ):				$(SRCS) $(DEPS)
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
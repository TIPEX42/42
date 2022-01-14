CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -std=c11
LDFLAGS		=		-framework OpenGL -framework AppKit -std=c11
NAME		=		fdf

LIBFT		=		Libft
MINILIBX	=		minilibx_macos

DEPS		=		fdf.h

SRCDIR		=		srcs/
SRC			=		main.c mlx_draw.c mlx_colors.c parsing.c map_init.c map_draw.c map_scale.c app_init.c mlx_keys.c

SRCS		=		$(addprefix $(SRCDIR), $(SRC))

OBJDIR		=		objs/
OBJS		=		$(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))


all:				$(NAME)

$(NAME):			$(OBJS)
					@$(MAKE) -C $(LIBFT)
					@$(MAKE) -C $(MINILIBX)
					$(CC) -Llibft -L$(MINILIBX) -lft -lmlx $(OBJS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)%.o:		$(SRCDIR)%.c
					@echo "Compiling $<"
					@mkdir -p objs
					@$(CC) -c $< $(CFLAGS) -o $@

clean:
					@make clean -C $(LIBFT)
					@make clean -C $(MINILIBX)
					rm -f $(OBJS)

fclean:				clean
					@make fclean -C $(LIBFT)
					@make clean -C $(MINILIBX)
					rm -f $(NAME)

re:					fclean $(NAME)

.PHONY: all clean fclean re
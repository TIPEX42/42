CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -std=c11
LDFLAGS		=		-framework OpenGL -framework AppKit -std=c11
NAME		=		fdf

LIBFT		=		Libft
MINILIBX	=		minilibx_macos

DEPS		=		fdf.h

SRCDIR		=		srcs/
SRC			=		main.c mlx_draw.c mlx_colors.c mlx_keys.c parsing.c map_init.c map_draw.c map_scale.c app_init.c
SRCBONUS	=		main.c mlx_draw.c mlx_colors.c mlx_keys_bonus.c parsing.c map_init.c map_draw.c map_scale.c app_init.c

SRCS		=		$(addprefix $(SRCDIR), $(SRC))
SRCSBONUS	=		$(addprefix $(SRCDIR), $(SRCBONUS))

OBJDIR		=		objs/
OBJ			=		$(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))
OBJBONUS	=		$(addprefix $(OBJDIR), $(notdir $(SRCSBONUS:.c=.o)))

$(OBJDIR)%.o:		$(SRCDIR)%.c
					@echo "Compiling $<"
					@mkdir -p objs
					@$(CC) -c $< $(CFLAGS) -o $@

all:				$(LIBFT)/libft.a $(OBJ)
					$(CC) -Llibft -L$(MINILIBX) -lft -lmlx $(OBJ) $(LDFLAGS) -o $(NAME)

$(NAME):			$(LIBFT)/libft.a $(OBJ)
					$(CC) -Llibft -L$(MINILIBX) -lft -lmlx $(OBJ) $(LDFLAGS) -o $(NAME)

bonus:				$(OBJBONUS) $(LIBFT)/libft.a
					$(CC) -Llibft -L$(MINILIBX) -lft -lmlx $(OBJBONUS) $(LDFLAGS) -o $(NAME)

$(LIBFT)/libft.a:	FORCE
					@$(MAKE) -C libft

FORCE:;

build:				$(OBJ)
					$(CC) -Llibft -L$(MINILIBX) -lft -lmlx $(OBJ) $(LDFLAGS) -o $(NAME)

build_bonus:		$(OBJBONUS)
					$(CC) -Llibft -L$(MINILIBX) -lft -lmlx $(OBJBONUS) $(LDFLAGS) -o $(NAME)

run:				all
					./$(NAME)

clean:
					@make clean -C $(LIBFT)
					rm -f $(OBJBONUS)

fclean:				clean
					@make fclean -C $(LIBFT)
					rm -f $(NAME)

re:					fclean $(NAME)

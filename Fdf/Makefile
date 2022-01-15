CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -std=c11
LDFLAGS		=		-framework OpenGL -framework AppKit -std=c11
NAME		=		fdf
BONUS		=		bonus

LIBFT		=		Libft
MINILIBX	=		minilibx_macos

DEPS		=		fdf.h

SRCDIR		=		srcs/
SRCBASE		=		main.c mlx_draw.c mlx_colors.c parsing.c map_init.c map_draw.c map_scale.c app_init.c
SRCM		=		mlx_keys.c
SRCBONUS	=		mlx_keys_bonus.c

SRCSBASE	=		$(addprefix $(SRCDIR), $(SRCBASE))
SRCSM		=		$(addprefix $(SRCDIR), $(SRCBASE) $(SRCM))
SRCSBONUS	=		$(addprefix $(SRCDIR), $(SRCBASE) $(SRCBONUS))

OBJDIR		=		objs/
OBJBASE		=		$(addprefix $(OBJDIR), $(notdir $(SRCSBASE:.c=.o)))
OBJM		=		$(addprefix $(OBJDIR), $(notdir $(SRCSM:.c=.o)))
OBJBONUS	=		$(addprefix $(OBJDIR), $(notdir $(SRCSBONUS:.c=.o)))

all:				$(NAME)

$(NAME):			$(OBJM)
					@$(MAKE) -C $(LIBFT)
					@$(MAKE) -C $(MINILIBX)
					@$(CC) -L$(LIBFT) -L$(MINILIBX) -lft -lmlx $(OBJM) $(LDFLAGS) -o $(NAME)

$(BONUS):			$(OBJBONUS)
					@$(MAKE) -C $(LIBFT)
					@$(MAKE) -C $(MINILIBX)
					@$(CC) -L$(LIBFT) -L$(MINILIBX) -lft -lmlx $(OBJBONUS) $(LDFLAGS) -o $(NAME)

$(OBJDIR)%.o:		$(SRCDIR)%.c $(DEPS)
					@echo "Compiling $<"
					@mkdir -p objs
					@$(CC) -c $< $(CFLAGS) -o $@

clean:
					@make clean -C $(LIBFT)
					@make clean -C $(MINILIBX)
					rm -f $(OBJBONUS)

fclean:				clean
					@make fclean -C $(LIBFT)
					@make clean -C $(MINILIBX)
					rm -f $(NAME)

re:					fclean $(NAME)

.PHONY: all clean fclean re $(BONUS)

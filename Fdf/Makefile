CC			=		gcc
CFLAGS		=		-Wall -Werror -Wextra -o2 -std=c11
LDFLAGS		=		-Wall -Werror -Wextra -o2 -framework OpenGL -framework AppKit -std=c11
CFLAGSD		=		$(CFLAGS) $(FSANITIZE)
LDFLAGSD	=		$(LDFLAGS) $(FSANITIZE)
FSANITIZE	=		-fsanitize=address
NAME		=		fdf

LIBFT		=		Libft
MINILIBX	=		minilibx_macos

DEPS		=		fdf.h

SRCDIR		=		srcs/
SRC			=		main.c mlx_draw.c mlx_colors.c mlx_keys.c parsing.c map_init.c map_draw.c app_init.c

SRCS		=		$(addprefix $(SRCDIR), $(SRC))

OBJDIR		=		objs/
OBJ			=		$(addprefix $(OBJDIR), $(notdir $(SRCS:.c=.o)))

OBJDIRD		=		objsd/
OBJD		=		$(addprefix $(OBJDIRD), $(notdir $(SRCS:.c=d.o)))

all:				$(NAME)

debug:				libsd
debug:				$(OBJD) Makefile
					$(CC) -Llibft -Lminilibx_macos -lftd -lmlx $(OBJD) $(LDFLAGSD) -o $(NAME)

$(NAME):			libs
$(NAME):			$(OBJ) Makefile
					$(CC) -Llibft -Lminilibx_macos -lft -lmlx $(OBJ) $(LDFLAGS) -o $(NAME)

run:				all
					./$(NAME)

libsd:
					@make debug -C $(LIBFT)
					@make -C $(MINILIBX)

libs:
					@make -C $(LIBFT)
					@make -C $(MINILIBX)

$(OBJDIR)%.o:		$(SRCDIR)%.c $(DEPS)
					@echo "Compiling $<"
					@mkdir -p objs
					@$(CC) -c $< $(CFLAGS) -o $@

$(OBJDIRD)%d.o:		$(SRCDIR)%.c $(DEPS)
					@echo "Compiling $<"
					@mkdir -p objsd
					@$(CC) -c $< $(CFLAGSD) -o $@

clean:
					@make clean -C $(MINILIBX)
					@make clean -C $(LIBFT)
					rm -f $(OBJ)
					rm -f $(OBJSD)

fclean:				clean
					@make clean -C $(MINILIBX)
					@make fclean -C $(LIBFT)
					rm -f $(NAME)

re:					fclean $(NAME)
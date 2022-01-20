MAKE_DIR		:=		$(PWD)

ROOT_DIR		:=		$(MAKE_DIR)/project
LIBFT_DIR		:=		$(MAKE_DIR)/Libft
MINILIBX_DIR	:=		$(MAKE_DIR)/minilibx

INC_PATH		:=		-I$(ROOT_DIR)
INC_PATH		+=		-I$(LIBFT_DIR)
INC_PATH		+=		-I$(MINILIBX_DIR)

LIB_PATH		:=
LIB_PATH		+=		-L$(LIBFT_DIR)
LIB_PATH		+=		-L$(MINILIBX_DIR)

LIBS			:=		-lft -lmlx

BIN_CC			=		gcc

BIN_CFLAGS		:=
BIN_CFLAGS		+=		$(INC_PATH)
BIN_CFLAGS		+=		-MD
BIN_CFLAGS		+=		-Wall -Werror -Wextra -std=c11

BIN_LDFLAGS		:=
BIN_LDFLAGS		+=		-framework OpenGL -framework AppKit

BIN				=		$(MAKE_DIR)/fdf

export MAKE_DIR
export INC_PATH
export LIB_PATH
export LIBS
export BIN_CC
export BIN_CFLAGS
export BIN_LDFLAGS
export BIN

.PHONY: all
all:
	@$(MAKE) -C Libft
	@$(MAKE) -C minilibx
	@$(MAKE) -C project -f root.mk -r -R  --warn-undefined-variables

.PHONY: bonus
bonus:
	@$(MAKE) -C Libft
	@$(MAKE) -C minilibx
	@$(MAKE) -C project -f bonus.mk -r -R --warn-undefined-variables

.PHONY: clean
clean:
	@$(MAKE) -C Libft clean
	@$(MAKE) -C minilibx clean
	@$(MAKE) -C project -f root.mk clean
	@$(MAKE) -C project -f bonus.mk clean

.PHONY: fclean
fclean:
	@$(MAKE) -C Libft fclean
	@$(MAKE) -C minilibx clean
	@$(MAKE) -C project -f root.mk clean
	@$(MAKE) -C project -f bonus.mk clean
	@rm -f $(BIN)

.PHONY: re
re: fclean all

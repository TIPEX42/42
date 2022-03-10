MAKE_DIR		:=		$(PWD)

MASTER_MAKE		:=		$(MAKE_DIR)/Makefile

SRCS_DIR		:=		$(MAKE_DIR)/src
OBJS_DIR		:=		$(MAKE_DIR)/obj

LIB_DIR			:=		$(MAKE_DIR)/libft

INC_PATH		:=		-I$(LIB_DIR) -I$(MAKE_DIR)/includes

LIB_PATH		:=		-L$(LIB_DIR)

READLINE		:=		-L ~/.brew/opt/readline/lib -lreadline -lhistory
INC_PATH		+=		-I ~/.brew/opt/readline/include/readline

LIBS			:=		$(LIB_PATH) -lftd $(READLINE)

BIN_CC			:=		gcc

BIN_CFLAGS		:=
BIN_CFLAGS		+=		-MD
BIN_CFLAGS		+=		-Wall -Wextra
BIN_CFLAGS		+=		-g3 -fsanitize=address
BIN_CFLAGS		+=		$(INC_PATH)

BIN_LDFLAGS		:=
BIN_LDFLAGS		+=		-fsanitize=address

LIBFT_LIB		:=		$(LIB_DIR)/libftd.a

export MAKE_DIR
export OBJS_DIR
export MASTER_MAKE
export SRCS_DIR
export OBJS_DIR
export INC_PATH
export LIB_PATH
export LIBS
export BIN_CC
export BIN_CFLAGS
export BIN_LDFLAGS
export LIBFT_LIB
export LIB_PATH
export READLINE

.PHONY: all
all:
	@$(MAKE) -j4 -C $(LIB_DIR) debug
	@$(MAKE) -C $(SRCS_DIR) -r -R --warn-undefined-variables

.PHONY: clean
clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@$(MAKE) -C $(SRCS_DIR) clean

.PHONY: fclean
fclean:
	@$(MAKE) -C $(LIB_DIR) fclean
	@$(MAKE) -C $(SRCS_DIR) fclean

.PHONY: re
re: fclean all

# Colors
# ****************************************************************************

_GREY	= \033[30m
_RED	= \033[31m
_GREEN	= \033[32m
_YELLOW	= \033[33m
_BLUE	= \033[34m
_PURPLE	= \033[35m
_CYAN	= \033[36m
_WHITE	= \033[37m
_END	= \033[0m

export _GREY
export _GREEN
export _YELLOW
export _BLUE
export _PURPLE
export _CYAN
export _WHITE
export _END


# ****************************************************************************

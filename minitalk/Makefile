MAKE_DIR		:=		$(PWD)

MASTER_MAKE		:=		$(MAKE_DIR)/Makefile

SRCS_DIR		:=		$(MAKE_DIR)/srcs

CLIENT_DIR		:=		$(SRCS_DIR)/client
SERVER_DIR		:=		$(SRCS_DIR)/server
LIB_DIR			:=		$(SRCS_DIR)/lib

INC_PATH		:=		-I$(CLIENT_DIR)
INC_PATH		+=		-I$(SERVER_DIR)
INC_PATH		+=		-I$(LIB_DIR)

LIB_PATH		:=		-L$(LIB_DIR)

LIBS			:=		-ltalk

BIN_CC			:=		gcc

BIN_CFLAGS		:=
BIN_CFLAGS		+=		$(INC_PATH)
BIN_CFLAGS		+=		-MD
BIN_CFLAGS		+=		-Wall -Werror -Wextra -O2 -fsanitize=address

BIN_LDFLAGS		:=
BIN_LDFLAGS		+=		-fsanitize=address

CLIENT_BIN		:=		$(MAKE_DIR)/client
SERVER_BIN		:=		$(MAKE_DIR)/server
LIBTALK_LIB		:=		$(LIB_DIR)/libtalk.a

export MAKE_DIR
export MASTER_MAKE
export INC_PATH
export LIB_PATH
export LIBS
export BIN_CC
export BIN_CFLAGS
export BIN_LDFLAGS
export CLIENT_BIN
export SERVER_BIN
export LIBTALK_LIB

.PHONY: all
all:
	@$(MAKE) -C $(LIB_DIR) -f libtalk.mk
	@$(MAKE) -C $(CLIENT_DIR) -f client.mk -r -R --warn-undefined-variables
	@$(MAKE) -C $(SERVER_DIR) -f server.mk -r -R --warn-undefined-variables

.PHONY: bonus
bonus:
	@$(MAKE) -C $(LIB_DIR) -f libtalk.mk
	@$(MAKE) -C $(CLIENT_DIR) -f client.mk -r -R --warn-undefined-variables
	@$(MAKE) -C $(SERVER_DIR) -f server.mk -r -R --warn-undefined-variables

.PHONY: clean
clean:
	@$(MAKE) -C $(LIB_DIR) -f libtalk.mk clean
	@$(MAKE) -C $(CLIENT_DIR) -f client.mk clean
	@$(MAKE) -C $(SERVER_DIR) -f server.mk clean

.PHONY: fclean
fclean:
	@$(MAKE) -C $(LIB_DIR) -f libtalk.mk clean
	@$(MAKE) -C $(CLIENT_DIR) -f client.mk clean
	@$(MAKE) -C $(SERVER_DIR) -f server.mk clean
	@rm -f $(BIN)

.PHONY: re
re: fclean all

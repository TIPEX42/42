CLIENT_SRCS	=		main.c

OBJDIR		=		objs/
OBJS		=		$(addprefix $(OBJDIR), $(CLIENT_SRCS:.c=.o))

DEPENDS		=		$(addprefix $(OBJDIR), $(CLIENT_SRCS:.c=.d))

.PHONY: all
all:				$(CLIENT_BIN)

$(CLIENT_BIN):		$(OBJS) $(LIBTALK_LIB) $(MASTER_MAKE)
					@echo "Linking $(notdir $(CLIENT_BIN))..."
					@$(BIN_CC) $(LIB_PATH) $(LIBS) $(OBJS) $(BIN_LDFLAGS) -o $(CLIENT_BIN)

$(OBJDIR)%.o:		%.c
					@echo "Compiling $<"
					@mkdir -p $(OBJDIR)
					@$(BIN_CC) -c $< $(BIN_CFLAGS) -o $@

.PHONY: clean
clean:
					rm -f $(DEPENDS)
					rm -f $(OBJS)

.PHONY: re
re:					fclean $(CLIENT_BIN)

-include $(DEPENDS)

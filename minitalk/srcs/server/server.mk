SERVER_SRCS	=		main.c

OBJDIR		=		objs/
OBJS		=		$(addprefix $(OBJDIR), $(notdir $(SERVER_SRCS:.c=.o)))

DEPENDS		=		$(addprefix $(OBJDIR), $(notdir $(SERVER_SRCS:.c=.d)))

.PHONY: all
all:				$(SERVER_BIN)

$(SERVER_BIN):		$(OBJS) $(LIBTALK_LIB) $(MASTER_MAKE)
					@echo "Linking $(notdir $(SERVER_BIN))..."
					@$(BIN_CC) $(LIB_PATH) $(LIBS) $(OBJS) $(BIN_LDFLAGS) -o $(SERVER_BIN)

$(OBJDIR)%.o:		%.c
					@echo "Compiling $<"
					@mkdir -p $(OBJDIR)
					@$(BIN_CC) -c $< $(BIN_CFLAGS) -o $@

.PHONY: clean
clean:
					rm -f $(DEPENDS)
					rm -f $(OBJS)

.PHONY: re
re:					fclean $(SERVER_BIN)

-include $(DEPENDS)
NAME		:=		zombieHorde

CFLAGS		:=		-Wall -Wextra -Werror -std=c++98 -MD
CXX			:=		c++

SRCS		:=		main.cpp zombieHorde.cpp Zombie.cpp

OBJDIR		:=		objs/
OBJS		:=		$(addprefix $(OBJDIR), $(SRCS:.cpp=.o))
DEPENDS		:=		$(addprefix $(OBJDIR), $(SRCS:.cpp=.d))

.PHONY: all
all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o: %.cpp $(OBJDIR)
	$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile
	$(CXX) $(OBJS) -o $(NAME)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPENDS)

.PHONY: re
re: fclean all

-include $(DEPENDS)
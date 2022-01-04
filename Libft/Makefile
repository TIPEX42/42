NAME				=		libft.a
CC					=		gcc
CFLAGS				=		-Wall -Werror -Wextra -o2
DEPS				=		libft.h

#=========================
#===========SRCS==========
#=========================
#LinkLists
LINKLISTDIR			=		DataStructures/LinkList/
LINKLIST			=		ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstize.c	\
							ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

#IO
IODIR				=		IO/
IO					=		ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_get_next_line.c

#Memory Management
MEMORYDIR			=		Memory/
MEMORY				=		ft_bzero.c ft_calloc.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c

#C style strings
CSTRINGSDIR			=		Strings/CStrings/
CSTRINGS			=		ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c		\
 							ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c 	\
 							ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c 	\
 							ft_tolower.c ft_toupper.c

#Stringviews
STRINGVIEWDIR		=		Strings/StringView/
STRINGVIEW			=		string_view.c

SRCS				=		$(addprefix $(LINKLISTDIR), $(LINKLIST))													\
							$(addprefix $(IODIR), $(IO)) 																\
							$(addprefix $(MEMORYDIR), $(MEMORY)) 														\
							$(addprefix $(CSTRINGSDIR), $(CSTRINGS)) 													\
							$(addprefix $(STRINGVIEWDIR), $(STRINGVIEW)) 												\

OBJSDIR				=		objs/

OBJS				=		$(addprefix $(OBJSDIR), $(notdir $(SRCS:.c=.o)))



$(OBJSDIR)%.o:		$(LINKLISTDIR)%.c $(DEPS)
					@$(CC) -c $< $(CFLAGS) -o $@
$(OBJSDIR)%.o:		$(IODIR)%.c $(DEPS)
					@$(CC) -c $< $(CFLAGS) -o $@
$(OBJSDIR)%.o:		$(MEMORYDIR)%.c $(DEPS)
					@$(CC) -c $< $(CFLAGS) -o $@
$(OBJSDIR)%.o:		$(CSTRINGSDIR)%.c $(DEPS)
					@$(CC) -c $< $(CFLAGS) -o $@
$(OBJSDIR)%.o:		$(STRINGVIEWDIR)%.c $(DEPS)
					@$(CC) -c $< $(CFLAGS) -o $@

$(NAME):			$(OBJS)
					@rm -f libft.a
					@ar -rcs libft.a $(OBJS)
					@ranlib $(NAME)

all:				$(NAME)

clean:
					@rm -f $(OBJSDIR)*.o

fclean: clean
					@rm -f $(NAME)

re: fclean all
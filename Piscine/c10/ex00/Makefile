# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/26 14:17:20 by njennes           #+#    #+#              #
#    Updated: 2021/08/26 14:24:40 by njennes          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

all: main.o
	gcc -Wall -Wextra -Werror -o ft_display_file main.o

main.o: main.c
	gcc -Wall -Wextra -Werror -c main.c

fclean:
	rm -f main.o

clean: fclean
	rm -f ft_display_file
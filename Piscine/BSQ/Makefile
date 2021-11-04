# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njennes <njennes@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 00:24:30 by bjeannot          #+#    #+#              #
#    Updated: 2021/08/25 13:32:58 by njennes          ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

bsq: File_parsing.o File_handling.o heatmap_generator.o heatmap_generator2.o List.o obstacle_finder.o output.o Math.o main_test.o
	gcc -Wall -Wextra -Werror -o bsq File_parsing.o File_handling.o heatmap_generator.o heatmap_generator2.o List.o obstacle_finder.o output.o Math.o main_test.o
File_handling.o: File_handling.c
	gcc -Wall -Wextra -Werror -c File_handling.c
File_parsing.o: File_parsing.c
	gcc -Wall -Wextra -Werror -c File_parsing.c
heatmap_generator.o: heatmap_generator.c
	gcc -Wall -Wextra -Werror -c heatmap_generator.c
heatmap_generator2.o: heatmap_generator2.c
	gcc -Wall -Wextra -Werror -c heatmap_generator2.c
List.o: List.c
	gcc -Wall -Wextra -Werror -c List.c
obstacle_finder.o: obstacle_finder.c
	gcc -Wall -Wextra -Werror -c obstacle_finder.c
output.o: output.c
	gcc -Wall -Wextra -Werror -c output.c
Math.o: Math.c
	gcc -Wall -Wextra -Werror -c Math.c
main_test.o: main_test.c
	gcc -Wall -Wextra -Werror -c main_test.c

clean:
	rm -f *.o
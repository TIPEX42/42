#!/bin/bash

make debug
gcc main.c libftd.a -fsanitize=address

if [ "$(./a.out 10)" != "V" ]; then
			echo "\x1B[31mError with ./a.out 10"
fi
if [ "$(./a.out -10)" != "V" ]; then
			echo "\x1B[31mError with ./a.out -10"
fi
if [ "$(./a.out 1)" != "V" ]; then
			echo "\x1B[31mError with ./a.out 1"
fi
if [ "$(./a.out -1)" != "V" ]; then
			echo "\x1B[31mError with ./a.out -1"
fi
if [ "$(./a.out a)" != "N" ]; then
			echo "\x1B[31mError with ./a.out a"
fi
if [ "$(./a.out "")" != "N" ]; then
			echo "\x1B[31mError with ./a.out "
fi
if [ "$(./a.out)" != "N" ]; then
			echo "\x1B[31mError with ./a.out"
fi
if [ "$(./a.out "-")" != "N" ]; then
			echo "\x1B[31mError with ./a.out -"
fi
if [ "$(./a.out "1a")" != "N" ]; then
			echo "\x1B[31mError with ./a.out 1a"
fi
if [ "$(./a.out "a1")" != "N" ]; then
			echo "\x1B[31mError with ./a.out a1"
fi
if [ "$(./a.out "-a")" != "N" ]; then
			echo "\x1B[31mError with ./a.out -a"
fi

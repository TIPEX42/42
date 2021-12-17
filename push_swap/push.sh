#!/bin/sh

git add *.c
git add srcs/*c
git add *.h
git add Makefile
git add testing/generator
git add push.sh
git add testing/start.sh
git add testing/stress.sh
cd libft
git add *.c
git add *.h
git add Makefile
cd ..
git commit -m "$@"
git push
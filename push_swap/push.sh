#!/bin/sh

git add *.c
git add *.h
git add Makefile
git add push.sh
cd libft
git add *.c
git add *.h
git add Makefile
cd ..
git commit -m "$@"
git push
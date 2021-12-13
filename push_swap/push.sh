#!/bin/sh

git add *.c
git add *.h
git add Makefile
git add generator
git add push.sh
git add start.sh
git add stress.sh
cd libft
git add *.c
git add *.h
git add Makefile
cd ..
git commit -m "$@"
git push
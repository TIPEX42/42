#!/bin/bash

find . -maxdepth 1 -type d \( ! -name . \) -exec bash -c "cd '{}' && make clean" \;
find . -maxdepth 1 -type d \( ! -name . \) -exec bash -c "cd '{}' && make fclean" \;

git add .
git status
git commit -m "auto"
git push
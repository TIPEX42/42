#!/bin/bash

find . -maxdepth 1 -type d \( ! -name . \) -exec bash -c "cd '{}' && make clean" \;
find . -maxdepth 1 -type d \( ! -name . \) -exec bash -c "cd '{}' && make fclean" \;

git add .
echo "------------------------------------------------------------"
git status
echo "------------------------------------------------------------"
git commit -m "auto"
git push
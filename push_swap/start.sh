#!/bin/sh

make

echo "Tests with size 10"
./push_swap $(./generator 200) | wc -l
echo "Finished ----------------"
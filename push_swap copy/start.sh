#!/bin/sh

make

echo "Tests with size 10"
./push_swap $(./generator 10 1) | wc -l
./push_swap $(./generator 10 3) | wc -l
./push_swap $(./generator 10 5) | wc -l
./push_swap $(./generator 10 7) | wc -l
./push_swap $(./generator 10 9) | wc -l
echo "Finished ----------------"

echo "Tests with size 50"
./push_swap $(./generator 50 1) | wc -l
./push_swap $(./generator 50 3) | wc -l
./push_swap $(./generator 50 5) | wc -l
./push_swap $(./generator 50 7) | wc -l
./push_swap $(./generator 50 9) | wc -l
echo "Finished ----------------"

echo "Tests with size 100"
./push_swap $(./generator 100 1) | wc -l
./push_swap $(./generator 100 3) | wc -l
./push_swap $(./generator 100 5) | wc -l
./push_swap $(./generator 100 7) | wc -l
./push_swap $(./generator 100 9) | wc -l
echo "Finished ----------------"

echo "Tests with size 500"
./push_swap $(./generator 500 1) | wc -l
./push_swap $(./generator 500 3) | wc -l
./push_swap $(./generator 500 5) | wc -l
./push_swap $(./generator 500 7) | wc -l
./push_swap $(./generator 500 9) | wc -l
echo "Finished ----------------"
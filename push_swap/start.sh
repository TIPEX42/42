#!/bin/sh

make

AVG=0

echo "\x1B[32m----Tests with size 1 to 10----"

i=2
while (( $i <= 10 ))
do
	echo "\x1B[33m$i"
	n=0
	AVG=0
	while (( $n < 25 ))
	do
		AVG=$(( AVG+$(./push_swap $(./generator $i n) | wc -l )))
		n=$(( n+1 ))
	done
	AVG=$(( AVG/25 ))
	echo "\x1B[33mAverage operations : \x1B[31m$AVG"
	i=$(( i+1 ))
done
echo "\x1B[32mFinished ----------------"

echo "\x1B[32m----Tests with size 50----"

n=0
while (( $n < 10 ))
do
	AVG=$(( AVG+$(./push_swap $(./generator 50 n) | wc -l )))
	n=$(( n+1 ))
done
n=0
while (( $n < 10 ))
do
	nbs=$(./generator 50 $n)
	./push_swap $nbs | ./checker_Mac.dms $nbs
	n=$(( n+1 ))
done
AVG=$(( AVG/10 ))
echo "\x1B[33mAverage operations : \x1B[31m$AVG"
echo "\x1B[32mFinished ----------------"

echo "\x1B[32m----Tests with size 100----"

n=0
while (( $n < 10000 ))
do
	AVG=$(( AVG+$(./push_swap $(./generator 100 n) | wc -l )))
	n=$(( n+1 ))
done
n=0
while (( $n < 10 ))
do
	nbs=$(./generator 100 $n)
	./push_swap $nbs | ./checker_Mac.dms $nbs
	n=$(( n+1 ))
done
AVG=$(( AVG/10000 ))
echo "\x1B[33mAverage operations : \x1B[31m$AVG"
echo "\x1B[32mFinished ----------------"

echo "\x1B[32m----Tests with size 500----"

n=0
while (( $n < 5000 ))
do
	AVG=$(( AVG+$(./push_swap $(./generator 500 n) | wc -l )))
	n=$(( n+1 ))
done
n=0
while (( $n < 10 ))
do
	nbs=$(./generator 500 $n)
	./push_swap $nbs | ./checker_Mac.dms $nbs
	n=$(( n+1 ))
done
AVG=$(( AVG/5000 ))
echo "\x1B[33mAverage operations : \x1B[31m$AVG"
echo "\x1B[32mFinished ----------------"

AVG=0
echo "\x1B[32m----Tests with size 1000----"

n=0
while (( $n < 3 ))
do
	AVG=$(( AVG+$(./push_swap $(./generator 1000 n) | wc -l )))
	n=$(( n+1 ))
done
n=0
while (( $n < 3 ))
do
	nbs=$(./generator 1000 $n)
	./push_swap $nbs | ./checker_Mac.dms $nbs
	n=$(( n+1 ))
done
AVG=$(( AVG/3 ))
echo "\x1B[33mAverage operations : \x1B[31m$AVG"
echo "\x1B[32mFinished ----------------"
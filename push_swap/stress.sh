#!/bin/sh

make
i=1
while (( $i < 500 ))
do
	echo "\x1B[33m$i"
	n=0
	while (( $n < 10 ))
	do
		nbs=$(./generator $i $n)
		if [ "$(./push_swap $nbs | ./checker_Mac.dms $nbs)" != "OK" ]; then
			echo "\x1B[31mError"
		fi
		n=$(( n+1 ))
	done
	i=$(( i+1 ))
done
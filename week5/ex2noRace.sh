#!/bin/bash
if test ! -f numbers
then 
	echo 0 > numbers #create file
fi

if ln numbers numbers.lock
	then
	for ((i = 1; i <= 100; i++))
	do
		n="$(tail -1 numbers)"
		expr $n + 1 >> numbers
	done

	rm numbers.lock #unlock
fi

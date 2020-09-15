
#!/bin/bash
if test ! -f numbers
then 
	echo 0 > numbers #create file
fi

for ((i = 1; i <= 100; i++))
do
	n="$(tail -1 numbers)"
	expr $n + 1 >>numbers
done

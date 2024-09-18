#bin/bash

echo "Input number!"
read num

sum=0
tmp=0
count=0
average=0

if [[ $num =~ [A-z] ]]
	then
	echo " '$num' isnot a number"
else while (( $num ))
	do
           tmp=$(( $num % 10))
           num=$(( $num / 10))
           sum=$(( $sum + $tmp))
	   ((count++))
	done
fi
	echo "Digits sum is $sum"
	average=$(( $sum / $count))
	echo "Average is $average"


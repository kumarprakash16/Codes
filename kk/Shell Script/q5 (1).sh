# check if number is even or odd
clear
val=`expr $1 % 2`
if [ $val -eq 0 ]
then
	echo "$1 is even"
else
	echo "$1 is odd"
fi

